#pragma once

#include <limits>

#include "safetyproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "proof.hpp"
#include "dependencygraph.hpp"
#include "linkedhashmap.hpp"


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

    using BoundPair = std::pair<std::optional<Arith::Expr>, std::optional<Arith::Expr>>;
    using NondetSubs = linked_hash_map<Arith::Var, BoundPair>;

    explicit SABMC(SafetyProblem &t);

    void analyze();

    struct Loop {
        Bools::Expr trans;
        unsigned length;
        unsigned id;

        Loop(const Bools::Expr trans, const unsigned length, const unsigned id);

    };

    SafetyProblem &t;
    SmtPtr solver {SmtFactory::solver()};
    std::vector<std::vector<Subs>> subs {};
    std::vector<Transition> trace {};
    std::vector<Loop> blocked {};
    linked_hash_map<Var, Var> var_map {};
    linked_hash_map<Var, Var> inverse_var_map {};
    VarSet vars {};
    linked_hash_map<Arith::Var, Arith::Var> lower_vars {};
    linked_hash_map<Arith::Var, Arith::Var> upper_vars {};
    ArithSubs reverse_low_up_vars {};
    std::unordered_map<Int, Transition> rule_map {};
    const Arith::Var trace_var {ArithVar::next()};
    const Arith::Var n {ArithVar::next()};
    Proof proof {};
    DependencyGraph<Transition> dependency_graph {};
    unsigned depth {0};
    Bools::Expr step {};

    Bools::Expr encode_transition(const Transition &idx);
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();
    void add_learned_clause(const Transition &accel, unsigned length);
    std::pair<Transition, Model> build_loop(const Range &range);
    void handle_loop(const Range &range);
    void unknown();
    void sat();
    void build_trace();
    const Subs& get_subs(const unsigned start, const unsigned steps);

    Transition mbp(const Transition &trans, const Model &model) const;
    BoundPair bound_selection(const Transition &t, const Model &model, const Arith::Var x, linked_hash_set<Arith::Expr> &chosen) const;
    NondetSubs bound_selection(const Transition &t, const Model &model) const;
    linked_hash_map<Bools::Var, bool> value_selection(const Model &model) const;
    std::pair<NondetSubs, unsigned> closed_form(const NondetSubs &update, const Model &model);
    void handle_rel(const ArithLit &rel, const NondetSubs &update, const NondetSubs &closed, const Model &model, std::vector<Bools::Expr> &res);

public:

    static void analyze(SafetyProblem &its);

};

std::ostream& operator<<(std::ostream &s, const std::vector<Transition> &trace);
