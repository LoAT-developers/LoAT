/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "itsproblem.hpp"
#include "export.hpp"

using namespace std;

ITSProblem::ITSProblem(VariableManager &&varMan) : VariableManager(varMan) {}

bool ITSProblem::isEmpty() const {
    std::lock_guard guard(mutex);
    return rules.empty();
}

bool ITSProblem::isLinear() const {
    std::lock_guard guard(mutex);
    for (const auto &it : rules) {
        if (!it.second.isLinear()) {
            return false;
        }
    }
    return true;
}

LocationIdx ITSProblem::getInitialLocation() const {
    std::lock_guard guard(mutex);
    return initialLocation;
}

option<LocationIdx> ITSProblem::getSink() const {
    std::lock_guard guard(mutex);
    return sink;
}

bool ITSProblem::isInitialLocation(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return loc == initialLocation;
}

void ITSProblem::setInitialLocation(LocationIdx loc) {
    std::lock_guard guard(mutex);
    initialLocation = loc;
}

void ITSProblem::setSink(LocationIdx loc) {
    std::lock_guard guard(mutex);
    sink = loc;
}

bool ITSProblem::hasRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    return rules.find(transition) != rules.end();
}

const Rule ITSProblem::getRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    assert(rules.count(transition) > 0);
    return rules.at(transition);
}

void ITSProblem::lock() {
    mutex.lock();
}

void ITSProblem::unlock() {
    mutex.unlock();
}

LinearRule ITSProblem::getLinearRule(TransIdx transition) const {
    std::lock_guard guard(mutex);
    return rules.at(transition).toLinear();
}

const std::set<LocationIdx> ITSProblem::getTransitionTargets(TransIdx idx) const {
    std::lock_guard guard(mutex);
    return graph.getTransTargets(idx);
}

std::set<TransIdx> ITSProblem::getTransitionsFrom(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getTransFrom(loc);
}

std::vector<TransIdx> ITSProblem::getTransitionsFromTo(LocationIdx from, LocationIdx to) const {
    std::lock_guard guard(mutex);
    return graph.getTransFromTo(from, to);
}

std::set<TransIdx> ITSProblem::getTransitionsTo(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getTransTo(loc);
}

std::vector<TransIdx> ITSProblem::getAllTransitions() const {
    std::lock_guard guard(mutex);
    return graph.getAllTrans();
}

bool ITSProblem::hasTransitionsFrom(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.hasTransFrom(loc);
}

bool ITSProblem::hasTransitionsFromTo(LocationIdx from, LocationIdx to) const {
    std::lock_guard guard(mutex);
    return graph.hasTransFromTo(from, to);
}

bool ITSProblem::hasTransitionsTo(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.hasTransTo(loc);
}

std::vector<TransIdx> ITSProblem::getSimpleLoopsAt(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    vector<TransIdx> res;
    for (TransIdx rule : getTransitionsFromTo(loc, loc)) {
        if (getRule(rule).isSimpleLoop()) {
            res.push_back(rule);
        }
    }
    return res;
}

std::set<LocationIdx> ITSProblem::getSuccessorLocations(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getSuccessors(loc);
}

std::set<LocationIdx> ITSProblem::getPredecessorLocations(LocationIdx loc) const {
    std::lock_guard guard(mutex);
    return graph.getPredecessors(loc);
}

void ITSProblem::removeRule(TransIdx transition) {
    std::lock_guard guard(mutex);
    graph.removeTrans(transition);
    auto it = rules.find(transition);
    if (it != rules.end()) {
        rulesBwd.erase(it->second);
    }
    rules.erase(transition);
}

option<TransIdx> ITSProblem::addRule(Rule rule) {
    std::lock_guard guard(mutex);
    auto it = rulesBwd.find(rule);
    if (it != rulesBwd.end()) {
        return {};
    }
    // gather target locations
    set<LocationIdx> rhsLocs;
    for (auto it = rule.rhsBegin(); it != rule.rhsEnd(); ++it) {
        rhsLocs.insert(it->getLoc());
    }

    // add transition and store mapping to rule
    TransIdx idx = graph.addTrans(rule.getLhsLoc(), rhsLocs);
    rules.emplace(idx, rule);
    rulesBwd.emplace(rule, idx);
    return idx;
}

std::vector<TransIdx> ITSProblem::replaceRules(const std::vector<TransIdx> &toReplace, const std::vector<Rule> replacement) {
    std::lock_guard guard(mutex);
    std::vector<TransIdx> keep;
    std::vector<TransIdx> result;
    for (const Rule& r: replacement) {
        option<TransIdx> added = addRule(r);
        if (added) {
            result.push_back(added.get());
        } else {
            keep.push_back(rulesBwd.find(r)->second);
        }
    }
    for (TransIdx idx: toReplace) {
        if (std::find(keep.begin(), keep.end(), idx) == keep.end()) {
            removeRule(idx);
        }
    }
    return result;
}

LocationIdx ITSProblem::addLocation() {
    std::lock_guard guard(mutex);
    LocationIdx loc = nextUnusedLocation++;
    locations.insert(loc);
    return loc;
}

LocationIdx ITSProblem::addNamedLocation(std::string name) {
    std::lock_guard guard(mutex);
    LocationIdx loc = addLocation();
    locationNames.emplace(loc, name);
    return loc;
}

set<LocationIdx> ITSProblem::getLocations() const {
    std::lock_guard guard(mutex);
    return locations;
}

option<string> ITSProblem::getLocationName(LocationIdx idx) const {
    std::lock_guard guard(mutex);
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return {};
}

string ITSProblem::getPrintableLocationName(LocationIdx idx) const {
    std::lock_guard guard(mutex);
    auto it = locationNames.find(idx);
    if (it != locationNames.end()) {
        return it->second;
    }
    return "[" + to_string(idx) + "]";
}


void ITSProblem::removeOnlyLocation(LocationIdx loc) {
    std::lock_guard guard(mutex);
    // The initial location must not be removed
    assert(loc != initialLocation);

    locations.erase(loc);
    locationNames.erase(loc);
    set<TransIdx> removed = graph.removeNode(loc);

    // Check that all rules from/to loc were removed before
    assert(removed.empty());
}

std::set<TransIdx> ITSProblem::removeLocationAndRules(LocationIdx loc) {
    std::lock_guard guard(mutex);
    // The initial location must not be removed
    assert(loc != initialLocation);

    locations.erase(loc);
    locationNames.erase(loc);
    set<TransIdx> removed = graph.removeNode(loc);

    // Also remove all rules from/to loc
    for (TransIdx t : removed) {
        removeRule(t);
    }
    return removed;
}

void ITSProblem::print(std::ostream &s) const {
    std::lock_guard guard(mutex);
    ITSExport::printDebug(*this, s);
}

