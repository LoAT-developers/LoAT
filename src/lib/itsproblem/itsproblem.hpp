#pragma once

#include "rule.hpp"
#include "dependencygraph.hpp"
#include "linkedhashset.hpp"

#include <optional>

using LocationIdx = unsigned int;

class ITSProblem {

public:

    using DG = DependencyGraph<RulePtr>;

    // Creates an empty ITS problem. The initialLocation is set to 0
    ITSProblem() = default;
    ITSProblem(const ITSProblem&) = delete;

    // True iff there are no rules
    bool isEmpty() const;

    LocationIdx getInitialLocation() const;
    bool isInitialLocation(LocationIdx loc) const;
    void setInitialLocation(LocationIdx loc);
    void setSinkLocation(LocationIdx loc);
    LocationIdx getSink() const;
    std::optional<LocationIdx> getLocationIdx(const std::string &name) const;

    const linked_hash_set<RulePtr>& getAllTransitions() const;
    linked_hash_set<RulePtr> getSuccessors(const RulePtr& loc) const;
    linked_hash_set<RulePtr> getPredecessors(const RulePtr& loc) const;
    bool areAdjacent(const RulePtr& first, const RulePtr& second) const;

    // Mutation of Rules
    void removeRule(const RulePtr& transition);

private:

    RulePtr addRule(const RulePtr& rule, LocationIdx start, LocationIdx target, const linked_hash_set<RulePtr> &preds, const linked_hash_set<RulePtr> &succs);

public:

    void addRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs);
    void addLearnedRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs);
    void addRule(const RulePtr& rule, LocationIdx start);
    RulePtr addQuery(const Bools::Expr& guard, const RulePtr& same_preds);
    void replaceRule(const RulePtr& toReplace, const RulePtr& replacement);

    // Mutation for Locations
    LocationIdx addLocation();
    LocationIdx addNamedLocation(const std::string& name);
    LocationIdx getOrAddLocation(const std::string &name);

    // Required for printing (see ITSExport)
    linked_hash_set<LocationIdx> getLocations() const;
    std::string getPrintableLocationName(LocationIdx idx) const; // returns "[idx]" if there is no name

    VarSet getVars() const;

    Arith::Expr getCost(const RulePtr& rule) const;

    ArithVarPtr getCostVar() const;

    ArithVarPtr getLocVar() const;

    LocationIdx getLhsLoc(const RulePtr& idx) const;

    LocationIdx getRhsLoc(const RulePtr& idx) const;

    const linked_hash_set<RulePtr>& getInitialTransitions() const;

    const linked_hash_set<RulePtr>& getSinkTransitions() const;

    bool isSimpleLoop(const RulePtr& idx) const;

    bool isSinkTransition(const RulePtr& idx) const;

    bool isInitialTransition(const RulePtr& idx) const;

    const DG& getDependencyGraph() const;

    linked_hash_set<DG::Edge> refineDependencyGraph(const std::function<bool(const RulePtr&, const RulePtr&)> &is_edge);

    size_t size() const;

protected:

    DG graph {};
    linked_hash_set<RulePtr> rules {};
    linked_hash_set<LocationIdx> locations {};
    std::unordered_map<LocationIdx, std::string> locationNames {};
    linked_hash_map<RulePtr, std::pair<LocationIdx, LocationIdx>> startAndTargetLocations {};
    LocationIdx nextUnusedLocation {1};
    LocationIdx initialLocation {0};
    LocationIdx sink {addNamedLocation("LoAT_sink")};
    ArithVarPtr loc_var {arrays::nextProgConst<Arith>()};
    ArithVarPtr cost_var {arrays::nextProgConst<Arith>()};

};

using ITSPtr = std::shared_ptr<ITSProblem>;

std::ostream& operator<<(std::ostream &s, const ITSPtr& its);
