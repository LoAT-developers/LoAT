#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "itsproof.hpp"

template<>
struct std::hash<std::pair<std::vector<int>, BoolExpr>> {
    std::size_t operator()(const std::pair<std::vector<int>, BoolExpr>& x) const noexcept {
        std::size_t seed {0};
        boost::hash_combine(seed, x.first);
        boost::hash_combine(seed, x.second);
        return seed;
    }
};

class ABMC {

private:

    ABMC(ITSProblem &its);

    void analyze();

    struct Loop {
        TransIdx idx;
        unsigned prefix;
        unsigned period;
        BoolExpr covered;
        bool deterministic;
    };

    ITSProblem &its;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver {SmtFactory::solver<IntTheory, BoolTheory>()};
    bool approx {false};
    unsigned last_orig_clause;
    BoolExpr query;
    std::vector<Subs> subs {Subs::Empty};
    std::vector<Implicant> trace;
    VarSet vars;
    NumVar n {NumVar::next()};
    std::unordered_map<Var, Var> post_vars;
    std::unordered_map<Implicant, int> lang_map;
    std::unordered_map<std::pair<std::vector<int>, BoolExpr>, std::unordered_map<BoolExpr, std::optional<Loop>>> cache;
    std::unordered_set<std::pair<std::vector<int>, BoolExpr>> nonterm_cache;
    std::unordered_map<int, std::vector<int>> history;
    NumVar trace_var;
    std::optional<TransIdx> shortcut;
    std::unordered_map<unsigned, TransIdx> rule_map;
    int next {0};
    ITSProof proof;
    DependencyGraph<Implicant> dependency_graph;
    unsigned depth {0};

    int get_language(unsigned i);
    BoolExpr encode_transition(const TransIdx idx);
    bool is_orig_clause(const TransIdx idx) const;
    std::optional<unsigned> has_looping_suffix(unsigned start, std::vector<int> &lang);
    TransIdx add_learned_clause(const Rule &accel, const unsigned backlink);
    std::pair<Rule, Subs> build_loop(const int backlink);
    BoolExpr build_blocking_clause(const int backlink, const Loop &loop);
    std::pair<Rule, BoolExpr> project(const Rule &r, const ExprSubs &sample_point);
    std::optional<Loop> handle_loop(int backlink, const std::vector<int> &lang);
    void unsat();
    void unknown();
    void sat();
    void build_trace();
    bool is_redundant(const std::vector<int> &w) const;
    const Subs& subs_at(const unsigned i);

public:

    static void analyze(ITSProblem &its);

};

std::ostream& operator<<(std::ostream &s, const std::vector<Implicant> &trace);
