#pragma once

#include "rule.hpp"
#include "dependencygraph.hpp"
#include "linkedhashset.hpp"

using LocationIdx = Int;

class ITSProblem;

using ITSPtr = std::shared_ptr<const ITSProblem>;

class ITSProblem: public std::enable_shared_from_this<ITSProblem> {

public:

    using DG = DependencyGraph<RulePtr>;

    ITSProblem();

    explicit ITSProblem(const DG& p_graph);

    // True iff there are no rules
    bool isEmpty() const;

    const linked_hash_set<RulePtr>& getAllTransitions() const;
    linked_hash_set<RulePtr> getSuccessors(const RulePtr& p_rule) const;
    linked_hash_set<RulePtr> getPredecessors(const RulePtr& p_rule) const;
    bool areAdjacent(const RulePtr& p_first, const RulePtr& p_second) const;

    // Mutation of Rules
    ITSPtr removeRule(const RulePtr& p_transition) const;

    bool hasArrays() const;

    struct RuleProperties {
        bool is_loop;
        bool is_initial;
        bool is_sink;
    };

    ITSPtr addRule(RulePtr p_rule, const RuleProperties& p_props, const linked_hash_set<RulePtr> &p_preds, const linked_hash_set<RulePtr> &p_succs) const;
    ITSPtr addRule(RulePtr p_rule, RulePtr p_same_preds, RulePtr p_same_succs) const;
    ITSPtr addLearnedRule(RulePtr p_rule, RulePtr p_same_preds, RulePtr p_same_succs) const;
    ITSPtr addQuery(RulePtr p_err, RulePtr p_same_preds) const;
    ITSPtr replaceRule(RulePtr p_to_replace, RulePtr p_replacement) const;

    VarSet getVars() const;
    CellSet getCells() const;

    static Arith::Expr getCost(const RulePtr& rule) ;

    const linked_hash_set<RulePtr>& getInitialTransitions() const;

    const linked_hash_set<RulePtr>& getSinkTransitions() const;

    bool isSimpleLoop(const RulePtr& idx) const;

    bool isSinkTransition(const RulePtr& idx) const;

    bool isInitialTransition(const RulePtr& idx) const;

    const DG& getDependencyGraph() const;

    std::pair<ITSPtr, linked_hash_set<DG::Edge>> refineDependencyGraph(const std::function<bool(const RulePtr&, const RulePtr&)> &is_edge) const;

    size_t size() const;

    static ArithVarPtr loc_var();
    static ArithVarPtr cost_var();

protected:

    const DG graph {};

};

std::ostream& operator<<(std::ostream &s, const ITSPtr& its);
