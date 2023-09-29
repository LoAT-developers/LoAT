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
#include "linearsolver.hpp"
#include "dependencygraph.hpp"
#include "types.hpp"

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

    const std::set<Rule>& getAllTransitions() const;
    std::set<TransIdx> getSuccessors(const TransIdx loc) const;
    std::set<TransIdx> getPredecessors(const TransIdx loc) const;
    bool areAdjacent(const TransIdx first, const TransIdx second) const;

    // Mutation of Rules
    void removeRule(TransIdx transition);

private:

    TransIdx addRule(const Rule &rule, const LocationIdx start, const LocationIdx target, const std::set<TransIdx> &preds, const std::set<TransIdx> &succs);

public:

    TransIdx addRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs);
    TransIdx addLearnedRule(const Rule &rule, const TransIdx same_preds, const TransIdx same_succs);
    TransIdx addRule(const Rule &rule, const LocationIdx start);
    TransIdx addQuery(const BoolExpr &guard, const TransIdx same_preds);
    TransIdx replaceRule(const TransIdx toReplace, const Rule &replacement);
    void removeEdge(const TransIdx from, const TransIdx to);

    // Mutation for Locations
    LocationIdx addLocation();
    LocationIdx addNamedLocation(std::string name);

    // Required for printing (see ITSExport)
    std::set<LocationIdx> getLocations() const;
    const std::map<LocationIdx, std::string>& getLocationNames() const;
    std::string getPrintableLocationName(LocationIdx idx) const; // returns "[idx]" if there is no name

    VarSet getVars() const;

    // Print the ITSProblem in a simple, but user-friendly format
    void print(std::ostream &s) const;

    Expr getCost(const Rule &rule) const;

    NumVar getCostVar() const;

    std::optional<LocationIdx> getRhsLoc(const Rule &rule) const;

    LocationIdx getLhsLoc(const TransIdx idx) const;

    LocationIdx getRhsLoc(const TransIdx idx) const;

    const std::set<TransIdx>& getInitialTransitions() const;

    const std::set<TransIdx>& getSinkTransitions() const;

    bool isSimpleLoop(const TransIdx idx) const;

    bool isSinkTransition(const TransIdx idx) const;

    bool isInitialTransition(const TransIdx idx) const;

    const DG& getDependencyGraph() const;

    std::set<DG::Edge> refineDependencyGraph();

    std::set<DG::Edge> refineDependencyGraph(const Implicant &idx);

    size_t size() const;

    // TODO: these attributes should probably not be "so" public. They should only be initialized
    // once after parsing and should not be mutated during analysis. But because the ITS instance is constructed 
    // incrementally, we can't pass these values into the constructor and having public getters+setters
    // is no different from making the attributes public directly.    
    std::vector<NumVar> numProgVars;
    std::vector<BoolVar> boolProgVars;
    const std::vector<Var> getProgVars() const;

    std::list<Clause> nonLinearCHCs;

    void addClause(const Clause &chc);

    const Clause clauseFrom(TransIdx trans_idx) const;

protected:

    DG graph;
    std::set<Rule> rules;
    std::set<LocationIdx> locations;
    std::map<LocationIdx, std::string> locationNames;
    std::map<TransIdx, std::pair<LocationIdx, LocationIdx>> startAndTargetLocations;
    std::set<TransIdx> initialTransitions;
    std::set<TransIdx> sinkTransitions;
    LocationIdx nextUnusedLocation {0};
    LocationIdx initialLocation;
    LocationIdx sink {addNamedLocation("LoAT_sink")};
    NumVar cost {NumVar::nextProgVar()};

};

using ITSPtr = std::shared_ptr<ITSProblem>;
