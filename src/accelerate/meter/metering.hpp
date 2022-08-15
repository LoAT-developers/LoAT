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

#ifndef METERING_H
#define METERING_H

#include "expression.hpp"
#include "variablemanager.hpp"
#include "rule.hpp"
#include "guard.hpp"
#include "option.hpp"
#include "boolexpr.hpp"
#include "proof.hpp"
#include "model.hpp"

#include <vector>
#include <map>


/**
 * Class to encapsulate the process of finding a metering function for a given transition using z3 and Farkas lemma
 *
 * Central constraints for the metering function f (G is guard, U is update, x the variables)
 *  (1)  (not G)   implies  f(x) <= 0
 *  (2)   G        implies  f(x) >= 1 (equivalent to f(x) > 0 on integers)
 *  (3)  (G and U) implies  f(x) <= f(x') + 1
 *
 * The search is performed by constructing a linear template f(x) = c*x + c0,
 * where x are variables (only those we consider relevant for the metering function)
 * and c are the corresponding coefficients (c0 is the absolute coefficient).
 * The values for c and c0 are determined by a z3 query, such that constraints (1)-(3) are satisfied.
 */
class MeteringFinder {
public:
    /**
     * Success: metering function was found
     * Nonterm: if the guard is satisfied, the loop does not terminate (whole guard is irrelevant for termination)
     * Nonlinear: the problem is nonlinear
     * Unsat: no metering function was found (z3 unknown/unsat)
     */
    enum ResultKind { Success, Nonterm, Nonlinear, Unsat };

    struct Result {
        // Flag indicating whether a metering function was successfully found
        ResultKind result;

        // The metering function (only relevant if result is Success)
        Expr metering;

        // Additional constraint that has to be added to the rule's guard to ensure correctness.
        // Only relevant if result is Success (and real coefficients are used).
        option<Rel> integralConstraint;

        option<Rule> rule;

        Proof proof;
    };

    /**
     * Tries to find a metering function for the given rule by identifying relevant variables,
     * constructing a template for the metering function using these variables and then using
     * z3 to fill the template given encodings of the constraints (1), (2) and (3).
     *
     * @return The resulting metering function or the reason for failure (and possibly additional information).
     */
    static Result generate(VarMan &varMan, const Rule &rule);

    /**
     * Heuristic to instantiate temporary variables by their bounds (e.g. for "x <= 4", instantiate x by 4).
     * This might help to find a metering function, but of course makes the rule less general.
     *
     * This method tries several instantiations, until it finds one which satisfies the main constraints
     * for the metering function (so calling generate with the resulting rule is likely successful).
     * This is very expensive!
     *
     * @return the rule resulting from instantiation, if a successful instantiaton was found
     */
    static option<std::pair<Rule, Proof>> instantiateTempVarsHeuristic(ITSProblem &its, const Rule &rule);

    /**
     * Guard strengthening heuristic for constant updates, see MeteringToolbox::strengthenGuard.
     * @note modifies the given rule
     * @return true iff successful (i.e., iff rule was modified)
     */
    static option<Rule> strengthenGuard(VarMan &varMan, const Rule &rule);

private:
    MeteringFinder(VarMan &varMan, const Guard &guard, const std::vector<Subs> &update);

    /**
     * Helper for convenience, collects all updates of the given rule into a vector.
     */
    static std::vector<Subs> getUpdateList(const Rule &rule);

    /**
     * Simplifies guard/update by removing constraints that do not affect the metering function.
     * While doing so, computes reducedGuard, irrelevantGuard and relevantVars.
     */
    void simplifyAndFindVariables();

    /**
     * Performs all available pre-processing steps:
     *  - eliminates temporary variables (where possible)
     *  - simplifies guard/update (calls simplifyAndFindVariables)
     *
     * Sets/modifies the members: guard, update, reducedGuard, irrelevantGuard, relevantVars.
     */
    void preprocess();

    bool isLinear() const;

    /**
     * Uses relevantVars to set meterVars (symbols and coefficients).
     * The type of the generated coefficients depends on FARKAS_ALLOW_REAL_COEFFS.
     */
    void buildMeteringVariables();

    /**
     * Builds the required lists of constraints (guard, reducedGuard, guardUpdate)
     * in the form "linear term <= constant"
     */
    void buildLinearConstraints();

    /**
     * Helper to build the implication: "(G and U) --> f(x)-f(x') <= 1" using applyFarkas
     */
    BoolExpr genUpdateImplications() const;

    /**
     * Helper to build the implication: "(not G) --> f(x) <= 0" using multiple applyFarkas calls (which are AND-concated)
     * @note makes use of reducedGuard instead of guard
     */
    BoolExpr genNotGuardImplication() const;

    /**
     * Helper to build the implication: "G --> f(x) > 0" using applyFarkas
     * @param strict if true, the rhs is strict, i.e. f(x) > 0 formulated as f(x) >= 1; if false f(x) >= 0 is used
     */
    BoolExpr genGuardPositiveImplication(bool strict) const;

    /**
     * Helper to build constraints to suppress trivial solutions, i.e. "OR c_i != 0" for the coefficients c_i
     */
    BoolExpr genNonTrivial() const;

    /**
     * Given the z3 model, builds the corresponding linear metering function
     */
    Expr buildResult(const Model &model) const;

    /**
     * Modifies the current result to ensure that the metering function evaluates to an integer.
     * To this end, replaces the metering function with a fresh variable and adds a constraint
     * (to be added to the rule's guard) that relates the fresh variable with the original metering function.
     *
     * Note: Only required if FARKAS_ALLOW_REAL_COEFFS is set.
     */
    void ensureIntegralMetering(Result &result, const Model &model) const;


    void dump(const std::string &msg) const;


private:
    /**
     * The VariableManager instance, used for fresh variables and for conversion between indices/symbols
     */
    VariableManager &varMan;


    std::vector<Subs> updates;
    Guard guard;

    /**
     * Same as guard, but only contains constraints that (might) limit the execution of the loop.
     * irrelevantGuard is the guard without the reducedGuard (so the constraints that were dropped).
     */
    Guard reducedGuard;
    Guard irrelevantGuard;

    /**
     * The set of variables that might occur in the metering function.
     * These variables are used to build the template for the metering function.
     */
    VarSet relevantVars;



    /**
     * Linear constraints (of the form "linear term <= constant")
     * obtained from guard, reduced guard, irrelevant guard, guard and update.
     */
    struct {
        RelSet guard;
        RelSet reducedGuard;
        RelSet irrelevantGuard;
        std::vector<RelSet> guardUpdate; // one for each update
    } linearConstraints;

    /**
     * Variables and their coefficients for the metering function template.
     * primedSymbols maps updated variables to a primed version of the variable's symbol.
     */
    struct {
        std::vector<Var> symbols;
        std::vector<Var> coeffs;
        VarMap<Var> primedSymbols;
    } meterVars;

    /**
     * The absolute coefficient for the metering function template.
     */
    Var absCoeff;

};

#endif // METERING_H
