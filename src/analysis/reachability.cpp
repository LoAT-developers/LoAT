#include "reachability.hpp"
#include "chainstrategy.hpp"
#include "chain.hpp"
#include "preprocess.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "yices.hpp"
#include "smtfactory.hpp"
#include "export.hpp"
#include "expression.hpp"
#include "boolexpression.hpp"

#include <numeric>

bool Reachability::log = false;

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

ResultViaSideEffects Reachability::unroll() {
    ResultViaSideEffects ret;
    for (const TransIdx idx: its.getAllTransitions()) {
        const Rule &r = its.getRule(idx);
        if (r.isSimpleLoop()) {
            const auto [res, period] = LoopAcceleration::chain(r.toLinear(), its);
            if (period > 1) {
                const auto simplified = Preprocess::simplifyRule(its, res, true);
                ret.succeed();
                ret.ruleTransformationProof(r, "unrolling", res, its);
                if (simplified) {
                    its.replaceRules({idx}, {*simplified});
                    ret.concat(simplified.getProof());
                } else {
                    its.replaceRules({idx}, {res});
                }
            }
        }
    }
    return ret;
}

BoolExpr Reachability::project(const TransIdx idx) {
    std::vector<Lit> res;
    const Subs model = sigmas.back().compose(z3.model().toSubs());
    for (const auto &rel: its.getRule(idx).getGuard()->lits()) {
        if (literal::subs(rel, model)->isTriviallyTrue()) {
            res.push_back(rel);
        }
    }
    return BExpression::buildAndFromLits(res);
}

bool Reachability::covers(const Subs &model, const BoolExpr &rels) const {
    return SmtFactory::check(rels->subs(model), its) == Sat;
}

bool Reachability::leaves_scc(const TransIdx idx) const {
    const Rule &r = its.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

int Reachability::is_loop() {
    if (trace.empty()) {
        return -1;
    }
    const TransIdx idx = trace.back().transition;
    const Subs model = z3.model().toSubs();
    const LocationIdx dst = its.getRule(idx).getRhsLoc(0);
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition) || !covers(sigmas[pos].concat(model), step.sat)) {
            return -1;
        }
        if (its.getRule(step.transition).getLhsLoc() == dst) {
            bool non_simple = static_cast<unsigned>(pos) < trace.size() - 1;
            bool orig_rule = idx <= lastOrigRule;
            if ((non_simple || orig_rule)) {
                return pos;
            }
        }
    }
    return -1;
}

Automaton Reachability::singleton_language(const TransIdx idx, const Guard &guard) {
    Automaton res;
    faudes::EventSet events;
    events.Insert(covered.InsEvent(std::to_string(next_char)));
    faudes::AlphabetLanguage(events, res);
    alphabet.emplace(std::pair<TransIdx, Guard>{idx, guard}, res);
    next_char++;
    return res;
}

