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

#ifndef GUARDTOOLBOX_H
#define GUARDTOOLBOX_H

#include "expression.hpp"
#include "../its/variablemanager.hpp"
#include "../util/option.hpp"
#include "../util/result.hpp"

#include <vector>
#include <map>

/**
 * Namespace for several functions operating on guards (list of relational expressions) and related helpers.
 * Note: We never allow != in relations.
 */
namespace GuardToolbox {

    // Specifies for which coefficients c we can solve "c*x == t" for x.
    enum SolvingLevel {
        TrivialCoeffs = 0, // only c=1 and c=-1 is allowed
        ResultMapsToInt = 1, // c can be any rational constant, as long as x = t/c maps to int
        ConstantCoeffs = 2, // c can be any rational constant (the result may not map to int, use with caution!)
    };

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
    option<Rule> propagateEqualities(const VarMan &varMan, const Rule &rule, SolvingLevel level, SymbolAcceptor allow);


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
    option<Rule> eliminateByTransitiveClosure(const Rule &rule, bool removeHalfBounds, SymbolAcceptor allow);

    std::pair<option<Expr>, option<Expr>> getBoundFromIneq(const Rel &rel, const Var &N);

    /**
     * Tries to solve the equation term == 0 for the given variable, using the given level of restrictiveness
     * @return if possible, the term t such that "var == t" is equivalent to "term == 0"
     */
    option<Expr> solveTermFor(Expr term, const Var &var, SolvingLevel level);


    /**
     * Given two relations lhs and rhs, checks if rhs is trivially (syntactically) implied by lhs.
     * For example, A > 0 or A == 0 both imply A+1 > 0
     * @return true if lhsConstraint implies rhsConstraint, false has no meaning.
     */
    bool isTrivialImplication(const Rel &lhsConstraint, const Rel &rhsConstraint);


    /**
     * Replaces bidirectional inequalities, e.g. x <= y, y >= x by an equality, e.g. x == y.
     * The inequalties are removed, the equality is added to guard.
     * @note expensive for large guards
     * @return true iff guard was changed.
     */
    option<Rule> makeEqualities(const Rule &rule);

    Result<Rule> propagateEqualitiesBySmt(const Rule &rule, ITSProblem &its);


    /**
     * Returns true iff term contains a temporary variable
     */
    template<class T>
    bool containsTempVar(const VarMan &varMan, const T &x) {
        return x.hasVarWith([&varMan](const Var &sym) {
            return varMan.isTempVar(sym);
        });
    }

}


#endif // GUARDTOOLBOX_H
