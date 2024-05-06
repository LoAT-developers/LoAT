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

#include <numeric>

using namespace std;

LoopAcceleration::LoopAcceleration(
    const Rule &rule,
    const std::optional<Subs> &sample_point,
    const AccelConfig &config)
    : rule(rule), sample_point(sample_point), config(config) {}

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
        res.nonterm->certificate = bools::mkAnd(accelerator.formula);
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
    const auto fail = [&]() {
        res.prefix = 0;
        rec = {};
        res.status = acceleration::ClosedFormFailed;
    };
    const auto is_temp_var = [](const auto z) {
        return z->isTempVar();
    };
    // Heuristic: Search for updates x = x + p where p contains temporary variables without lower bounds
    // and temporary variables without upper bounds. Such updates are pretty much equivalent to x = *,
    // but accelerating them sometimes yields quite complex expressions. Hence, we do not accelerate them.
    for (const auto &[x, y] : rule.getUpdate().get<Arith>()) {
        if (y->has(x) && y->hasVarWith(is_temp_var)) {
            const auto vars{y->vars()};
            auto all_lower_bounded{true};
            auto all_upper_bounded{true};
            for (const auto &z : vars) {
                // check all temporary variables
                if (z->isTempVar()) {
                    // we can only check boundedness for linear expressions
                    if (!y->isLinear({{z}})) {
                        fail();
                        return;
                    }
                    // we can only check boundedness if z's coefficient is a constant
                    const auto c {(*y->coeff(z))->isRational()};
                    if (!c) {
                        fail();
                        return;
                    }
                    const auto coeff{***c};
                    const auto bounds{rule.getGuard()->getBounds(z)};
                    auto lower_bounded{false};
                    auto upper_bounded{false};
                    // check if z is bounded
                    for (const auto &b : bounds) {
                        // early exit
                        if (lower_bounded && upper_bounded) {
                            break;
                        }
                        // only consider bounds without temporary variables to keep things simple
                        if (!b.bound->hasVarWith(is_temp_var)) {
                            switch (b.kind) {
                            case BoundKind::Equality:
                                lower_bounded = true;
                                upper_bounded = true;
                                break;
                            case BoundKind::Lower:
                                if (coeff > 0) {
                                    lower_bounded = true;
                                } else {
                                    upper_bounded = true;
                                }
                                break;
                            case BoundKind::Upper:
                                if (coeff > 0) {
                                    upper_bounded = true;
                                } else {
                                    lower_bounded = true;
                                }
                                break;
                            }
                        }
                    }
                    all_lower_bounded &= lower_bounded;
                    all_upper_bounded &= upper_bounded;
                    // fail if at least one temporary variable has no lower bound,
                    // and at least one temporary variable has no upper bound
                    if (!all_lower_bounded && !all_upper_bounded) {
                        fail();
                        return;
                    }
                }
            }
        }
    }
    rec = Recurrence::solve(rule.getUpdate(), config.n);
    if (rec) {
        res.prefix = rec->prefix;
    } else {
        fail();
    }
}

void LoopAcceleration::accelerate() {
    if (rec && config.tryAccel) {
        const auto accelerator {AccelerationProblem(rule, rec, sample_point, config).computeRes()};
        if (accelerator) {
            res.accel = acceleration::Accel(Rule(bools::mkAnd(accelerator->formula), rec->closed_form));
            res.accel->proof = accelerator->proof;
            res.accel->covered = bools::mkAnd(accelerator->covered);
            store_nonterm(*accelerator);
        }
    }
}

void LoopAcceleration::prepend_prefix() {
    /*
     * For all literals p>0 in the guard, acceleration either ensures that p>0 is satisfied before the iterations [1..n], or all of the following:
     *
     * (A) p>0 holds before the 1st iteration
     * (B) p^{i-1}>0 holds for all i in [1..prefix]
     * (C) p>0 holds before the iterations (prefix..n]
     *
     * (B) is meaningless, as p^{i-1} only has the intended meaning if j >= prefix, or if the loop has been executed 'prefix-j' times before.
     *
     * Example: If the update is x=0, then we get x^(j)=0 and prefix = 1. So if j = 0, then x^(j) = 0 != x.
     *          However, if the loop has been executed prefix-j = 1 times before,
     *          then we have x = 0 before applying the accelerated transition, and thus we get x^(j) = 0 = x.
     *
     * If prefix = 0, then we are done due to (C).
     *
     * If prefix = 1, then we are done due to (A) and (C).
     *
     * If prefix > 1, we prepend the loop 'prefix-1' times via chaining. Then the guard is satisfied before the iterations
     * (a) [1..prefix) due to chaining,
     * (b) prefix-1 + 1 due to (A)
     * (c) prefix-1 + [2..prefix] due to (B), and
     * (d) prefix-1 + (prefix..n] due to (C).
     *
     * For (c), note that we would need to prepend the loop 'prefix' instead of 'prefix-1' times to also cover the case prefix-1 + 1 = prefix,
     * since then p^{0} would have the intended meaning.
     */
    if (res.prefix > 1 && res.accel) {
        auto prefix {rule};
        for (unsigned i = 1; i < res.prefix; ++i) {
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
            rule = *Preprocess::removeTrivialUpdates(rule);
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
