#pragma once

#include "theory.hpp"
#include "safetyproblem.hpp"
#include "stepwise.hpp"
#include "trp.hpp"
#include "itstosafetyproblem.hpp"
#include "smtfactory.hpp"
#include "range.hpp"

#include <map>

class TRPUtil: public StepwiseAnalysis {

protected:

    struct TraceElem {
        Int id;
        Bools::Expr implicant;
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
    std::unordered_map<Int, Bools::Expr> concretization;
    Int next_id {0};
    rule_map_t rule_map {};
    ITSPtr its;
    TRP trp;
    Renaming post_to_pre;
    Int last_orig_clause;
    const ArithVarPtr safety_var {arrays::nextConst<Arith>()};
    DependencyGraph<Bools::Expr> dependency_graph {};
    std::unordered_map<Int, Bools::Expr> projections {};
    linked_hash_map<Int, Bools::Expr> accel;
    bool safe {true};
    // step -> ID of corresponding transition formula -> blocked transition
    std::unordered_map<Int, std::map<Int, BoolExprSet>> blocked_per_step {};

    TRPUtil(const ITSPtr &its, const Config::TRPConfig &config);

    std::pair<Bools::Expr, ModelPtr> compress(const Range &range);
    const Renaming& get_subs(unsigned start, unsigned steps);
    Bools::Expr encode_transition(const Bools::Expr &t, const Int &id) const;
    Int add_learned_clause(const Range &range, const Bools::Expr &accel);
    std::pair<Bools::Expr, Bools::Expr> specialize(const Bools::Expr& e, const ModelPtr &model, const std::function<bool(const Cell&)> &eliminate) const;
    std::tuple<Bools::Expr, Bools::Expr, ModelPtr> specialize(const Range &range, const std::function<bool(const Cell&)> &eliminate);
    std::optional<Arith::Expr> prove_term(const Bools::Expr& loop, const ModelPtr &model);
    bool build_cex();
    void add_projection(const Int& id, const Bools::Expr& projection);
    void add_blocking_clauses(unsigned depth);
    virtual void add_blocking_clause(const Range &range, const Int &id, Bools::Expr loop) = 0;
    bool add_blocking_clauses(const Range &range, const ModelPtr& model);
    std::optional<Int> refine_abstraction(const Range&);
    std::optional<Int> refine_partially(const Range&);
    std::optional<Int> refine_by_model(const Range& range, const ModelPtr& m);

public:

    static const Config::TRPConfig forwardConfig;
    static const Config::TRPConfig backwardConfig;

    ITSSafetyCex get_cex() override;

};
