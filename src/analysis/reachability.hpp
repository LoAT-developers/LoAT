#pragma once

#include "itsproblem.hpp"
#include "linearizingsolver.hpp"
#include "itsproblem.hpp"
#include "result.hpp"
#include "redundanceviaautomata.hpp"
#include "complexity.hpp"

#include <limits>
#include <list>
#include <optional>

/**
 * Possible improvements:
 * - remove original clauses that are subsumed by learned clauses
 * - allow disjunctive clauses on the trace and project wrt. the current model before acceleration, not after every step
 */
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

    const Rule resolvent;

    Step(const TransIdx transition, const BoolExpr &sat, const Subs &var_renaming, const Rule &resolvent);

};

std::ostream& operator<<(std::ostream &s, const Step &step);

// forward declarations of acceleration states
class Succeeded;
class Covered;
class Unroll;
class Restart;
class Dropped;
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
    virtual std::optional<Succeeded> succeeded();
    /**
     * true if no clause was learned since it would have been redundant
     */
    virtual std::optional<Covered> covered();

    virtual std::optional<Dropped> dropped();

    virtual std::optional<Unroll> unroll();

    virtual std::optional<ProvedUnsat> unsat();

    virtual std::optional<Restart> restart();
};

struct LearnedClauses {
    std::vector<TransIdx> res;
    const unsigned prefix;
    const unsigned period;
};

class Succeeded final: public LearningState {
    /**
     * the indices of the learned clause
     */
    Result<LearnedClauses> learned;

public:
    Succeeded(const Result<LearnedClauses> &learned);
    std::optional<Succeeded> succeeded() override;
    const Result<LearnedClauses>& operator*() const;
    const Result<LearnedClauses>* operator->() const;
};

class Covered final: public LearningState {
    std::optional<Covered> covered() override;
};

class Dropped final: public LearningState {

    ITSProof proof;

public:
    Dropped(const ITSProof &proof);
    std::optional<Dropped> dropped() override;
    const ITSProof& get_proof() const;
};

class Unroll final: public LearningState {

private:

    std::optional<unsigned> max;

public:

    Unroll();

    Unroll(unsigned max);

    std::optional<unsigned> get_max();

    std::optional<Unroll> unroll() override;
};

class ProvedUnsat final: public LearningState {
    ITSProof proof;

public:
    ProvedUnsat(const ITSProof &proof);
    std::optional<ProvedUnsat> unsat() override;
    ITSProof& operator*();
    ITSProof* operator->();
};

class Restart final: public LearningState {
    std::optional<Restart> restart() override;
};

class ProofFailed : public std::runtime_error {
public:
    ProofFailed(const std::string &msg);
};

class Reachability : public ILinearSolver {

    ITSProblem &chcs;

    ITSProof proof;

    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;

    const bool drop;

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
    unsigned last_orig_clause {0};

    std::pair<int, int> luby {1,1};

    unsigned luby_unit {10};

    unsigned luby_loop_count {0};

    void luby_next();

    using Red = RedundanceViaAutomata;
    std::unique_ptr<Red> redundancy {std::make_unique<Red>()};

    Complexity cpx = Complexity::Const;

    bool is_learned_clause(const TransIdx idx) const;

    bool is_orig_clause(const TransIdx idx) const;

    void update_cpx();

    Result<Rule> instantiate(const NumVar &n, const Rule &rule) const;

    /**
     * initializes all data structures after preprocessing
     */
    void init();

    /**
     * finishes the analysis when we were able to prove unsat
     */
    void unsat();

    void sat();

    /**
     * tries to resolve the trace with the given clause
     */
    std::optional<Rule> resolve(const TransIdx idx);

    /**
     * computes (an approximation of) the language associated with the clause used for the given step
     */
    Automaton get_language(const Step &step);

    /**
     * computes (an approximation of) the language associated with the clause that can be learned
     * from the looping suffix of the trace
     * @param backlink the start of the looping suffix of the trace
     */
    Automaton build_language(const int backlink);

    /**
     * computes a clause that is equivalent to the looping suffix of the trace
     * @param backlink the start of the looping suffix of the trace
     */
    Rule build_loop(const int backlink);

    /**
     * adds a learned clause to all relevant data structures
     * @param lang (an approximation of) the language associated with the learned clause
     */
    TransIdx add_learned_clause(const Rule &clause, const unsigned backlink);

    /**
     * tries to accelerate the given clause
     * @param lang the language associated with the learned clause.
     */
    std::unique_ptr<LearningState> learn_clause(const Rule &rule, const unsigned backlink);

    bool check_consistency();

    void drop_until(const int new_size);

    /**
     * does everything that needs to be done if the trace has a looping suffix
     */
    std::unique_ptr<LearningState> handle_loop(const unsigned backlink);

    /**
     * @return the start position of the looping suffix of the trace, if any, or -1
     */
    std::optional<unsigned> has_looping_suffix(int start);

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

    Rule compute_resolvent(const TransIdx idx, const BoolExpr &implicant) const;

    /**
     * Assumes that the trace can be resolved with the given clause.
     * Does everything that needs to be done to apply the rule "Step".
     */
    bool store_step(const TransIdx idx, const Rule &resolvent, bool force);

    void print_trace(std::ostream &s);

    void print_state();

    bool try_to_finish();

    void analyze();

    void analyze_incremental();

    bool main_loop_body();

    void restart();

    LinearSolver::Result analysis_result;

    LinearSolver::Result analysis_result_from(std::string res) const;

    const bool incremental_mode;

    std::set<std::vector<std::pair<TransIdx, BoolExpr>>> seen_traces;

    const std::optional<Clause> trace_as_fact();

public:

    Reachability(ITSProblem &chcs, bool incremental_mode);

    LinearSolver::Result get_analysis_result() const override;

    void add_clauses(const std::list<Clause> &chc) override;

    const std::list<Clause> derive_new_facts() override;

    const std::list<Clause> get_initial_facts() const override;

    const std::list<Clause> get_non_linear_chcs() const override;

    static void analyze(ITSProblem &its);

};

}
