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
#include "theory.hpp"
#include "guardtoolbox.hpp"
#include "theory.hpp"

#include <unordered_set>
#include <numeric>

using namespace std;

/**
 * Returns the set of all variables that appear in the rhs of some update.
 * For an update x := a and x := x+a, this is {a} and {x,a}, respectively.
 */
static VarSet collectVarsInUpdateRhs(const Rule &rule) {
    VarSet varsInUpdate;
    for (const auto &[_, v] : rule.getUpdate()) {
        theory::collectVars(v, varsInUpdate);
    }
    return varsInUpdate;
}

RuleResult propagateBooleanEqualities(const Rule &rule) {
    RuleResult res {rule};
    const auto subs {GuardToolbox::propagateBooleanEqualities(rule.getGuard())};
    if (subs) {
        res = res->subs(Subs::build<Bools>(*subs));
        res.ruleTransformationProof(rule, "Propagated Equivalences", *res);
        res.storeSubProof(subs.getProof());
    }
    return res;
}

RuleResult propagateEqualities(const Rule &rule, GuardToolbox::SymbolAcceptor &allow) {
    RuleResult res {rule};
    const auto subs {GuardToolbox::propagateEqualities(rule.getGuard(), allow)};
    if (subs) {
        res = res->subs(Subs::build<Arith>(*subs));
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

RuleResult simplify(const Rule &rule) {
    RuleResult res {rule};
    const auto new_guard {GuardToolbox::simplify(rule.getGuard())};
    if (new_guard) {
        res = rule.withGuard(*new_guard);
        res.append("Simplified Guard");
        res.storeSubProof(new_guard.getProof());
    }
    return res;
}

RuleResult eliminateTempVars(Rule rule) {
    auto res {propagateBooleanEqualities(rule)};
    if (res) {
        return res;
    }
    auto varsInUpdate {rule.getUpdate().coDomainVars()};
    GuardToolbox::SymbolAcceptor isTemp {theory::isTempVar};
    GuardToolbox::SymbolAcceptor isTempInUpdate {[&](const Var &sym) {
        return isTemp(sym) && varsInUpdate.contains(sym);
    }};
    res = propagateEqualities(rule, isTempInUpdate);
    if (res) {
        return res;
    }
    varsInUpdate = rule.getUpdate().coDomainVars();
    res = propagateEqualities(rule, isTemp);
    if (res) {
        return res;
    }
    res = simplify(rule);
    if (res) {
        return res;
    }
    auto isTempOnlyInGuard = [&](const Var &sym) {
        VarSet varsInUpdate = collectVarsInUpdateRhs(rule);
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    return eliminateByTransitiveClosure(rule, true, isTempOnlyInGuard);
}

bool removeTrivialUpdates(Subs &update) {
    stack<Var> remove;
    for (const auto &[x,v] : update) {
        if (TheTheory::varToExpr(x) == v) {
            remove.push(x);
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

ResultBase<Transition, Proof> eliminateTempVars(const Transition &trans) {
    std::unordered_set<Var> post_vars;
    for (const auto &[_,y]: *trans.var_map()) {
        post_vars.emplace(y);
    }
    const auto allow = [&post_vars](const auto &x) {
        return theory::isTempVar(x) && !post_vars.contains(x);
    };
    const auto res {GuardToolbox::eliminateTempVars(trans.toBoolExpr(), allow)};
    ResultBase<Transition, Proof> ret {trans};
    if (res) {
        ret = Transition::build(*res, trans.var_map());
        ret.append("Eliminated Temporary Variables from Transition:");
        ret.appendAll(*res);
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
