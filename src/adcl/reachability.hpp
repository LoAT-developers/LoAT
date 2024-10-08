#pragma once

#include "itsproblem.hpp"
#include "redundanceviaautomata.hpp"
#include "complexity.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "itssafetycex.hpp"
#include "itscpxcex.hpp"

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

    const RulePtr clause_idx;

    /**
     * a conjunction that implies the condition of the clause
     */
    const Bools::Expr implicant;

    /**
     * renames the program variables to fresh variables that serve as input for the next step
     */
    const Renaming var_renaming;
    const Renaming tmp_var_renaming;

    const RulePtr resolvent;

    Step(const RulePtr transition, const Bools::Expr sat, const Renaming &var_renaming, const Renaming &tmp_var_renaming, const RulePtr resolvent);

    Step(const Step &that);

    Step& operator=(const Step &that);

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

    virtual ~LearningState();

};

struct LearnedClauses {
    std::vector<RulePtr> res;
    const unsigned prefix;
    const unsigned period;
};

class Succeeded final: public LearningState {
    /**
     * the indices of the learned clause
     */
    LearnedClauses learned;

public:
    Succeeded(const LearnedClauses &learned);
    std::optional<Succeeded> succeeded() override;
    const LearnedClauses& operator*() const;
    const LearnedClauses* operator->() const;
};

class Covered final: public LearningState {
    std::optional<Covered> covered() override;
};

class Dropped final: public LearningState {

public:
    Dropped();
    std::optional<Dropped> dropped() override;
};

class Unroll final: public LearningState {

private:

    std::optional<unsigned> max {};
    bool accel_failed {false};

public:

    Unroll();

    Unroll(unsigned max, bool accel_failed = false);

    std::optional<unsigned> get_max();

    bool acceleration_failed();

    std::optional<Unroll> unroll() override;
};

class ProvedUnsat final: public LearningState {

public:
    ProvedUnsat();
    std::optional<ProvedUnsat> unsat() override;
};

class Restart final: public LearningState {
    std::optional<Restart> restart() override;
};

class Reachability {

    ITSPtr chcs;

    SmtPtr solver {SmtFactory::solver()};

    const bool drop;

    std::vector<Step> trace {};

    /**
     * A conjunctive clause x is blocked if find(x) != end().
     * A conjunctive variant y of a non-conjunctive clause x is blocked if cond(y) implies an element of at(x).
     * Maybe it would be better to subdivide the blocking formulas w.r.t. pairs of predicates instead of clauses.
     */
    std::vector<std::unordered_map<RulePtr, BoolExprSet>> blocked_clauses {{}};

    /**
     * Languages that correspond to non-linear learned clauses that are not used for resolution after a restart.
     * They get activated again once the corresponding loop has been unrolled.
     */
    std::unordered_set<Automaton> locked {};

    VarSet prog_vars {};

    /**
     * clauses up to this one are original ones, all other clauses are learned
     */
    unsigned last_orig_clause {0};

    ITSSafetyCex cex;
    ITSCpxCex cpx_cex;

    std::pair<int, int> luby {1,1};

    unsigned luby_unit {10};

    unsigned luby_count {0};

    void luby_next();

    std::unordered_map<RulePtr, unsigned> penalty {};

    using Red = RedundanceViaAutomata;
    std::unique_ptr<Red> redundancy {std::make_unique<Red>()};

    Complexity cpx = Complexity::Const;

    const std::function<void(const ITSCpxCex&)> &print_cpx_cex;

    bool is_learned_clause(const RulePtr idx) const;

    bool is_orig_clause(const RulePtr idx) const;

    void set_cpx_witness(const RulePtr witness, const ArithSubs &subs, const Arith::Var &param);

    void update_cpx();

    std::optional<RulePtr> instantiate(const Arith::Var n, const RulePtr rule) const;

    /**
     * initializes all data structures after preprocessing
     */
    void init();

    /**
     * finishes the analysis when we were able to prove unsat
     */
    void unsat();

    unsigned get_penalty(const RulePtr idx) const;

    void bump_penalty(const RulePtr idx);

    /**
     * tries to resolve the trace with the given clause
     */
    std::optional<RulePtr> resolve(const RulePtr idx);

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
    std::pair<RulePtr, Model> build_loop(const int backlink);

    /**
     * adds a learned clause to all relevant data structures
     * @param lang (an approximation of) the language associated with the learned clause
     */
    void add_learned_clause(const RulePtr accel, const unsigned backlink);

    /**
     * tries to accelerate the given clause
     * @param lang the language associated with the learned clause.
     */
    std::unique_ptr<LearningState> learn_clause(const RulePtr rule, const Model &model, const unsigned backlink);

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
    std::pair<Renaming, Renaming> handle_update(const RulePtr idx);

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

    RulePtr compute_resolvent(const RulePtr idx, const Bools::Expr implicant) const;

    /**
     * Assumes that the trace can be resolved with the given clause.
     * Does everything that needs to be done to apply the rule "Step".
     */
    bool store_step(const RulePtr idx, const RulePtr resolvent);

    void print_trace(std::ostream &s);

    void print_state();

    bool try_to_finish();

    ITSCex* the_cex();

public:

    Reachability(ITSPtr its, const std::function<void(const ITSCpxCex&)> &print_cpx_cex);

    SmtResult analyze();

    ITSSafetyCex get_cex();

};

}
