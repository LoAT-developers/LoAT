#include "itsproblem.hpp"
#include "chain.hpp"
#include "config.hpp"

bool ITSProblem::isEmpty() const {
    return rules.empty();
}

LocationIdx ITSProblem::getInitialLocation() const {
    return initialLocation;
}

bool ITSProblem::isInitialLocation(LocationIdx loc) const {
    return loc == initialLocation;
}

void ITSProblem::setInitialLocation(LocationIdx loc) {
    initialLocation = loc;
}

LocationIdx ITSProblem::getSink() const {
    return sink;
}

const linked_hash_set<Rule>& ITSProblem::getAllTransitions() const {
    return rules;
}

linked_hash_set<TransIdx> ITSProblem::getSuccessors(const TransIdx loc) const {
    return graph.getSuccessors(loc);
}

linked_hash_set<TransIdx> ITSProblem::getPredecessors(const TransIdx loc) const {
    return graph.getPredecessors(loc);
}

bool ITSProblem::areAdjacent(const TransIdx first, const TransIdx second) const {
    return graph.hasEdge(first, second);
}

void ITSProblem::removeRule(TransIdx transition) {
    graph.removeNode(transition);
    startAndTargetLocations.erase(transition);
    initialTransitions.erase(transition);
    sinkTransitions.erase(transition);
    rules.erase(*transition);
}

TransIdx ITSProblem::addRule(const Rule &rule, const LocationIdx start, const LocationIdx target, const linked_hash_set<TransIdx> &preds, const linked_hash_set<TransIdx> &succs) {
    const auto idx {&*rules.emplace(rule).first};
    startAndTargetLocations.emplace(idx, std::pair<LocationIdx, LocationIdx>(start, target));
    graph.addNode(idx, preds, succs, start == target);
    if (start == initialLocation) {
        initialTransitions.insert(idx);
    }
    if (target == sink) {
        sinkTransitions.insert(idx);
    }
    return idx;
}

TransIdx ITSProblem::addRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs) {
    const auto start = getLhsLoc(same_preds);
    const auto target = getRhsLoc(same_succs);
    const auto preds = graph.getPredecessors(same_preds);
    const auto succs = graph.getSuccessors(same_succs);
    return addRule(rule, start, target, preds, succs);
}

TransIdx ITSProblem::addLearnedRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs) {
    const auto res = addRule(rule, same_preds, same_succs);
    graph.removeEdge(res, res);
    return res;
}

TransIdx ITSProblem::addQuery(const Bools::Expr guard, const TransIdx same_preds) {
    const auto start = getLhsLoc(same_preds);
    const auto preds = graph.getPredecessors(same_preds);
    return addRule(Rule(guard, Subs::build<Arith>(loc_var, arith::mkConst(sink))), start, sink, preds, {});
}

TransIdx ITSProblem::addRule(const Rule &rule, const LocationIdx start) {
    const auto target_opt = getRhsLoc(rule);
    const auto target = target_opt ? *target_opt : start;
    linked_hash_set<TransIdx> preds, succs;
    for (const auto &e: startAndTargetLocations) {
        if (e.second.first == target) {
            succs.insert(e.first);
        }
        if (e.second.second == start) {
            preds.insert(e.first);
        }
    }
    return addRule(rule, start, target, preds, succs);
}

TransIdx ITSProblem::replaceRule(const TransIdx toReplace, const Rule &replacement) {
    const auto idx {&*rules.emplace(replacement).first};
    startAndTargetLocations.emplace(idx, startAndTargetLocations[toReplace]);
    startAndTargetLocations.erase(toReplace);
    graph.replaceNode(toReplace, idx);
    if (isInitialTransition(toReplace)) {
        initialTransitions.insert(idx);
        initialTransitions.erase(toReplace);
    }
    if (isSinkTransition(toReplace)) {
        sinkTransitions.insert(idx);
        sinkTransitions.erase(toReplace);
    }
    rules.erase(*toReplace);
    return idx;
}

