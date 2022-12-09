#include "satisfiability.hpp"
#include "chainstrategy.hpp"
#include "chain.hpp"
#include "preprocess.hpp"
#include "loopacceleration.hpp"
#include "result.hpp"
#include "yices.hpp"
#include "smt.hpp"
#include "export.hpp"
#include "expression.hpp"
#include "literal.hpp"
#include "vector.hpp"

#include <numeric>

namespace satisfiability {

using ::operator<<;

bool Satisfiability::log = false;

LearningState::LearningState() {}

option<Succeeded> LearningState::succeeded() {
    return {};
}

option<Covered> LearningState::covered() {
    return {};
}

option<Dropped> LearningState::dropped() {
    return {};
}

option<Failed> LearningState::failed() {
    return {};
}

Succeeded::Succeeded(const Result<TransIdx> &idx): idx(idx) {}

option<Succeeded> Succeeded::succeeded() {
    return *this;
}

Result<TransIdx>& Succeeded::operator*() {
    return idx;
}

Result<TransIdx>* Succeeded::operator->() {
    return &idx;
}

option<Covered> Covered::covered() {
    return *this;
}

option<Dropped> Dropped::dropped() {
    return *this;
}

option<Failed> Failed::failed() {
    return *this;
}

PushPop::PushPop(LinearizingSolver<IntTheory, BoolTheory> &solver): solver(solver) {
    solver.push();
}

PushPop::~PushPop() {
    solver.pop();
}

Satisfiability::Satisfiability(ITSProblem &chcs): chcs(chcs), solver(chcs), non_loops(chcs) {
    solver.enableModels();
}

Step::Step(const TransIdx transition, const BoolExpr &sat, const Subs &var_renaming, const ThModel &model):
    clause_idx(transition),
    implicant(sat),
    var_renaming(var_renaming),
    model(model.toSubs()){}

std::ostream& operator<<(std::ostream &s, const std::vector<Step> &step) {
    for (auto it = step.begin(); it != step.end(); ++it) {
        s << " [" << it->implicant << "] " << it->clause_idx;
    }
    return s;
}

NonLoops::NonLoops(const ITSProblem &chcs): chcs(chcs) {}

std::vector<long> NonLoops::build(const std::vector<Step> &trace, int backlink) {
   std::vector<long> sequence;
   for (int i = trace.size() - 1; i >= backlink; --i) {
       append(sequence, trace[i]);
   }
   return sequence;
}

void NonLoops::add(const std::vector<Step> &trace, int backlink) {
    non_loops.insert(build(trace, backlink));
}

bool NonLoops::contains(const std::vector<long> &sequence) {
    return non_loops.contains(sequence);
}

void NonLoops::append(std::vector<long> &sequence, const Step &step) {
    std::pair<TransIdx, BoolExpr> key;
    if (chcs.getRule(step.clause_idx).getGuard()->isConjunction()) {
        key = {step.clause_idx, BExpression::True};
    } else {
        key = {step.clause_idx, step.implicant};
    }
    const auto it = alphabet.find(key);
    if (it == alphabet.end()) {
        alphabet.emplace(key, next_char);
        sequence.push_back(next_char);
        ++next_char;
    } else {
        sequence.push_back(it->second);
    }
}

ResultViaSideEffects Satisfiability::remove_irrelevant_clauses() {
    std::set<LocationIdx> keep;
    std::stack<LocationIdx> todo;
    todo.push(chcs.getSink());
    do {
        const LocationIdx current = todo.top();
        todo.pop();
        keep.insert(current);
        for (const auto p: chcs.getPredecessorLocations(current)) {
            if (keep.find(p) == keep.end()) {
                todo.push(p);
            }
        }
    } while (!todo.empty());
    std::set<TransIdx> deleted;
    for (const auto idx: chcs.getAllTransitions()) {
        const LocationIdx target = chcs.getRule(idx).getRhsLoc(0);
        if (keep.find(target) == keep.end()) {
            const std::set<TransIdx> d = chcs.removeLocationAndRules(target);
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

ResultViaSideEffects Satisfiability::simplify() {
    ResultViaSideEffects ret;
    for (const TransIdx idx: chcs.getAllTransitions()) {
        const auto res = Preprocess::preprocessRule(chcs, chcs.getRule(idx));
        if (res) {
            ret.succeed();
            chcs.replaceRules({idx}, {res.get()});
            ret.concat(res.getProof());
        }
    }
    return ret;
}

ResultViaSideEffects Satisfiability::unroll() {
    ResultViaSideEffects ret;
    for (const TransIdx idx: chcs.getAllTransitions()) {
        const Rule &r = chcs.getRule(idx);
        if (r.isSimpleLoop()) {
            const auto [res, period] = LoopAcceleration::chain(r.toLinear(), chcs);
            if (period > 1) {
                const auto simplified = Preprocess::simplifyRule(chcs, res);
                ret.succeed();
                ret.ruleTransformationProof(r, "unrolling", res, chcs);
                if (simplified) {
                    chcs.replaceRules({idx}, {*simplified});
                    ret.concat(simplified.getProof());
                } else {
                    chcs.replaceRules({idx}, {res});
                }
            }
        }
    }
    return ret;
}

bool Satisfiability::leaves_scc(const TransIdx idx) const {
    const Rule &r = chcs.getRule(idx);
    return sccs.getSccIndex(r.getLhsLoc()) != sccs.getSccIndex(r.getRhsLoc(0));
}

int Satisfiability::has_looping_suffix() {
    if (trace.empty()) {
        return -1;
    }
    const auto last_clause = chcs.getRule(trace.back().clause_idx);
    const auto dst = last_clause.getRhsLoc(0);
    std::vector<long> sequence;
    for (int pos = trace.size() - 1; pos >= 0; --pos) {
        const Step &step = trace[pos];
        if (leaves_scc(step.clause_idx)) {
            return -1;
        }
        non_loops.append(sequence, step);
        if (non_loops.contains(sequence)) {
            if (log) std::cout << sequence << " is a non-loop" << std::endl;
            continue;
        }
        if (chcs.getRule(step.clause_idx).getLhsLoc() == dst) {
            bool looping = static_cast<unsigned>(pos) < trace.size() - 1 || is_orig_clause(step.clause_idx);
            if (looping) {
                return pos;
            }
        }
    }
    return -1;
}

Subs Satisfiability::handle_update(const TransIdx idx) {
    const Rule &r = chcs.getRule(idx);
    const Subs last_var_renaming = trace.empty() ? Subs() : trace.back().var_renaming;
    Subs new_var_renaming;
    const Subs up = r.getUpdate(0);
    for (const auto &x: prog_vars) {
        new_var_renaming.put(x, TheTheory::varToExpr(chcs.getFreshUntrackedSymbol(x)));
    }
    for (const auto &var: r.vars()) {
        if (chcs.isTempVar(var)) {
            new_var_renaming.put(var, TheTheory::varToExpr(chcs.getFreshUntrackedSymbol(var)));
        }
    }
    for (const auto &x: prog_vars) {
        solver.add(literal::mkEq(new_var_renaming.get(x), expression::subs(up.get(x), last_var_renaming)));
    }
    return new_var_renaming;
}

void Satisfiability::block(const Step &step) {
    if (log) std::cout << "blocking " << step.clause_idx << ", " << step.implicant << std::endl;
    if (chcs.getRule(step.clause_idx).getGuard()->isConjunction()) {
        blocked_clauses.back()[step.clause_idx] = {};
    }
    auto block = blocked_clauses.back().find(step.clause_idx);
    if (block == blocked_clauses.back().end()) {
        blocked_clauses.back()[step.clause_idx] = {step.implicant};
    } else {
        block->second.insert(step.implicant);
    }
}

void Satisfiability::pop() {
    blocked_clauses.pop_back();
    trace.pop_back();
    solver.pop();
    proof.pop();
}

void Satisfiability::backtrack() {
    if (log) std::cout << "backtracking" << std::endl;
    // copy the last step before popping it
    const Step step = trace.back();
    pop();
    block(step);
}

void Satisfiability::add_to_trace(const Step &step) {
    trace.emplace_back(step);
    proof.push();
    proof.headline("extended trace");
    proof.append(std::stringstream() << "added " << step.clause_idx << " to trace");
    Proof subProof;
    subProof.section("implicant");
    subProof.append(std::stringstream() << step.implicant);
    subProof.section("trace");
    subProof.append(std::stringstream() << trace);
    proof.storeSubProof(subProof);
}

bool Satisfiability::store_step(const TransIdx idx, const BoolExpr &implicant) {
    solver.push();
    if (trace.empty()) {
        solver.add(implicant);
    } else {
        // TODO This makes little sense for loops with more than one clause, since temporary variables from
        // previous steps do not get renamed
        solver.add(implicant->subs(trace.back().var_renaming));
    }
    if (solver.check() == Sat) {
        const auto model = solver.model();
        const auto new_var_renaming = handle_update(idx);
        const Step step(idx, implicant, new_var_renaming, model);
        add_to_trace(step);
        blocked_clauses.push_back({});
        // block learned clauses after adding them to the trace
        if (is_learned_clause(idx)) {
            block(step);
        }
        return true;
    } else {
        solver.pop();
        return false;
    }
}

void Satisfiability::print_trace(std::ostream &s) {
    for (const auto &step: trace) {
        s << " [";
        for (const auto &x: prog_vars) {
            s << " " << x << "=" << expression::subs(step.var_renaming.get(x), step.model);
        }
        s << " ] " << step.clause_idx;
    }
    s << std::endl;
}

void Satisfiability::preprocess() {
    ResultViaSideEffects res = remove_irrelevant_clauses();
    if (res) {
        proof.majorProofStep("removed irrelevant transitions", chcs);
        proof.storeSubProof(res.getProof());
    }
    res = Chaining::chainLinearPaths(chcs);
    if (res) {
        proof.majorProofStep("chained linear paths", chcs);
        proof.storeSubProof(res.getProof());
    }
    res = simplify();
    if (res) {
        proof.majorProofStep("simplified transitions", chcs);
        proof.storeSubProof(res.getProof());
    }
    /*
    res = unroll();
    if (res) {
        proof.majorProofStep("unrolled loops", chcs);
        proof.storeSubProof(res.getProof());
    }
    */
    if (log) {
        std::cout << "simplified ITS" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
    }
}

void Satisfiability::update_rules(const LocationIdx idx) {
    auto l_it = cross_scc.find(idx);
    // the order of the clauses in this list determines the selection order for resolution
    std::list<LocationIdx> trans;
    // try to get out of the current SCC as we want to reach 'bottom', which is its own SCC
    if (l_it != cross_scc.end()) {
        trans.insert(trans.end(), l_it->second.begin(), l_it->second.end());
    }
    // try learned clauses next
    const auto it = learned_clauses.find(idx);
    if (it != learned_clauses.end()) {
        trans.insert(trans.end(), it->second.begin(), it->second.end());
    }
    // try original clauses that stay within the current SCC last
    l_it = in_scc.find(idx);
    if (l_it != in_scc.end()) {
        trans.insert(trans.end(), l_it->second.begin(), l_it->second.end());
    }
    rules[idx] = trans;
}

void Satisfiability::init() {
    srand(42);
    for (const auto &x: chcs.getVars()) {
        if (!chcs.isTempVar(x)) {
            prog_vars.insert(x);
        }
    }
    for (const TransIdx idx: chcs.getAllTransitions()) {
        last_orig_clause = std::max(last_orig_clause, idx);
        const auto rule = chcs.getRule(idx);
        const auto src = rule.getLhsLoc();
        const auto dst = rule.getRhsLoc(0);
        if (src == chcs.getInitialLocation() && dst == chcs.getSink()) {
            conditional_empty_clauses.push_back(idx);
        } else {
            std::map<LocationIdx, std::vector<TransIdx>> *to_insert;
            if (dst == chcs.getSink()) {
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
    for (const auto loc: chcs.getLocations()) {
        update_rules(loc);
    }
}

void Satisfiability::luby_next() {
    const auto [u,v] = luby;
    luby = (u & (u-1)) == v ? std::pair<unsigned, unsigned>(u+1, 1) : std::pair<unsigned, unsigned>(u, 2 * v);
    luby_loop_count = 0;
}

void Satisfiability::unsat() {
     std::cout << "unknown" << std::endl << std::endl;
    /*
     std::cout << "unsat" << std::endl << std::endl;
    std::stringstream trace_stream, counterexample;
    trace_stream << trace;
    print_trace(counterexample);
    if (log) {
        std::cout << "final ITS:" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
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
    */
}

option<BoolExpr> Satisfiability::resolve(const TransIdx idx) {
    PushPop pp(solver);
    const auto var_renaming = trace.empty() ? Subs() : trace.back().var_renaming;
    const auto clause = chcs.getRule(idx);
    const auto block = blocked_clauses.back().find(idx);
    if (block != blocked_clauses.back().end()) {
        // a blocked conjunctive clause --> fail
        if (clause.getGuard()->isConjunction()) {
            return {};
        }
        // a non-conjunctive clause where some variants are blocked
        // --> make sure that we use a non-blocked variant, if any
        for (const auto &b: block->second) {
            solver.add(!b->subs(var_renaming));
        }
    }
    const auto guard = clause.getGuard()->subs(var_renaming);
    solver.add(guard);
    if (solver.check() == Sat) {
        if (log) std::cout << "found model for " << idx << std::endl;
        const auto implicant = clause.getGuard()->implicant(substitution::compose(var_renaming, solver.model(guard->vars()).toSubs()));
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

void Satisfiability::drop_until(const int new_size) {
    while (trace.size() > static_cast<unsigned>(new_size)) {
        pop();
    }
}

Satisfiability::Red::T Satisfiability::get_language(const Step &step) {
    if (is_orig_clause(step.clause_idx)) {
        return redundance->get_singleton_language(step.clause_idx, step.implicant->conjunctionToGuard());
    } else {
        return redundance->get_language(step.clause_idx);
    }
}

Satisfiability::Red::T Satisfiability::build_language(const int backlink) {
    auto lang = get_language(trace.back());
    for (int i = trace.size() - 2; i >= backlink; --i) {
        redundance->concat(lang, get_language(trace[i]));
    }
    redundance->transitive_closure(lang);
    return lang;
}

Rule Satisfiability::build_loop(const int backlink) {
    Rule loop = chcs.getRule(trace.back().clause_idx).withGuard(trace.back().implicant);
    for (int i = trace.size() - 2; i >= backlink; --i) {
        const Step &step = trace[i];
        auto sigma = step.var_renaming;
        sigma.erase(prog_vars); // rename temporary variables before chaining
        loop = *Chaining::chainRules(chcs, chcs.getRule(step.clause_idx).withGuard(step.implicant).subs(sigma), loop, false);

    }
    assert(loop.getLhsLoc() == loop.getRhsLoc(0));
    if (log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(loop, chcs, std::cout);
        std::cout << std::endl;
    }
    return loop;
}

TransIdx Satisfiability::add_learned_clause(const Rule &accel, const Red::T &lang) {
    const auto loop_idx = chcs.addRule(accel);
    redundance->set_language(loop_idx, lang);
    const auto src = accel.getLhsLoc();
    auto acc_it = learned_clauses.find(src);
    if (acc_it == learned_clauses.end()) {
        learned_clauses.emplace(src, std::vector<TransIdx>{loop_idx});
    } else {
        acc_it->second.push_back(loop_idx);
    }
    update_rules(src);
    return loop_idx;
}

bool Satisfiability::is_learned_clause(const TransIdx idx) const {
    return idx > last_orig_clause;
}

bool Satisfiability::is_orig_clause(const TransIdx idx) const {
    return idx <= last_orig_clause;
}

std::unique_ptr<LearningState> Satisfiability::learn_clause(const Rule &rule, const Red::T &lang) {
    Result<Rule> res = Preprocess::simplifyRule(chcs, rule);
    if (res->getUpdate(0) == substitution::concat(res->getUpdate(0), res->getUpdate(0))) {
        // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
        // Such clauses are pretty useless, so we do not store them. Return 'Failed', so that it becomes a non-loop.
        if (log) std::cout << "acceleration would yield equivalent rule -> dropping it" << std::endl;
        return std::make_unique<Failed>();
    }
    AccelConfig config;
    config.allowDisjunctions = false;
    config.approx = OverApprox;
    // ---
    acceleration::Result accel_res = LoopAcceleration::accelerate(chcs, res->toLinear(), Complexity::Const, config);
    if (accel_res.rule) {
        // acceleration succeeded, simplify the result
        const auto simplified = Preprocess::simplifyRule(chcs, *accel_res.rule);
        if (simplified->getUpdate(0) == res->getUpdate(0)) {
            if (log) std::cout << "acceleration yielded equivalent rule -> dropping it" << std::endl;
            return std::make_unique<Failed>();
        } else {
            // accelerated rule differs from the original one, update the result
            res = *accel_res.rule;
            res.storeSubProof(accel_res.proof);
            res.concat(simplified);
            if (log) {
                std::cout << "accelerated rule:" << std::endl;
                ITSExport::printRule(*res, chcs, std::cout);
                std::cout << std::endl;
            }
        }
    } else {
        if (log) std::cout << "acceleration failed" << std::endl;
        return std::make_unique<Failed>();
    }
    return std::make_unique<Succeeded>(res.map<TransIdx>([this, &lang](const auto &x){
        return add_learned_clause(x, lang);
    }));
}

std::unique_ptr<LearningState> Satisfiability::handle_loop(const int backlink) {
    const auto lang = build_language(backlink);
    if (redundance->is_redundant(lang)) {
        if (log) std::cout << "loop already covered" << std::endl;
        return std::make_unique<Covered>();
    } else if (log) {
        std::cout << "learning clause for the following language:" << std::endl;
        std::cout << lang << std::endl;
    }
    luby_loop_count++;
    redundance->mark_as_redundant(lang);
    const auto loop = build_loop(backlink);
    if (loop.getUpdate(0).empty()) {
        if (log) std::cout << "trivial looping suffix" << std::endl;
        return std::make_unique<Covered>();
    }
    auto state = learn_clause(loop, lang);
    if (!state->succeeded()) {
        return state;
    }
    auto accel_state = *state->succeeded();
    const auto idx = **accel_state;
    const auto subproof = accel_state->getProof();
    const auto accel = chcs.getRule(idx);
    // drop the looping suffix
    drop_until(backlink);
    proof.majorProofStep("accelerated loop", chcs);
    proof.storeSubProof(subproof);
    if (store_step(idx, accel.getGuard())) {
        return state;
    } else {
        if (log) std::cout << "applying accelerated rule failed" << std::endl;
        return std::make_unique<Dropped>();
    }
}

LocationIdx Satisfiability::get_current_predicate() const {
    return trace.empty() ? chcs.getInitialLocation() : chcs.getRule(trace.back().clause_idx).getRhsLoc(0);
}

bool Satisfiability::try_to_finish(const std::vector<TransIdx> &clauses) {
    solver.setTimeout(2000);
    for (const auto &q: clauses) {
        const option<BoolExpr> implicant = resolve(q);
        if (implicant) {
            // no need to compute the model and the variable renaming for the next step, as we are done
            add_to_trace(Step(q, *implicant, Subs(), ThModel()));
            unsat();
            return true;
        }
    }
    solver.setTimeout(Config::Smt::DefaultTimeout);
    return false;
}

bool Satisfiability::try_to_finish() {
    return try_to_finish(queries[get_current_predicate()]);
}

bool Satisfiability::try_conditional_empty_clauses() {
    return try_to_finish(conditional_empty_clauses);
}

bool Satisfiability::learn_trivial_clause(const LocationIdx idx) {
    // constructs a new, trivial clause
    Subs update;
    for(const auto &x: prog_vars){
        update.put(x, TheTheory::varToExpr(chcs.getFreshUntrackedSymbol(x)));
    }
    const LinearRule trivialClause = LinearRule(idx, BExpression::True, 1, idx, update);


    //TODO: add new, trivial clause to all relevant data structures
    //const auto lang = redundance->get_singleton_language();
    //add_learned_clause(&trivialClause, &lang);

    //TODO: store step in the trace
    /*if(store_step()){

    }else{
        std::cout << "Error: adding trivial clause to the trace failed" << std::endl;
        return false;
    }*/
    return true;
}

void Satisfiability::analyze() {
    proof.majorProofStep("initial ITS", chcs);
    if (log) {
        std::cout << "initial ITS" << std::endl;
        ITSExport::printForProof(chcs, std::cout);
    }
    preprocess();
    init();
    if (try_conditional_empty_clauses()) {
        return;
    }
    do {
        if (luby_loop_count == luby_unit * luby.second) {
            if (log) std::cout << "restarting after " << luby_loop_count << " loops" << std::endl;
            // restart
            while (!trace.empty()) {
                pop();
            }
            luby_next();
            solver.setSeed(rand());
        }
        if (log) std::cout << "trace: " << trace << std::endl;
        for (int backlink = has_looping_suffix(); backlink >= 0; backlink = has_looping_suffix()) {
            Step step = trace[backlink];
            bool simple_loop = static_cast<unsigned>(backlink) == trace.size() - 1;
            auto state = handle_loop(backlink);
            if (state->covered()) {
                backtrack();
            } else if (state->succeeded()) {
                if (simple_loop) {
                    block(step);
                }
                // try to apply a query before doing another step
                if (try_to_finish()) {
                    return;
                }
            } else if (state->dropped()) {
                block(step);
            } else if (state->failed()) {
                // non-loop --> do not backtrack
                // This case should only happen if the learned clause is trivially redundant w.r.t. the looping suffix
                non_loops.add(trace, backlink);
                break;
            }
        }
        const auto current = get_current_predicate();
        auto &to_try = rules[current];
        auto it = to_try.begin();
        std::vector<TransIdx> append;
        while (it != to_try.end()) {
            const option<BoolExpr> implicant = resolve(*it);
            if (implicant && store_step(*it, *implicant)) {
                break;
            }
            append.push_back(*it);
            it = to_try.erase(it);
        }
        if (trace.empty()) {
            break;
        }
        if (it == to_try.end()) {
            backtrack();
        } else {
            // check whether a query is applicable after every step and,
            // importantly, before acceleration (which might approximate)
            if (try_to_finish()) {
                return;
            }
        }
        to_try.insert(to_try.end(), append.begin(), append.end());
    } while (true);
    std::cout << "sat" << std::endl << std::endl;
}

void Satisfiability::analyze(ITSProblem &its) {
    yices::init();
    Satisfiability(its).analyze();
    yices::exit();
}

}
