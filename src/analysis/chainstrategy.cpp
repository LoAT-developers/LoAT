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

#include "chainstrategy.hpp"
#include "complexity.hpp"
#include "chain.hpp"

using namespace std;


// ############################
// ##  Location Elimination  ##
// ############################

/**
 * Eliminates the given location by chaining every incoming with every outgoing transition.
 *
 * @note The given location must not have any self-loops (simple or non-simple),
 * unless allowSelfloops is true (but even then, it must not have simple loops!).
 *
 * If keepUnchainable is true and some incoming transition T cannot be chained with at least one outgoing transition,
 * then a new dummy location is inserted and T is kept, connecting its its old source to the new dummy location.
 * However, this is only done if the cost of T is more than constant.
 *
 * The old location is removed, together with all old transitions. So if an outgoing transition cannot be chained
 * with any incoming transition, it will simply be removed.
 */
static Proof eliminateLocationByChaining(ITSProblem &its, LocationIdx loc,
                                        bool keepUnchainable, bool allowSelfloops = false)
{
    set<TransIdx> keepRules;
    ITSProof proof;
    proof.headline("Eliminating location " + its.getPrintableLocationName(loc) + " by chaining:");

    // Chain all pairs of in- and outgoing rules
    for (TransIdx in : its.getTransitionsTo(loc)) {
        bool wasChainedWithAll = true;
        const Rule inRule = its.getRule(in);

        // We usually require that loc doesn't have any self-loops (since we would destroy the self-loop by chaining).
        // E.g. chaining f -> g, g -> g would result in f -> g without the self-loop.
        assert(allowSelfloops || inRule.getLhsLoc() != loc);

        // If we allow self-loops, we ignore them for incoming rules,
        // since the resulting chained rule would in the end be deleted (together with loc) anyway.
        if (inRule.getLhsLoc() == loc) continue;

        for (TransIdx out : its.getTransitionsFrom(loc)) {
            const Rule outRule = its.getRule(out);
            auto optRule = Chaining::chainRules(its, inRule, outRule);
            if (optRule) {

                proof.chainingProof(inRule, outRule, *optRule, its);
                its.addRule(*optRule);


            } else {
                wasChainedWithAll = false;
            }
        }

        if (keepUnchainable && !wasChainedWithAll) {
            // Only keep the rule if it might give non-trivial complexity
            bool keep;
            if (Config::Analysis::complexity()) {
                keep = toComplexity(inRule.getCost()) > Complexity::Const;
            } else {
                keep = inRule.getCost().isNontermSymbol();
            }
            if (keep) {
                keepRules.insert(in);
            }
        }
    }

    // Backup all incoming transitions which could not be chained with any outgoing one
    if (keepUnchainable && !keepRules.empty()) {
        LocationIdx dummyLoc = its.addLocation();
        for (TransIdx trans : keepRules) {
            const Rule oldRule = its.getRule(trans);
            // If all rhss lead to loc (for instance if the rule is linear), we add a new dummy rhs
            const Rule &dummyRule = oldRule.replaceRhsBySink(dummyLoc);
            its.addRule(dummyRule);
            proof.ruleTransformationProof(oldRule, "partial deletion", dummyRule, its);
        }
    }

    // Remove loc and all incoming/outgoing rules.
    // Note that all rules have already been chained (or backed up), so removing these rules is ok.
    const std::set<TransIdx> &removed = its.removeLocationAndRules(loc);
    proof.deletionProof(removed);
    return proof;
}


// ##############################
// ##  Helpers for Strategies  ##
// ##############################

/**
 * Implementation of callRepeatedlyOnEachNode
 */
template <typename F>
static bool callOnEachNodeImpl(ITSProblem &its, ResultViaSideEffects &proof, F function, LocationIdx node, bool repeat, set<LocationIdx> &visited) {
    if (!visited.insert(node).second) {
        return false;
    }

    bool changedOverall = false;
    bool changed;

    // Call the function repeatedly, until it returns false
    do {
        changed = function(its, proof, node);
        changedOverall = changedOverall || changed;
    } while (repeat && changed);

    // Continue with the successors of the current node (DFS traversal)
    for (LocationIdx next : its.getSuccessorLocations(node)) {
        bool changed = callOnEachNodeImpl(its, proof, function, next, repeat, visited);
        changedOverall = changedOverall || changed;
    }

    return changedOverall;
}


/**
 * A dfs traversal through the its's graph, starting in the initial location,
 * calling the given function for each node.
 *
 * The given function must return a boolean value (a "changed" flag).
 * If repeat is true, the function is called several times on every
 * visited node, as long as it returns true. If it returns false
 * (or if repeat is false), the DFS continues with the next node.
 * The function is allowed to modify the ITS (and thus the graph).
 *
 * The given set `visited` should be empty.
 *
 * @returns true iff at least one call of the given function returned true.
 */
template <typename F>
static bool callOnEachNode(ITSProblem &its, ResultViaSideEffects &proof, F function, bool repeat) {
    set<LocationIdx> visited;
    return callOnEachNodeImpl(its, proof, function, its.getInitialLocation(), repeat, visited);
}


/**
 * Checks whether the given node lies on a linear path (and is not an endpoint of the path).
 * See chainLinearPaths for an explanation.
 */
static bool isOnLinearPath(ITSProblem &its, LocationIdx node) {
    // If node is a leaf, we return false (we cannot chain over leafs)
    if (its.getTransitionsFrom(node).size() != 1) {
        return false;
    }

    // The node must not have two (or zero) predecessors ...
    set<LocationIdx> preds = its.getPredecessorLocations(node);
    if (preds.size() != 1) {
        return false;
    }

    // ... it must not have a self-loop ...
    if (preds.count(node) > 0) {
        return false;
    }

    // ... or two (or zero) incoming edges (possibly from the same predecessor)
    LocationIdx pred = *preds.begin();
    return its.getTransitionsFromTo(pred, node).size() == 1;
}


// ###########################
// ##  Chaining Strategies  ##
// ###########################

ResultViaSideEffects Chaining::chainLinearPaths(ITSProblem &its) {
    auto implementation = [](ITSProblem &its, ResultViaSideEffects &proof, LocationIdx node) {
        bool changed = false;
        for (LocationIdx succ : its.getSuccessorLocations(node)) {

            // Avoid chaining over the initial node (it would then be removed) and skip self-loops
            if (its.isInitialLocation(succ) || succ == node) {
                continue;
            }

            // Only apply chaining if succ has exactly one in- and one outgoing transition
            if (isOnLinearPath(its, succ)) {
                changed = true;
                proof.concat(eliminateLocationByChaining(its, succ, true));
                proof.succeed();
            }
        }
        return changed;
    };
    ResultViaSideEffects proof;
    callOnEachNode(its, proof, implementation, true);
    return proof;
}