void ITSProblem::removeEdge(const TransIdx from, const TransIdx to) {
    graph.removeEdge(from, to);
}

LocationIdx ITSProblem::addLocation() {
    LocationIdx loc = nextUnusedLocation++;
    locations.insert(loc);
    return loc;
}

LocationIdx ITSProblem::addNamedLocation(std::string name) {
    LocationIdx loc = addLocation();
    locationNames.emplace(loc, name);
    return loc;
}

LocationIdx ITSProblem::getOrAddLocation(const std::string &name) {
    if (const auto res {getLocationIdx(name)}) {
        return *res;
    } else {
        return addNamedLocation(name);
    }
}

linked_hash_set<LocationIdx> ITSProblem::getLocations() const {
    return locations;
}

std::optional<LocationIdx> ITSProblem::getLocationIdx(const std::string &name) const {
    for (const auto &p: locationNames) {
        if (p.second == name) {
            return p.first;
        }
    }
    return {};
}

std::string ITSProblem::getPrintableLocationName(LocationIdx idx) const {
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return (std::stringstream() << "[" << idx << "]").str();
}

VarSet ITSProblem::getVars() const {
    VarSet res;
    for (const auto &r: rules) {
        r.collectVars(res);
    }
    return res;
}

Arith::Expr ITSProblem::getCost(const Rule &rule) const {
    return rule.getUpdate().get<Arith>(cost_var) - cost_var;
}

Arith::Var ITSProblem::getCostVar() const {
    return cost_var;
}

Arith::Var ITSProblem::getLocVar() const {
    return loc_var;
}

std::optional<LocationIdx> ITSProblem::getRhsLoc(const Rule &rule) const {
    const auto res {rule.getUpdate().get<Arith>(loc_var)};
    const auto r {res->isInt()};
    if (r) {
        return r->convert_to<LocationIdx>();
    } else {
        return {};
    }
}

LocationIdx ITSProblem::getLhsLoc(const TransIdx idx) const {
    return startAndTargetLocations[idx].first;
}

LocationIdx ITSProblem::getRhsLoc(const TransIdx idx) const {
    return startAndTargetLocations[idx].second;
}

const linked_hash_set<TransIdx>& ITSProblem::getInitialTransitions() const {
    return initialTransitions;
}

const linked_hash_set<TransIdx>& ITSProblem::getSinkTransitions() const {
    return sinkTransitions;
}

bool ITSProblem::isSimpleLoop(const TransIdx idx) const {
    return graph.hasEdge(idx, idx);
}

bool ITSProblem::isSinkTransition(const TransIdx idx) const {
    return sinkTransitions.contains(idx);
}

bool ITSProblem::isInitialTransition(const TransIdx idx) const {
    return initialTransitions.contains(idx);
}

const ITSProblem::DG& ITSProblem::getDependencyGraph() const {
    return graph;
}

linked_hash_set<ITSProblem::DG::Edge> ITSProblem::refineDependencyGraph(const std::function<bool(const TransIdx, const TransIdx)> &is_edge) {
    return graph.refine(is_edge);
}

size_t ITSProblem::size() const {
    return graph.size();
}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its) {
    s << "Start location: ";
    s << its.getPrintableLocationName(its.getInitialLocation()) << "\n\n";
    if (!its.getLocations().empty()) {
        s << "Location map:" << std::endl;
        for (const auto p: its.getLocations()) {
            s << its.getPrintableLocationName(p);
            s << " -> " << p << std::endl;
        }
    }
    s << "\n\nRules:\n";
    if (its.isEmpty()) {
        s << "  <empty>\n";
    } else {
        for (const auto &idx : its.getAllTransitions()) {
            s << std::setw(4);
            s << idx;
            s << std::endl;
        }
    }
    if (Config::Output::PrintDependencyGraph) {
        s << "\nDependency graph:\n";
        s << its.getDependencyGraph() << std::endl;
    }
    return s;
}
