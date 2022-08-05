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

#include "chain.hpp"
#include "preprocess.hpp"


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
    Proof proof;
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
                // If we allow self loops at loc, then chained rules may still lead to loc,
                // e.g. if h -> f and f -> f,g are chained to h -> f,g (where f is loc).
                // Since we want to eliminate loc, we remove all rhss leading to loc (e.g. h -> g).
                if (allowSelfloops) {
                    optRule = optRule.get().stripRhsLocation(loc);
                    assert(optRule); // this only happens for simple loops, which we disallow
                }

                proof.chainingProof(inRule, outRule, *optRule, its);
                its.addRule(*optRule);


            } else {
                wasChainedWithAll = false;
            }
        }

        if (keepUnchainable && !wasChainedWithAll) {
            // Only keep the rule if it might give non-trivial complexity
            if ((Config::Analysis::nonTermination() && inRule.getCost().isNontermSymbol()) || (Config::Analysis::complexity() && inRule.getCost().toComplexity() > Complexity::Const)) {
                keepRules.insert(in);
            }
        }
    }

    // Backup all incoming transitions which could not be chained with any outgoing one
    if (keepUnchainable && !keepRules.empty()) {
        LocationIdx dummyLoc = its.addLocation();
        for (TransIdx trans : keepRules) {
            const Rule oldRule = its.getRule(trans);
            auto newRule = oldRule.stripRhsLocation(loc);
            if (newRule) {
                // In case of nonlinear rules, we can simply delete all rhss leading to loc, but keep the other ones
                its.addRule(newRule.get());
                proof.ruleTransformationProof(oldRule, "partial deletion", newRule.get(), its);
            } else {
                // If all rhss lead to loc (for instance if the rule is linear), we add a new dummy rhs
                const Rule &dummyRule = oldRule.replaceRhssBySink(dummyLoc);
                its.addRule(dummyRule);
                proof.ruleTransformationProof(oldRule, "partial deletion", dummyRule, its);
            }
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


ResultViaSideEffects Chaining::chainTreePaths(ITSProblem &its) {
    auto implementation = [](ITSProblem &its, ResultViaSideEffects &proof, LocationIdx node) {
        bool changed = false;
        for (LocationIdx succ : its.getSuccessorLocations(node)) {

            // Avoid chaining over the initial node (it would then be removed) and skip self-loops
            if (its.isInitialLocation(succ) || succ == node) {
                continue;
            }

            // if succ has several predecessors, try contracting the rest first (succ might be a loop head)
            if (its.getPredecessorLocations(succ).size() > 1) {
                continue;
            }

            // Chain transitions from node to succ with all transitions from succ.
            if (its.hasTransitionsFrom(succ)) {
                proof.concat(eliminateLocationByChaining(its, succ, true));
                proof.succeed();
                changed = true;
            }
        }
        return changed;
    };

    // To avoid rule explosion, the implementation is only called once per node.
    // Example: path f -> g -> h -> u -> ... When called on f, g is eliminated.
    // We then call the implementation on h (f's new child), which may eliminate u.
    // This avoids the exponential blowup, so we can first accelerate rules or
    // prune rules before calling this method again.
    ResultViaSideEffects proof;
    callOnEachNode(its, proof, implementation, false);
    return proof;
}


/**
 * Implementation of eliminateALocation
 */
static ResultViaSideEffects eliminateALocationImpl(ITSProblem &its, LocationIdx node, set<LocationIdx> &visited, string &eliminated) {
    ResultViaSideEffects proof;
    if (!visited.insert(node).second) {
        return proof;
    }

    bool hasIncoming = its.hasTransitionsTo(node);
    bool hasOutgoing = its.hasTransitionsFrom(node);
    bool hasSimpleLoop = !its.getSimpleLoopsAt(node).empty();

    // If we cannot eliminate node, continue with its children (DFS traversal)
    if (hasSimpleLoop || its.isInitialLocation(node) || !hasIncoming || !hasOutgoing) {
        for (LocationIdx succ : its.getSuccessorLocations(node)) {
            const ResultViaSideEffects proof = eliminateALocationImpl(its, succ, visited, eliminated);
            if (proof) {
                return proof;
            }
        }
        return proof;
    }

    // Otherwise, we can eliminate node
    eliminated = its.getPrintableLocationName(node);
    proof.concat(eliminateLocationByChaining(its, node, true, true));
    proof.succeed();
    return proof;
}


ResultViaSideEffects Chaining::eliminateALocation(ITSProblem &its, string &eliminatedLocation) {
    set<LocationIdx> visited;
    return eliminateALocationImpl(its, its.getInitialLocation(), visited, eliminatedLocation);
}


// ###################################
// ##  Chaining after Acceleration  ##
// ###################################

ResultViaSideEffects Chaining::chainAcceleratedRules(ITSProblem &its, const set<TransIdx> &acceleratedRules) {
    ResultViaSideEffects proof;
    if (acceleratedRules.empty()) return proof;
    set<TransIdx> successfullyChained;

    // Find all lhs locations of accelerated rules, so we can iterate over them.
    // If we would iterate over acceleratedRules directly, we might consider an lhs location twice,
    // so we would use chained rules from the first visit as incoming rules for the second visit.
    set<LocationIdx> nodes;
    for (TransIdx accel : acceleratedRules) {
        nodes.insert(its.getRule(accel).getLhsLoc());
    }

    for (LocationIdx node : nodes) {
        // We only query the incoming transitions once, before adding new rules starting at node
        set<TransIdx> incomingTransitions = its.getTransitionsTo(node);

        std::set<TransIdx> deleted;
        for (TransIdx accel : its.getTransitionsFrom(node)) {
            // Only chain accelerated rules
            if (acceleratedRules.count(accel) == 0) continue;
            const Rule accelRule = its.getRule(accel);

            deleted.insert(accel);
            std::vector<Rule> replacement;

            for (TransIdx incoming : incomingTransitions) {
                // Do not chain with another accelerated rule
                if (acceleratedRules.count(incoming) > 0) continue;

                // Do not chain with incoming loops that are themselves self-loops at node
                // (no matter if they are simple or not)
                const Rule incomingRule = its.getRule(incoming);
                if (incomingRule.getLhsLoc() == node) continue;

                auto optRule = Chaining::chainRules(its, incomingRule, accelRule);
                if (optRule) {
                    // Simplify the rule (can help to eliminate temporary variables of the metering function)
                    proof.chainingProof(incomingRule, accelRule, optRule.get(), its);
                    Result<Rule> simplified = Preprocess::simplifyRule(its, optRule.get(), true);
                    Rule newRule = simplified ? simplified.get() : optRule.get();
                    if (simplified) {
                        proof.ruleTransformationProof(*optRule, "simplification", newRule, its);
                        proof.storeSubProof(simplified.getProof());
                    }

                    // Add the chained rule
                    replacement.push_back(newRule);
                    successfullyChained.insert(incoming);
                }
            }
            its.replaceRules({accel}, replacement);
            proof.succeed();
        }
        proof.deletionProof(deleted);
    }

    return proof;
}
