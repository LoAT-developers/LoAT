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
#include "boolexpression.hpp"
#include "smtfactory.hpp"
#include "recurrence.hpp"
#include "chain.hpp"
#include "accelerationfactory.hpp"

#include <purrs.hh>
#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx)
    : its(its), rule(rule), sink(sink), cpx(cpx) {}

bool LoopAcceleration::shouldAccelerate() const {
    return (!Config::Analysis::tryNonterm() || !rule.getCost().isNontermSymbol()) && (!Config::Analysis::complexity() || rule.getCost().isPoly());
}

const std::pair<LinearRule, unsigned> LoopAcceleration::chain() const {
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
                    res = Chaining::chainRules(its, res, res, false).get();
                    period *= 2;
                    break;
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
            res = Chaining::chainRules(its, res, res, false).get();
            period *= 2;
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
                res = Chaining::chainRules(its, res, res, false).get();
                period *= 2;
                changed = true;
                break;
            }
        }
    } while (changed);
    return {res, period};
}

AccelerationResult LoopAcceleration::run() {
    AccelerationResult res;
    if (!shouldAccelerate()) {
        return res;
    }
    const auto [rule, period] = chain();
    bool sat = SmtFactory::check(rule.getGuard(), its);
    if (sat != Sat) {
        return res;
    }
    if (period > 1) {
        res.proof.ruleTransformationProof(this->rule, "unrolling", rule, its);
        res.period = period;
    }
    const auto rec = Recurrence::iterateRule(its, rule);
    const auto accelerationTechnique = AccelerationFactory::get(rule, rec, its);
    const auto accelerationResult = accelerationTechnique->computeRes();
    if (Config::Analysis::tryNonterm() && accelerationResult.nonterm) {
        res.nontermRule = LinearRule(
                    rule.getLhsLoc(),
                    boolExpression::transform(accelerationResult.nonterm->formula),
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
        BoolExpr guard = boolExpression::transform(accelerationResult.term->formula);
        if (SmtFactory::check(guard->subs(Subs::build<IntTheory>(rec->n, 2)), its) == Sat) {
            res.rule = LinearRule(
                        rule.getLhsLoc(),
                        guard,
                        rec->cost,
                        rule.getRhsLoc(),
                        Subs::build<IntTheory>(rec->update));
            res.proof.ruleTransformationProof(rule, "acceleration", *res.rule, its);
            res.proof.storeSubProof(accelerationResult.term->proof);
        }
    }
    return res;
}


AccelerationResult LoopAcceleration::accelerate(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx) {
    LoopAcceleration ba(its, rule, sink, cpx);
    return ba.run();
}
