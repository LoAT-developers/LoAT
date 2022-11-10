#pragma once

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "result.hpp"
#include "redundance.hpp"
#include "redundanceviasquarefreewords.hpp"

#include <list>

struct Step {
    const TransIdx transition;
    const BoolExpr sat;

    Step(const TransIdx transition, const BoolExpr &sat);

    friend std::ostream& operator<<(std::ostream &s, const Step &step);

};

class Accelerated;
class Covered;
class Dropped;
class Failed;

class LoopState{

protected:
    LoopState();

public:
    virtual void foo() = 0;
    virtual option<Accelerated> accelerated();
    virtual option<Covered> covered();
    virtual option<Dropped> dropped();
    virtual option<Failed> failed();
};

class Accelerated: public LoopState {
    Result<TransIdx> idx;

public:
    Accelerated(const Result<TransIdx> &idx);
    void foo() override;
    option<Accelerated> accelerated() override;
    Result<TransIdx>& operator*();
    Result<TransIdx>* operator->();
};

class Covered: public LoopState {
    void foo() override;
    option<Covered> covered() override;
};

class Dropped: public LoopState {
    void foo() override;
    option<Dropped> dropped() override;
};

class Failed: public LoopState {
    void foo() override;
    option<Failed> failed() override;
};

class Reachability {

    ITSProblem &its;
    Proof proof;
    HyperGraph::SCCs sccs = its.sccs();
    std::map<LocationIdx, std::vector<TransIdx>> cross_scc;
    std::map<LocationIdx, std::vector<TransIdx>> in_scc;
    std::map<LocationIdx, std::vector<TransIdx>> accelerated;
    std::map<LocationIdx, std::list<TransIdx>> transitions;
    std::map<LocationIdx, std::vector<TransIdx>> queries;
    std::vector<TransIdx> conditional_empty_clauses;
    LocationIdx sink = *its.getSink();
    Z3<IntTheory, BoolTheory> z3;

    std::vector<Step> trace;
    std::vector<Subs> sigmas{{}};
    std::vector<Subs> models;
    std::vector<std::map<TransIdx, std::set<BoolExpr>>> blocked{{}};
    VarSet prog_vars;
    std::map<Var, Var> post_vars;
    TransIdx lastOrigRule = 0;

    using Red = RedundanceViaSquareFreeWords;
    std::unique_ptr<Red> redundance {std::make_unique<Red>()};

    ResultViaSideEffects removeIrrelevantTransitions();
    ResultViaSideEffects simplify();
    ResultViaSideEffects unroll();
    void preprocess();
    void update_transitions(const LocationIdx loc);
    void init();
    void unsat();
    option<BoolExpr> do_step(const TransIdx idx);
    void drop_loop(const int backlink);
    Red::T get_language(const Step &step);
    Red::T build_language(const int backlink);
    Rule build_loop(const int backlink);
    Result<Rule> preprocess_loop(const Rule &loop);
    TransIdx add_accelerated_rule(const Rule &accel, const Red::T &automaton);
    std::unique_ptr<LoopState> learn_clause(const Rule &rule, const Red::T &automaton, const int backlink);
    std::unique_ptr<LoopState> handle_loop(const int backlink);
    bool leaves_scc(const TransIdx idx) const;
    int is_loop();
    void handle_update(const TransIdx idx);
    void do_block(const Step &step);
    void backtrack();
    void pop();
    void extend_trace(const TransIdx idx, const BoolExpr &sat);
    void store(const TransIdx idx, const BoolExpr &sat);
    void print_run(std::ostream &s);
    LocationIdx get_current_location() const;
    bool try_queries(const std::vector<TransIdx> &queries);
    bool try_queries();
    bool try_conditional_empty_clauses();

    Reachability(ITSProblem &its);
    void analyze();

public:

    static bool log;
    static void analyze(ITSProblem &its);

};
