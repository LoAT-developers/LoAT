#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "safetyproblem.hpp"
#include "stepwise.hpp"
#include "trp.hpp"
#include "itstosafetyproblem.hpp"
#include "smtfactory.hpp"
#include "renamingcentral.hpp"

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

    struct LearnedTransInfo {

        const std::vector<std::pair<Int, Bools::Expr>> loop;
        const LitSet lits;
        std::optional<Bools::Expr> accel {};

        LearnedTransInfo(const std::vector<std::pair<Int, Bools::Expr>> &loop, const LitSet &lits);

    };

    SmtPtr solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    std::vector<TraceElem> trace {};
    std::optional<RenamingCentral> renaming_central;
    const Config::TRPConfig::MbpKind mbp_kind;
    ITSToSafety its2safety;
    SafetyProblem t;
    Model model;
    const Arith::Var trace_var {ArithVar::next()};
    Int next_id {0};
    std::unordered_map<Int, Bools::Expr> rule_map {};
    std::unordered_map<Int, LearnedTransInfo> learned_rule_map {};
    ITSPtr its;
    TRP trp;
    const Arith::Var safety_var {ArithVar::next()};
    DependencyGraph<Bools::Expr> dependency_graph {};
    bool safe {true};

    TRPUtil(const ITSPtr its, const Config::TRPConfig &config);

    std::pair<Bools::Expr, Model> compress(const Range &range);
    Bools::Expr encode_transition(const Bools::Expr &idx, const Int &id);
    Int add_learned_clause(const Range &range, const Bools::Expr &accel);
    Bools::Expr specialize(const Bools::Expr e, const Model &m, const std::function<bool(const Var&)> &eliminate);
    std::pair<Bools::Expr, Model> specialize(const Range &range, const std::function<bool(const Var&)> &eliminate);
    std::optional<Arith::Expr> prove_term(const Bools::Expr loop, const Model &model);
    bool build_cex();
    virtual void add_blocking_clause(const Range &range, const Int &id, const Bools::Expr loop) = 0;
    bool add_blocking_clauses(const Range &range, Model model);

public:

    static const Config::TRPConfig forwardConfig;
    static const Config::TRPConfig backwardConfig;

    ITSSafetyCex get_cex() override;

};
