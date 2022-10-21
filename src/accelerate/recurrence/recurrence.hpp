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
#include "variablemanager.hpp"
#include "option.hpp"
#include "numexpression.hpp"


/**
 * This class is the interface end to the recurrence solver PURRS,
 * and allows calculating iterated cost and update
 */
class Recurrence
{
private:

public:

    struct Result {
        Expr cost;
        ExprSubs update;
        unsigned int validityBound;
        NumVar n;

        Result(const NumVar &n);

    };

    /**
     * Iterates the rule's update and cost, similar to iterateUpdateCost.
     * In addition to iterateUpdateCost, an additional heuristic is used if no dependency order is found.
     * This heuristic adds new constraints to the rule's guard and is thus only used in this method.
     */
    static option<Result> iterateRule(VarMan &varMan, const LinearRule &rule);

private:

    struct RecurrenceSolution {
        GiNaC::ex res;
        const unsigned int validityBound;
    };

    struct RecurrenceSystemSolution {
        GiNaC::exmap update;
        const unsigned int validityBound;
    };

    Recurrence(VarMan &varMan, const std::vector<NumVar> &dependencyOrder);

    /**
     * Main implementation
     */
    option<Result> iterate(const ExprSubs &update, const Expr &cost);

    /**
     * Computes the iterated update, with meterfunc as iteration step (if possible).
     * @note dependencyOrder must be set before
     * @note sets updatePreRecurrences
     */
    option<RecurrenceSystemSolution> iterateUpdate(const ExprSubs &update);

    /**
     * Computes the iterated cost, with meterfunc as iteration step (if possible).
     * @note updatePreRecurrences must be set before (so iterateUpdate() needs to be called before)
     */
    option<GiNaC::ex> iterateCost(const Expr &c);

    /**
     * Helper for iterateUpdate.
     * Tries to find a recurrence for the given single update.
     * Note that all variables occurring in update must have been solved before (and added to updatePreRecurrences).
     */
    option<RecurrenceSolution> findUpdateRecurrence(const Expr &updateRhs, NumVar updateLhs, const std::map<NumVar, unsigned int> &validitybounds);

    static const option<RecurrenceSystemSolution> iterateUpdate(const VariableManager&, const Subs&);

    /**
     * To query variable names/indices
     */
    VariableManager &varMan;

    /**
     * Purrs::Recurrence::n converted to a ginac expression, for convenience only
     */
    const GiNaC::symbol ginacN;

    /**
     * Order in which recurrences for updated variables can be computed
     */
    std::vector<NumVar> dependencyOrder;

    /**
     * Substitution map, mapping variables to their recurrence equations
     * @note the recurrence equations are valid *before* the transition is taken,
     * i.e. these are the terms for r(n-1) and _not_ for r(n) where r is the recurrence equation.
     */
    GiNaC::exmap updatePreRecurrences;
};
