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

std::ostream& operator<<(std::ostream &s, const std::vector<Step> &step) {
    for (auto it = step.begin(); it != step.end(); ++it) {
        s << " [" << it->sat << "] " << it->transition;
    }
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

Result<Rule> Reachability::unroll(const Rule &rule) {
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
            const auto res = unroll(r);
            if (res) {
                const auto simplified = Preprocess::simplifyRule(its, *res, true);
                ret.succeed();
                ret.concat(res.getProof());
                if (simplified) {
                    its.replaceRules({idx}, {*simplified});
                    ret.concat(simplified.getProof());
                } else {
                    its.replaceRules({idx}, {*res});
                }
            }
        }
    }
    return ret;
}

BoolExpr Reachability::project(const TransIdx idx) {
    RelSet res;
    const Subs model = sigmas.back().compose(z3.model().toSubs());
    for (const auto &rel: its.getRule(idx).getGuard()->lits()) {
        if (rel.subs(model).isTriviallyTrue()) {
            res.insert(rel);
        }
    }
    return buildAnd(res);
}

bool Reachability::covers(const Subs &model, const BoolExpr &rels) const {
    return Smt::check(rels->subs(model), its) == Smt::Sat;
}

bool Reachability::leaves_scc(const TransIdx idx) const {
    const Rule &r = its.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

option<int> Reachability::is_loop(const TransIdx idx) {
    const Subs model = z3.model().toSubs();
    const LocationIdx dst = its.getRule(idx).getRhsLoc(0);
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition) || !covers(sigmas[pos].concat(model), step.sat)) {
            return {};
        }
        if (its.getRule(step.transition).getLhsLoc() == dst) {
            bool non_simple = static_cast<unsigned>(pos) < trace.size() - 1;
            bool orig_rule = idx <= lastOrigRule;
            if ((non_simple || orig_rule)) {
                return pos;
            }
        }
    }
    return {};
}

Automaton Reachability::singleton_automaton(const TransIdx idx) const {
    Automaton res;
    res.InsInitState(1);
    res.InsMarkedState(2);
    res.SetTransition(1, res.InsEvent(std::to_string(idx)), 2);
    return res;
}

bool Reachability::is_covered(const Automaton &automaton, const Subs &model) const {
    return std::any_of(covered.begin(), covered.end(), [&](const auto &p) {
        return faudes::LanguageInclusion(automaton, p.first) && covers(model, p.second);
    });
}

void Reachability::handle_update(const TransIdx idx) {
    const Rule &r = its.getRule(idx);
    RelSet eqs;
    const Subs &oldSigma = sigmas.back();
    Subs newSigma;
    const Subs up = r.getUpdate(0);
    for (const auto &var: prog_vars) {
        const Var x = its.getFreshUntrackedSymbol(var.get_name(), Expr::Int);
        z3.add(buildLit(Rel::buildEq(x, Expr(var).subs(up).subs(oldSigma))));
        newSigma.put(var, x);
    }
    for (const auto &var: r.vars()) {
        if (its.isTempVar(var)) {
            newSigma.put(var, its.getFreshUntrackedSymbol(var.get_name(), Expr::Int));
        }
    }
    sigmas.push_back(newSigma);
}

void Reachability::do_block(const Step &step) {
    if (log) std::cout << "blocking " << step.transition << ", " << step.sat << std::endl;
    auto block = blocked.back().find(step.transition);
    if (block == blocked.back().end()) {
        blocked.back()[step.transition] = {step.sat};
    } else {
        block->second.insert(step.sat);
    }
}

void Reachability::pop() {
    sigmas.pop_back();
    blocked.pop_back();
    trace.pop_back();
    z3.pop();
    proof.pop();
}

void Reachability::backtrack() {
    if (log) std::cout << "backtracking" << std::endl;
    const Step step = trace.back();
    pop();
    do_block(step);
}

void Reachability::extend_trace(const TransIdx idx, const BoolExpr &sat) {
    if (!trace.empty()) {
        assert(its.getRule(trace.back().transition).getRhsLoc(0) == its.getRule(idx).getLhsLoc());
    }
    trace.emplace_back(idx, sat);
    proof.push();
    proof.headline("extended trace");
    proof.append(std::stringstream() << "added " << idx << " to trace");
    Proof subProof;
    subProof.section("sat");
    subProof.append(std::stringstream() << sat);
    subProof.section("trace");
    subProof.append(std::stringstream() << trace);
    proof.storeSubProof(subProof);
}

