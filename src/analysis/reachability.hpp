#pragma once

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "automaton.hpp"

class Reachability {

    using fset = std::set<const Rel&>;

    struct Step {
        const TransIdx transition;
        const fset sat;
    };

    ITSProblem its;
    Proof proof;
    HyperGraph::SCCs sccs = its.sccs();
    LocationIdx current = its.getInitialLocation();
    LocationIdx sink = *its.getSink();
    std::vector<Step> trace;
    std::vector<size_t> scc_change;
    std::vector<std::map<TransIdx, std::set<fset>>> blocked;
    std::map<TransIdx, Automaton<TransIdx>> regexes;
    Z3 z3;
    Subs sigma;

    void removeIrrelevantTransitions();
    void simplify();
    void chain();

    bool is_redundant(const TransIdx idx, const Subs &model) const;
    bool is_blocked(const TransIdx idx, const Subs &model) const;


public:

    Reachability(const ITSProblem &its);
    void analyze();

};
