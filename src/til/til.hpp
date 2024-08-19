#pragma once

#include <limits>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

#include "chcproblem.hpp"
#include "safetyproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "proof.hpp"
#include "dependencygraph.hpp"
#include "linkedhashmap.hpp"
#include "config.hpp"
#include "chcmodel.hpp"
#include "chctosafetyproblem.hpp"


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

class TIL {

public:

private:

    using BoundPair = std::pair<std::optional<Arith::Expr>, std::optional<Arith::Expr>>;
    using NondetSubs = linked_hash_map<Arith::Var, BoundPair>;

    struct Loop {
        std::vector<Int> expanded;
        Bools::Expr compressed;
    };

    struct RefinementJob {
        Int id;
        Bools::Expr pre;
        Loop loop;
        Bools::Expr post;
        Bools::Expr unrolling;
    };

    enum RefinementResult {
        Refined, Failed, Unsat
    };

    struct TraceElem {
        Int id;
        Bools::Expr implicant;
        Model model;
    };

    Config::TILConfig config;
    SafetyProblem t;
    SmtPtr solver {SmtFactory::solver(Logic::QF_LA)};
    std::vector<std::vector<Subs>> subs {};
    std::vector<TraceElem> trace {};
    Model model;
    std::vector<std::pair<Int, Bools::Expr>> blocked {};
    std::vector<std::pair<Int, Bools::Expr>> projections {};
    std::unordered_map<Int, Bools::Expr> blocked_per_step {};
    VarSet vars {};
    VarSet pre_vars {};
    Int last_orig_clause;
    Subs post_to_pre {};
    Subs pre_to_post {};
    ReversibleCHCToSafety reversible;
    bool produce_model {false};

    Int next_id {0};

    using rule_map_t = boost::bimap<boost::bimaps::unordered_set_of<Int>, boost::bimaps::unordered_set_of<Bools::Expr>>;

    rule_map_t rule_map {};
    const Arith::Var trace_var {ArithVar::next()};
    const Arith::Var n {ArithVar::next()};
    Proof proof {};
    DependencyGraph<Bools::Expr> dependency_graph {};
    unsigned depth {0};
    Bools::Expr step {bot()};

    Bools::Expr encode_transition(const Bools::Expr &idx, const Int &id);
    void add_blocking_clause(const Range &range, const Bools::Expr loop);
    bool add_blocking_clauses(const Range &range, Model model);
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();
    Int add_learned_clause(const Bools::Expr &accel);
    std::pair<Bools::Expr, Model> compress(const Range &range);
    Bools::Expr specialize(const Bools::Expr e, const Model &m, const std::function<bool(const Var&)> &eliminate);
    std::pair<Bools::Expr, Model> specialize(const Range &range, const std::function<bool(const Var&)> &eliminate);
    void recurrent_exps(const Bools::Expr loop, const Model &model, LitSet &res_lits);
    void recurrent_pseudo_divisibility(const Bools::Expr loop, const Model &model, LitSet &res_lits);
    void recurrent_cycles(const Bools::Expr loop, LitSet &res_lits);
    void recurrent_bounds(const Bools::Expr loop, Model model, LitSet &res_lits);
    Bools::Expr recurrence_analysis(const Bools::Expr loop, const Model &model);
    Bools::Expr compute_transition_invariant(const Bools::Expr pre, const Bools::Expr loop, const Bools::Expr post, Model model);
    void handle_loop(const Range &range);
    void unknown();
    void build_trace();
    const Subs& get_subs(const unsigned start, const unsigned steps);
    void pop();
    CHCModel get_model();

    Bools::Expr mbp_impl(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate);
    Bools::Expr mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate) const;

public:

    void sat();
    explicit TIL(const CHCProblem &chcs, const Config::TILConfig &config);
    bool setup();
    std::optional<SmtResult> do_step();
    void analyze();
    static void analyze(const CHCProblem &chcs);

};

std::ostream& operator<<(std::ostream &s, const std::vector<Bools::Expr> &trace);
