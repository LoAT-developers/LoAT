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
#include "accelerationfactory.hpp"
#include "chain.hpp"
#include "expr.hpp"

#include <purrs.hh>
#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(
        const Rule &rule,
        const Subs &sample_point,
        const AccelConfig &config)
    : rule(rule), sample_point(sample_point), config(config) {
    auto up {rule.getUpdate()};
    up.put<IntTheory>(NumVar::loc_var, Expr(NumVar::loc_var));
    this->rule = rule.withUpdate(up);
}

const std::pair<Rule, unsigned> LoopAcceleration::chain(const Rule &rule) {
    Rule res = rule;
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
                    res = Chaining::chain(res, res).first;
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
                res = Chaining::chain(res, res).first;
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
        const auto var = expr::first(p);
        const auto ex = expr::second(p);
        auto vars = expr::vars(ex);
        unsigned oldSize = 0;
        unsigned count = 1;
        while (oldSize != vars.size() && vars.find(var) == vars.end()) {
            oldSize = vars.size();
            count++;
            VarSet toInsert;
            for (const auto& var: vars) {
                auto it = up.find(var);
                if (it != up.end()) {
                    toInsert.insertAll(expr::vars(expr::second(*it)));
                }
            }
            vars.insertAll(toInsert);
        }
        if (count > 0 && vars.find(var) != vars.end()) {
            cycleLength = std::lcm(cycleLength, count);
        }
    }
    if (cycleLength > 1) {
        Rule orig(res);
        for (unsigned i = 1; i < cycleLength; ++i) {
            res = Chaining::chain(res, orig).first;
        }
        period *= cycleLength;
    }
    Rule orig(res);
    // chain if it eliminates variables from an update
    NEXT: while (true) {
        const auto up = res.getUpdate().get<IntTheory>();
        for (const auto &p: up) {
            std::set<NumVar> varsOneStep(p.second.vars());
            std::set<NumVar> varsTwoSteps;
            for (const auto &var: varsOneStep) {
                if (expr::isTempVar(var)) {
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
                if (expr::isTempVar(var)) {
                    continue;
                }
                if (varsTwoSteps.find(var) == varsTwoSteps.end()) {
                    res = Chaining::chain(res, orig).first;
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
    if (config.approx != UnderApprox) {
        if (!rule.getGuard()->isConjunction()) {
            res.status = acceleration::Disjunctive;
            return res;
        }
        // for non-deterministic loops, we can only offer under-approximations
        for (const auto &x: rule.vars()) {
            if (expr::isTempVar(x)) {
                res.status = acceleration::Nondet;
                return res;
            }
        }
    }
    const auto [rule, period] = chain(this->rule);
    switch (SmtFactory::check(rule.getGuard())) {
    case Unsat: res.status = acceleration::PseudoLoop;
        return res;
    case Unknown: res.status = acceleration::NotSat;
        return res;
    case Sat: {}
    }
    Proof proof;
    if (period > 1) {
        res.period = period;
        proof.append(stringstream() << "period: " << period);
    }
    // for rules with runtime 1, our acceleration techniques do not work properly,
    // as the closed forms are usually only valid for n > 0 --> special case
    switch (SmtFactory::check(rule.chain(rule).getGuard())) {
    case Unsat:
        res.accel = {BExpression::True, rule, proof};
        res.accel->proof.append("rule cannot be iterated more than once");
        res.status = acceleration::PseudoLoop;
        return res;
    case Unknown: res.status = acceleration::NotSat;
        return res;
    case Sat: {}
    }
    const auto rec {Recurrence::solve(rule.getUpdate())};
    if (!rec && config.approx != UnderApprox) {
        res.status = acceleration::ClosedFormFailed;
        return res;
    }
    res.prefix = rec->prefix;
    const auto accelerationTechnique {AccelerationFactory::get(rule, rec, sample_point, config)};
    const auto accelerationResult {accelerationTechnique->computeRes()};
    if (!accelerationResult.term && config.approx != UnderApprox) {
        res.status = acceleration::AccelerationFailed;
        return res;
    }
    if (config.tryNonterm && accelerationResult.nonterm) {
        res.nonterm = {accelerationResult.nonterm->covered, accelerationResult.nonterm->formula, proof};
        res.nonterm->proof.concat(accelerationResult.nonterm->proof);
    }
    if (rec && accelerationResult.term) {
        res.n = rec->n;
        Rule r {accelerationResult.term->formula, rec->closed_form};
        for (unsigned i = 0; i < res.prefix; ++i) {
            r = rule.chain(r);
        }
        res.accel = {accelerationResult.term->covered, r, proof};
        res.accel->proof.concat(accelerationResult.term->proof);
    }
    return res;
}


acceleration::Result LoopAcceleration::accelerate(
        const Rule &rule,
        const Subs &sample_point,
        const AccelConfig &config) {
    LoopAcceleration ba(rule, sample_point, config);
    return ba.run();
}
