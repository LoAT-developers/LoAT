#pragma once

#include "itsproblem.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "vector.hpp"
#include "renaming.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "stepwise.hpp"

class ABMC final : public StepwiseAnalysis {

    struct Loop {
        RulePtr idx;
        unsigned prefix;
        unsigned period;
        Bools::Expr covered;
        bool deterministic;
    };

    ITSPtr its;
    SmtPtr solver {SmtFactory::solver()};
    bool approx {false};
    unsigned last_orig_clause {};
    Bools::Expr query {bot()};
    std::vector<Renaming> subs {Renaming::Empty};
    std::vector<Renaming> subsTmp {Renaming::Empty};
    std::vector<Renaming> subsProg {Renaming::Empty};
    std::vector<Implicant> trace {};
    std::vector<Bools::Expr> transitions {};
    VarSet vars {};
    ArithVarPtr n {arrays::nextConst<Arith>()};
    Renaming pre_to_post {};
    std::unordered_map<Implicant, int> lang_map {};
    std::unordered_map<std::vector<int>, std::unordered_map<Bools::Expr, std::optional<Loop>>> cache {};
    std::unordered_set<std::vector<int>> nonterm_cache {};
    std::unordered_map<int, std::vector<int>> history {};
    ArithVarPtr trace_var {arrays::nextConst<Arith>()};
    std::optional<RulePtr> shortcut {};
    std::unordered_map<Int, RulePtr> rule_map {};
    int next {0};
    DependencyGraph<Implicant> dependency_graph {};
    unsigned depth {0};
    ITSSafetyCex cex;
    Bools::Expr step {top()};
    VarSet declared_vars {};
    std::vector<Subs> elim {Subs()};

    int get_language(unsigned i);
    Bools::Expr encode_transition(const RulePtr& idx, bool with_id = true);
    bool is_orig_clause(const RulePtr& idx) const;
    std::optional<unsigned> has_looping_suffix(unsigned start, std::vector<int> &lang);
    void add_learned_clause(const RulePtr& accel, unsigned backlink);
    std::pair<RulePtr, ModelPtr> build_loop(int backlink) const;
    Bools::Expr build_blocking_clause(int backlink, const Loop &loop);
    std::optional<Loop> handle_loop(unsigned backlink, const std::vector<int> &lang);
    void build_trace();
    bool is_redundant(const std::vector<int> &w) const;
    const Renaming& subs_at(unsigned i);
    void add(const Bools::Expr&);
    void pop();

public:

    ~ABMC() override = default;
    explicit ABMC(const ITSPtr& its);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};

std::ostream& operator<<(std::ostream &s, const std::vector<Implicant> &trace);
