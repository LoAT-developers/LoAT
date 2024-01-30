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

#include "rulepreprocessing.hpp"
#include "expr.hpp"
#include "guardtoolbox.hpp"
#include "expr.hpp"

#include <numeric>

using namespace std;

RuleResult eliminateTempVars(const Rule &rule) {
    RuleResult res(rule);

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    res.concat(GuardToolbox::makeEqualities(*res));
    res.fail(); // *just* finding implied equalities does not suffice for success

    res.concat(GuardToolbox::propagateBooleanEqualities(*res));

    //try to remove all remaining temp variables (we do 2 steps to prioritize removing vars from the update)

    res.concat(GuardToolbox::propagateEqualities(*res, ResultMapsToInt, expr::isTempVar));

    BoolExpr guard = res->getGuard();
    BoolExpr newGuard = guard->simplify();
    if (newGuard.get() != guard.get()) {
        const Rule newRule = res->withGuard(newGuard);
        res.ruleTransformationProof(res.get(), "Simplified Guard", newRule);
        res = newRule;
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    const auto varsInUpdate {expr::coDomainVars(res->getUpdate())};
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return expr::isTempVar(sym) && varsInUpdate.find(sym) == varsInUpdate.end();
    };
    res.concat(GuardToolbox::eliminateByTransitiveClosure(*res, true, isTempOnlyInGuard));

    return res;
}

bool removeTrivialUpdates(Subs &update) {
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

RuleResult removeTrivialUpdates(const Rule &rule) {
    bool changed = false;
    Subs up = rule.getUpdate();
    changed |= removeTrivialUpdates(up);
    RuleResult res{Rule(rule.getGuard(), up), changed};
    if (res) {
        res.ruleTransformationProof(rule, "Removed Trivial Updates", res.get());
    }
    return res;
}

RuleResult simplifyRule(const Rule &rule) {
    RuleResult res(rule);
    res.concat(eliminateTempVars(*res));
    res.concat(removeTrivialUpdates(*res));
    return res;
}

RuleResult Preprocess::preprocessRule(const Rule &rule) {
    RuleResult res(rule);

    // The other steps are repeated (might not help very often, but is probably cheap enough)
    bool changed = false;
    do {
        RuleResult tmp {simplifyRule(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}
