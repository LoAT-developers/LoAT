/*  This file is part of LoAT.
 *  Copyright (c) 2018-2019 Florian Frohn
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

#include "loopacceleration.hpp"
#include "smtfactory.hpp"
#include "recurrence.hpp"
#include "chain.hpp"
#include "accelerationfactory.hpp"

#include <purrs.hh>
#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(
        ITSProblem &its,
        const LinearRule &rule,
        Complexity cpx,
        const AccelConfig &config)
    : its(its), rule(rule), cpx(cpx), config(config) {}

bool LoopAcceleration::shouldAccelerate() const {
    return (!Config::Analysis::tryNonterm() || !rule.getCost().isNontermSymbol()) && (!Config::Analysis::complexity() || rule.getCost().isPoly());
}

LinearRule LoopAcceleration::renameTmpVars(const LinearRule &rule, ITSProblem &its) {
    Subs sigma;
    for (const auto &x: rule.vars()) {
        if (its.isTempVar(x)) {
            if (std::holds_alternative<NumVar>(x)) {
                const auto &var = std::get<NumVar>(x);
                sigma.put<IntTheory>(var, its.addFreshTemporaryVariable<IntTheory>(var.getName()));
            } else if (std::holds_alternative<BoolVar>(x)) {
                const auto &var = std::get<BoolVar>(x);
                sigma.put<BoolTheory>(var, BExpression::buildTheoryLit(its.addFreshTemporaryVariable<BoolTheory>(var.getName())));
            }
        }
    }
    return rule.subs(sigma).toLinear();
}

const std::pair<LinearRule, unsigned> LoopAcceleration::chain(const LinearRule &rule, ITSProblem &its) {
    LinearRule res = rule;
    unsigned period = 1;
    // chain if there are updates like x = -x + p
    for (const auto &p: rule.getUpdate().get<IntTheory>()) {
        const auto var = p.first;
        const auto up = p.second.expand();
        const auto upVars = up.vars();
        if (upVars.find(var) != upVars.end()) {
            if (up.isPoly() && up.degree(var) == 1) {
                const Expr coeff = up.coeff(var);
                if (coeff.isRationalConstant() && coeff.toNum().is_negative()) {
                    res = *Chaining::chainRules(its, res, renameTmpVars(res, its), false);
                    period = 2;
                    break;
                }
            }
        }
    }
    if (period == 1) {
        // chain if there are updates like b = !b
        for (const auto &p: rule.getUpdate().get<BoolTheory>()) {
            const auto lits = p.second->lits();
            const auto lit = BoolLit(p.first);
            if (lits.find(!lit) != lits.end() && lits.find(lit) == lits.end()) {
                res = *Chaining::chainRules(its, res, renameTmpVars(res, its), false);
                period = 2;
                break;
            }
        }
    }
    // chain if there are updates like x = y; y = x
    unsigned cycleLength = 1;
    const auto up = res.getUpdate();
    for (const auto &p: up) {
        if (p.index() == 1) continue;
        const auto var = substitution::first(p);
        const auto expr = substitution::second(p);
        auto vars = expression::variables(expr);
        unsigned oldSize = 0;
        unsigned count = 1;
        while (oldSize != vars.size() && vars.find(var) == vars.end()) {
            oldSize = vars.size();
            count++;
            VarSet toInsert;
            for (const auto& var: vars) {
                auto it = up.find(var);
                if (it != up.end()) {
                    toInsert.insertAll(expression::variables(substitution::second(*it)));
                }
            }
            vars.insertAll(toInsert);
        }
        if (count > 0 && vars.find(var) != vars.end()) {
            cycleLength = std::lcm(cycleLength, count);
        }
    }
    if (cycleLength > 1) {
        LinearRule orig(res);
        for (unsigned i = 1; i < cycleLength; ++i) {
            res = *Chaining::chainRules(its, res, renameTmpVars(orig, its), false);
        }
        period *= cycleLength;
    }
    LinearRule orig(res);
    // chain if it eliminates variables from an update
    NEXT: while (true) {
        const auto up = res.getUpdate().get<IntTheory>();
        for (const auto &p: up) {
            std::set<NumVar> varsOneStep(p.second.vars());
            std::set<NumVar> varsTwoSteps;
            for (const auto &var: varsOneStep) {
                if (its.isTempVar(var)) {
                    continue;
                }
                auto it = up.find(var);
                if (it == up.end()) {
                    varsTwoSteps.insert(var);
                } else {
                    const auto toInsert = it->second.vars();
                    varsTwoSteps.insert(toInsert.begin(), toInsert.end());
                }
            }
            for (const auto &var: varsOneStep) {
                if (its.isTempVar(var)) {
                    continue;
                }
                if (varsTwoSteps.find(var) == varsTwoSteps.end()) {
                    res = *Chaining::chainRules(its, res, renameTmpVars(orig, its), false);
                    period *= 2;
                    goto NEXT;
                }
            }
        }
        return {res, period};
    }
}

acceleration::Result LoopAcceleration::run() {
    acceleration::Result res;
    if (!shouldAccelerate()) {
        return res;
    }
    if (config.approx != UnderApprox) {
        if (!rule.getGuard()->isConjunction()) {
            res.status = acceleration::Disjunctive;
            return res;
        }
        // for non-deterministic loops, we can only offer under-approximations
        for (const auto &x: rule.vars()) {
            if (its.isTempVar(x)) {
                res.status = acceleration::Nondet;
                return res;
            }
        }
    }
    const auto [rule, period] = chain(this->rule, its);
    if (SmtFactory::check(rule.getGuard(), its) != Sat) {
        res.status = acceleration::Unsat;
        return res;
    } else if (period > 1) {
        res.proof.ruleTransformationProof(this->rule, "unrolling", rule, its);
        res.period = period;
    }
    // for rules with runtime 1, our acceleration techniques do not work properly,
    // as the closed forms are usually only valid for n > 0 --> special case
    if (!Chaining::chainRules(its, rule, rule)) {
        res.rule = rule;
        res.status = acceleration::PseudoLoop;
        res.proof.append("rule cannot be iterated more than once");
        return res;
    }
    const auto rec = Recurrence::iterateRule(its, rule);
    if (!rec && config.approx != UnderApprox) {
        res.status = acceleration::ClosedFormFailed;
        return res;
    }
    const auto accelerationTechnique = AccelerationFactory::get(rule, rec, its, config);
    const auto accelerationResult = accelerationTechnique->computeRes();
    if (!accelerationResult.term && config.approx != UnderApprox) {
        res.status = acceleration::AccelerationFailed;
        return res;
    }
    if (Config::Analysis::tryNonterm() && accelerationResult.nonterm) {
        res.nontermRule = LinearRule(
                    rule.getLhsLoc(),
                    accelerationResult.nonterm->formula,
                    Expr::NontermSymbol,
                    its.getSink(),
                    {});
        res.proof.ruleTransformationProof(rule, "nonterm", *res.nontermRule, its);
        res.proof.storeSubProof(accelerationResult.nonterm->proof);
    }
    if (rec && accelerationResult.term) {
        res.n = rec->n;
        res.rule = LinearRule(
                    rule.getLhsLoc(),
                    accelerationResult.term->formula,
                    rec->cost,
                    rule.getRhsLoc(),
                    rec->update);
        res.proof.ruleTransformationProof(rule, "acceleration", *res.rule, its);
        res.proof.storeSubProof(accelerationResult.term->proof);
    }
    return res;
}


acceleration::Result LoopAcceleration::accelerate(
        ITSProblem &its,
        const LinearRule &rule,
        Complexity cpx,
        const AccelConfig &config) {
    LoopAcceleration ba(its, rule, cpx, config);
    return ba.run();
}
