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

RuleResult makeEqualities(const Rule &rule) {
    RuleResult res {rule};
    const auto eqs {GuardToolbox::makeEqualities(rule.getGuard())};
    if (eqs) {
        res = res->withGuard(res->getGuard() & BExpression::buildAndFromLits(*eqs));
        res.ruleTransformationProof(rule, "Extracted Implied Equalities", *res);
        res.storeSubProof(eqs.getProof());
    }
    return res;
}

RuleResult propagateBooleanEqualities(const Rule &rule) {
    RuleResult res {rule};
    const auto subs {GuardToolbox::propagateBooleanEqualities(rule.getGuard())};
    if (subs) {
        res = res->subs(Subs::build<BoolTheory>(*subs));
        res.ruleTransformationProof(rule, "Propagated Equivalences", *res);
        res.storeSubProof(subs.getProof());
    }
    return res;
}

RuleResult propagateEqualities(const Rule &rule, SolvingLevel maxlevel, const GuardToolbox::SymbolAcceptor &allow) {
    RuleResult res {rule};
    const auto subs {GuardToolbox::propagateEqualities(rule.getGuard(), maxlevel, allow)};
    if (subs) {
        res = res->subs(Subs::build<IntTheory>(*subs));
        res.ruleTransformationProof(rule, "Extracted Implied Equalities", *res);
        res.storeSubProof(subs.getProof());
    }
    return res;
}

RuleResult eliminateByTransitiveClosure(const Rule &rule, bool removeHalfBounds, const GuardToolbox::SymbolAcceptor &allow) {
    RuleResult res {rule};
    const auto new_guard {GuardToolbox::eliminateByTransitiveClosure(rule.getGuard(), removeHalfBounds, allow)};
    if (new_guard) {
        res = res->withGuard(*new_guard);
        res.ruleTransformationProof(rule, "Eliminated Temporary Variables", *res);
        res.storeSubProof(new_guard.getProof());
    }
    return res;
}

RuleResult eliminateTempVars(const Rule &rule) {
    RuleResult res(rule);

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    res.concat(makeEqualities(*res));
    res.fail(); // *just* finding implied equalities does not suffice for success

    res.concat(propagateBooleanEqualities(*res));

    auto varsInUpdate {expr::coDomainVars(res->getUpdate())};
    auto isTempInUpdate = [&](const Var &sym) {
        return expr::isTempVar(sym) && varsInUpdate.contains(sym);
    };
    //try to remove temp variables from the update by equality propagation (they are removed from guard and update)
    res.concat(propagateEqualities(*res, ResultMapsToInt, isTempInUpdate));

    varsInUpdate = expr::coDomainVars(res->getUpdate());
    auto isTempOnlyInGuard = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(*res);
        return expr::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    //try to remove all remaining temp variables (we do 2 steps to prioritize removing vars from the update)
    res.concat(propagateEqualities(*res, ResultMapsToInt, expr::isTempVar));

    BoolExpr guard = res->getGuard();
    BoolExpr newGuard = guard->simplify();
    if (newGuard != guard) {
        const Rule newRule = res->withGuard(newGuard);
        res.ruleTransformationProof(res.get(), "Simplified Guard", newRule);
        res = newRule;
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    res.concat(eliminateByTransitiveClosure(*res, true, isTempOnlyInGuard));

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
    RuleResult res {rule};
    auto changed {false};
    do {
        auto tmp {simplifyRule(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}

ResultBase<BoolExpr, Proof> makeEqualities(const BoolExpr &e) {
    ResultBase<BoolExpr, Proof> res {e};
    const auto eqs {GuardToolbox::makeEqualities(e)};
    if (eqs) {
        res = e & BExpression::buildAndFromLits(*eqs);
        res.append("Extracted Implied Equalities");
        res.storeSubProof(eqs.getProof());
    }
    return res;
}

ResultBase<BoolExpr, Proof> propagateBooleanEqualities(const BoolExpr &e) {
    ResultBase<BoolExpr, Proof> res {e};
    const auto subs {GuardToolbox::propagateBooleanEqualities(e)};
    if (subs) {
        res = e->subs(Subs::build<BoolTheory>(*subs));
        res.append("Propagated Equivalences");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<BoolExpr, Proof> propagateEqualities(const BoolExpr e, SolvingLevel maxlevel, const GuardToolbox::SymbolAcceptor &allow) {
    ResultBase<BoolExpr, Proof> res {e};
    const auto subs {GuardToolbox::propagateEqualities(e, maxlevel, allow)};
    if (subs) {
        res = e->subs(Subs::build<IntTheory>(*subs));
        res.append("Extracted Implied Equalities");
        res.storeSubProof(subs.getProof());
    }
    return res;
}

ResultBase<Transition, Proof> eliminateTempVars(const Transition &trans) {
    ResultBase<BoolExpr, Proof> res(trans.toBoolExpr());

    //equalities allow easy propagation, thus transform x <= y, x >= y into x == y
    res.concat(makeEqualities(*res));
    res.fail(); // *just* finding implied equalities does not suffice for success

    res.concat(propagateBooleanEqualities(*res));

    //try to remove all remaining temp variables (we do 2 steps to prioritize removing vars from the update)
    res.concat(propagateEqualities(*res, ResultMapsToInt, expr::isTempVar));

    BoolExpr simplified = (*res)->simplify();
    if (simplified != *res) {
        res = simplified;
        res.append("Simplified Formula");
    }

    //now eliminate a <= x and replace a <= x, x <= b by a <= b for all free variables x where this is sound
    //(not sound if x appears in update or cost, since we then need the value of x)
    res.concat(GuardToolbox::eliminateByTransitiveClosure(*res, true, expr::isTempVar));

    ResultBase<Transition, Proof> ret {trans};
    if (res) {
        ret = Transition(*res, trans.var_map());
        ret.append("Eliminated Temporary Variables");
        ret.storeSubProof(res.getProof());
    }
    return ret;
}

ResultBase<Transition, Proof> Preprocess::preprocessTransition(const Transition &trans) {
    ResultBase<Transition, Proof> res {trans};
    auto changed {false};
    do {
        auto tmp {eliminateTempVars(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}
