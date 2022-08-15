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

#include "prune.hpp"

#include "../config.hpp"
#include "../its/itsproblem.hpp"
#include "../expr/boolexpr.hpp"
#include "../smt/smt.hpp"
#include "../asymptotic/asymptoticbound.hpp"
#include "../its/export.hpp"

#include <queue>


using namespace std;

bool Pruning::pruneParallelRules(ITSProblem &its) {
    // To compare rules, we store a tuple of the rule's index, its complexity and the number of inftyVars
    // (see ComplexityResult for the latter). We first compare the complexity, then the number of inftyVars.
    typedef tuple<TransIdx,Complexity,int> TransCpx;
    auto comp = [](TransCpx a, TransCpx b) { return get<1>(a) < get<1>(b) || (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b)); };

    // We use a priority queue with the aforementioned comparison of rules (and vector as underlying container).
    typedef priority_queue<TransCpx, vector<TransCpx>, decltype(comp)> PriorityQueue;

    bool changed = false;
    for (LocationIdx node : its.getLocations()) {
        for (LocationIdx pre : its.getPredecessorLocations(node)) {
            // First remove duplicates (this is rather cheap)
            removeDuplicateRules(its, its.getTransitionsFromTo(pre, node));

            // Then prune rules by only keeping the "best" ones (heuristically)
            const vector<TransIdx> &parallel = its.getTransitionsFromTo(pre, node);

            if (parallel.size() > Config::Prune::MaxParallelRules) {
                PriorityQueue queue(comp);
                set<TransIdx> keep;

                for (unsigned int i=0; i < parallel.size(); ++i) {
                    // alternating iteration (idx=0,n-1,1,n-2,...) that might avoid choosing similar edges
                    unsigned long idx = (i % 2 == 0) ? i/2 : parallel.size()-1-i/2;

                    TransIdx ruleIdx = parallel[idx];
                    const Rule rule = its.getRule(parallel[idx]);

                    // compute the complexity (real check using asymptotic bounds) and store in priority queue
                    Complexity cpx;
                    size_t inftyVars;
                    if (Config::Analysis::nonTermination()) {
                        cpx = Complexity::Unknown;
                        inftyVars = 0;
                    } else {
                        const auto& res = AsymptoticBound::determineComplexityViaSMT(
                                    its,
                                    rule.getGuard(),
                                    rule.getCost());
                        cpx = res.cpx;
                        inftyVars = res.inftyVars;
                    }
                    queue.push(make_tuple(ruleIdx, cpx, inftyVars));
                }

                // Keep only the top elements of the queue
                for (unsigned int i=0; i < Config::Prune::MaxParallelRules; ++i) {
                    keep.insert(get<0>(queue.top()));
                    queue.pop();
                }

                // Check if there is an dummy rule (if there is, we want to keep an empty rule)
                bool hasDummy = false;
                for (TransIdx rule : parallel) {
                    if (its.getRule(rule).isDummyRule()) {
                        hasDummy = true;
                        break;
                    }
                }

                // Remove all rules except for the ones in keep, add a dummy rule if there was one before
                // Note that for nonlinear rules, we only remove edges (so only single rhss), not the entire rule
                std::vector<TransIdx> toRemove;
                std::vector<Rule> toAdd;
                for (TransIdx rule : parallel) {
                    const Rule r = its.getRule(rule);
                    if ((Config::Analysis::complexity() || !r.getCost().isNontermSymbol()) && keep.count(rule) == 0) {
                        toRemove.push_back(rule);
                        auto optRule = r.stripRhsLocation(node);
                        if (optRule) {
                            toAdd.push_back(optRule.get());
                        }
                    }
                }
                if (hasDummy) {
                    toAdd.push_back(LinearRule::dummyRule(pre, node));
                }
                its.replaceRules(toRemove, toAdd);

                changed = true;
            }
        }
    }
    return changed;
}


/**
 * Helper for removeLeafsAndUnreachable.
 * Performs a DFS and removes rules to leafs with constant complexity.
 * Returns true iff the ITS was modified.
 */
