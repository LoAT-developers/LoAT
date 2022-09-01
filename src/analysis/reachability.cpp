#include "reachability.hpp"
#include "chainstrategy.hpp"
#include "chain.hpp"
#include "preprocess.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "yices.hpp"
#include "export.hpp"

#include <numeric>

Reachability::Reachability(ITSProblem &its): its(its), z3(its) {
    z3.enableModels();
}

Step::Step(const TransIdx transition, const BoolExpr &sat): transition(transition), sat(sat) {}

std::ostream& operator<<(std::ostream &s, const Step &step) {
    s << "transition: " << step.transition << ", sat: " << step.sat;
    return s;
}

std::ostream& operator<<(std::ostream &s, const std::vector<Step> &step) {
    s << "[";
    for (auto it = step.begin(); it != step.end(); ++it) {
        if (it == step.begin()) {
            s << *it;
        } else {
            s << " :: " << *it;
        }
    }
    s << "]";
    return s;
}

ResultViaSideEffects Reachability::removeIrrelevantTransitions() {
    std::set<LocationIdx> keep;
    std::stack<LocationIdx> todo;
    todo.push(*its.getSink());
    do {
        const LocationIdx current = todo.top();
        todo.pop();
        keep.insert(current);
        for (const auto p: its.getPredecessorLocations(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }

    } while (!todo.empty());
    std::set<TransIdx> deleted;
    for (const auto idx: its.getAllTransitions()) {
        const LocationIdx target = its.getRule(idx).getRhsLoc(0);
        if (keep.find(target) == keep.end()) {
            const std::set<TransIdx> d = its.removeLocationAndRules(target);
            deleted.insert(d.begin(), d.end());
        }
    }
    ResultViaSideEffects ret;
    if (!deleted.empty()) {
        ret.succeed();
        ret.deletionProof(deleted);
    }
    return ret;
}

ResultViaSideEffects Reachability::simplify() {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(its, its.getRule(idx));
        if (res) {
            ret.succeed();
            its.replaceRules({idx}, {res.get()});
            ret.concat(res.getProof());
        }
    }
    return ret;
}

Rule Reachability::rename_tmp_vars(const Rule &rule) {
    Subs sigma;
    for (const auto &x: rule.vars()) {
        if (its.isTempVar(x)) {
            sigma.put(x, its.addFreshTemporaryVariable(x.get_name()));
        }
    }
    return rule.subs(sigma);
}

Result<Rule> Reachability::chain(const Rule &rule) {
    Result<Rule> res(rule);
    // chain if there are updates like x = -x + p
    for (const auto &p: rule.getUpdate(0)) {
        const Var var = p.first;
        const Expr up = p.second.expand();
        const VarSet upVars = up.vars();
        if (upVars.find(var) != upVars.end()) {
            if (up.isPoly() && up.degree(var) == 1) {
                const Expr coeff = up.coeff(var);
                if (coeff.isRationalConstant() && coeff.toNum().is_negative()) {
                    const Rule c = *Chaining::chainRules(its, *res, rename_tmp_vars(*res), false);
                    res.set(c.toLinear());
                    break;
                }
            }
        }
    }
    // chain if there are updates like x = y; y = x
    VarMap<unsigned> cycleLength;
    auto up = res->getUpdate(0);
    for (const auto &p: up) {
        VarSet vars = p.second.vars();
        unsigned oldSize = 0;
        unsigned count = 0;
        while (oldSize != vars.size() && vars.find(p.first) == vars.end()) {
            oldSize = vars.size();
            count++;
            for (const auto& var: vars) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    vars.insert(newVars.begin(), newVars.end());
                }
            }
        }
        if (vars.find(p.first) != vars.end() && count > 0) {
            cycleLength[p.first] = count;
        }
    }
    if (!cycleLength.empty()) {
        unsigned lcm = 1;
        for (const auto &e: cycleLength) {
            lcm = std::lcm(lcm, e.second);
        }
        for (unsigned i = 0; i < lcm; ++i) {
            const Rule c = *Chaining::chainRules(its, *res, rename_tmp_vars(*res), false);
            res.set(c.toLinear());
        }
    }
    // chain if it eliminates variables from an update
    bool changed;
    do {
        changed = false;
        up = res->getUpdate(0);
        for (const auto &p: up) {
            VarSet varsOneStep = p.second.vars();
            VarSet varsTwoSteps;
            for (const auto &var: varsOneStep) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    varsTwoSteps.insert(newVars.begin(), newVars.end());
                } else {
                    varsTwoSteps.insert(var);
                }
            }
            if (varsTwoSteps.size() < varsOneStep.size() && std::includes(varsOneStep.begin(), varsOneStep.end(), varsTwoSteps.begin(), varsTwoSteps.end())) {
                const Rule c = *Chaining::chainRules(its, *res, rename_tmp_vars(*res), false);
                res.set(c.toLinear());
                changed = true;
                break;
            }
        }
    } while (changed);
    if (res) {
        res.ruleTransformationProof(rule, "unrolling", *res, its);
    }
    return res;
}

