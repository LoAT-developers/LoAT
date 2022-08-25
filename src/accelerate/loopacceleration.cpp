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

#include "smt.hpp"
#include "smtfactory.hpp"
#include "asymptoticbound.hpp"
#include "recurrence.hpp"
#include "metertools.hpp"
#include "guardtoolbox.hpp"
#include "relevantvariables.hpp"
#include "chain.hpp"
#include "accelerationfactory.hpp"
#include "vareliminator.hpp"
#include "status.hpp"
#include "export.hpp"

#include <purrs.hh>

using namespace std;

LoopAcceleration::LoopAcceleration(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx)
    : its(its), rule(rule), sink(sink), cpx(cpx) {}

bool LoopAcceleration::shouldAccelerate() const {
    return !rule.getCost().isNontermSymbol() && (!Config::Analysis::complexity() || rule.getCost().isPoly());
}

vector<Rule> LoopAcceleration::replaceByUpperbounds(const Var &N, const Rule &rule) {
    // gather all upper bounds (if possible)
    VarEliminator ve(rule.getGuard(), N, its);

    // avoid rule explosion (by not instantiating N if there are too many bounds)
    if (ve.getRes().empty() || ve.getRes().size() > Config::LoopAccel::MaxUpperboundsForPropagation) {
        return {};
    }

    // create one rule for each upper bound, by instantiating N with this bound
    vector<Rule> res;
    for (const Subs &subs : ve.getRes()) {
        if (subs.get(N).isRationalConstant()) continue;
        res.push_back(rule.subs(subs));
    }
    return res;
}

LinearRule LoopAcceleration::buildNontermRule(const BoolExpr &guard) const {
    return LinearRule(rule.getLhsLoc(), guard, Expr::NontermSymbol, sink, {});
}

AccelerationResult LoopAcceleration::run() {
    AccelerationResult res;
    res.status = Failure;
    if (shouldAccelerate()) {
        const auto rec = Recurrence::iterateRule(its, rule);
        auto accel = AccelerationFactory::get(rule, rec, its);
        for (const auto &ar: accel->computeRes()) {
            res.status = rec->validityBound > 1 ? PartialSuccess : Success;
            if (ar.witnessesNonterm) {
                option<Rule> resultingRule;
                if (rec->validityBound > 0) {
                    option<Rule> prefix = rule;
                    for (unsigned i = 0; i < rec->validityBound - 1; ++i) {
                        prefix = Chaining::chainRules(its, rule, prefix.get(), false);
                    }
                    resultingRule = buildNontermRule(prefix->getGuard() & ar.formula);
                    if (Smt::check(resultingRule->getGuard(), its) != Smt::Sat) {
                        continue;
                    }
                } else {
                    resultingRule = buildNontermRule(ar.formula);
                }
                res.rules.emplace_back(resultingRule.get());
                res.proof.ruleTransformationProof(rule, "nonterm", resultingRule.get(), its);
                res.proof.storeSubProof(ar.proof);
            } else {
                option<Rule> resultingRule;
                if (rec->validityBound > 0) {
                    option<Rule> prefix = rule;
                    for (unsigned i = 0; i < rec->validityBound - 1; ++i) {
                        prefix = Chaining::chainRules(its, rule, prefix.get(), false);
                    }
                    resultingRule = Rule(rule.getLhsLoc(), prefix->getGuard() & ar.formula, rec->cost, rule.getRhsLoc(), rec->update);
                } else {
                    resultingRule = Rule(rule.getLhsLoc(), ar.formula, rec->cost, rule.getRhsLoc(), rec->update);
                }
                const BoolExpr toCheck = resultingRule->getGuard()->subs({rec->n, max(2u, rec->validityBound)});
                if (Smt::check(toCheck, its) != Smt::Sat) {
                    continue;
                }
                res.proof.ruleTransformationProof(rule, "acceleration", resultingRule.get(), its);
                res.proof.storeSubProof(ar.proof);
                std::vector<Rule> instantiated = replaceByUpperbounds(rec->n, resultingRule.get());
                if (instantiated.empty()) {
                    res.rules.emplace_back(resultingRule.get());
                } else {
                    for (const Rule &r: instantiated) {
                        res.proof.ruleTransformationProof(resultingRule.get(), "instantiation", r, its);
                        res.rules.emplace_back(r);
                    }
                }
            }
        }
    }
    return res;
}


AccelerationResult LoopAcceleration::accelerate(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx) {
    LoopAcceleration ba(its, rule, sink, cpx);
    return ba.run();
}
