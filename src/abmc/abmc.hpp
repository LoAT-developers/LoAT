#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "smt.hpp"
#include "variant.hpp"

class ABMC {

private:

    static const bool max_smt;
    static const bool optimize;

public:

    using Implicant = std::pair<TransIdx, std::set<LitPtr>>;

private:

    ABMC(const ITSProblem &its);

    void analyze();

    ITSProblem its;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver;
    bool approx {false};
    TransIdx last_orig_clause;
    std::vector<Subs> subs {Subs::Empty};
    std::vector<Implicant> trace;
    VarSet vars;
    std::map<Var, Var> post_vars;
    std::map<Implicant, std::string> lang_map;
    std::map<std::string, TransIdx> cache;
    NumVar trace_var;
    BoolExpr shortcut {BExpression::True};
    std::optional<NumVar> n;
    Expr objective {0};
    NumVar objective_var;
    std::map<unsigned, TransIdx> rule_map;
    long next {0};

    std::string get_language(unsigned i);
    BoolExpr encode_transition(const TransIdx idx);
    bool is_orig_clause(const TransIdx idx) const;
    std::optional<unsigned> has_looping_suffix(unsigned start, std::string &lang);
    TransIdx add_learned_clause(const Rule &accel, const unsigned backlink);
    std::pair<Rule, Subs> build_loop(const int backlink);
    bool handle_loop(int backlink, const std::string &lang);

public:

    static void analyze(const ITSProblem &its);

};

std::ostream& operator<<(std::ostream &s, const LitPtr lit);

std::ostream& operator<<(std::ostream &s, const ABMC::Implicant &imp);

std::ostream& operator<<(std::ostream &s, const std::vector<ABMC::Implicant> &trace);