ResultViaSideEffects Reachability::unroll() {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const Rule &r = its.getRule(idx);
        if (r.isSimpleLoop()) {
            const auto res = chain(r);
            if (res) {
                ret.succeed();
                its.replaceRules({idx}, {res.get()});
                ret.concat(res.getProof());
            }
        }
    }
    return ret;
}

BoolExpr Reachability::satisfied(const BoolExpr &b, const Subs &model) const {
    fset res;
    for (const auto &rel: b->lits()) {
        if (rel.subs(model).isTriviallyTrue()) {
            res.insert(rel);
        }
    }
    return buildAnd(res);
}

bool Reachability::covers(const BoolExpr rels, const Subs &model) const {
    return Smt::check(rels->subs(model), its) == Smt::Sat;
}

bool Reachability::leaves_scc(const TransIdx idx) const {
    const Rule &r = its.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

option<unsigned> Reachability::is_loop(const TransIdx idx, const Subs &model) const {
    const LocationIdx dst = its.getRule(idx).getRhsLoc(0);
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition)) {
            return {};
        }
        if (its.getRule(step.transition).getLhsLoc() == dst && covers(step.sat, model)) {
            if (pos < trace.size() - 1 || idx <= lastOrigRule) {
                return pos + 1;
            }
        }
    }
    return {};
}

faudes::Generator Reachability::singleton_automaton(const TransIdx idx) const {
    faudes::Generator res;
    res.InsInitState(1);
    res.InsMarkedState(2);
    res.SetTransition(1, res.InsEvent(std::to_string(idx)), 2);
    return res;
}

bool Reachability::is_covered(const faudes::Generator &automaton, const Subs &model) const {
    return std::any_of(covered.begin(), covered.end(), [&](const auto &p){
        return faudes::LanguageInclusion(automaton, p.first) && covers(p.second, model);
    });
}

bool Reachability::is_redundant(const TransIdx idx, const Subs &model) const {
    if (leaves_scc(idx)) {
        return false;
    }
    faudes::Generator regex = regexes.at(idx);
    faudes::Generator concat;
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition) || !covers(step.sat, model)) {
            return false;
        }
        const faudes::Generator previous = regexes.at(step.transition);
        faudes::LanguageConcatenate(previous, regex, concat);
        regex = concat;
        if (faudes::LanguageInclusion(regex, previous)) {
            return true;
        }
    }
    return false;
}

BoolExpr Reachability::handle_update(const Rule &r) {
    RelSet eqs;
    const Subs &oldSigma = sigmas.back();
    Subs newSigma, newInvSigma;
    const Subs up = r.getUpdate(0);
    for (const auto &var: prog_vars) {
        const Var x = its.getFreshUntrackedSymbol(var.get_name(), Expr::Int);
        eqs.insert(Rel::buildEq(x, Expr(var).subs(up).subs(oldSigma)));
        newSigma.put(var, x);
        newInvSigma.put(x, var);
    }
    for (const auto &tmp: its.getTempVars()) {
        const Var x = its.getFreshUntrackedSymbol(tmp.get_name(), Expr::Int);
        newSigma.put(tmp, x);
        newInvSigma.put(x, tmp);
    }
    sigmas.push_back(newSigma);
    inv_sigmas.push_back(newInvSigma);
    return buildAnd(eqs);
}

