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
#include "loopcomplexity.hpp"
#include "ruleresult.hpp"
#include "rulepreprocessing.hpp"

#include <purrs.hh>
#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(
    const Rule &rule,
    const std::optional<Subs> &sample_point,
    const AccelConfig &config)
    : rule(rule), sample_point(sample_point), config(config) {
    auto up {rule.getUpdate()};
    up.put<IntTheory>(NumVar::loc_var, NumVar::loc_var->toExpr());
    this->rule = rule.withUpdate(up);
}

std::pair<Rule, unsigned> LoopAcceleration::chain(const Rule &rule) {
    auto changed {false};
    auto res {rule};
    unsigned period {1};
    do {
        changed = false;
        RuleResult chained {Chaining::chain(res, res).first};
        chained.concat(Preprocess::preprocessRule(*chained));
        if (LoopComplexity::compute(res) > LoopComplexity::compute(*chained)) {
            res = *chained;
            period *= 2;
            changed = true;
        }
    } while (changed);
    return {res, period};
}

void LoopAcceleration::chain() {
    const auto &[chained, period] {chain(rule)};
    rule = chained;
    res.period = period;
}

void LoopAcceleration::store_nonterm(const AccelerationProblem::Accelerator &accelerator) {
    if (accelerator.nonterm) {
        res.nonterm = acceleration::Nonterm();
        res.nonterm->proof = accelerator.proof;
        res.nonterm->certificate = BExpression::mkAnd(accelerator.formula);
    }
}

void LoopAcceleration::try_nonterm() {
    if (config.tryNonterm) {
        AccelConfig c {config};
        c.tryAccel = false;
        const auto accelerator {AccelerationProblem(rule, rec, sample_point, c).computeRes()};
        if (accelerator) {
            store_nonterm(*accelerator);
        }
    }
}

void LoopAcceleration::compute_closed_form() {
    rec = Recurrence::solve(rule.getUpdate(), config.n);
    if (rec) {
        res.prefix = rec->prefix;
        const auto is_temp_var = [](const auto z){
            return z->isTempVar();
        };
        for (const auto &[x,y]: rule.getUpdate().get<IntTheory>()) {
            if (y->has(x) && y != x->toExpr()) {
                if (!y->hasVarWith(is_temp_var)) {
                    return;
                }
                if (!y->isLinear()) {
                    continue;
                }
                const auto vars {y->vars()};
                auto all_lower_bounded {true};
                auto all_upper_bounded {true};
                for (const auto &z: vars) {
                    if (z->isTempVar()) {
                        const auto bounds {rule.getGuard()->getBounds(z)};
                        const auto coeff {*(*y->coeff(z))->isRational()};
                        auto lower_bounded {false};
                        auto upper_bounded {false};
                        for (const auto &b: bounds.lowerBounds) {
                            if (!b->hasVarWith(is_temp_var)) {
                                if (bounds.upperBounds.contains(b)) {
                                    lower_bounded = true;
                                    upper_bounded = true;
                                }
                                if (coeff > 0) {
                                    lower_bounded = true;
                                } else {
                                    upper_bounded = true;
                                }
                                if (lower_bounded && upper_bounded) {
                                    break;
                                }
                            }
                        }
                        if (!lower_bounded || !upper_bounded) {
                            for (const auto &b: bounds.upperBounds) {
                                if (!b->hasVarWith(is_temp_var)) {
                                    if (coeff > 0) {
                                        upper_bounded = true;
                                    } else {
                                        lower_bounded = true;
                                    }
                                    if (lower_bounded && upper_bounded) {
                                        break;
                                    }
                                }
                            }
                        }
                        all_lower_bounded &= lower_bounded;
                        all_upper_bounded &= upper_bounded;
                        if (!all_lower_bounded && !all_upper_bounded) {
                            break;
                        }
                    }
                }
                if (all_lower_bounded || all_upper_bounded) {
                    return;
                }
            }
        }
    }
    res.prefix = 0;
    rec = {};
    res.status = acceleration::ClosedFormFailed;
}

void LoopAcceleration::accelerate() {
    if (rec && config.tryAccel) {
        const auto accelerator {AccelerationProblem(rule, rec, sample_point, config).computeRes()};
        if (accelerator) {
            res.accel = acceleration::Accel(Rule(BExpression::mkAnd(accelerator->formula), rec->closed_form));
            res.accel->proof = accelerator->proof;
            res.accel->covered = BExpression::mkAnd(accelerator->covered);
            prepend_first = accelerator->prependFirst;
            store_nonterm(*accelerator);
        }
    }
}

void LoopAcceleration::prepend_prefix() {
    unsigned bound = prepend_first ? 0 : 1;
    if (res.prefix > bound && res.accel) {
        auto prefix {rule};
        for (unsigned i = bound + 1; i < res.prefix; ++i) {
            prefix = prefix.chain(rule);
        }
        res.accel->rule = prefix.chain(res.accel->rule);
        if (SmtFactory::check(res.accel->rule.getGuard()) != SmtResult::Sat) {
            res.accel = {};
        }
    }
}

void LoopAcceleration::run() {
    res.status = acceleration::AccelerationFailed;
    if (!rule.getGuard()->isConjunction()) {
        res.status = acceleration::Disjunctive;
    } else {
        chain();
        switch (SmtFactory::check(Chaining::chain(rule, rule).first.getGuard())) {
        case Unsat: res.status = acceleration::PseudoLoop;
            return;
        case Unknown: res.status = acceleration::NotSat;
            return;
        case Sat: {
            compute_closed_form();
            accelerate();
            if (config.tryNonterm && !res.nonterm) {
                try_nonterm();
            }
            prepend_prefix();
            if (res.accel) {
                res.status = acceleration::Success;
            } else if (res.nonterm) {
                res.status = acceleration::Nonterminating;
            }
        }
        }
    }
}

acceleration::Result LoopAcceleration::accelerate(
    const Rule &rule,
    const Subs &sample_point,
    const AccelConfig &config) {
    LoopAcceleration accel{rule, sample_point, config};
    accel.run();
    return accel.res;
}

acceleration::Result LoopAcceleration::accelerate(
    const Rule &rule,
    const AccelConfig &config) {
    LoopAcceleration accel{rule, std::optional<Subs>(), config};
    accel.run();
    return accel.res;
}
