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

#include "arithexpr.hpp"
#include "theory.hpp"
#include "result.hpp"

#include <vector>

/**
 * Namespace for several functions operating on guards (list of relational expressions) and related helpers.
 * Note: We never allow != in relations.
 */
namespace GuardToolbox {

    // Shorthand for lambdas that check if a given symbol is accepted/allowed (depending on the context)
    using SymbolAcceptor = std::function<bool(const Var &)>;


    /**
     * Tries to remove equalities by propagating them into the other guard expressions
     * E.g. x == 2y, x > z can be transformed into 2y > z.
     *
     * @param level Defines in which cases a propagation is performed:
     * @param freevar Defines if replacing non-free variables by free variables is allowed
     * @param subs if given, this will be assigned the resulting substititon map
     * @param allowFunc if given, lambda must be true to propagate the given symbol
     *
     * @note is is ensured that substitutions of the form x/x^2 cannot happen
     *
     * @note replacing non-free variables by free variables is not sound for the runtime complexity
     * (only if the free variable is somehow marked as bounded afterwards)
     * Example: for x==free, x might be substituted by free, resulting in possible INF runtime, although free was in fact bounded by x.
     *
     * NoCoefficients: the eliminated variable (x above) must have no coefficient (i.e. 1)
     * LinearCoefficients: a numeric coefficient is allowed, NOT SOUND IN MOST CASES!
     * Nonlinear: Allow non-numeric coefficients (e.g. x*y == 2y^2 --> x == 2y), NOT SOUND IN ALMOST ALL CASES!
     *
     * @return true if any progpagation was performed.
     */
    ResultBase<ArithSubs, Proof> propagateEqualities(const BoolExprPtr e, const SymbolAcceptor &allow);

    ResultBase<BoolSubs, Proof> propagateBooleanEqualities(const BoolExprPtr e);

    /**
     * Tries to replace inequalities using their transitive closure,
     * so A <= x and x <= B will be replaced by A <= B (for any terms A,B).
     * Note that for soundness, all terms with x must be replaced at once.
     * Note that x may not have any coefficient in any of these terms.
     *
     * @note this is only sound for the resulting runtime, if only free variables are allowed to be eliminated!
     *
     * @param removeHalfBounds if true, terms like a <= x (without x <= b) will also be removed!
     * @param allowFunc if lambda is false, the given variable may not be considered for elimination.
     *
     * @return true if any changes have been made
     */
    ResultBase<BoolExprPtr, Proof> eliminateByTransitiveClosure(const BoolExprPtr e, bool removeHalfBounds, const SymbolAcceptor &allow);

    ResultBase<BoolExprPtr, Proof> simplify(const BoolExprPtr e);

    /**
     * Returns true iff term contains a temporary variable
     */
    template<class T>
    bool containsTempVar(const T &x) {
        return x.hasVarWith([](const ArithVar &sym) {
            return sym.isTempVar();
        });
    }

    ResultBase<BoolExprPtr, Proof> eliminateTempVars(BoolExprPtr trans, const SymbolAcceptor &allow);

    ResultBase<BoolExprPtr, Proof> preprocessFormula(const BoolExprPtr e, const SymbolAcceptor &allow);

}
