#pragma once

#include "theory.hpp"
#include "safetyproblem.hpp"
#include "stepwise.hpp"
#include "trp.hpp"
#include "itstosafetyproblem.hpp"
#include "smtfactory.hpp"

class Range {
    unsigned s;
    unsigned e;

    Range(unsigned s, unsigned e);

public:
    unsigned start() const;
    unsigned end() const;
    unsigned length() const;
    bool empty() const;

    static Range from_length(unsigned start, unsigned length);
    static Range from_interval(unsigned start, unsigned end);

};

class TRPUtil: public StepwiseAnalysis {

protected:

    struct TraceElem {
        Int id;
        Bools::Expr implicant;
        ModelPtr model;
    };

    using rule_map_t = linked_hash_map<Int, Bools::Expr>;

    SmtPtr solver {SmtFactory::solver(Logic::QF_LA)};
    std::vector<TraceElem> trace {};
    std::vector<std::vector<Renaming>> subs {};
    VarSet vars {};
    const Config::TRPConfig::MbpKind mbp_kind;
    ITSToSafety its2safety;
    SafetyProblem t;
    std::optional<ModelPtr> model;
    const ArithVarPtr trace_var {arrays::nextConst<Arith>()};
    linked_hash_map<Int, std::vector<std::pair<Int, Bools::Expr>>> learned_to_loop;
    Int next_id {0};
    rule_map_t rule_map {};
    ITSPtr its;
    TRP trp;
    Renaming post_to_pre;
    Int last_orig_clause;
    const ArithVarPtr safety_var {arrays::nextConst<Arith>()};
    DependencyGraph<Bools::Expr> dependency_graph {};
    std::vector<std::pair<Int, Bools::Expr>> projections {};
    linked_hash_map<Int, Bools::Expr> accel;
    bool safe {true};

    TRPUtil(const ITSPtr &its, const Config::TRPConfig &config);

    std::pair<Bools::Expr, ModelPtr> compress(const Range &range);
    const Renaming& get_subs(unsigned start, unsigned steps);
    Bools::Expr encode_transition(const Bools::Expr &t, const Int &id) const;
    Int add_learned_clause(const Range &range, const Bools::Expr &accel);
    Bools::Expr specialize(const Bools::Expr& e, const ModelPtr &model, const std::function<bool(const Cell&)> &eliminate) const;
    std::pair<Bools::Expr, ModelPtr> specialize(const Range &range, const std::function<bool(const Cell&)> &eliminate);
    std::optional<Arith::Expr> prove_term(const Bools::Expr& loop, const ModelPtr &model);
    bool build_cex();
    virtual void add_blocking_clause(const Range &range, const Int &id, Bools::Expr loop) = 0;
    bool add_blocking_clauses(const Range &range, const ModelPtr& model);

public:

    static const Config::TRPConfig forwardConfig;
    static const Config::TRPConfig backwardConfig;

    ITSSafetyCex get_cex() override;

};
