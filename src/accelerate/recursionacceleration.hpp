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

#ifndef FORWARD_H
#define FORWARD_H

#include "types.hpp"
#include "itsproblem.hpp"
#include "expression.hpp"
#include "metering.hpp"
#include "status.hpp"
#include "proof.hpp"
#include "option.hpp"
#include "accelerationresult.hpp"

/**
 * The classic acceleration technique by using metering functions.
 * This is applicable to for both linear and nonlinear rules (with several right-hand sides).
 */
namespace RecursionAcceleration {

    /**
     * Tries to accelerate the given rule, which must be a simple loop.
     * If no metering function is found in the first attempt, several heuristics are used to simplify the rule.
     * All resulting accelerated rules are returned (some heuristics may yield several rules).
     *
     * All resulting rules are linear.
     * If the original loop was linear, the result is still a simple loop, unless it is non-terminating.
     * If the original loop was nonlinear or found to be non-terminating, the resulting rules go to the given sink.
     */
    AccelerationResult accelerate(ITSProblem &its, const Rule &rule, LocationIdx sink);

    /**
     * Like accelerateNonlinear, but does not invoke any heuristics (and is thus faster but less powerful).
     * The result is always a single accelerated rule (if acceleration was successful).
     */
    AccelerationResult accelerateFast(ITSProblem &its, const Rule &rule, LocationIdx sink);
}

#endif // FORWARD_H
