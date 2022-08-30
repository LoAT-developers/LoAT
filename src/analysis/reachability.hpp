#pragma once

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "automaton.hpp"

class Reachability {

    using fset = RelSet;

    struct Step {
        const TransIdx transition;
        const fset sat;

        Step(const TransIdx transition, const fset &sat);

    };

    ITSProblem its;
    Proof proof;
    HyperGraph::SCCs sccs = its.sccs();
    LocationIdx sink = *its.getSink();
    Z3 z3;

    LocationIdx current = its.getInitialLocation();
    std::vector<Step> trace;
    std::vector<Subs> sigmas{Subs()};
    std::vector<std::map<TransIdx, std::set<fset>>> blocked{{}};

    std::map<TransIdx, Automaton<TransIdx>> regexes;

    void removeIrrelevantTransitions();
    void simplify();
    void chain();

    fset satisfied(const BoolExpr &b, const Subs &model) const;
    bool leaves_scc(const TransIdx idx) const;
    option<unsigned> is_loop(const TransIdx idx, const Subs &model) const;
    bool is_redundant(const TransIdx idx, const Subs &model) const;
    BoolExpr handle_update(const Rule &r);

    Reachability(const ITSProblem &its);
    void analyze();

public:

    static void analyze(const ITSProblem &its);

};
