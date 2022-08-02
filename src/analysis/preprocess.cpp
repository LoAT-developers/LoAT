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

#include "../expr/guardtoolbox.hpp"
#include "../smt/smt.hpp"
#include "../smt/z3/z3.hpp"
#include "../smt/smtfactory.hpp"

using namespace std;


Result<Rule> Preprocess::preprocessRule(ITSProblem &its, const Rule &rule) {
    Result<Rule> oldRule(rule);
    option<Rule> newRule;

    // The other steps are repeated (might not help very often, but is probably cheap enough)
    bool changed = false;
    do {
        changed = false;
        Result<Rule> elim = eliminateTempVars(its, *oldRule, true);
        changed = changed || elim;
        oldRule.concat(elim);

        newRule = removeTrivialUpdates(*oldRule);
        if (newRule) {
            changed = true;
            oldRule = *newRule;
        }
    } while (changed);

    newRule = simplifyGuard(*oldRule, its);
    if (newRule) {
        oldRule = *newRule;
    }
    return oldRule;
}

Result<Rule> Preprocess::simplifyRule(ITSProblem &its, const Rule &rule, bool fast) {
    Result<Rule> oldRule = rule;
    option<Rule> newRule;

    oldRule.concat(eliminateTempVars(its, *oldRule, fast));

    newRule = simplifyGuard(*oldRule, its);
    if (newRule) {
        oldRule = *newRule;
    }

    newRule = removeTrivialUpdates(*oldRule);
    if (newRule) {
        oldRule = *newRule;
    }

    return oldRule;
}


option<Rule> Preprocess::simplifyGuard(const Rule &rule, const VariableManager &varMan) {
    const BoolExpr newGuard = Z3::simplify(rule.getGuard(), varMan);
    if (rule.getGuard() == newGuard) {
        return {};
    } else {
        return {rule.withGuard(newGuard)};
    }
}


option<Rule> Preprocess::removeTrivialUpdates(const Rule &rule) {
    bool changed = false;
    std::vector<RuleRhs> newRhss;
    for (const RuleRhs &rhs: rule.getRhss()) {
        Subs up = rhs.getUpdate();
        changed |= removeTrivialUpdates(up);
        newRhss.push_back(RuleRhs(rhs.getLoc(), up));
    }
    if (changed) {
        return {Rule(rule.getLhs(), newRhss)};
    } else {
        return {};
    }
}

bool Preprocess::removeTrivialUpdates(Subs &update) {
    stack<Var> remove;
    for (auto it : update) {
        if (it.second.equals(it.first)) {
            remove.push(it.first);
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
    for (auto rhs = rule.rhsBegin(); rhs != rule.rhsEnd(); ++rhs) {
        for (const auto &it : rhs->getUpdate()) {
            it.second.collectVars(varsInUpdate);
        }
    }
    return varsInUpdate;
}


Result<Rule> Preprocess::eliminateTempVars(ITSProblem &its, const Rule &rule, bool fast) {
    Result<Rule> oldRule(rule);
    option<Rule> newRule;

    //declare helper lambdas to filter variables, to be passed as arguments
    auto isTemp = [&](const Var &sym) {
        return its.isTempVar(sym);
    };
    auto isTempInUpdate = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*oldRule);
        return isTemp(sym) && varsInUpdate.count(sym) > 0;
    };
    auto isTempOnlyInGuard = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*oldRule);
        return isTemp(sym) && varsInUpdate.count(sym) == 0 && !rule.getCost().has(sym);
    };

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    newRule = GuardToolbox::makeEqualities(*oldRule);
    if (newRule) {
        oldRule.set(*newRule, false);
    }

    //try to remove temp variables from the update by equality propagation (they are removed from guard and update)
    newRule = GuardToolbox::propagateEqualities(its, *oldRule, GuardToolbox::ResultMapsToInt, isTempInUpdate);
    if (newRule) {
        oldRule = *newRule;
    }

    //try to remove all remaining temp variables (we do 2 steps to priorizie removing vars from the update)
    newRule = GuardToolbox::propagateEqualities(its, *oldRule, GuardToolbox::ResultMapsToInt, isTemp);
    if (newRule) {
        oldRule = *newRule;
    }

    if (!fast && !oldRule->getGuard()->isConjunction()) {
        oldRule.concat(GuardToolbox::propagateEqualitiesBySmt(*oldRule, its));
    }

    option<BoolExpr> newGuard = oldRule->getGuard()->simplify();
    if (newGuard) {
        oldRule = oldRule->withGuard(newGuard.get());
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    newRule = GuardToolbox::eliminateByTransitiveClosure(*oldRule, true, isTempOnlyInGuard);
    if (newRule) {
        oldRule = *newRule;
    }

    return oldRule;
}
