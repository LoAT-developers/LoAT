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

#ifndef PRUNE_H
#define PRUNE_H

#include "types.hpp"
#include "itsproblem.hpp"
#include "smt.hpp"

class Rule;
class ITSProblem;


namespace Pruning {
    /**
     * Tries to identify and remove duplicate transitions within the given list/set of transitions
     * @param trans vector/set/... of transitions that are checked
     * @note does not catch all duplicates, as this is a purely syntactical check (no z3 calls)
     * @return true iff the ITS was modified (i.e. a duplicate got deleted)
     */
    template <typename Container>
    std::set<TransIdx> removeDuplicateRules(ITSProblem &its, const Container &trans, bool compareRhss = true) {
        std::set<TransIdx> toRemove;

        for (auto i = trans.begin(); i != trans.end(); ++i) {
            for (auto j = i; ++j != trans.end(); /**/) {
                TransIdx idxA = *i;
                TransIdx idxB = *j;

                const Rule &ruleA = its.getRule(idxA);
                const Rule &ruleB = its.getRule(idxB);

                // if rules are identical up to cost, keep the one with the higher cost
                if (ruleA.approxEqual(ruleB, compareRhss)) {
                    if ((ruleA.getCost() - ruleB.getCost()).toNum().is_positive() > 0) {
                        toRemove.insert(idxB);
                    } else {
                        toRemove.insert(idxA);
                        break; // do not remove trans[i] again
                    }
                }
            }
        }

        for (TransIdx rule : toRemove) {
            its.removeRule(rule);
        }

        return toRemove;
    }

    /**
     * Removes all rules within the given list/set/... whose guard is found to be unsatisfiable.
     * This involves a single z3 query for every transition.
     * @return true iff the ITS was modified (i.e., an unsat rule got deleted)
     */
    template <typename Container>
    bool removeUnsatRules(ITSProblem &its, const Container &trans) {
        bool changed = false;

        for (TransIdx rule : trans) {
            if (Smt::check(its.getRule(rule).getGuard(), its) == Smt::Unsat) {
                its.removeRule(rule);
                changed = true;
            }
        }

        return changed;
    }

    /**
     * Reduces the number of parallel rules by applying some greedy heuristic to find the "best" rules
     * @note Two nonlinear rules are considered parallel if they have at least one target location in common.
     * @note For nonlinear rules, only certain right-hand sides are removed, but not necessarily entire rules.
     * @return true iff the ITS was modified (transitions were deleted)
     */
    bool pruneParallelRules(ITSProblem &its);

    /**
     * Removes all unreachable nodes and rules to leafs with constant cost, as they have no impact on the runtime
     * @return true iff the ITS was modified
     */
    bool removeLeafsAndUnreachable(ITSProblem &its);

    /**
     * Removes sink locations (locations without outgoing rules) from right-hand sides of nonlinear rules.
     * Example: f -> f,g and g has no outgoing rules, then the rule is reduced to f -> f.
     *
     * If all right-hand sides of a single rule would be deleted, the rule is either removed
     * or a dummy right-hand side (with trivial update) is added to retain the rule.
     * The sink location itself is also removed if it becomes isolated (it no longer apperas on any rhs).
     *
     * @return true iff the ITS was modified
     */
    bool removeSinkRhss(ITSProblem &its);
}

#endif // PRUNE_H
