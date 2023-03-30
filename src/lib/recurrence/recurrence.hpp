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

#include <optional>

#include "theory.hpp"
#include "variablemanager.hpp"
#include "numexpression.hpp"


class Recurrence {
private:

public:

    struct Result {
        Subs update;
        unsigned int validityBound;
        NumVar n;

        Result(const NumVar &n);

    };

    static std::optional<Result> iterate(VarMan &varMan, const Subs &update);

private:

    template <ITheory Th>
    struct RecurrenceSolution {
        typename Th::Expression res;
        const unsigned int validityBound;
    };

    struct RecurrenceSystemSolution {
        Subs update;
        const unsigned int validityBound;
    };

    Recurrence(VarMan &varMan, const std::vector<Var> &dependencyOrder);

    std::optional<Result> iterate(const Subs &update);

    std::optional<RecurrenceSystemSolution> iterateUpdate(const Subs &update);

    /**
     * Helper for iterateUpdate.
     * Tries to find a recurrence for the given single update.
     * Note that all variables occurring in update must have been solved before (and added to updatePreRecurrences).
     */
    std::optional<RecurrenceSolution<IntTheory>> solve(const NumVar &updateLhs, const Expr &updateRhs, const std::map<Var, unsigned int> &validitybounds);

    std::optional<RecurrenceSolution<BoolTheory>> solve(const BoolVar &updateLhs, const BoolExpr &updateRhs, const std::map<Var, unsigned int> &validitybounds);

    static const std::optional<RecurrenceSystemSolution> iterateUpdate(const VariableManager&, const Subs&);

    /**
     * To query variable names/indices
     */
    VariableManager &varMan;

    /**
     * Order in which recurrences for updated variables can be computed
     */
    std::vector<Var> dependencyOrder;

    /**
     * Substitution map, mapping variables to their recurrence equations
     * @note the recurrence equations are valid *before* the transition is taken,
     * i.e. these are the terms for r(n-1) and _not_ for r(n) where r is the recurrence equation.
     */
    Subs updatePreRecurrences;
};
