#pragma once

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "result.hpp"

#include "libfaudes.h"

using fset = RelSet;

struct Step {
    const TransIdx transition;
    const BoolExpr sat;

    Step(const TransIdx transition, const BoolExpr &sat);

    friend std::ostream& operator<<(std::ostream &s, const Step &step);

};

class Reachability {

    ITSProblem &its;
    Proof proof;
    HyperGraph::SCCs sccs = its.sccs();
    LocationIdx sink = *its.getSink();
    Z3 z3;

    LocationIdx current = its.getInitialLocation();
    std::vector<Step> trace;
    std::vector<Subs> sigmas{Subs()};
    std::vector<Subs> inv_sigmas{Subs()};
    std::vector<std::map<TransIdx, std::set<BoolExpr>>> blocked{{}};
    std::vector<std::pair<faudes::Generator, BoolExpr>> covered;
    VarSet prog_vars;
    TransIdx lastOrigRule = 0;

    std::map<TransIdx, faudes::Generator> regexes;

    ResultViaSideEffects removeIrrelevantTransitions();
    ResultViaSideEffects simplify();
    ResultViaSideEffects unroll();
    Result<Rule> chain(const Rule &r);
    Rule rename_tmp_vars(const Rule &rule);

    BoolExpr satisfied(const BoolExpr &b, const Subs &model) const;
    bool leaves_scc(const TransIdx idx) const;
    option<unsigned> is_loop(const TransIdx idx, const Subs &model) const;
    bool is_redundant(const TransIdx idx, const Subs &model) const;
    bool is_covered(const faudes::Generator &automaton, const Subs &model) const;
    BoolExpr handle_update(const Rule &r);
    faudes::Generator singleton_automaton(const TransIdx idx) const;

    bool covers(const BoolExpr rels, const Subs &model) const;
    void do_block(const TransIdx idx, const BoolExpr &sat);
    void backtrack();
    void store(const TransIdx idx, const BoolExpr &sat);
    option<BoolExpr> search_non_redundant_model(const TransIdx idx);
    void print_run();

    Reachability(ITSProblem &its);
    void analyze();

public:

    static void analyze(ITSProblem &its);

};