void Reachability::handle_update(const TransIdx idx) {
    const Rule &r = its.getRule(idx);
    RelSet eqs;
    const Subs &oldSigma = sigmas.back();
    Subs newSigma;
    const Subs up = r.getUpdate(0);
    for (const auto &v: prog_vars) {
        if (std::holds_alternative<NumVar>(v)) {
            const auto &var = std::get<NumVar>(v);
            const auto x = its.getFreshUntrackedSymbol<IntTheory>(var.getName(), Expr::Int);
            z3.add(boolExpression::build(Rel::buildEq(x, up.get<IntTheory>(var).subs(oldSigma.get<IntTheory>()))));
            newSigma.put<IntTheory>(var, x);
        } else if (std::holds_alternative<BoolVar>(v)) {
            const auto &var = std::get<BoolVar>(v);
            const auto x = its.getFreshUntrackedSymbol<BoolTheory>(var.getName(), Expr::Bool);
            const auto lhs = boolExpression::build(x);
            const auto rhs = up.get<BoolTheory>(var)->subs(oldSigma);
            z3.add((lhs & rhs) | ((!lhs) & (!rhs)));
            newSigma.put<BoolTheory>(var, lhs);
        }
    }
    for (const auto &var: r.vars()) {
        if (its.isTempVar(var)) {
            if (std::holds_alternative<NumVar>(var)) {
                newSigma.put<IntTheory>(std::get<NumVar>(var), its.getFreshUntrackedSymbol<IntTheory>(variable::getName(var), Expr::Int));
            } else if (std::holds_alternative<BoolVar>(var)) {
                newSigma.put<BoolTheory>(std::get<BoolVar>(var), boolExpression::build(its.getFreshUntrackedSymbol<BoolTheory>(variable::getName(var), Expr::Bool)));
            } else {
                throw std::logic_error("unsupported theory");
            }
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
            s << " " << x << "=" << expression::subs(it->get(x), model);
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

void Reachability::update_transitions(const LocationIdx loc) {
    auto it = cross_scc.find(loc);
    std::list<LocationIdx> trans;
    if (it != cross_scc.end()) {
        trans.insert(trans.end(), it->second.begin(), it->second.end());
    }
    it = accelerated.find(loc);
    if (it != accelerated.end()) {
        trans.insert(trans.end(), it->second.begin(), it->second.end());
    }
    it = in_scc.find(loc);
    if (it != in_scc.end()) {
        trans.insert(trans.end(), it->second.begin(), it->second.end());
    }
    transitions[loc] = trans;
}

void Reachability::init() {
    for (const auto &x: its.getVars()) {
        if (!its.isTempVar(x)) {
            prog_vars.insert(x);
        }
    }
    faudes::EmptyLanguage({}, covered);
    for (const TransIdx idx: its.getAllTransitions()) {
        lastOrigRule = std::max(lastOrigRule, idx);
        const TransIdx src = its.getRule(idx).getLhsLoc();
        auto *to_insert = leaves_scc(idx) ? &cross_scc : &in_scc;
        const auto it = to_insert->find(src);
        if (it == to_insert->end()) {
            to_insert->emplace(src, std::vector<TransIdx>{idx});
        } else {
            it->second.push_back(idx);
        }
    }
    for (const auto loc: its.getLocations()) {
        update_transitions(loc);
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
    if (z3.check() == Sat) {
        if (log) std::cout << "found model for " << idx << std::endl;
        return project(idx);
    } else {
        if (log) std::cout << "could not find a model for " << idx << std::endl;
        return {};
    }
}

void Reachability::drop_loop(const int backlink) {
    while (trace.size() > static_cast<unsigned>(backlink)) {
        pop();
    }
}

Automaton Reachability::get_language(const Step &step) {
    if (step.transition <= lastOrigRule) {
        const auto g = step.sat->conjunctionToGuard();
        const auto it = alphabet.find({step.transition, g});
        if (it == alphabet.end()) {
            return singleton_language(step.transition, g);
        } else {
            return it->second;
        }
    } else {
        return regexes[step.transition];
    }
}

std::pair<Rule, Automaton> Reachability::build_loop(const int backlink) {
    Automaton automaton = get_language(trace.back());
    Rule loop = its.getRule(trace.back().transition).withGuard(trace.back().sat);
    for (int i = trace.size() - 2; i >= backlink; --i) {
        const Step &step = trace[i];
        auto sigma = sigmas[i+1];
        sigma.erase(prog_vars); // rename temporary variables before chaining
        const TransIdx t = step.transition;
        const Rule &r = its.getRule(t);
        loop = *Chaining::chainRules(its, r.withGuard(step.sat).subs(sigma), loop, false);
        faudes::LanguageConcatenate(get_language(step), automaton, automaton);
    }
    assert(loop.getLhsLoc() == loop.getRhsLoc(0));
    if (log) {
        std::cout << "found loop:" << std::endl;
        ITSExport::printRule(loop, its, std::cout);
        std::cout << std::endl;
    }
    Automaton closure;
    faudes::KleeneClosure(automaton, closure);
    faudes::LanguageConcatenate(automaton, closure, closure);
    faudes::StateMin(closure, closure);
    return {loop, closure};
}

Result<Rule> Reachability::preprocess_loop(const Rule &loop) {
    Result<Rule> res(loop);
    const Result<Rule> simplified = Preprocess::simplifyRule(its, *res, true);
    if (simplified) {
        res = *simplified;
        res = res->withGuard(res->getGuard()->toG());
        res.storeSubProof(simplified.getProof());
        if (log) {
            std::cout << "simplified loop:" << std::endl;
            ITSExport::printRule(*res, its, std::cout);
            std::cout << std::endl;
        }
    }
    return res;
}

TransIdx Reachability::add_accelerated_rule(const Rule &accel, const Automaton &automaton) {
    const auto loop_idx = its.addRule(accel);
    regexes[loop_idx] = automaton;
    const auto src = accel.getLhsLoc();
    auto it = accelerated.find(src);
    if (it == accelerated.end()) {
        accelerated.emplace(src, std::vector<TransIdx>{loop_idx});
    } else {
        it->second.push_back(loop_idx);
    }
    update_transitions(src);
    return loop_idx;
}

Reachability::LoopState Reachability::handle_loop(const int backlink) {
    const Step step = trace[backlink];
    const auto p = build_loop(backlink);
    Rule loop = p.first;
    const Automaton automaton = p.second;
    const Subs old_model = sigmas[backlink].concat(z3.model().toSubs());
    if (faudes::LanguageInclusion(automaton, covered)) {
        if (log) std::cout << "loop already covered" << std::endl;
        return Covered;
    }
    faudes::LanguageUnion(covered, automaton, covered);
    faudes::StateMin(covered, covered);
    Proof accel_proof;
    const Result<Rule> preprocessed = preprocess_loop(loop);
    if (preprocessed) {
        accel_proof.concat(preprocessed.getProof());
        loop = *preprocessed;
    }
    AccelerationResult accel_res = LoopAcceleration::accelerate(its, loop.toLinear(), -1, Complexity::Const);
    option<Rule> accel;
    if (accel_res.rule) {
        accel = accel_res.rule;
        const auto simplified = Preprocess::simplifyRule(its, *accel, true);
        if (simplified) {
            accel = *simplified;
        }
        if (log) {
            std::cout << "accelerated rule:" << std::endl;
            ITSExport::printRule(*accel, its, std::cout);
            std::cout << std::endl;
        }
        if (accel->getUpdate(0) == loop.getUpdate(0)) {
            if (log) std::cout << "acceleration yielded equivalent rule" << std::endl;
            accel = loop;
            accel_proof.append("acceleration yielded equivalent rule, using resolvent as accelerator");
        } else {
            accel_proof.storeSubProof(accel_res.proof);
            if (simplified) {
                accel_proof.storeSubProof(simplified.getProof());
            }
        }
    } else {
        if (log) std::cout << "acceleration failed" << std::endl;
        accel = loop;
        accel_proof.append("acceleration failed, using resolvent as accelerator");
    }
    const auto loop_idx = add_accelerated_rule(*accel, automaton);
    drop_loop(backlink);
    proof.majorProofStep("accelerated loop", its);
    proof.storeSubProof(accel_proof);
    z3.push();
    z3.add(accel->getGuard()->subs(sigmas.back()));
    if (z3.check() == Sat) {
        store(loop_idx, accel->getGuard());
        proof.append(std::stringstream() << "added " << loop_idx << " to trace");
        return Accelerated;
    } else {
        if (log) std::cout << "applying accelerated rule failed" << std::endl;
        z3.pop();
        return Dropped;
    }
}

void Reachability::analyze() {
    proof.majorProofStep("initial ITS", its);
    if (log) {
        std::cout << "initial ITS" << std::endl;
        ITSExport::printForProof(its, std::cout);
    }
    preprocess();
    init();
    do {
        if (log) std::cout << "trace: " << trace << std::endl;
        for (int backlink = is_loop(); backlink >= 0; backlink = is_loop()) {
            const Step step = trace[backlink];
            LoopState state = handle_loop(backlink);
            switch (state) {
            case Covered: {
                backtrack();
                break;
            }
            case Accelerated: {
                bool simple_loop = static_cast<unsigned>(backlink) == trace.size() - 1;
                if (simple_loop) {
                    do_block(step);
                }
                // make sure that we do not apply the accelerated transition again straight away, which is redundant
                do_block(trace.back());
                break;
            }
            case Dropped: {
                do_block(step);
                break;
            }
            }
        }
        const TransIdx current = trace.empty() ? its.getInitialLocation() : its.getRule(trace.back().transition).getRhsLoc(0);
        auto &trans = transitions[current];
        auto it = trans.begin();
        std::vector<TransIdx> append;
        while (it != trans.end()) {
            z3.push();
            const option<BoolExpr> sat = do_step(*it);
            if (!sat) {
                z3.pop();
                append.push_back(*it);
                it = trans.erase(it);
            } else {
                const Rule &r = its.getRule(*it);
                if (r.getRhsLoc(0) == sink) {
                    extend_trace(*it, *sat);
                    unsat();
                    return;
                }
                // TODO Is this needed?
                if (*it > lastOrigRule && r.isSimpleLoop()) {
                    do_block(trace.back());
                }
                store(*it, *sat);
                break;
            }
        }
        trans.insert(trans.end(), append.begin(), append.end());
        if (it == trans.end() && !trace.empty()) {
            backtrack();
        }
    } while (!trace.empty());
    std::cout << "unknown" << std::endl << std::endl;
}

void Reachability::analyze(ITSProblem &its) {
    yices::init();
    Reachability(its).analyze();
    yices::exit();
}
