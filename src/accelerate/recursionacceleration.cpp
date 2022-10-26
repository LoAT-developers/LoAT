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

#include "recursionacceleration.hpp"
#include "metering.hpp"


using namespace std;

/**
 * Helper function that searches for a metering function and,
 * if not successful, tries to instantiate temporary variables.
 */
static MeteringFinder::Result meterWithInstantiation(ITSProblem &its, const Rule &rule) {
    // Searching for metering functions works the same for linear and nonlinear rules
    MeteringFinder::Result meter = MeteringFinder::generate(its, rule);

    // If we fail, try again after instantiating temporary variables
    // (we always want to try this heuristic, since it is often applicable)
    if (meter.result == MeteringFinder::Unsat) {
        const auto &instantiation = MeteringFinder::instantiateTempVarsHeuristic(its, rule);
        if (instantiation) {
            const Rule &instantiatedRule = instantiation.get().first;
            Proof proof = instantiation.get().second;
            meter = MeteringFinder::generate(its, instantiatedRule);
            proof.concat(meter.proof);
            meter.proof = proof;
        }
    }

    return meter;
}


/**
 * Helper function that calls meterWithInstantiation and, if successful,
 * tries to compute the iterated cost and update (for linear rules) or tries
 * to approximate the iterated cost (for nonlinear rules).
 *
 * @param sink Used for non-terminating and nonlinear rules (since we do not know to what they evaluate).
 * otherwise it is not modified.
 */
static AccelerationResult meterAndIterate(ITSProblem &its, const Rule &r, LocationIdx sink) {
    using namespace RecursionAcceleration;
    AccelerationResult res;

    // We may require that the cost is at least 1 in every single iteration of the loop.
    // For linear rules, this is only required for non-termination (see special case below).
    // For nonlinear rules, we lower bound the costs by 1 for the iterated cost, so we always require this.
    // Note that we have to add this before searching for a metering function, since it has to hold in every step.
    Rule rule = r.withGuard(r.getGuard() & Rel::buildGeq(r.getCost(), 1));

    // Try to find a metering function
    MeteringFinder::Result meter = meterWithInstantiation(its, rule);
    if (meter.rule) {
        rule = meter.rule.get();
    }

    switch (meter.result) {
        case MeteringFinder::Nonlinear:
        case MeteringFinder::Nonterm:
        case MeteringFinder::Unsat:
            return res;

        case MeteringFinder::Success:
        {
            string meterStr = meter.metering.toString();

            // First apply the modifications required for this metering function
            Rule newRule = rule;
            if (meter.integralConstraint) {
                newRule = newRule.withGuard(newRule.getGuard() & meter.integralConstraint.get());
                meterStr += " (where " + meter.integralConstraint.get().toString() + ")";
            }

            // Compute the "iterated costs" by just assuming every step has cost 1
            Expr degree = static_cast<long>(newRule.rhsCount());
            Expr newCost = degree ^ meter.metering;
            newRule = newRule.withCost((newCost - 1) / (degree - 1)); // resulting cost is (d^meter-1)/(d-1)

            // We don't know to what result the rule evaluates (multiple rhss, so no single result).
            // So we have to clear the rhs (fresh sink location, update is irrelevant).
            const Rule &accelRule = newRule.replaceRhssBySink(sink);
            res.proof.ruleTransformationProof(rule, "Acceleration with metering function " + meterStr, accelRule, its);
            res.rule = accelRule;

            return res;
        }
    }

    throw std::logic_error("unreachable");
}


AccelerationResult RecursionAcceleration::accelerateFast(ITSProblem &its, const Rule &rule, LocationIdx sink) {
    return meterAndIterate(its, rule, sink);
}


AccelerationResult RecursionAcceleration::accelerate(ITSProblem &its, const Rule &rule, LocationIdx sink) {
    // Try to find a metering function without any heuristics
    AccelerationResult accel = meterAndIterate(its, rule, sink);
    if (accel.rule) {
        return accel;
    }

    AccelerationResult res;

    // Guard strengthening heuristic (helps in the presence of constant updates like x := 5 or x := free).
    // Check and (possibly) apply heuristic, this modifies newRule
    option<Rule> strengthened = MeteringFinder::strengthenGuard(its, rule);
    if (strengthened) {
        res.strengthened = true;
        const AccelerationResult &accel = accelerateFast(its, strengthened.get(), sink);
        if (accel.rule) {
            res.proof.ruleTransformationProof(rule, "strengthening", strengthened.get(), its);
            res.proof.concat(accel.proof);
            res.rule = accel.rule;
            return res;
        }
    }

    return res;
}
