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

#ifndef METERTOOLS_H
#define METERTOOLS_H

#include "expression.hpp"
#include "variablemanager.hpp"
#include "rule.hpp"
#include "guard.hpp"

#include <vector>
#include <map>


/**
 * Static helper functions that are used to compute metering functions.
 */
namespace MeteringToolbox {

    // just a shorthand
    using MultiUpdate = std::vector<ExprSubs>;

    /**
     * Helper that applies a given substitution to all right-hand sides of all given updates.
     */
    MultiUpdate applySubsToUpdates(const ExprSubs &subs, const MultiUpdate &update);

    /**
     * Checks if the given variable is affected by any of the given updates
     */
    bool isUpdatedByAny(Var var, const MultiUpdate &updates);



    /**
     * Modifies guard (member) to contain only <,<=,>=,> by replacing == with <= and >=
     * @return true iff successfull, false if guard contains != which cannot be handled
     */
    Guard replaceEqualities(const Guard &guard);

    /**
     * Computes a guard by only keeping those constraints that might be relevant for the metering function.
     *
     * A constraint is relevant if there is at least one update such that the constraint
     * is not implied after applying the update (given that the guard holds before the update).
     * In other words, a constraint is relevant if it may cause the loop to terminate.
     *
     * (e.g. in n >= 0, i >= 0, i < n with i=i+1, the constraints n >= 0 and i >= 0 are not relevant.
     * The former only contains n, which is not updated. For the latter, note that it reads i+1 >= 0
     * after applying the update. If the guard holds (so i >= 0), then i+1 >= 0 also holds, so it is not relevant.)
     *
     * If irrelevantGuard is not null, it must be empty and is set to the list of non-relevant constraints.
     *
     * Note: The result of this method is soundness critical, since removing too many constraints
     * from the guard would allow incorrect metering functions (removing too few is not a soundness issue).
     */
    Guard reduceGuard(VarMan &varMan, const Guard &guard, const MultiUpdate &updates, Guard *irrelevantGuard = nullptr);

    /**
     * Computes a list of variables that might occur in the metering function
     * (these variables are later used to build the template for the metering function).
     *
     * A variable is relevant if
     *  a) it appears in the (reduced) guard and might thus influence the rank func
     *  b) it appears on any update rhs, where the lhs is already relevant (indirect influence)
     * In other cases, the variable is irrelevant for the metering function.
     *
     * Note: The result of this method is important to find metering functions, but does not affect soundness
     */
    VarSet findRelevantVariables(const Guard &reducedGuard, const MultiUpdate &updates);

    /**
     * Removes updates that do not update a variable from vars.
     */
    void restrictUpdatesToVariables(MultiUpdate &updates, const VarSet &vars);

    /**
     * Removes constraints that do not contain a variable from vars.
     */
    void restrictGuardToVariables(Guard &guard, const VarSet &vars);



    /**
     * Strengthens the guard by appending new constraints (if applicable).
     *
     * If a variable x is updated by a constant expression (e.g. x := 4 or x := y if y is not updated itself),
     * and there is a constraint on x (e.g. x > 0), a metering function might be difficult to find.
     * This method propagates such constant updates to the guard by applying the update to constraints with x,
     * e.g. x > 0 becomes 4 > 0 or y > 0.
     *
     * This is performed individually for every update, so each update may lead to adding some constraints.
     *
     * @return true iff the guard was modified (extended).
     */
    option<Guard> strengthenGuard(VarMan &varMan, const Guard &guard, const MultiUpdate &updates);

    /**
     * Creates all combinations of instantiating temporary variables by their bounds (i.e. free <= x --> set free=x)
     * @return list of all possible combinations (limited by FREEVAR_INSTANTIATE_MAXBOUNDS per variable).
     */
    std::stack<ExprSubs> findInstantiationsForTempVars(const VarMan &varMan, const Guard &guard);

}

#endif // METERTOOLS_H
