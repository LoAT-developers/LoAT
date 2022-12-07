#pragma once

#include "itsproblem.hpp"
#include "linearizingsolver.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "result.hpp"
#include "redundanceviaautomata.hpp"

#include <limits>
#include <list>

namespace reachability {

/**
 * Represents a resolution step, i.e., an element of the trace.
 */
struct Step {

    const TransIdx clause_idx;

    /**
     * a conjunction that implies the condition of the clause
     */
    const BoolExpr implicant;

    /**
     * renames the program variables to fresh variables that serve as input for the next step
     */
    const Subs var_renaming;

    Step(const TransIdx transition, const BoolExpr &sat, const Subs &var_renaming);

};

/**
 * Stores which looping sequences of CHCs should be treated as if they were non-looping.
 * Used for sequences whose resolvent is something like f(x) -> f(0). For such clauses,
 * the learned clause would be equivalent to the original clause, and we want to avoid
 * learning many of those useless clauses.
 *
 * TODO Should be sound for SAT, but we have to check that carefully.
 *
 * Additionally, we treat looping sequences where acceleration fails as if they were
 * non-looping.
 *
 * Note that we still mark the corresponding language as redundant. So if [1,2,3] is
 * a non-loop, then we keep using "Step" such that we may eventually obtain [1,2,3,1,2,3].
 * Then the latter is redundant and we backtrack, i.e., non-loops should not be a problem
 * w.r.t. termination.
 */
class NonLoops {

    std::map<std::pair<TransIdx, BoolExpr>, long> alphabet;
    long next_char = 0;
    std::set<std::vector<long>> non_loops;
    const ITSProblem &chcs;

public:

    NonLoops(const ITSProblem &chcs);

    std::vector<long> build(const std::vector<Step> &trace, int backlink);

    void add(const std::vector<Step> &trace, int backlink);

    bool contains(const std::vector<long> &sequence);

    void append(std::vector<long> &sequence, const Step &step);

};

std::ostream& operator<<(std::ostream &s, const Step &step);

// forward declarations of acceleration states
class Succeeded;
class Covered;
class Dropped;
class Failed;
class ProvedUnsat;

/**
 * When learning clauses, an instance of this class is returned.
 * It indicates whether a clause has been learned or not,
 * as well as the reason for not learning a clause.
 */
class LearningState {

protected:
    LearningState();

public:
    /**
     * true if a clause was learned
     */
    virtual option<Succeeded> succeeded();
    /**
     * true if no clause was learned since it would have been redundant
     */
    virtual option<Covered> covered();
    /**
     * True if the learned clause could not be added to the trace without introducing
     * inconsistencies. This may happen when our acceleration technique returns an
     * under-approximation.
     * TODO For sat, the current handling of this case is not sound.
     */
    virtual option<Dropped> dropped();
    /**
     * true if no clause was learned for some other reason
     * TODO We have to think about ways to deal with this case when trying to prove sat.
     */
    virtual option<Failed> failed();

    virtual option<ProvedUnsat> unsat();
};

class Succeeded: public LearningState {
    /**
     * the indices of the learned clause
     */
    Result<std::vector<TransIdx>> idx;

public:
    Succeeded(const Result<std::vector<TransIdx>> &idx);
    option<Succeeded> succeeded() override;
    Result<std::vector<TransIdx>>& operator*();
    Result<std::vector<TransIdx>>* operator->();
};

class Covered: public LearningState {
    option<Covered> covered() override;
};

class Dropped: public LearningState {
    option<Dropped> dropped() override;
};

class Failed: public LearningState {
    option<Failed> failed() override;
};

class ProvedUnsat: public LearningState {
    option<ProvedUnsat> unsat() override;
};

/**
 * auxiliary class for incremental SMT via RAII
 */
struct PushPop {
    LinearizingSolver<IntTheory, BoolTheory> &solver;
    PushPop(LinearizingSolver<IntTheory, BoolTheory> &solver);
    ~PushPop();
};

struct RecursiveSuffix {
    unsigned backlink;
    unsigned depth;
};

class Reachability {

    ITSProblem &chcs;

    Proof proof;

    const HyperGraph::SCCs sccs {chcs.sccs()};

    /**
     * rules where the head and body symbol belong to different SCCs
     */
    std::map<LocationIdx, std::vector<TransIdx>> cross_scc;

    /**
     * rules where the head and the body symbol belong to the same SCC
     */
    std::map<LocationIdx, std::vector<TransIdx>> in_scc;

    std::map<LocationIdx, std::vector<TransIdx>> learned_clauses;

    /**
     * All rules (including learned clauses).
     * The order of these lists determines the selection order of clauses for resolution.
     * It is updated on the fly when we learn clauses.
     */
    std::map<LocationIdx, std::list<TransIdx>> rules;

    std::map<TransIdx, unsigned> depth;

    std::map<LocationIdx, std::vector<TransIdx>> queries;

    std::vector<TransIdx> conditional_empty_clauses;

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

    unsigned current_depth = Config::ADCL::IterativeDeepening ? 0 : std::numeric_limits<unsigned>::max();

    bool depth_suffices = true;

    std::pair<int, int> luby{1,1};

    unsigned luby_unit = 10;

    unsigned luby_loop_count = 0;

    void luby_next();

    /**
     * Implementation of our redundancy check.
     * TODO RedundanceViaSquareFreeWords is not sound for sat. RedundanceViaAutomata should be sound.
     */
    using Red = RedundanceViaAutomata;
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
    TransIdx add_learned_clause(const Rule &clause, const Red::T &lang, unsigned depth);

    /**
     * tries to accelerate the given clause
     * @param lang the language associated with the learned clause.
     */
    std::unique_ptr<LearningState> learn_clause(const Rule &rule, const Red::T &lang, unsigned depth);

    /**
     * does everything that needs to be done if the trace has a looping suffix
     */
    std::unique_ptr<LearningState> handle_loop(const RecursiveSuffix&);

    /**
     * checks whether the head and the body symbol of the given clause belong to different SCCs
     */
    bool leaves_scc(const TransIdx idx) const;

    /**
     * @return the start position of the looping suffix of the trace, if any, or -1
     */
    option<RecursiveSuffix> has_looping_suffix();

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
    bool store_step(const TransIdx idx, const BoolExpr &sat);

    void print_trace(std::ostream &s);

    /**
     * @return the head predicate of the trace
     */
    LocationIdx get_current_predicate() const;

    bool try_to_finish(const std::vector<TransIdx> &clauses);
    bool try_to_finish();
    bool try_conditional_empty_clauses();

    Reachability(ITSProblem &its);

    void analyze();

public:

    static bool log;
    static void analyze(ITSProblem &its);

};

}