void Reachability::store(const TransIdx idx, const BoolExpr &sat) {
    extend_trace(idx, sat);
    blocked.push_back({});
    z3.add(sat->subs(sigmas.back()));
    handle_update(idx);
}

void Reachability::print_run(std::ostream &s) {
    auto it = sigmas.begin();
    const Subs model = z3.model().toSubs();
    for (const auto &step: trace) {
        s << " [";
        for (const auto &x: prog_vars) {
            s << " " << x << "=" << Expr(x).subs(*it).subs(model);
        }
        ++it;
        s << " ] " << step.transition;
    }
    s << std::endl;
}

void Reachability::preprocess() {
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
    if (log) {
        std::cout << "simplified ITS" << std::endl;
        ITSExport::printForProof(its, std::cout);
    }
}

void Reachability::init() {
    Subs sigma;
    for (const auto &x: its.getVars()) {
        if (!its.isTempVar(x)) {
            sigma.put(x, x);
            prog_vars.insert(x);
        }
    }
    sigmas.push_back(sigma);
    for (const TransIdx idx: its.getAllTransitions()) {
        regexes[idx] = singleton_automaton(idx);
        lastOrigRule = std::max(lastOrigRule, idx);
    }
}

void Reachability::unsat() {
    std::cout << "unsat" << std::endl << std::endl;
    std::stringstream trace_stream, counterexample;
    trace_stream << trace;
    print_run(counterexample);
    if (log) {
        std::cout << "final ITS:" << std::endl;
        ITSExport::printForProof(its, std::cout);
        std::cout << std::endl << "final trace:" << trace_stream.str() << std::endl << std::endl;
        std::cout << "counterexample:" << counterexample.str();
    }
    proof.headline("proved unsatisfiability");
    Proof subProof;
    subProof.section("final trace");
    subProof.append(trace_stream);
    subProof.section("counterexample");
    subProof.append(counterexample);
    proof.storeSubProof(subProof);
    proof.print();
}

option<BoolExpr> Reachability::do_step(const TransIdx idx) {
    Subs sigma = sigmas.back();
    const Rule r = its.getRule(idx);
    BoolExpr g = r.getGuard()->subs(sigma);
    z3.add(g);
    const auto block = blocked.back().find(idx);
    if (block != blocked.back().end()) {
        for (const auto &b: block->second) {
            z3.add(!b->subs(sigma));
        }
    }
    if (z3.check() == Smt::Sat) {
        if (log) std::cout << "found model for " << idx << std::endl;
        return project(idx);
    } else {
        if (log) std::cout << "could not find a model for " << idx << std::endl;
        return {};
    }
}

std::pair<Rule, Automaton> Reachability::build_loop(const int backlink) {
    Automaton automaton;
    automaton.InsInitState(1);
    automaton.SetMarkedState(1);
    const auto event = automaton.InsEvent(std::to_string(trace.back().transition));
    Rule loop = its.getRule(trace.back().transition).withGuard(trace.back().sat);
    pop();
    Automaton concat;
    while (trace.size() > static_cast<unsigned>(backlink)) {
        const TransIdx t = trace.back().transition;
        const Rule &r = its.getRule(t);
        loop = *Chaining::chainRules(its, r.withGuard(trace.back().sat), loop, false);
        faudes::LanguageConcatenate(regexes[t], automaton, concat);
        automaton = concat;
        pop();
    }
    if (log) {
        std::cout << "found loop:" << std::endl;
        ITSExport::printRule(loop, its, std::cout);
        std::cout << std::endl;
    }
    const auto init = automaton.InitState();
    for (auto it = automaton.MarkedStatesBegin(); it != automaton.MarkedStatesEnd(); ++it) {
        automaton.SetTransition(*it, event, init);
    }
    return {loop, automaton};
}

