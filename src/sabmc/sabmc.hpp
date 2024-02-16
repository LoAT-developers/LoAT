#pragma once

#include <limits>

#include "safetyproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "proof.hpp"
#include "dependencygraph.hpp"
#include "map.hpp"


class Range {
    unsigned s;
    unsigned e;

    Range(const unsigned s, const unsigned e);

public:
    unsigned start() const;
    unsigned end() const;
    unsigned length() const;

    static Range from_length(const unsigned start, const unsigned length);
    static Range from_interval(const unsigned start, const unsigned end);

};

class SABMC {

private:

    using BoundPair = std::pair<std::optional<Expr>, std::optional<Expr>>;
    using NondetSubs = linked_hash_map<NumVar, BoundPair>;

    explicit SABMC(SafetyProblem &t);

    void analyze();

    struct Loop {
        BoolExpr trans;
        unsigned length;
        unsigned id;

        Loop(const BoolExpr trans, const unsigned length, const unsigned id);

    };

    SafetyProblem &t;
    SmtPtr solver {SmtFactory::solver()};
    std::vector<std::vector<Subs>> subs {};
    std::vector<Transition> trace {};
    std::vector<Loop> blocked {};
    linked_hash_map<Var, Var> var_map {};
    linked_hash_map<Var, Var> inverse_var_map {};
    VarSet vars {};
    linked_hash_map<NumVar, NumVar> lower_vars {};
    linked_hash_map<NumVar, NumVar> upper_vars {};
    ExprSubs reverse_low_up_vars {};
    std::unordered_map<unsigned, Transition> rule_map {};
    const NumVar trace_var {NumVar::next()};
    const NumVar n {NumVar::next()};
    Proof proof {};
    DependencyGraph<Transition> dependency_graph {};
    unsigned depth {0};
    BoolExpr step {};

    BoolExpr encode_transition(const Transition &idx);
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();
    void add_learned_clause(const Transition &accel, unsigned length);
    std::pair<Transition, Subs> build_loop(const Range &range);
    void handle_loop(const Range &range);
    void unknown();
    void sat();
    void build_trace();
    const Subs& get_subs(const unsigned start, const unsigned steps);

    Transition mbp(const Transition &trans, const Subs &model) const;
    BoundPair bound_selection(const Transition &t, const Subs &model, const NumVar &x, linked_hash_set<Expr> &chosen) const;
    NondetSubs bound_selection(const Transition &t, const Subs &model) const;
    linked_hash_map<BoolVar, bool> value_selection(const Subs &model) const;
    std::pair<NondetSubs, unsigned> closed_form(const NondetSubs &update, const Subs &model);
    void handle_rel(const Rel &rel, const NondetSubs &update, const NondetSubs &closed, const Subs &model, std::vector<BoolExpr> &res);

public:

    static void analyze(SafetyProblem &its);

};

std::ostream& operator<<(std::ostream &s, const std::vector<Transition> &trace);
