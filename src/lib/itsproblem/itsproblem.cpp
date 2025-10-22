#include "itsproblem.hpp"
#include "config.hpp"

bool ITSProblem::isEmpty() const {
    return rules.empty();
}

LocationIdx ITSProblem::getInitialLocation() const {
    return initialLocation;
}

bool ITSProblem::isInitialLocation(const LocationIdx loc) const {
    return loc == initialLocation;
}

void ITSProblem::setInitialLocation(const LocationIdx loc) {
    initialLocation = loc;
}

void ITSProblem::setSinkLocation(const LocationIdx loc) {
    sink = loc;
}

LocationIdx ITSProblem::getSink() const {
    return sink;
}

const linked_hash_set<RulePtr>& ITSProblem::getAllTransitions() const {
    return rules;
}

linked_hash_set<RulePtr> ITSProblem::getSuccessors(const RulePtr& loc) const {
    return graph.getSuccessors(loc);
}

linked_hash_set<RulePtr> ITSProblem::getPredecessors(const RulePtr& loc) const {
    return graph.getPredecessors(loc);
}

bool ITSProblem::areAdjacent(const RulePtr& first, const RulePtr& second) const {
    return graph.hasEdge(first, second);
}

void ITSProblem::removeRule(const RulePtr& transition) {
    graph.removeNode(transition);
    startAndTargetLocations.erase(transition);
    rules.erase(transition);
}

RulePtr ITSProblem::addRule(const RulePtr& rule, const LocationIdx start, const LocationIdx target, const linked_hash_set<RulePtr> &preds, const linked_hash_set<RulePtr> &succs) {
    const auto [idx, changed] {rules.emplace(rule)};
    if (changed) {
        startAndTargetLocations.emplace(*idx, std::pair(start, target));
        graph.addNode(*idx, preds, succs, start == target);
        if (start == initialLocation) {
            graph.markRoot(*idx);
        }
        if (target == sink) {
            graph.markSink(*idx);
        }
    }
    return *idx;
}

void ITSProblem::addRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs) {
    const auto start = getLhsLoc(same_preds);
    const auto target = getRhsLoc(same_succs);
    const auto preds = graph.getPredecessors(same_preds);
    const auto succs = graph.getSuccessors(same_succs);
    addRule(rule, start, target, preds, succs);
}

void ITSProblem::addLearnedRule(const RulePtr& rule, const RulePtr& same_preds, const RulePtr& same_succs) {
    addRule(rule, same_preds, same_succs);
    graph.removeEdge(rule, rule);
}

RulePtr ITSProblem::addQuery(const Bools::Expr& guard, const RulePtr& same_preds) {
    const auto start = getLhsLoc(same_preds);
    const auto preds = graph.getPredecessors(same_preds);
    const auto res {Rule::mk(guard, Subs::build(loc_var, arith::mkConst(sink)))};
    addRule(res, start, sink, preds, {});
    return res;
}

void ITSProblem::addRule(const RulePtr& rule, const LocationIdx start) {
    const auto target {rule->getUpdate().getConst(loc_var)->isInt().value_or(start).convert_to<LocationIdx>()};
    linked_hash_set<RulePtr> preds, succs;
    for (const auto & [s, t]: startAndTargetLocations) {
        if (t.first == target) {
            succs.insert(s);
        }
        if (t.second == start) {
            preds.insert(s);
        }
    }
    addRule(rule, start, target, preds, succs);
}

void ITSProblem::replaceRule(const RulePtr& toReplace, const RulePtr& replacement) {
    rules.emplace(replacement);
    startAndTargetLocations.emplace(replacement, startAndTargetLocations[toReplace]);
    startAndTargetLocations.erase(toReplace);
    graph.replaceNode(toReplace, replacement);
    rules.erase(toReplace);
}

LocationIdx ITSProblem::addLocation() {
    const LocationIdx loc = nextUnusedLocation++;
    locations.insert(loc);
    return loc;
}

LocationIdx ITSProblem::addNamedLocation(const std::string& name) {
    LocationIdx loc = addLocation();
    locationNames.emplace(loc, name);
    return loc;
}

LocationIdx ITSProblem::getOrAddLocation(const std::string &name) {
    if (const auto res {getLocationIdx(name)}) {
        return *res;
    }
    return addNamedLocation(name);
}

linked_hash_set<LocationIdx> ITSProblem::getLocations() const {
    return locations;
}

std::optional<LocationIdx> ITSProblem::getLocationIdx(const std::string &name) const {
    for (const auto & [loc, n]: locationNames) {
        if (n == name) {
            return loc;
        }
    }
    return {};
}

std::string ITSProblem::getPrintableLocationName(const LocationIdx idx) const {
    if (const auto it = locationNames.find(idx); it != locationNames.end()) {
        return it->second;
    }
    return (std::stringstream() << "[" << idx << "]").str();
}

VarSet ITSProblem::getVars() const {
    VarSet res;
    for (const auto &r: rules) {
        r->collectVars(res);
    }
    return res;
}

Arith::Expr ITSProblem::getCost(const RulePtr& rule) const {
    return rule->getUpdate().getConst(cost_var) - cost_var;
}

ArithVarPtr ITSProblem::getCostVar() const {
    return cost_var;
}

ArithVarPtr ITSProblem::getLocVar() const {
    return loc_var;
}

LocationIdx ITSProblem::getLhsLoc(const RulePtr& idx) const {
    return startAndTargetLocations[idx].first;
}

LocationIdx ITSProblem::getRhsLoc(const RulePtr& idx) const {
    return startAndTargetLocations[idx].second;
}

const linked_hash_set<RulePtr>& ITSProblem::getInitialTransitions() const {
    return graph.getRoots();
}

const linked_hash_set<RulePtr>& ITSProblem::getSinkTransitions() const {
    return graph.getSinks();
}

bool ITSProblem::isSimpleLoop(const RulePtr& idx) const {
    return graph.hasEdge(idx, idx);
}

bool ITSProblem::isSinkTransition(const RulePtr& idx) const {
    return graph.getSinks().contains(idx);
}

bool ITSProblem::isInitialTransition(const RulePtr& idx) const {
    return graph.getRoots().contains(idx);
}

const ITSProblem::DG& ITSProblem::getDependencyGraph() const {
    return graph;
}

linked_hash_set<ITSProblem::DG::Edge> ITSProblem::refineDependencyGraph(const std::function<bool(const RulePtr&, const RulePtr&)> &is_edge) {
    return graph.refine(is_edge);
}

size_t ITSProblem::size() const {
    return graph.size();
}

std::ostream& operator<<(std::ostream &s, const ITSPtr& its) {
    s << "Start location: ";
    s << its->getPrintableLocationName(its->getInitialLocation()) << "\n\n";
    if (!its->getLocations().empty()) {
        s << "Location map:" << std::endl;
        for (const auto p: its->getLocations()) {
            s << its->getPrintableLocationName(p);
            s << " -> " << p << std::endl;
        }
    }
    s << "\n\nRules:\n";
    if (its->isEmpty()) {
        s << "  <empty>\n";
    } else {
        for (const auto &idx : its->getAllTransitions()) {
            s << std::setw(4);
            s << *idx;
            s << std::endl;
        }
    }
    if (Config::Output::PrintDependencyGraph) {
        s << "\nDependency graph:\n";
        s << its->getDependencyGraph() << std::endl;
    }
    return s;
}
