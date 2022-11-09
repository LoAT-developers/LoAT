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
#include "literal.hpp"

#include <numeric>

bool Reachability::log = false;

long Automaton::next_char = 0;

Automaton Automaton::covered;

Automaton Automaton::singleton() {
    Automaton res;
    res.t.StateNamesEnabled(false);
    faudes::EventSet events;
    res.representative = {{next_char}};
    res.str = std::to_string(next_char);
    events.Insert(covered.t.InsEvent(std::to_string(next_char)));
    faudes::AlphabetLanguage(events, res.t);
    next_char++;
    return res;
}

Automaton Automaton::concat(const Automaton &that) const {
    if (this->empty()) {
        return *this;
    }
    if (that.empty()) {
        return that;
    }
    Automaton res;
    res.t.StateNamesEnabled(false);
    faudes::LanguageConcatenate(t, that.t, res.t);
    res.str = str + "." + that.str;
    if (representative && that.representative) {
        res.representative = {{*representative}};
        res.representative->insert(res.representative->end(), that.representative->begin(), that.representative->end());
    }
    return res;
}

Automaton Automaton::unite(const Automaton &that) const {
    if (this->empty()) {
        return that;
    }
    if (that.empty()) {
        return *this;
    }
    Automaton res;
    res.t.StateNamesEnabled(false);
    faudes::LanguageUnion(t, that.t, res.t);
    faudes::StateMin(res.t, res.t);
    res.str = "(" + str + ") u (" + that.str + ")";
    return res;
}

Automaton Automaton::kleene_plus() const {
    if (this->empty()) {
        return *this;
    }
    Automaton res;
    res.t.StateNamesEnabled(false);
    faudes::KleeneClosure(t, res.t);
    faudes::LanguageConcatenate(t, res.t, res.t);
    faudes::StateMin(res.t, res.t);
    res.str = "(" + str + ")+";
    res.representative = representative;
    return res;
}

bool Automaton::subset(const Automaton &that) const {
    return faudes::LanguageInclusion(t, that.t);
}

bool Automaton::empty() const {
    return faudes::IsEmptyLanguage(t);
}

option<std::vector<long>> Automaton::get_representative() const {
    return representative;
}

std::ostream& operator<<(std::ostream &s, const Automaton &a) {
    return s << a.str;
}

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