Result<Rule> Reachability::preprocess_loop(const Rule &loop) {
    Result<Rule> res(loop);
    const Result<Rule> simplified = Preprocess::simplifyRule(its, *res, true);
    if (simplified) {
        res = *simplified;
        res.storeSubProof(simplified.getProof());
        if (log) {
            std::cout << "simplified loop:" << std::endl;
            ITSExport::printRule(*res, its, std::cout);
            std::cout << std::endl;
        }
    }
    const Result<Rule> unrolled = unroll(*res);
    if (unrolled) {
        res = *unrolled;
        res.storeSubProof(unrolled.getProof());
        if (log) {
            std::cout << "unrolled loop:" << std::endl;
            ITSExport::printRule(*res, its, std::cout);
            std::cout << std::endl;
        }
    }
    return res;
}

bool Reachability::handle_loop(const int backlink) {
    const Step step = trace[backlink];
    const auto p = build_loop(backlink);
    Rule loop = p.first;
    const Automaton automaton = p.second;
    const Subs old_model = sigmas[backlink].concat(z3.model().toSubs());
    if (is_covered(automaton, old_model)) {
        if (log) std::cout << "loop already covered" << std::endl;
        return false;
    }
    covered.emplace_back(automaton, loop.getGuard());
    Proof accel_proof;
    const Result<Rule> preprocessed = preprocess_loop(loop);
    if (preprocessed) {
        accel_proof.concat(preprocessed.getProof());
        loop = *preprocessed;
    }
    const AccelerationResult accel_res = LoopAcceleration::accelerate(its, loop.toLinear(), -1, Complexity::Const);
    if (accel_res.rules.empty()) {
        if (log) std::cout << "acceleration failed" << std::endl;
        return false;
    }
    assert(accel_res.rules.size() == 1);
    accel_proof.storeSubProof(accel_res.proof);
    Rule accel = accel_res.rules.front();
    const auto simplified = Preprocess::simplifyRule(its, accel, true);
    if (simplified) {
        accel = *simplified;
        accel_proof.storeSubProof(simplified.getProof());
    }
    if (log) {
        std::cout << "accelerated rule:" << std::endl;
        ITSExport::printRule(accel, its, std::cout);
        std::cout << std::endl;
    }
    if (accel.getUpdate(0) == loop.getUpdate(0)) {
        if (log) std::cout << "acceleration yielded equivalent rule" << std::endl;
        return false;
    }
    z3.push();
    z3.add(accel.getGuard()->subs(sigmas.back()));
    if (z3.check() != Smt::Sat) {
        if (log) std::cout << "applying accelerated rule failed" << std::endl;
        z3.pop();
        return false;
    }
    const auto loop_idx = its.addRule(accel);
    for (const auto idx: its.getTransitionsFrom(2)) {
        assert(its.getRule(idx).getLhsLoc() == 2);
    }
    if (!loop_idx) {
        if (log) std::cout << "adding rule failed" << std::endl;
        z3.pop();
        return false;
    }
    regexes[*loop_idx] = automaton;
    store(*loop_idx, project(*loop_idx));
    proof.majorProofStep("accelerated loop", its);
    proof.storeSubProof(accel_proof);
    return true;
}

enum State {
    Successful,
    Failed,
    DroppedLoop
};

void Reachability::analyze() {
    proof.majorProofStep("initial ITS", its);
    preprocess();
    init();
    do {
        if (log) std::cout << "trace: " << trace << std::endl;
        State state = Failed;
        const TransIdx current = trace.empty() ? its.getInitialLocation() : its.getRule(trace.back().transition).getRhsLoc(0);
        for (const TransIdx idx: its.getTransitionsFrom(current)) {
            z3.push();
            const option<BoolExpr> sat = do_step(idx);
            if (!sat) {
                z3.pop();
                continue;
            }
            if (its.getRule(idx).getRhsLoc(0) == sink) {
                extend_trace(idx, *sat);
                unsat();
                return;
            }
            store(idx, *sat);
            const option<int> backlink = is_loop(idx);
            if (!backlink) {
                state = Successful;
                break;
            }
            if (*backlink < 0) {
                backtrack();
                continue;
            }
            const Step step = trace[*backlink];
            if (handle_loop(*backlink)) {
                state = Successful;
            } else {
                state = DroppedLoop;
                do_block(step);
            }
            break;
        }
        if (state == Failed && !trace.empty()) {
            backtrack();
        }
    } while (!trace.empty());
    std::cout << "unknown" << std::endl << std::endl;
}

void Reachability::analyze(ITSProblem &its) {
    Yices::init();
    Reachability(its).analyze();
    Yices::exit();
}
