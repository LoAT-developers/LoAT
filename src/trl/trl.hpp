#pragma once

#include <limits>
#include <boost/bimap.hpp>
#include <boost/bimap/set_of.hpp>

#include "safetyproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "dependencygraph.hpp"
#include "linkedhashmap.hpp"
#include "config.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"
#include "itssafetycex.hpp"
#include "stepwise.hpp"
#include "trp.hpp"

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

class TRL: public StepwiseAnalysis {

public:

    static const Config::TRPConfig forwardConfig;
    static const Config::TRPConfig backwardConfig;
    static const Config::TRPConfig intTermConfig;
    static const Config::TRPConfig realTermConfig;

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

    linked_hash_map<Int, std::vector<std::pair<Int, Bools::Expr>>> learned_to_loop;
    const Config::TRPConfig::MbpKind mbp_kind;
    SmtPtr solver {SmtFactory::solver(Logic::QF_LA)};
    std::vector<std::vector<Renaming>> subs {};
    std::vector<TraceElem> trace {};
    Model model;
    std::vector<std::pair<Int, Bools::Expr>> projections {};
    // step -> ID of corresponding transition formula -> blocked transition
    std::unordered_map<Int, std::map<Int, Bools::Expr>> blocked_per_step {};
    VarSet vars {};
    Int last_orig_clause;
    ITSToSafety its2safety;
    SafetyProblem t;
    ITSPtr its;
    bool produce_model {false};
    TRP trp;

    Int next_id {0};

    using rule_map_t = boost::bimap<boost::bimaps::set_of<Int>, boost::bimaps::set_of<Bools::Expr>>;

    rule_map_t rule_map {};
    const Arith::Var trace_var {ArithVar::next()};
    const Arith::Var safety_var {ArithVar::next()};
    DependencyGraph<Bools::Expr> dependency_graph {};
    unsigned depth {0};
    Bools::Expr step {bot()};

    Bools::Expr encode_transition(const Bools::Expr &idx, const Int &id);
    Bools::Expr get_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop);
    void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop);
    bool add_blocking_clauses(const Range &range, Model model);
    void add_blocking_clauses();
    std::optional<Range> has_looping_infix();
    Int add_learned_clause(const Range &range, const Bools::Expr &accel);
    std::pair<Bools::Expr, Model> compress(const Range &range);
    Bools::Expr specialize(const Bools::Expr e, const Model &m, const std::function<bool(const Var&)> &eliminate);
    std::pair<Bools::Expr, Model> specialize(const Range &range, const std::function<bool(const Var&)> &eliminate);

    std::optional<Arith::Expr> prove_term(const Bools::Expr loop, const Model &model);
    bool handle_loop(const Range &range);
    void build_trace();
    const Renaming& get_subs(const unsigned start, const unsigned steps);
    void pop();

    bool build_cex() const;

public:

    explicit TRL(const ITSPtr its, const Config::TRPConfig &config);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};

std::ostream& operator<<(std::ostream &s, const std::vector<Bools::Expr> &trace);