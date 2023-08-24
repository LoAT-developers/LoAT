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
#include "accelerationproblem.hpp"
#include "chain.hpp"
#include "expr.hpp"

#include <purrs.hh>
#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(
        const Rule &rule,
        const std::optional<Subs> &sample_point,
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

Rule LoopAcceleration::overApproximatingAcceleration(const Subs &closed_form) {
    Subs up;
    for (const auto &p: closed_form) {
        auto tmp {false};
        for (const auto &x: expr::vars(expr::second(p))) {
            if (x != Var(config.n) && expr::isTempVar(x)) {
                const auto var {expr::first(p)};
                up.put(var, expr::toExpr(expr::next(var)));
                tmp = true;
                break;
            }
        }
        if (!tmp) {
            up.put(p);
        }
    }
    BoolExprSet lits, up_lits;
    auto previous {Subs::build<IntTheory>(config.n, Expr(config.n)-1)};
    for (const auto &l: rule.getGuard()->lits()) {
        auto add {true};
        for (const auto &x: expr::variables(l)) {
            if (expr::isTempVar(x)) {
                add = false;
                break;
            }
        }
        if (add) {
            lits.insert(BExpression::buildTheoryLit(l));
        }
        auto updated {expr::subs(l, up)};
        add = true;
        for (const auto &x: updated->vars()) {
            if (x != Var(config.n) && expr::isTempVar(x)) {
                add = false;
                break;
            }
        }
        if (add) {
            lits.insert(updated->subs(previous));
        }
    }
    auto guard {BExpression::buildAnd(lits) & Rel::buildGt(config.n, 0)};
    return Rule(guard, up);
}

acceleration::Result LoopAcceleration::run() {
    acceleration::Result res;
    if (!rule.getGuard()->isConjunction()) {
        res.status = acceleration::Disjunctive;
        return res;
    }
    const auto [rule, period] = chain(this->rule);
    Proof proof;
    if (period > 1) {
        res.period = period;
        proof.append(stringstream() << "period: " << period);
    }
    switch (SmtFactory::check(Chaining::chain(rule, rule).first.getGuard())) {
    case Unsat: res.status = acceleration::PseudoLoop;
        return res;
    case Unknown: res.status = acceleration::NotSat;
        return res;
    case Sat: {}
    }
    const auto rec {Recurrence::solve(rule.getUpdate(), config.n)};
    if (!rec && !config.tryNonterm) {
        res.status = acceleration::ClosedFormFailed;
        return res;
    }
    res.prefix = rec->prefix;
    std::optional<Rule> accel_rule;
    auto covered {BExpression::True};
    if (config.approx == OverApprox) {
        accel_rule = overApproximatingAcceleration(rec->closed_form);
        proof.append("over-approximating acceleration using closed form");
        res.status = acceleration::Success;
    } else {
        auto accelerator {AccelerationProblem(rule, rec, sample_point, config).computeRes()};
        res.status = acceleration::AccelerationFailed;
        if (accelerator) {
            res.status = acceleration::Success;
            covered = BExpression::buildAnd(accelerator->covered);
            accel_rule = Rule(BExpression::buildAnd(accelerator->formula), rec->closed_form);
            proof.concat(accelerator->proof);
        }
        if (config.tryNonterm && (!accelerator || !accelerator->nonterm)) {
            accelerator = AccelerationProblem(rule, {}, sample_point, config).computeRes();
            if (accelerator) {
                if (res.status == acceleration::AccelerationFailed) {
                    res.status = acceleration::Nonterminating;
                }
                res.nonterm = {BExpression::buildAnd(accelerator->formula), proof};
                res.nonterm->proof.concat(accelerator->proof);
            }
        }
    }
    if (accel_rule) {
        for (unsigned i = 1; i < res.prefix; ++i) {
            accel_rule = rule.chain(*accel_rule);
        }
        res.accel = {*accel_rule, proof, covered};
    }
    return res;
}


acceleration::Result LoopAcceleration::accelerate(
        const Rule &rule,
        const Subs &sample_point,
        const AccelConfig &config) {
    return LoopAcceleration(rule, sample_point, config).run();
}

acceleration::Result LoopAcceleration::accelerate(
        const Rule &rule,
        const AccelConfig &config) {
    return LoopAcceleration(rule, std::optional<Subs>(), config).run();
}
