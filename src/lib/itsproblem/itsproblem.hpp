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

    // True iff there are no rules
    bool isEmpty() const;

    static LocationIdx getInitialLocation();
    static void nameInitialLocation(const std::string& name);
    static bool isInitialLocation(LocationIdx loc) ;
    static LocationIdx getSink() ;
    static void nameSink(const std::string& name);
    static std::optional<LocationIdx> getLocationIdx(const std::string &name);

    const linked_hash_set<RulePtr>& getAllTransitions() const;
    linked_hash_set<RulePtr> getSuccessors(const RulePtr& loc) const;
    linked_hash_set<RulePtr> getPredecessors(const RulePtr& loc) const;
    bool areAdjacent(const RulePtr& first, const RulePtr& second) const;

    // Mutation of Rules
    void removeRule(const RulePtr& transition);

    bool hasArrays() const;

private:

    RulePtr addRule(const RulePtr& rule, LocationIdx start, LocationIdx target, const linked_hash_set<RulePtr> &preds, const linked_hash_set<RulePtr> &succs);

public:

    void addRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs);
    void addLearnedRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs);
    void addRule(const RulePtr& rule, LocationIdx start);
    RulePtr addQuery(const Bools::Expr& guard, const RulePtr& same_preds);
    void replaceRule(const RulePtr& toReplace, const RulePtr& replacement);

    // Mutation for Locations
    static LocationIdx addLocation();
    static LocationIdx addNamedLocation(const std::string& name);
    static LocationIdx getOrAddLocation(const std::string &name);

    // Required for printing (see ITSExport)
    linked_hash_set<LocationIdx> getLocations() const;

    static std::string getPrintableLocationName(LocationIdx idx); // returns "[idx]" if there is no name

    VarSet getVars() const;
    CellSet getCells() const;

    static Arith::Expr getCost(const RulePtr& rule) ;

    static LocationIdx getLhsLoc(const RulePtr& idx);

    static LocationIdx getRhsLoc(const RulePtr& idx);

    const linked_hash_set<RulePtr>& getInitialTransitions() const;

    const linked_hash_set<RulePtr>& getSinkTransitions() const;

    bool isSimpleLoop(const RulePtr& idx) const;

    bool isSinkTransition(const RulePtr& idx) const;

    bool isInitialTransition(const RulePtr& idx) const;

    const DG& getDependencyGraph() const;

    linked_hash_set<DG::Edge> refineDependencyGraph(const std::function<bool(const RulePtr&, const RulePtr&)> &is_edge);

    size_t size() const;

    static ArithVarPtr loc_var();
    static ArithVarPtr cost_var();

protected:

    DG graph {};
    linked_hash_set<RulePtr> rules {};
    static std::unordered_map<LocationIdx, std::string> locationNames;
    static linked_hash_map<RulePtr, std::pair<LocationIdx, LocationIdx>> startAndTargetLocations;
    static LocationIdx nextUnusedLocation;
    static LocationIdx initialLocation;
    static LocationIdx sink;

};

using ITSPtr = std::shared_ptr<ITSProblem>;

std::ostream& operator<<(std::ostream &s, const ITSPtr& its);