static bool removeIrrelevantLeafs(ITSProblem &its, LocationIdx node, set<LocationIdx> &visited) {
    if (!visited.insert(node).second) return false; // already present

    // for brevity only
    auto isLeaf = [&its](LocationIdx loc){ return !its.hasTransitionsFrom(loc); };
    auto isLeafRhs = [&](const RuleRhs &rhs){ return isLeaf(rhs.getLoc()); };

    bool changed = false;
    for (LocationIdx next : its.getSuccessorLocations(node)) {
        // recurse first
        changed = removeIrrelevantLeafs(its, next, visited) || changed;

        // If next is (now) a leaf, rules leading to next are candidates for removal
        if (isLeaf(next)) {
            for (TransIdx ruleIdx : its.getTransitionsFromTo(node, next)) {
                const Rule rule = its.getRule(ruleIdx);

                // only remove irrelevant rules
                const Complexity &c = rule.getCost().toComplexity();
                bool remove;
                if (Config::Analysis::complexity()) {
                    remove = c == Complexity::Const;
                } else {
                    remove = c != Complexity::Nonterm;
                }

                // only remove rules where _all_ right-hand sides lead to leafs
                if (remove && (rule.rhsCount() == 1 || std::all_of(rule.rhsBegin(), rule.rhsEnd(), isLeafRhs))) {
                    its.removeRule(ruleIdx);
                    changed = true;
                }
            }

            // If we removed all rules to the leaf, we can safely delete it
            if (!its.hasTransitionsTo(next)) {
                its.removeOnlyLocation(next);
            }
        }
    }

    return changed;
}


bool Pruning::removeLeafsAndUnreachable(ITSProblem &its) {
    set<LocationIdx> visited;

    // Remove rules to leafs if they do not give nontrivial complexity
    bool changed = removeIrrelevantLeafs(its, its.getInitialLocation(), visited);

    // Remove all nodes that have not been reached in the DFS traversal
    for (LocationIdx node : its.getLocations()) {
        if (visited.count(node) == 0) {
            if (!its.removeLocationAndRules(node).empty()) {
                changed = true;
            }
        }
    }

    return changed;
}


/**
 * Helper for removeSinkRhss.
 * Deletes all rhss of the given rule that lead to the given location.
 * If all rhss lead to loc, then the rule is completely deleted (if it has constant complexity)
 * or a dummy rhs is added (if the rule has more than constant complexity).
 * @return true iff the ITS was modified
 */
static bool partialDeletion(ITSProblem &its, TransIdx ruleIdx, LocationIdx loc) {
    const Rule rule = its.getRule(ruleIdx);
    assert(its.getTransitionTargets(ruleIdx).count(loc) > 0); // should only call this if we can delete something

    // If the rule only has one rhs, we do not change it (this ensures termination of the overall algorithm)
    if (rule.isLinear()) {
        return false;
    }

    std::vector<Rule> toAdd;
    // Replace the rule by a stripped rule (without rhss leading to loc), if possible
    auto optRule = rule.stripRhsLocation(loc);
    if (optRule) {
        toAdd.push_back(optRule.get());
    }

    // If all rhss would be deleted, we still keep the rule if it has an interesting complexity.
    if (!optRule) {
        if (rule.getCost().toComplexity() > Complexity::Const) {
            // Note that it is only sound to add a dummy transition to loc if loc is a sink location.
            // This should be the case when partialDeletion is called, at least for the current implementation.
            assert(!its.hasTransitionsFrom(loc));
            toAdd.push_back(rule.replaceRhssBySink(loc));
        }
    }
    its.replaceRules({ruleIdx}, toAdd);

    return true;
}


// remove edges to locations without outdegree 0 (sink)
bool Pruning::removeSinkRhss(ITSProblem &its) {
    bool changed = false;

    for (LocationIdx node : its.getLocations()) {
        // if the location is a sink, remove it from all rules
        if (!its.hasTransitionsFrom(node)) {
            for (TransIdx rule : its.getTransitionsTo(node)) {
                changed = partialDeletion(its, rule, node) || changed;
            }

            // if we could remove all incoming rules, we can remove the sink
            if (!its.isInitialLocation(node) && !its.hasTransitionsTo(node)) {
                its.removeOnlyLocation(node);
            }
        }
    }

    return changed;
}
