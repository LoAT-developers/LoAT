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

#include "rule.hpp"
#include "dependencygraph.hpp"
#include "types.hpp"
#include "set.hpp"

#include <optional>

class ITSProblem {

public:

    using DG = DependencyGraph<TransIdx>;

    // Creates an empty ITS problem. The initialLocation is set to 0
    ITSProblem() = default;
    ITSProblem(const ITSProblem&) = delete;

    // True iff there are no rules
    bool isEmpty() const;

    LocationIdx getInitialLocation() const;
    bool isInitialLocation(LocationIdx loc) const;
    void setInitialLocation(LocationIdx loc);
    LocationIdx getSink() const;
    std::optional<LocationIdx> getLocationIdx(const std::string &name) const;

    const linked_hash_set<Rule>& getAllTransitions() const;
    linked_hash_set<TransIdx> getSuccessors(const TransIdx loc) const;
    linked_hash_set<TransIdx> getPredecessors(const TransIdx loc) const;
    bool areAdjacent(const TransIdx first, const TransIdx second) const;

    // Mutation of Rules
    void removeRule(TransIdx transition);

private:

    TransIdx addRule(const Rule &rule, const LocationIdx start, const LocationIdx target, const linked_hash_set<TransIdx> &preds, const linked_hash_set<TransIdx> &succs);

public:

    TransIdx addRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs);
    TransIdx addLearnedRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs);
    TransIdx addRule(const Rule &rule, const LocationIdx start);
    TransIdx addQuery(const BoolExpr guard, const TransIdx same_preds);
    TransIdx replaceRule(const TransIdx toReplace, const Rule &replacement);
    void removeEdge(const TransIdx from, const TransIdx to);

    // Mutation for Locations
    LocationIdx addLocation();
    LocationIdx addNamedLocation(std::string name);

    // Required for printing (see ITSExport)
    linked_hash_set<LocationIdx> getLocations() const;
    std::string getPrintableLocationName(LocationIdx idx) const; // returns "[idx]" if there is no name

    VarSet getVars() const;

    // Print the ITSProblem in a simple, but user-friendly format
    void print(std::ostream &s) const;

    IntTheory::Expression getCost(const Rule &rule) const;

    IntTheory::Var getCostVar() const;

    std::optional<LocationIdx> getRhsLoc(const Rule &rule) const;

    LocationIdx getLhsLoc(const TransIdx idx) const;

    LocationIdx getRhsLoc(const TransIdx idx) const;

    const linked_hash_set<TransIdx>& getInitialTransitions() const;

    const linked_hash_set<TransIdx>& getSinkTransitions() const;

    bool isSimpleLoop(const TransIdx idx) const;

    bool isSinkTransition(const TransIdx idx) const;

    bool isInitialTransition(const TransIdx idx) const;

    const DG& getDependencyGraph() const;

    linked_hash_set<DG::Edge> refineDependencyGraph();

    size_t size() const;

protected:

    DG graph {};
    linked_hash_set<Rule> rules {};
    linked_hash_set<LocationIdx> locations {};
    std::unordered_map<LocationIdx, std::string> locationNames {};
    linked_hash_map<TransIdx, std::pair<LocationIdx, LocationIdx>> startAndTargetLocations {};
    linked_hash_set<TransIdx> initialTransitions {};
    linked_hash_set<TransIdx> sinkTransitions {};
    LocationIdx nextUnusedLocation {0};
    LocationIdx initialLocation {0};
    LocationIdx sink {addNamedLocation("LoAT_sink")};
    IntTheory::Var cost {NumVar::nextProgVar()};

};

using ITSPtr = std::shared_ptr<ITSProblem>;
