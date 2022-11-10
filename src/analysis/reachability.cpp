#include "reachability.hpp"
#include "chainstrategy.hpp"
#include "chain.hpp"
#include "preprocess.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "yices.hpp"
#include "smt.hpp"
#include "export.hpp"
#include "expression.hpp"
#include "boolexpression.hpp"
#include "vector.hpp"

#include <numeric>

bool Reachability::log = false;

LoopState::LoopState() {}

option<Accelerated> LoopState::accelerated() {
    return {};
}

option<Covered> LoopState::covered() {
    return {};
}

option<Dropped> LoopState::dropped() {
    return {};
}

option<Failed> LoopState::failed() {
    return {};
}

Accelerated::Accelerated(const Result<TransIdx> &idx): idx(idx) {}

void Accelerated::foo() {}

option<Accelerated> Accelerated::accelerated() {
    return *this;
}

Result<TransIdx>& Accelerated::operator*() {
    return idx;
}

Result<TransIdx>* Accelerated::operator->() {
    return &idx;
}

void Covered::foo() {}

option<Covered> Covered::covered() {
    return *this;
}

void Dropped::foo() {}

option<Dropped> Dropped::dropped() {
    return *this;
}

void Failed::foo() {}

option<Failed> Failed::failed() {
    return *this;
}

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

bool Reachability::leaves_scc(const TransIdx idx) const {
    const Rule &r = its.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

int Reachability::is_loop() {
    if (trace.empty()) {
        return -1;
    }
    const LocationIdx dst = its.getRule(trace.back().transition).getRhsLoc(0);
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step step = trace[pos];
        if (leaves_scc(step.transition)) {
            return -1;
        }
        if (its.getRule(step.transition).getLhsLoc() == dst) {
            bool looping = static_cast<unsigned>(pos) < trace.size() - 1 || step.transition <= lastOrigRule;
            if (looping) {
                return pos;
            }
        }
    }
    return -1;
}

void Reachability::handle_update(const TransIdx idx) {
    const Rule &r = its.getRule(idx);
    RelSet eqs;
    const Subs &old_sigma = sigmas.back();
    Subs new_sigma;
    const Subs up = r.getUpdate(0);
    for (const auto &v: prog_vars) {
        if (std::holds_alternative<NumVar>(v)) {
            const auto &var = std::get<NumVar>(v);
            const auto x = its.getFreshUntrackedSymbol<IntTheory>(var.getName(), Expr::Int);
            z3.add(boolExpression::build(Rel::buildEq(x, up.get<IntTheory>(var).subs(old_sigma.get<IntTheory>()))));
            new_sigma.put<IntTheory>(var, x);
        } else if (std::holds_alternative<BoolVar>(v)) {
            const auto &var = std::get<BoolVar>(v);
            const auto x = its.getFreshUntrackedSymbol<BoolTheory>(var.getName(), Expr::Bool);
            const auto lhs = boolExpression::build(x);
            const auto rhs = up.get<BoolTheory>(var)->subs(old_sigma);
            z3.add((lhs & rhs) | ((!lhs) & (!rhs)));
            new_sigma.put<BoolTheory>(var, lhs);
        }
    }
    for (const auto &var: r.vars()) {
        if (its.isTempVar(var)) {
            if (std::holds_alternative<NumVar>(var)) {
                new_sigma.put<IntTheory>(std::get<NumVar>(var), its.getFreshUntrackedSymbol<IntTheory>(variable::getName(var), Expr::Int));
            } else if (std::holds_alternative<BoolVar>(var)) {
                new_sigma.put<BoolTheory>(std::get<BoolVar>(var), boolExpression::build(its.getFreshUntrackedSymbol<BoolTheory>(variable::getName(var), Expr::Bool)));
            } else {
                throw std::logic_error("unsupported theory");
            }
        }
    }
    sigmas.push_back(new_sigma);
}