void Reachability::do_block(const TransIdx idx, const BoolExpr &sat) {
    auto block = blocked.back().find(idx);
    if (block == blocked.back().end()) {
        blocked.back()[idx] = {sat};
    } else {
        block->second.insert(sat);
    }
}

void Reachability::backtrack() {
    std::cout << "backtracking" << std::endl;
    const Step &step = trace.back();
    current = its.getRule(step.transition).getLhsLoc();
    sigmas.pop_back();
    inv_sigmas.pop_back();
    blocked.pop_back();
    do_block(step.transition, step.sat);
    trace.pop_back();
    z3.pop();
}

void Reachability::store(const TransIdx idx, const BoolExpr &sat) {
    const Rule &r = its.getRule(idx);
    current = r.getRhsLoc(0);
    blocked.push_back({});
    trace.emplace_back(idx, sat);
    z3.add(handle_update(r));
};

option<BoolExpr> Reachability::search_non_redundant_model(const TransIdx idx) {
    const Subs sigma = sigmas.back();
    const Subs inv_sigma = inv_sigmas.back();
    const BoolExpr g = its.getRule(idx).getGuard()->subs(sigma);
    do {
        if (z3.check() != Smt::Sat) {
            std::cout << "could not find a non-redundant model for " << idx << std::endl;
            return {};
        }
        std::cout << "found model for " << idx << std::endl;
        Subs model = z3.model().toSubs();
        const BoolExpr sat = satisfied(g, model)->subs(inv_sigma);
        if (is_redundant(idx, sigma.concat(model))) {
            std::cout << "redundant, adding blocking clause " << (!sat) << std::endl;
            do_block(idx, sat);
            z3.add(!sat->subs(sigma));
        } else {
            std::cout << "not redundant" << std::endl;
            return sat;
        }
    } while(1);
}

void Reachability::print_run() {
    auto it = sigmas.begin();
    const Subs model = z3.model().toSubs();
    for (const auto &step: trace) {
        std::cout << " [";
        for (const auto &x: prog_vars) {
            std::cout << " " << x << "=" << Expr(x).subs(*it).subs(model);
        }
        ++it;
        std::cout << " ] " << step.transition;
    }
    std::cout << std::endl;
}

