#pragma once

#include <limits>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

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
    bool empty() const;

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

        Loop(const Bools::Expr trans, const unsigned length);

    };

    SafetyProblem &t;
    SmtPtr solver {SmtFactory::solver()};
    std::vector<std::vector<Subs>> subs {};
    std::vector<Bools::Expr> trace {};
    std::vector<Loop> blocked {};
    VarSet vars {};

    Int next_id {0};

    using rule_map_t = boost::bimap<boost::bimaps::unordered_set_of<Int>, boost::bimaps::unordered_set_of<Bools::Expr>>;

    rule_map_t rule_map {};
    const Arith::Var trace_var {ArithVar::next()};
    const Arith::Var n {ArithVar::next()};
    Proof proof {};
    DependencyGraph<Bools::Expr> dependency_graph {};
    unsigned depth {0};
    Bools::Expr step {bot()};

    Bools::Expr encode_transition(const Bools::Expr &idx);
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();
    void add_learned_clause(const Bools::Expr &accel, unsigned length);
    std::pair<Bools::Expr, Model> compress(const Bools::Expr pre, const Range &range);
    Bools::Expr specialize(const Bools::Expr e, const Model &m, const std::function<bool(const Var&)> &eliminate);
    Bools::Expr specialize(const Bools::Expr pre, const Range &range, const std::function<bool(const Var&)> &eliminate);
    Bools::Expr recurrence_analysis(const Bools::Expr loop);
    void handle_loop(const Range &range);
    void unknown();
    void sat();
    void build_trace();
    const Subs& get_subs(const unsigned start, const unsigned steps);

    Bools::Expr mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate) const;

public:

    static void analyze(SafetyProblem &its);

};

std::ostream& operator<<(std::ostream &s, const std::vector<Bools::Expr> &trace);
