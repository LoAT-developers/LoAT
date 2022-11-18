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
        LocationIdx sink,
        Complexity cpx,
        const AccelConfig &config)
    : its(its), rule(rule), sink(sink), cpx(cpx), config(config) {}

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
                    const auto sub_res = Chaining::chainRules(its, res, renameTmpVars(res, its));
                    if (sub_res) {
                        res = *sub_res;
                        period *= 2;
                        break;
                    } else {
                        return {res, period};
                    }
                }
            }
        }
    }
    // chain if there are updates like x = y; y = x
    std::map<NumVar, unsigned> cycleLength;
    auto up = res.getUpdate().get<IntTheory>();
    for (const auto &p: up) {
        auto vars = p.second.vars();
        unsigned oldSize = 0;
        unsigned count = 0;
        while (oldSize != vars.size() && vars.find(p.first) == vars.end()) {
            oldSize = vars.size();
            count++;
            for (const auto& var: vars) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    vars.insert(newVars.begin(), newVars.end());
                }
            }
        }
        if (vars.find(p.first) != vars.end() && count > 0) {
            cycleLength[p.first] = count;
        }
    }
    if (!cycleLength.empty()) {
        unsigned lcm = 1;
        for (const auto &e: cycleLength) {
            lcm = std::lcm(lcm, e.second);
        }
        for (unsigned i = 0; i < lcm; ++i) {
            const auto sub_res = Chaining::chainRules(its, res, renameTmpVars(res, its));
            if (sub_res) {
                res = *sub_res;
                period *= 2;
            } else {
                return {res, period};
            }
        }
    }
    // chain if it eliminates variables from an update
    bool changed;
    do {
        changed = false;
        up = res.getUpdate().get<IntTheory>();
        for (const auto &p: up) {
            auto varsOneStep = p.second.vars();
            std::set<NumVar> varsTwoSteps;
            for (const auto &var: varsOneStep) {
                const auto it = up.find(var);
                if (it != up.end()) {
                    const auto newVars = it->second.vars();
                    varsTwoSteps.insert(newVars.begin(), newVars.end());
                } else {
                    varsTwoSteps.insert(var);
                }
            }
            if (varsTwoSteps.size() < varsOneStep.size() && std::includes(varsOneStep.begin(), varsOneStep.end(), varsTwoSteps.begin(), varsTwoSteps.end())) {
                const auto sub_res = Chaining::chainRules(its, res, renameTmpVars(res, its));
                if (sub_res) {
                    res = *sub_res;
                    period *= 2;
                    changed = true;
                    break;
                } else {
                    return {res, period};
                }
            }
        }
    } while (changed);
    return {res, period};
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
    // only check sat if we didn't chain, as chaining ensures that the guard is sat
    if (period == 1 && SmtFactory::check(rule.getGuard(), its) != Sat) {
        res.status = acceleration::Unsat;
        return res;
    } else if (period > 1) {
        res.proof.ruleTransformationProof(this->rule, "unrolling", rule, its);
        res.period = period;
    }
    // for rules with runtime 1, our acceleration techniques do not work properly,
    // as the closed forms are usually only valid for n > 0 --> special case
    if (!Chaining::chainRules(its, rule, rule)) {
        if (config.allowSameUpdate) {
            res.rule = rule;
            res.status = acceleration::PseudoLoop;
            res.proof.append("rule cannot be iterated more than once");
        }
        return res;
    }
    const auto rec = Recurrence::iterateRule(its, rule);
    if (!rec && config.approx != UnderApprox) {
        res.status = acceleration::ClosedFormFailed;
        return res;
    }
    if (rec && !config.allowSameUpdate && rec->update == rule.getUpdate()) {
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
                    sink,
                    {});
        res.proof.ruleTransformationProof(rule, "nonterm", *res.rule, its);
        res.proof.storeSubProof(accelerationResult.nonterm->proof);
    }
    if (rec && accelerationResult.term) {
        if (rec->validityBound > 1) {
            throw logic_error("validity bound should be at most one due to unrolling");
        }
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
        LocationIdx sink,
        Complexity cpx,
        const AccelConfig &config) {
    LoopAcceleration ba(its, rule, sink, cpx, config);
    return ba.run();
}
