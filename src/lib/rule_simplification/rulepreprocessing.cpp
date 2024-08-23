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
#include "formulapreprocessing.hpp"
#include "theory.hpp"
#include "intfm.hpp"

#include <unordered_set>
#include <numeric>

using namespace std;

RuleResult propagateEquivalences(const Rule &rule) {
    RuleResult res{rule};
    const auto subs{Preprocess::propagateEquivalences(rule.getGuard())};
    if (subs) {
        res = res->subs(Subs::build<Bools>(*subs));
        res.ruleTransformationProof(rule, "Propagated Equivalences", *res);
        res.storeSubProof(subs.getProof());
    }
    return res;
}

RuleResult eliminateIdentities(const Rule &rule) {
    RuleResult res{rule};
    Subs update = rule.getUpdate();
    VarSet remove;
    for (const auto &[x, v] : update) {
        if (TheTheory::varToExpr(x) == v) {
            remove.insert(x);
        }
    }
    if (!remove.empty()) {
        update.erase(remove);
        res = rule.withUpdate(update);
        res.ruleTransformationProof(rule, "Removed Identity Updates", res.get());
    }
    return res;
}

RuleResult propagateEqualitiesImpl(const Rule &rule, const Preprocess::SymbolAcceptor &allow) {
    RuleResult res{rule};
    const auto subs{Preprocess::propagateEqualities(rule.getGuard(), allow)};
    if (subs) {
        res = res->subs(Subs::build<Arith>(*subs));
        res.ruleTransformationProof(rule, "Extracted Implied Equalities", *res);
        res.storeSubProof(subs.getProof());
    }
    return res;
}

RuleResult propagateEqualities(const Rule &rule) {
    return propagateEqualitiesImpl(rule, theory::isTempVar);
}

RuleResult propagateEqualitiesPickily(const Rule &rule) {
    auto varsInUpdate{rule.getUpdate().coDomainVars()};
    Preprocess::SymbolAcceptor isTempInUpdate{[&](const Var &sym) {
        return theory::isTempVar(sym) && varsInUpdate.contains(sym);
    }};
    return propagateEqualitiesImpl(rule, isTempInUpdate);
}

/**
 * Returns the set of all variables that appear in the rhs of some update.
 * For an update x := a and x := x+a, this is {a} and {x,a}, respectively.
 */
VarSet collectVarsInUpdateRhs(const Rule &rule) {
    VarSet varsInUpdate;
    for (const auto &[_, v] : rule.getUpdate()) {
        theory::collectVars(v, varsInUpdate);
    }
    return varsInUpdate;
}

RuleResult fourierMotzkin(const Rule &rule) {
    RuleResult res{rule};
    VarSet varsInUpdate = collectVarsInUpdateRhs(rule);
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    const auto new_guard{integerFourierMotzkin(rule.getGuard(), isTempOnlyInGuard)};
    if (new_guard) {
        res = res->withGuard(*new_guard);
        res.ruleTransformationProof(rule, "Eliminated Temporary Variables", *res);
        res.storeSubProof(new_guard.getProof());
    }
    return res;
}

RuleResult eliminateArithVars(const Rule &rule) {
    auto res{propagateEqualitiesPickily(rule)};
    if (res) {
        return res;
    }
    res = propagateEqualities(rule);
    if (res) {
        return res;
    }
    return fourierMotzkin(rule);
}

RuleResult Preprocess::preprocessRule(const Rule &rule) {
    auto res{propagateEquivalences(rule)};
    res.concat(eliminateIdentities(*res));
    bool changed;
    do {
        const auto tmp{eliminateArithVars(*res)};
        changed = bool(tmp);
        res.concat(tmp);
    } while (changed);
    return res;
}

RuleResult Preprocess::removeTrivialUpdates(const Rule &rule) {
    RuleResult res{rule};
    Subs update = rule.getUpdate();
    VarSet remove;
    for (const auto &[x, v] : update.get<Arith>()) {
        if (!remove.contains(x) && rule.getGuard()->getEquality(x) == std::optional{v}) {
            remove.insert(x);
        }
    }
    if (!remove.empty()) {
        update.erase(remove);
        res = rule.withUpdate(update);
        res.ruleTransformationProof(rule, "Removed Trivial Updates", res.get());
    }
    return res;
}
