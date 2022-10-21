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

#pragma once

#include "option.hpp"
#include "rule.hpp"
#include "variablemanager.hpp"
#include "hypergraph.hpp"

#include <unordered_map>


class ITSProblem : public VariableManager {
public:
    // Creates an empty ITS problem. The initialLocation is set to 0
    ITSProblem() = default;

    // Creates an empty ITS problem with the given variables
    explicit ITSProblem(VariableManager &&varMan);

    // True iff there are no rules
    bool isEmpty() const;

    // True iff all rules are linear
    bool isLinear() const;

    LocationIdx getInitialLocation() const;
    bool isInitialLocation(LocationIdx loc) const;
    void setInitialLocation(LocationIdx loc);
    option<LocationIdx> getSink() const;
    void setSink(LocationIdx loc);
    option<LocationIdx> getLocationIdx(const std::string &name) const;

    // query the rule associated with a given transition
    bool hasRule(TransIdx transition) const;
    const Rule getRule(TransIdx transition) const;

    // the rule associated with the given index must be linear!
    LinearRule getLinearRule(TransIdx transition) const;

    // returns the destinations of the given transition
    const std::set<LocationIdx> getTransitionTargets(TransIdx idx) const;

    // query transitions of the graph
    std::set<TransIdx> getTransitionsFrom(LocationIdx loc) const;
    std::vector<TransIdx> getTransitionsFromTo(LocationIdx from, LocationIdx to) const;
    std::set<TransIdx> getTransitionsTo(LocationIdx loc) const;

    std::vector<TransIdx> getAllTransitions() const;

    bool hasTransitionsFrom(LocationIdx loc) const;
    bool hasTransitionsFromTo(LocationIdx from, LocationIdx to) const;
    bool hasTransitionsTo(LocationIdx loc) const;

    // returns transitions from loc to loc for which isSimpleLoops() holds
    std::vector<TransIdx> getSimpleLoopsAt(LocationIdx loc) const;

    // query nodes of the graph
    std::set<LocationIdx> getSuccessorLocations(LocationIdx loc) const;
    std::set<LocationIdx> getPredecessorLocations(LocationIdx loc) const;

    // Mutation of Rules
    void removeRule(TransIdx transition);
    option<TransIdx> addRule(Rule rule);
    std::vector<TransIdx> replaceRules(const std::vector<TransIdx> &toReplace, const std::vector<Rule> replacement);

    // Mutation for Locations
    LocationIdx addLocation();
    LocationIdx addNamedLocation(std::string name);

    // Required for printing (see ITSExport)
    std::set<LocationIdx> getLocations() const;
    option<std::string> getLocationName(LocationIdx idx) const;
    std::string getPrintableLocationName(LocationIdx idx) const; // returns "[idx]" if there is no name

    VarSet getVars() const;

    // Removes a location, but does _not_ care about rules.
    // Rules from/to this location must be removed before calling this!
    void removeOnlyLocation(LocationIdx loc);

    // Removes a location and all rules that visit loc
    std::set<TransIdx> removeLocationAndRules(LocationIdx loc);

    HyperGraph::SCCs sccs() const;

    // Print the ITSProblem in a simple, but user-friendly format
    void print(std::ostream &s) const;

    static void lock();
    static void unlock();

protected:

    // Main structure is the graph, where (hyper-)transitions are annotated with a RuleIdx.
    HyperGraph graph;

    // Collection of all rules, identified by the corresponding transitions in the graph.
    // The map allows to efficiently add/delete rules.
    std::map<TransIdx, Rule> rules;
    Rule::ApproxMap<TransIdx> rulesBwd;

    // the set of all locations (locations are just arbitrary numbers to allow simple addition/deletion)
    std::set<LocationIdx> locations;

    // the initial location
    LocationIdx initialLocation = 0;
    option<LocationIdx> sink;

    // the next free location index
    LocationIdx nextUnusedLocation = 0;

    // only for output, remembers the original location names
    std::map<LocationIdx, std::string> locationNames;

};
