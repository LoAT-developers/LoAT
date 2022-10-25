#pragma once

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "result.hpp"

#include "libfaudes.h"

#include <list>

using Automaton = faudes::Generator;

struct Step {
    const TransIdx transition;
    const BoolExpr sat;

    Step(const TransIdx transition, const BoolExpr &sat);

    friend std::ostream& operator<<(std::ostream &s, const Step &step);

};

class Reachability {

    enum State {
        Successful,
        Failed,
        DroppedLoop,
        PseudoLoop
    };

    ITSProblem &its;
    Proof proof;
    HyperGraph::SCCs sccs = its.sccs();
    std::map<LocationIdx, std::vector<TransIdx>> cross_scc;
    std::map<LocationIdx, std::vector<TransIdx>> in_scc;
    std::map<LocationIdx, std::vector<TransIdx>> accelerated;
    std::map<LocationIdx, std::list<TransIdx>> transitions;
    LocationIdx sink = *its.getSink();
    Z3<IntTheory, BoolTheory> z3;

    std::vector<Step> trace;
    std::vector<Subs> sigmas;
    std::vector<std::map<TransIdx, std::set<BoolExpr>>> blocked{{}};
    std::vector<std::pair<Automaton, BoolExpr>> covered;
    VarSet prog_vars;
    TransIdx lastOrigRule = 0;

    std::map<TransIdx, Automaton> regexes;

    ResultViaSideEffects removeIrrelevantTransitions();
    ResultViaSideEffects simplify();
    ResultViaSideEffects unroll();
    void preprocess();
    void update_transitions(const LocationIdx loc);
    void init();
    void unsat();
    option<BoolExpr> do_step(const TransIdx idx);
    void drop_loop(const int backlink);
    std::pair<Rule, Automaton> build_loop(const int backlink);
    Result<Rule> preprocess_loop(const Rule &loop);
    State handle_loop(const int backlink);
    Result<Rule> unroll(const Rule &r);
    Rule rename_tmp_vars(const Rule &rule);
    BoolExpr project(const TransIdx idx);
    bool leaves_scc(const TransIdx idx) const;
    int is_loop(const TransIdx idx);
    bool is_covered(const Automaton &automaton, const Subs &model) const;
    void handle_update(const TransIdx idx);
    Automaton singleton_automaton(const TransIdx idx) const;
    bool covers(const Subs &model, const BoolExpr &rels) const;
    void do_block(const Step &step);
    void backtrack();
    void pop();
    void extend_trace(const TransIdx idx, const BoolExpr &sat);
    void store(const TransIdx idx, const BoolExpr &sat);
    void print_run(std::ostream &s);

    Reachability(ITSProblem &its);
    void analyze();

public:

    static bool log;
    static void analyze(ITSProblem &its);

};
