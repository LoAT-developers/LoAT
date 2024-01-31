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
    up.put<IntTheory>(NumVar::loc_var, Expr(NumVar::loc_var));
    this->rule = rule.withUpdate(up);
}

const std::pair<Rule, unsigned> LoopAcceleration::chain(const Rule &rule) {
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

acceleration::Result LoopAcceleration::run() {
    acceleration::Result res;
    if (!rule.getGuard()->isConjunction()) {
        res.status = acceleration::Disjunctive;
        return res;
    }
    const auto p {chain(this->rule)};
    const auto rule {p.first};
    const auto period {p.second};
    Proof proof, accel_proof;
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
    const auto try_nonterm = [&]() {
        const auto accelerator = AccelerationProblem(rule, {}, sample_point, config).computeRes();
        if (accelerator) {
            res.nonterm = {BExpression::buildAnd(accelerator->formula), proof};
            res.nonterm->proof.concat(accelerator->proof);
            return true;
        }
        return false;
    };
    if (!rec) {
        if (config.tryNonterm && try_nonterm()) {
            return res;
        } else {
            res.status = acceleration::ClosedFormFailed;
            return res;
        }
    }
    res.prefix = rec->prefix;
    std::optional<Rule> accel_rule;
    auto covered {top()};
    accel_proof = proof;
    auto accelerator {AccelerationProblem(rule, rec, sample_point, config).computeRes()};
    if (accelerator) {
        covered = BExpression::buildAnd(accelerator->covered);
        accel_rule = Rule(BExpression::buildAnd(accelerator->formula), rec->closed_form);
        accel_proof.concat(accelerator->proof);
        if (accelerator->nonterm) {
            res.nonterm = {BExpression::buildAnd(accelerator->formula), accel_proof};
        }
    }
    if (config.tryNonterm && (!accelerator || !accelerator->nonterm)) {
        try_nonterm();
    }
    if (res.prefix > 1) {
        auto prefix {rule};
        for (unsigned i = 2; i < res.prefix; ++i) {
            prefix = prefix.chain(rule);
        }
        if (accel_rule) {
            accel_rule = prefix.chain(*accel_rule);
            if (SmtFactory::check(accel_rule->getGuard()) != SmtResult::Sat) {
                accel_rule = {};
            }
        }
        if (res.nonterm) {
            res.nonterm->certificate = prefix.getGuard() & res.nonterm->certificate->subs(prefix.getUpdate());
            if (SmtFactory::check(res.nonterm->certificate) != SmtResult::Sat) {
                res.nonterm = {};
            }
        }
    }
    if (accel_rule) {
        res.status = acceleration::Success;
        res.accel = {*accel_rule, accel_proof, covered};
    } else if (res.nonterm) {
        res.status = acceleration::Nonterminating;
    } else {
        res.status = acceleration::AccelerationFailed;
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