void Reachability::do_block(const Step &step) {
    if (log) std::cout << "blocking " << step.transition << ", " << step.sat << std::endl;
    // optimization for conjunctive clauses: blocked iff find(step.transition) != end()
    if (its.getRule(step.transition).getGuard()->isConjunction()) {
        blocked.back()[step.transition] = {};
    }
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
    models.push_back(z3.model().toSubs());
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
    const auto &model = models.back();
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
            post_vars.emplace(x, its.addFreshTemporaryVariable(x));
        }
    }
    for (const TransIdx idx: its.getAllTransitions()) {
        lastOrigRule = std::max(lastOrigRule, idx);
        const auto rule = its.getRule(idx);
        const auto src = rule.getLhsLoc();
        const auto dst = rule.getRhsLoc(0);
        if (src == its.getInitialLocation() && dst == its.getSink()) {
            conditional_empty_clauses.push_back(idx);
        } else {
            std::map<LocationIdx, std::vector<TransIdx>> *to_insert;
            if (dst == its.getSink()) {
                to_insert = &queries;
            } else if (leaves_scc(idx)) {
                to_insert = &cross_scc;
            } else {
                to_insert = &in_scc;
            }
            const auto it = to_insert->find(src);
            if (it == to_insert->end()) {
                to_insert->emplace(src, std::vector<TransIdx>{idx});
            } else {
                it->second.push_back(idx);
            }
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
    const auto block = blocked.back().find(idx);
    if (block != blocked.back().end()) {
        if (r.getGuard()->isConjunction()) {
            return {};
        }
        for (const auto &b: block->second) {
            z3.add(!b->subs(sigma));
        }
    }
    z3.add(r.getGuard()->subs(sigma));
    if (z3.check() == Sat) {
        if (log) std::cout << "found model for " << idx << std::endl;
        const auto implicant = r.getGuard()->implicant(sigma.compose(z3.model().toSubs()));
        if (implicant) {
            return BExpression::buildAndFromLits(*implicant);
        } else {
            throw std::logic_error("model, but no implicant");
        }
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

Reachability::Red::T Reachability::get_language(const Step &step) {
    if (step.transition <= lastOrigRule) {
        return redundance->get_singleton_language(step.transition, step.sat->conjunctionToGuard());
    } else {
        return redundance->get_language(step.transition);
    }
}

Reachability::Red::T Reachability::build_language(const int backlink) {
    std::vector<long> automaton = get_language(trace.back());
    for (int i = trace.size() - 2; i >= backlink; --i) {
        redundance->concat(automaton, get_language(trace[i]));
    }
    redundance->transitive_closure(automaton);
    return automaton;
}

Rule Reachability::build_loop(const int backlink) {
    Rule loop = its.getRule(trace.back().transition).withGuard(trace.back().sat);
    for (int i = trace.size() - 2; i >= backlink; --i) {
        const Step &step = trace[i];
        auto sigma = sigmas[i+1];
        sigma.erase(prog_vars); // rename temporary variables before chaining
        const TransIdx t = step.transition;
        const Rule &r = its.getRule(t);
        loop = *Chaining::chainRules(its, r.withGuard(step.sat).subs(sigma), loop, false);
    }
    assert(loop.getLhsLoc() == loop.getRhsLoc(0));
    if (log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(loop, its, std::cout);
        std::cout << std::endl;
    }
    return loop;
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

TransIdx Reachability::add_accelerated_rule(const Rule &accel, const Red::T &automaton) {
    const auto loop_idx = its.addRule(accel);
    redundance->set_language(loop_idx, automaton);
    const auto src = accel.getLhsLoc();
    auto acc_it = accelerated.find(src);
    if (acc_it == accelerated.end()) {
        accelerated.emplace(src, std::vector<TransIdx>{loop_idx});
    } else {
        acc_it->second.push_back(loop_idx);
    }
    update_transitions(src);
    return loop_idx;
}

std::unique_ptr<LoopState> Reachability::learn_clause(const Rule &rule, const Red::T &automaton, const int backlink) {
    Result<Rule> res {rule};
    res.concat(preprocess_loop(*res));
    AccelerationResult accel_res = LoopAcceleration::accelerate(its, res->toLinear(), -1, Complexity::Const);
    if (accel_res.rule) {
        // acceleration succeeded, simplify the result
        const auto simplified = Preprocess::simplifyRule(its, *accel_res.rule, true);
        if (simplified->getUpdate(0) == res->getUpdate(0)) {
            bool orig = false;
            for (size_t i = backlink; i < trace.size(); ++i) {
                if (trace[i].transition <= lastOrigRule) {
                    orig = true;
                    break;
                }
            }
            if (orig) {
                if (log) std::cout << "acceleration yielded equivalent rule, keeping preprocessed rule" << std::endl;
                res.succeed();
            } else {
                if (log) std::cout << "acceleration yielded equivalent rule -> dropping it" << std::endl;
                return std::make_unique<Failed>();
            }
        } else {
            // accelerated rule differs from the original one, update the result
            res = *accel_res.rule;
            res.storeSubProof(accel_res.proof);
            res.concat(simplified);
        }
        if (log) {
            std::cout << "accelerated rule:" << std::endl;
            ITSExport::printRule(*res, its, std::cout);
            std::cout << std::endl;
        }
    } else {
        if (log) std::cout << "acceleration failed" << std::endl;
        return std::make_unique<Failed>();
    }
    return std::make_unique<Accelerated>(res.map<TransIdx>([this, &automaton](const auto &x){
        return add_accelerated_rule(x, automaton);
    }));
}

std::unique_ptr<LoopState> Reachability::handle_loop(const int backlink) {
    const Step step = trace[backlink];
    const auto automaton = build_language(backlink);
    if (redundance->is_redundant(automaton)) {
        if (log) std::cout << "loop already covered" << std::endl;
        return std::make_unique<Covered>();
    } else if (log) {
        std::cout << "learning clause for the following language:" << std::endl;
        std::cout << automaton << std::endl;
    }
    redundance->mark_as_redundant(automaton);
    const auto loop = build_loop(backlink);
    // for large-degree polynomials, Z3 tends to get stalled, irrespectively of its timeout
    if (loop.getUpdate(0).isPoly() && !loop.getUpdate(0).isPoly(10)) {
        return std::make_unique<Failed>();
    }
    bool orig = static_cast<size_t>(backlink) == trace.size() - 1;
    auto state = learn_clause(loop, automaton, orig);
    if (!state->accelerated()) {
        return state;
    }
    auto accel_state = *state->accelerated();
    const auto idx = **accel_state;
    const auto subproof = accel_state->getProof();
    const auto accel = its.getRule(idx);
    drop_loop(backlink);
    proof.majorProofStep("accelerated loop", its);
    proof.storeSubProof(subproof);
    z3.push();
    z3.add(accel.getGuard()->subs(sigmas.back()));
    if (z3.check() == Sat) {
        store(idx, accel.getGuard());
        proof.append(std::stringstream() << "added " << idx << " to trace");
        return state;
    } else {
        if (log) std::cout << "applying accelerated rule failed" << std::endl;
        z3.pop();
        return std::make_unique<Dropped>();
    }
}

LocationIdx Reachability::get_current_location() const {
    return trace.empty() ? its.getInitialLocation() : its.getRule(trace.back().transition).getRhsLoc(0);
}

bool Reachability::try_queries(const std::vector<TransIdx> &queries) {
    for (const auto &q: queries) {
        z3.push();
        const option<BoolExpr> sat = do_step(q);
        if (sat) {
            extend_trace(q, *sat);
            unsat();
            return true;
        }
        z3.pop();
    }
    return false;
}

bool Reachability::try_queries() {
    return try_queries(queries[get_current_location()]);
}

bool Reachability::try_conditional_empty_clauses() {
    return try_queries(conditional_empty_clauses);
}

void Reachability::analyze() {
    proof.majorProofStep("initial ITS", its);
    if (log) {
        std::cout << "initial ITS" << std::endl;
        ITSExport::printForProof(its, std::cout);
    }
    preprocess();
    init();
    if (try_conditional_empty_clauses()) {
        return;
    }
    do {
        if (log) std::cout << "trace: " << trace << std::endl;
        for (int backlink = is_loop(); backlink >= 0; backlink = is_loop()) {
            const Step step = trace[backlink];
            bool simple_loop = static_cast<unsigned>(backlink) == trace.size() - 1;
            auto state = handle_loop(backlink);
            if (state->covered()) {
                backtrack();
            } else if (state->accelerated()) {
                if (simple_loop) {
                    do_block(step);
                }
                // make sure that we do not apply the accelerated transition again straight away, which is redundant
                do_block(trace.back());
                // try to apply a query before doing another step
                if (try_queries()) {
                    return;
                }
            } else if (state->dropped()) {
                do_block(step);
            } else if (state->failed()) {
                // acceleration failed, loop has been added to Automaton::covered so that it won't be unrolled again
                // try to continue instead of backtracking immediately
                break;
            }
        }
        auto &trans = transitions[get_current_location()];
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
                // block learned clauses after adding them to the trace
                if (*it > lastOrigRule) {
                    do_block(trace.back());
                }
                store(*it, *sat);
                break;
            }
        }
        trans.insert(trans.end(), append.begin(), append.end());
        if (!trace.empty()) {
            if (it == trans.end()) {
                backtrack();
            } else {
                // check whether a query is applicable after every step and,
                // importantly, before acceleration (which might approximate)
                if (try_queries()) {
                    return;
                }
            }
        }
    } while (!trace.empty());
    std::cout << "unknown" << std::endl << std::endl;
}

void Reachability::analyze(ITSProblem &its) {
    yices::init();
    Reachability(its).analyze();
    yices::exit();
}
