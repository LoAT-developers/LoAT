#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "vector.hpp"

class ABMC {

private:

    explicit ABMC(ITSProblem &its);

    void analyze();

    struct Loop {
        TransIdx idx;
        unsigned prefix;
        unsigned period;
        Bools::Expr covered;
        bool deterministic;
    };

    ITSProblem &its;
    SmtPtr solver {SmtFactory::solver()};
    bool approx {false};
    unsigned last_orig_clause {};
    Bools::Expr query {bot()};
    std::vector<Subs> subs {Subs::Empty};
    std::vector<Subs> subsTmp {Subs::Empty};
    std::vector<Implicant> trace {};
    VarSet vars {};
    Arith::Var n {ArithVar::next()};
    std::unordered_map<Var, Var> post_vars {};
    std::unordered_map<Implicant, int> lang_map {};
    std::unordered_map<std::vector<int>, std::unordered_map<Bools::Expr, std::optional<Loop>>> cache {};
    std::unordered_set<std::vector<int>> nonterm_cache {};
    std::unordered_map<int, std::vector<int>> history {};
    Arith::Var trace_var;
    std::optional<TransIdx> shortcut {};
    std::unordered_map<Int, TransIdx> rule_map {};
    int next {0};
    DependencyGraph<Implicant> dependency_graph {};
    unsigned depth {0};

    int get_language(unsigned i);
    Bools::Expr encode_transition(const TransIdx idx, const bool with_id = true);
    bool is_orig_clause(const TransIdx idx) const;
    std::optional<unsigned> has_looping_suffix(unsigned start, std::vector<int> &lang);
    TransIdx add_learned_clause(const Rule &accel, const unsigned backlink);
    std::pair<Rule, Model> build_loop(const int backlink);
    Bools::Expr build_blocking_clause(const int backlink, const Loop &loop);
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
