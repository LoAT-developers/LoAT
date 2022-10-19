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

#ifndef ACCELERATE_H
#define ACCELERATE_H

#include "types.hpp"
#include "itsproblem.hpp"
#include "numexpression.hpp"
#include "complexity.hpp"
#include "accelerationresult.hpp"


class Accelerator {
public:
    /**
     * Tries to accelerate all simple loops of the given location
     * by combining forward and backward acceleration techniques.
     * Also handles nesting and chaining of simple loops (if enabled).
     *
     * Successfully accelerated simple loops are removed afterwards.
     * rules for which acceleration failed may be kept (and are then also added to resultingRules).
     * This is intended for cases where the loop itself already has non-trivial complexity.
     *
     * @param resultingRules resulting (usually accelerated) rules are inserted (via their index).
     * @return true iff the ITS was modified
     *         (which is always the case if any simple loops were present)
     */
    static option<Proof> accelerateSimpleLoops(ITSProblem &its, LocationIdx loc, std::set<TransIdx> &resultingRules);

private:
    // Potential candidate for the inner loop when nesting two loops.
    // Inner loops are always accelerated loops, so this stores the original and the accelerated rule.
    // The information on the original rule is only used to avoid nesting a loop with itself
    struct NestingCandidate {
        TransIdx oldRule;
        TransIdx newRule;
        Complexity cpx;

        NestingCandidate() {}
        NestingCandidate(TransIdx oldRule, TransIdx newRule, Complexity cpx): oldRule(oldRule), newRule(newRule), cpx(cpx) {}
    };

private:
    Accelerator(ITSProblem &its, LocationIdx loc, std::set<TransIdx> &resultingRules);

    /**
     * Main function. Tries to accelerate and nest all loops
     * by calling the methods below in a suitable way.
     */
    option<Proof> run();

    /**
     * Helper that calls Preprocess::simplifyRule
     * Returns true iff any rule was modified.
     */
    bool simplifySimpleLoops();

    /**
     * Tries to accelerate the given rule by forward acceleration and,
     * if this fails, by backward acceleration.
     * @returns The acceleration result (including accelerated rules, if successful)
     */
    AccelerationResult tryAccelerate(const Rule &rule, Complexity cpx) const;


    /**
     * Tries to accelerate the given rule by calling tryAccelerate.
     * If this fails and the rule is nonlinear, we try to accelerate the rule again
     * after removing some of the right-hand sides. This may simplify the rule,
     * so acceleration might then be successful (maybe with a lower complexity).
     * Since we don't known which right-hand sides are causing trouble,
     * we try many combinations of removing right-hand sides, so this might be expensive.
     *
     * @note We also try to remove all but one right-hand side, so we reduce the nonlinear
     * rule to a linear rule which may lose the exponential complexity. But since we cannot
     * accelerate nonlinear rules by backward acceleration, this is still preferable to
     * just giving up.
     *
     * @returns If successful, the resulting accelerated rule(s). Otherwise,
     * the acceleration result from accelerating the original rule (before shortening).
     */
    AccelerationResult accelerateOrShorten(const Rule &rule, Complexity cpx) const;


    /**
     * Adds the given rule to the ITS problem and to resultingRules.
     * @return The index of the added rule.
     */
    option<TransIdx> addResultingRule(Rule rule);

    /**
     * Tries to nest the given nesting candidates (i.e., rules).
     * Returns true if nesting was successful (at least one new rule was added).
     */
    void nestRules(const NestingCandidate &inner, const NestingCandidate &outer);

    /**
     * Main implementation of nesting
     */
    void performNesting(std::unordered_map<TransIdx, NestingCandidate> origRules, std::vector<NestingCandidate> todo);

    /**
     * Removes all given loops, unless they are contained in keepRules.
     * Also prunes duplicate rules from resultingRules.
     */
    void removeOldLoops(const std::vector<TransIdx> &loops);

    const option<LinearRule> chain(const LinearRule &rule) const;

    unsigned int numNotInUpdate(const Subs &up) const;

private:
    // The ITS problem. Accelerated rules are added to the ITS immediately,
    // but no rules are removed until the very end (end of run()).
    ITSProblem &its;

    // The location for which simple loops shall be accelerated.
    LocationIdx targetLoc;

    // Sink location for accelerated (nonlinear/nonterminating) rules
    LocationIdx sinkLoc;

    // The set of resulting rules.
    // These are all accelerated rules and some rules for which acceleration failed.
    std::set<TransIdx> &resultingRules;

    // All rules where acceleration failed, but where we want to keep the un-accelerated rule.
    std::set<TransIdx> keepRules;

    const AccelerationResult strengthenAndAccelerate(const LinearRule &rule, Complexity cpx) const;

    Proof proof;

};

#endif // ACCELERATE_H
