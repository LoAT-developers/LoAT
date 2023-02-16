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

#include "chain.hpp"

#include "smtfactory.hpp"
#include "config.hpp"
#include "boolexpr.hpp"

using namespace std;


// ############################
// ##  Satisfiability Check  ##
// ############################

/**
 * Helper for chainRules. Checks if the given (chained) guard is satisfiable.
 */
static bool checkSatisfiability(const BoolExpr newGuard, VariableManager &varMan) {
    auto smtRes = SmtFactory::check(newGuard, varMan);

    // If we still get "unknown", we interpret it as "sat", so we prefer to chain if unsure.
    // This is especially needed for exponentials, since z3 cannot handle them well.
    return smtRes != Unsat;
}


// ########################
// ##  Chaining Helpers  ##
// ########################

/**
 * Part of the main chaining algorithm.
 * Chains the given first rule's lhs with the second rule's lhs,
 * by applying the first rule's update to the second rule's lhs (guard/cost).
 * Also checks whether the resulting guard is satisfiable (and returns none if not), unless checkSat is false.
 */
static std::optional<RuleLhs> chainLhss(VarMan &varMan, const RuleLhs &firstLhs, const Subs &firstUpdate,
                                 const RuleLhs &secondLhs, bool checkSat)
{
    // Concatenate both guards, but apply the first rule's update to second guard
    BoolExpr newGuard = firstLhs.getGuard() & secondLhs.getGuard()->subs(firstUpdate);

    // Add the costs, but apply first rule's update to second cost
    Expr newCost = firstLhs.getCost() + secondLhs.getCost().subs(firstUpdate.get<IntTheory>());

    // As a small optimization: Keep a NONTERM symbol (easier to identify NONTERM cost later on)
    if (firstLhs.getCost().isNontermSymbol() || secondLhs.getCost().isNontermSymbol()) {
        newCost = Expr::NontermSymbol;
    }

    if (Config::Chain::CheckSat) {
        // Avoid chaining if the resulting rule can never be taken
        if (checkSat && !checkSatisfiability(newGuard, varMan)) {
            return {};
        }
    }

    return RuleLhs(firstLhs.getLoc(), newGuard, newCost);
}

std::optional<Rule> Chaining::chainRules(VarMan &varMan, const Rule &first, const Rule &second, bool checkSat)
{
    assert(first.getRhsLoc() == second.getLhsLoc());

    auto newLhs = chainLhss(varMan, first.getLhs(), first.getUpdate(), second.getLhs(), checkSat);
    if (!newLhs) {
        return {};
    }

    return Rule(*newLhs, RuleRhs(second.getRhsLoc(), substitution::compose(second.getUpdate(), first.getUpdate())));
}
