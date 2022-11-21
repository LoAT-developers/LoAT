#pragma once

#include "itsproblem.hpp"
#include "linearizingsolver.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "result.hpp"
#include "redundanceviasquarefreewords.hpp"
#include "reachability.hpp"

#include <list>


class Satisfiability {

    ITSProblem &chcs;

    Proof proof;

    const HyperGraph::SCCs sccs {chcs.sccs()};

    /**
     * facts and rules where the head and body symbol belong to different SCCs
     */
    std::map<LocationIdx, std::vector<TransIdx>> cross_scc;

    /**
     * rules where the head and the body symbol belong to the same SCC
     */
    std::map<LocationIdx, std::vector<TransIdx>> in_scc;

    std::map<LocationIdx, std::vector<TransIdx>> learned_clauses;

    /**
     * All facts and rules (including learned clauses).
     * The order of these lists determines the selection order of clauses for resolution.
     * It is updated on the fly when we learn clauses.
     */
    std::map<LocationIdx, std::list<TransIdx>> facts_and_rules;

    std::map<LocationIdx, std::vector<TransIdx>> queries;

    std::vector<TransIdx> conditional_empty_clauses;

    /**
     * predicate representing 'false'
     */
    LocationIdx bottom = *chcs.getSink();

    LinearizingSolver<IntTheory, BoolTheory> solver;

    std::vector<Step> trace;

    /**
     * A conjunctive clause x is blocked if find(x) != end().
     * A conjunctive variant y of a non-conjunctive clause x is blocked if cond(y) implies an element of at(x).
     * Maybe it would be better to subdivide the blocking formulas w.r.t. pairs of predicates instead of clauses.
     */
    std::vector<std::map<TransIdx, std::set<BoolExpr>>> blocked_clauses{{}};

    VarSet prog_vars;

    /**
     * clauses up to this one are original ones, all other clauses are learned
     */
    TransIdx last_orig_clause = 0;

    /**
     * Implementation of our redundancy check.
     * TODO RedundanceViaSquareFreeWords is not sound for sat. RedundanceViaAutomata should be sound.
     */
    using Red = RedundanceViaSquareFreeWords;
    std::unique_ptr<Red> redundance {std::make_unique<Red>()};

    NonLoops non_loops;

    bool is_learned_clause(const TransIdx idx) const;

    bool is_orig_clause(const TransIdx idx) const;

    /**
     * removes clauses that are not on a CFG-path from a fact to a query
     */
    ResultViaSideEffects remove_irrelevant_clauses();

    /**
     * applies some very basic simplifications
     * TODO Should be sound for sat, but we should check it to be sure.
     */
    ResultViaSideEffects simplify();

    /**
     * resolves recursive clauses with themselves in cases where
     * the resulting clause might be easier to accelerate
     * TODO Not sound for sat.
     */
    ResultViaSideEffects unroll();

    /**
     * preprocesses the CHC problem
     */
    void preprocess();

    /**
     * updates the list of clauses, and hence the selection order for resolution, for the given predicate
     */
    void update_rules(const LocationIdx idx);

    /**
     * initializes all data structures after preprocessing
     */
    void init();

    /**
     * finishes the analysis when we were able to prove unsat
     */
    void unsat();

    /**
     * tries to resolve the trace with the given clause
     */
    option<BoolExpr> resolve(const TransIdx idx);

    /**
     * drops a suffix of the trace, up to the given new size
     */
    void drop_until(const int new_size);

    /**
     * computes (an approximation of) the language associated with the clause used for the given step
     */
    Red::T get_language(const Step &step);

    /**
     * computes (an approximation of) the language associated with the clause that can be learned
     * from the looping suffix of the trace
     * @param backlink the start of the looping suffix of the trace
     */
    Red::T build_language(const int backlink);

    /**
     * computes a clause that is equivalent to the looping suffix of the trace
     * @param backlink the start of the looping suffix of the trace
     */
    Rule build_loop(const int backlink);

    /**
     * adds a learned clause to all relevant data structures
     * @param lang (an approximation of) the language associated with the learned clause
     */
    TransIdx add_learned_clause(const Rule &clause, const Red::T &lang);

    /**
     * tries to accelerate the given clause
     * @param lang the language associated with the learned clause.
     */
    std::unique_ptr<LearningState> learn_clause(const Rule &rule, const Red::T &lang);

    /**
     * does everything that needs to be done if the trace has a looping suffix
     */
    std::unique_ptr<LearningState> handle_loop(const int backlink);

    /**
     * checks whether the head and the body symbol of the given clause belong to different SCCs
     */
    bool leaves_scc(const TransIdx idx) const;

    /**
     * @return the start position of the looping suffix of the trace, if any, or -1
     */
    int has_looping_suffix();

    /**
     * Generates a fresh copy of the program variables and fixes their value according to the update of the
     * given clause by adding corresponding constraints to the SMT solver.
     * @return a variable renaming from the program variables to the fresh copy
     */
    Subs handle_update(const TransIdx idx);

    /**
     * blocks the given step
     */
    void block(const Step &step);

    void backtrack();

    /**
     * remove the last element of the trace, and from all other data structures that have to have the same
     * size as the trace
     */
    void pop();

    void add_to_trace(const Step &step);

    /**
     * Assumes that the trace can be resolved with the given clause.
     * Does everything that needs to be done to apply the rule "Step".
     */
    void store_step(const TransIdx idx, const BoolExpr &sat);

    void print_trace(std::ostream &s);

    /**
     * @return the head predicate of the trace
     */
    LocationIdx get_current_predicate() const;

    bool try_queries(const std::vector<TransIdx> &queries);
    bool try_queries();
    bool try_conditional_empty_clauses();

    Satisfiability(ITSProblem &its);

    void analyze();

public:

    static bool log;
    static void analyze(ITSProblem &its);

};
