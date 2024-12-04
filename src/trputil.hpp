#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "safetyproblem.hpp"
#include "stepwise.hpp"
#include "trp.hpp"
#include "itstosafetyproblem.hpp"
#include "smtfactory.hpp"

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

class TRPUtil: public StepwiseAnalysis {

protected:

    struct TraceElem {
        Int id;
        Bools::Expr implicant;
        Model model;
    };

    using rule_map_t = boost::bimap<boost::bimaps::set_of<Int>, boost::bimaps::set_of<Bools::Expr>>;

    SmtPtr solver {SmtFactory::solver(Logic::QF_LA)};
    std::vector<TraceElem> trace {};
    std::vector<std::vector<Renaming>> subs {};
    VarSet vars {};
    const Config::TRPConfig::MbpKind mbp_kind;
    ITSToSafety its2safety;
    SafetyProblem t;
    Model model;
    const Arith::Var trace_var {ArithVar::next()};
    linked_hash_map<Int, std::vector<std::pair<Int, Bools::Expr>>> learned_to_loop;
    Int next_id {0};
    rule_map_t rule_map {};
    Bools::Expr step {bot()};
    ITSPtr its;
    TRP trp;
    Renaming post_to_pre;
    Int last_orig_clause;
    const Arith::Var safety_var {ArithVar::next()};
    DependencyGraph<Bools::Expr> dependency_graph {};

    TRPUtil(const ITSPtr its, const Config::TRPConfig &config);

    std::pair<Bools::Expr, Model> compress(const Range &range);
    const Renaming& get_subs(const unsigned start, const unsigned steps);
    Bools::Expr encode_transition(const Bools::Expr &idx, const Int &id);
    Int add_learned_clause(const Range &range, const Bools::Expr &accel);
    Bools::Expr specialize(const Bools::Expr e, const Model &m, const std::function<bool(const Var&)> &eliminate);
    std::pair<Bools::Expr, Model> specialize(const Range &range, const std::function<bool(const Var&)> &eliminate);
    std::optional<Arith::Expr> prove_term(const Bools::Expr loop, const Model &model);
    bool build_cex() const;
    virtual void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) = 0;
    bool add_blocking_clauses(const Range &range, Model model);

public:

    static const Config::TRPConfig forwardConfig;
    static const Config::TRPConfig backwardConfig;

    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};
