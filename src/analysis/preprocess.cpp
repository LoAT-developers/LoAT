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

#include "preprocess.hpp"
#include "expr.hpp"
#include "guardtoolbox.hpp"
#include "expr.hpp"

using namespace std;


Result<Rule> Preprocess::preprocessRule(const Rule &rule) {
    Result<Rule> res(rule);

    // The other steps are repeated (might not help very often, but is probably cheap enough)
    bool changed = false;
    do {
        Result<Rule> tmp {simplifyRule(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}

Result<Rule> Preprocess::simplifyRule(const Rule &rule) {
    Result<Rule> res(rule);
    res.concat(eliminateTempVars(*res));
    res.concat(removeTrivialUpdates(*res));
    return res;
}

Result<Rule> Preprocess::removeTrivialUpdates(const Rule &rule) {
    bool changed = false;
    Subs up = rule.getUpdate();
    changed |= removeTrivialUpdates(up);
    Result<Rule> res{Rule(rule.getGuard(), up), changed};
    if (res) {
        res.ruleTransformationProof(rule, "Removed Trivial Updates", res.get());
    }
    return res;
}

bool Preprocess::removeTrivialUpdates(Subs &update) {
    stack<Var> remove;
    for (const auto &it : update) {
        const auto first = expr::first(it);
        const auto second = expr::second(it);
        if (TheTheory::varToExpr(first) == second) {
            remove.push(first);
        }
    }
    if (remove.empty()) return false;
    while (!remove.empty()) {
        update.erase(remove.top());
        remove.pop();
    }
    return true;
}


/**
 * Returns the set of all variables that appear in the rhs of some update.
 * For an update x := a and x := x+a, this is {a} and {x,a}, respectively.
 */
static VarSet collectVarsInUpdateRhs(const Rule &rule) {
    VarSet varsInUpdate;
    for (const auto &it : rule.getUpdate()) {
        expr::collectVars(expr::second(it), varsInUpdate);
    }
    return varsInUpdate;
}


Result<Rule> Preprocess::eliminateTempVars(const Rule &rule) {
    Result<Rule> res(rule);

    //declare helper lambdas to filter variables, to be passed as arguments
    auto isTemp = [&](const Var &sym) {
        return expr::isTempVar(sym);
    };
    auto isTempInUpdate = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*res);
        return isTemp(sym) && varsInUpdate.find(sym) != varsInUpdate.end();
    };
    auto isTempOnlyInGuard = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*res);
        return isTemp(sym) && varsInUpdate.find(sym) == varsInUpdate.end();
    };

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    res.concat(GuardToolbox::makeEqualities(*res));
    res.fail(); // *just* finding implied equalities does not suffice for success

    res.concat(GuardToolbox::propagateBooleanEqualities(*res));

    //try to remove temp variables from the update by equality propagation (they are removed from guard and update)
    res.concat(GuardToolbox::propagateEqualities(*res, ResultMapsToInt, isTempInUpdate));

    //try to remove all remaining temp variables (we do 2 steps to prioritize removing vars from the update)
    res.concat(GuardToolbox::propagateEqualities(*res, ResultMapsToInt, isTemp));

    BoolExpr guard = res->getGuard();
    BoolExpr newGuard = guard->simplify();
    if (newGuard.get() != guard.get()) {
        const Rule newRule = res->withGuard(newGuard);
        res.ruleTransformationProof(res.get(), "Simplified Guard", newRule);
        res = newRule;
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    res.concat(GuardToolbox::eliminateByTransitiveClosure(*res, true, isTempOnlyInGuard));

    return res;
}