Automaton Reachability::singleton_language(const TransIdx idx, const Guard &guard) {
    Automaton res = Automaton::singleton();
    alphabet.emplace(std::pair<TransIdx, Guard>{idx, guard}, res);
    return res;
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
            if (src == dst) {
                update_deterministic_recursive_clauses(rule, idx);
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
        automaton = get_language(step).concat(automaton);
    }
    assert(loop.getLhsLoc() == loop.getRhsLoc(0));
    if (log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(loop, its, std::cout);
        std::cout << std::endl;
    }
    return {loop, automaton.kleene_plus()};
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

void Reachability::update_deterministic_recursive_clauses(const Rule &rule, TransIdx idx) {
    const auto vars = rule.vars();
    if (std::all_of(vars.begin(), vars.end(), [this](const auto &x){return !its.isTempVar(x);})) {
        const auto loc = rule.getLhsLoc();
        auto it = deterministic_recursive_clauses.find(loc);
        if (it == deterministic_recursive_clauses.end()) {
            deterministic_recursive_clauses[loc] = {idx};
        } else {
            it->second.push_back(idx);
        }
    }
}

TransIdx Reachability::add_accelerated_rule(const Rule &accel, const Automaton &automaton) {
    const auto loop_idx = its.addRule(accel);
    regexes[loop_idx] = automaton;
    const auto src = accel.getLhsLoc();
    auto acc_it = accelerated.find(src);
    if (acc_it == accelerated.end()) {
        accelerated.emplace(src, std::vector<TransIdx>{loop_idx});
    } else {
        acc_it->second.push_back(loop_idx);
    }
    update_transitions(src);
    update_deterministic_recursive_clauses(accel, loop_idx);
    auto rep_it = representative_to_transition.find(src);
    if (rep_it == representative_to_transition.end()) {
        representative_to_transition.emplace(src, std::map<std::vector<long>, TransIdx>{{*automaton.get_representative(), loop_idx}});
    } else {
        rep_it->second.emplace(*automaton.get_representative(), loop_idx);
    }
    return loop_idx;
}

/*
 * Phi is redundant if there is some psi without temporary variables such that !cond(psi) /\ cond(phi) is unsat.
 * We go one step further by cojoining !cond(psi) for /all/ such clauses psi. Hence, this function may return
 * true for clauses that are not redundant w.r.t. the redundancy criterion from our paper. For unsat, that's not
 * a problem.
 * Catches some cases where the language-based redundancy check fails.
 * Only considers clauses psi without temporary variables since they would have to be universally
 * qunantified in the formula above.
 */
bool Reachability::redundant(const Rule &phi) {
    const auto old_clauses = deterministic_recursive_clauses.find(phi.getLhsLoc());
    if (old_clauses == deterministic_recursive_clauses.end()) {
        return false;
    }
    const auto new_up = phi.getUpdate(0);
    std::vector<BoolExpr> conj;
    for (const auto &pair: new_up) {
        conj.push_back(literal::mkEq(post_vars.at(substitution::first(pair)), substitution::second(pair)));
    }
    conj.push_back(phi.getGuard());
    bool found_one = false;
    for (const auto &idx: old_clauses->second) {
        const auto clause = its.getLinearRule(idx);
        const auto old_up = clause.getUpdate();
        if (old_up.domain() == new_up.domain()) {
            found_one = true;
            std::vector<BoolExpr> disj;
            for (const auto &pair: old_up) {
                disj.push_back(!literal::mkEq(post_vars.at(substitution::first(pair)), substitution::second(pair)));
            }
            disj.push_back(!clause.getGuard());
            conj.push_back(BExpression::buildOr(disj));
        }
    }
    return found_one && SmtFactory::check(BExpression::buildAnd(conj), its) == Unsat;
}

void Reachability::learn_suffixes(const TransIdx idx) {
    const auto rep = *regexes.at(idx).get_representative();
    if (rep.size() <= 2) {
        return;
    }
    auto it = representative_to_transition.find(its.getRule(idx).getLhsLoc());
    if (it == representative_to_transition.end()) {
        return;
    }
    bool changed;
    std::vector<TransIdx> transitions;
    auto rep_it = rep.begin();
    do {
        changed = false;
        for (const auto &p: it->second) {
            if (p.second == idx) {
                continue;
            }
            const auto other_rep = p.first;
            auto res = std::mismatch(other_rep.begin(), other_rep.end(), rep_it);
            if (res.first == other_rep.end()) {
                transitions.push_back(p.second);
                for (size_t i = 0; i < other_rep.size(); ++i) {
                    ++rep_it;
                }
                changed = true;
            }
        }
    } while (changed && rep_it != rep.end());
    if (rep_it == rep.end()) {
        for (size_t i = transitions.size() - 2; i > 0; --i) {
            auto automaton = regexes.at(transitions[i]);
            auto rule = its.getRule(transitions[i]);
            for (size_t j = i + 1; j < transitions.size(); ++j) {
                automaton = automaton.concat(regexes.at(transitions[j]));
                rule = *Chaining::chainRules(its, rule, its.getRule(transitions[j]), false);
            }
            learn_clause(rule, automaton);
        }
    }
}

std::unique_ptr<LoopState> Reachability::learn_clause(const Rule &rule, const Automaton &automaton) {
    if (automaton.subset(Automaton::covered)) {
        if (log) std::cout << "loop already covered" << std::endl;
        return std::make_unique<Covered>(Covered());
    } else if (log) {
        std::cout << "learning clause for the following language:" << std::endl;
        std::cout << automaton << std::endl;
    }
    Automaton::covered = Automaton::covered.unite(automaton);
    Result<Rule> res {rule};
    res.concat(preprocess_loop(*res));
    AccelerationResult accel_res = LoopAcceleration::accelerate(its, res->toLinear(), -1, Complexity::Const);
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
        if (accel->getUpdate(0) == res->getUpdate(0)) {
            if (log) std::cout << "acceleration yielded equivalent rule" << std::endl;
            Automaton::covered = Automaton::covered.unite(automaton);
            return std::make_unique<Failed>(Failed());
        } else {
            res = *accel;
            res.storeSubProof(accel_res.proof);
            if (simplified) {
                res.storeSubProof(simplified.getProof());
            }
        }
    } else {
        if (log) std::cout << "acceleration failed" << std::endl;
        Automaton::covered = Automaton::covered.unite(automaton);
        return std::make_unique<Failed>(Failed());
    }
    if (redundant(*res)) {
        if (log) std::cout << "learned clause is redundant" << std::endl;
        return std::make_unique<Covered>(Covered());
    }
    return std::make_unique<Accelerated>(Accelerated(res.map<TransIdx>([this, &automaton](const auto &x){
        return add_accelerated_rule(x, automaton);
    })));
}

std::unique_ptr<LoopState> Reachability::handle_loop(const int backlink) {
    const Step step = trace[backlink];
    const auto p = build_loop(backlink);
    Rule loop = p.first;
    const Automaton automaton = p.second;
    auto state = learn_clause(loop, automaton);
    if (!state->accelerated()) {
        return state;
    }
    auto accel_state = *state->accelerated();
    const auto idx = **accel_state;
    const auto subproof = accel_state->getProof();
    const auto accel = its.getRule(idx);
    bool do_learn_suffixes = true;
    for (size_t i = backlink; i < trace.size(); ++i) {
        if (trace[i].transition <= lastOrigRule) {
            do_learn_suffixes = false;
            break;
        }
    }
    drop_loop(backlink);
    proof.majorProofStep("accelerated loop", its);
    proof.storeSubProof(subproof);
    z3.push();
    z3.add(accel.getGuard()->subs(sigmas.back()));
    if (z3.check() == Sat) {
        store(idx, accel.getGuard());
        proof.append(std::stringstream() << "added " << idx << " to trace");
        if (do_learn_suffixes) {
//            learn_suffixes(*res);
        }
        return state;
    } else {
        if (log) std::cout << "applying accelerated rule failed" << std::endl;
        z3.pop();
        return std::make_unique<Dropped>(Dropped());
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