void Reachability::analyze() {
    Yices::init();
    proof.majorProofStep("initial ITS", its);
    ResultViaSideEffects res = removeIrrelevantTransitions();
    if (res) {
        proof.majorProofStep("removed irrelevant transitions", its);
        proof.storeSubProof(res.getProof());
    }
    res = Chaining::chainLinearPaths(its);
    if (res) {
        proof.majorProofStep("chained linear paths", its);
        proof.storeSubProof(res.getProof());
    }
    res = simplify();
    if (res) {
        proof.majorProofStep("simplified transitions", its);
        proof.storeSubProof(res.getProof());
    }
    res = unroll();
    if (res) {
        proof.majorProofStep("unrolled loops", its);
        proof.storeSubProof(res.getProof());
    }
    res = simplify();
    if (res) {
        proof.majorProofStep("simplified transitions", its);
        proof.storeSubProof(res.getProof());
    }
    ITSExport::printForProof(its, std::cout);
    for (const auto &x: its.getVars()) {
        if (!its.isTempVar(x)) {
            prog_vars.insert(x);
        }
    }
    for (const TransIdx idx: its.getAllTransitions()) {
        regexes[idx] = singleton_automaton(idx);
        lastOrigRule = std::max(lastOrigRule, idx);
    }
    do {
        std::cout << "trace: " << trace << std::endl;
        if (current == sink) {
            std::cout << "UNSAT" << std::endl;
            ITSExport::printForProof(its, std::cout);
            std::cout << trace << std::endl;
            print_run();
            proof.print();
            break;
        }
        bool success = false;
        for (const TransIdx idx: its.getTransitionsFrom(current)) {
            Subs sigma = sigmas.back();
            Subs inv_sigma = inv_sigmas.back();
            const Rule r = its.getRule(idx);
            BoolExpr g = r.getGuard()->subs(sigma);
            z3.push();
            z3.add(g);
            const auto block = blocked.back().find(idx);
            if (block != blocked.back().end()) {
                for (const auto &b: block->second) {
                    z3.add(!b->subs(sigma));
                }
            }
            option<BoolExpr> sat = search_non_redundant_model(idx);
            if (!sat) {
                z3.pop();
                continue;
            }
            Subs model = sigma.compose(z3.model().toSubs());
            store(idx, *sat);
            sigma = sigmas.back();
            inv_sigma = inv_sigmas.back();
            option<unsigned> backlink = is_loop(idx, model);
            if (backlink) {
                faudes::Generator automaton;
                automaton.InsInitState(1);
                automaton.SetMarkedState(1);
                Rule loop = r;
                BoolExpr guard = *sat;
                faudes::Generator concat;
                for (unsigned i = *backlink; i < trace.size() - 1; ++i) {
                    const TransIdx t = trace[i].transition;
                    guard = guard & trace[i].sat->subs(loop.getUpdate(0));
                    loop = *Chaining::chainRules(its, loop, its.getRule(t));
                    faudes::LanguageConcatenate(automaton, regexes[t], concat);
                    automaton = concat;
                }
                loop = loop.withGuard(guard);
                std::cout << "found loop:" << std::endl;
                ITSExport::printRule(loop, its, std::cout);
                std::cout << std::endl;
                const auto event = automaton.InsEvent(std::to_string(trace.back().transition));
                const auto init = automaton.InitState();
                for (auto it = automaton.MarkedStatesBegin(); it != automaton.MarkedStatesEnd(); ++it) {
                    automaton.SetTransition(*it, event, init);
                }
                Proof accel_proof;
                const Result<Rule> simplified = Preprocess::simplifyRule(its, loop, false);
                if (simplified) {
                    loop = *simplified;
                    accel_proof.storeSubProof(simplified.getProof());
                    std::cout << "simplified loop:" << std::endl;
                    ITSExport::printRule(loop, its, std::cout);
                    std::cout << std::endl;
                }
                const Result<Rule> unrolled = chain(loop);
                if (unrolled) {
                    loop = *unrolled;
                    accel_proof.storeSubProof(unrolled.getProof());
                    std::cout << "unrolled loop:" << std::endl;
                    ITSExport::printRule(loop, its, std::cout);
                    std::cout << std::endl;
                }
                const AccelerationResult accel_res = LoopAcceleration::accelerate(its, loop.toLinear(), -1, Complexity::Const);
                if (accel_res.rules.empty()) {
                    std::cout << "acceleration failed" << std::endl;
                    backtrack();
                    continue;
                } else {
                    assert(accel_res.rules.size() == 1);
                    accel_proof.storeSubProof(accel_res.proof);
                    const Rule accel = accel_res.rules.front();
                    std::cout << "accelerated rule:" << std::endl;
                    ITSExport::printRule(accel, its, std::cout);
                    std::cout << std::endl;
                    g = accel.getGuard()->subs(sigma);
                    z3.push();
                    z3.add(g);
                    if (z3.check() == Smt::Sat) {
                        model = sigma.compose(z3.model().toSubs());
                        if (is_covered(automaton, model)) {
                            std::cout << "accelerated rule already covered" << std::endl;
                            z3.pop();
                            backtrack();
                            continue;
                        }
                        const auto loop_idx = its.addRule(accel);
                        if (loop_idx) {
                            std::cout << "acceleration succeeded" << std::endl;
                            success = true;
                            const BoolExpr sat = satisfied(g, model)->subs(inv_sigma);
                            store(*loop_idx, sat);
                            regexes[*loop_idx] = automaton;
                            covered.emplace_back(automaton, sat);
                            proof.majorProofStep("accelerated loop", its);
                            proof.storeSubProof(accel_proof);
                            break;
                        } else {
                            std::cout << "adding rule failed" << std::endl;
                            z3.pop();
                            backtrack();
                            continue;
                        }
                    } else {
                        std::cout << "applying accelerated rule failed" << std::endl;
                        z3.pop();
                        backtrack();
                        continue;
                    }
                }
            }
            success = true;
            break;
        }
        if (!success && !trace.empty()) {
            std::cout << "failed" << std::endl;
            backtrack();
        }
    } while (!trace.empty());
    if (trace.empty()) {
        std::cout << "MAYBE" << std::endl;
        proof.print();
    }
    Yices::exit();
}

void Reachability::analyze(ITSProblem &its) {
    Reachability(its).analyze();
}
