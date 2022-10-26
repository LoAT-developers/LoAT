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

#pragma once

#include "itsproblem.hpp"
#include "rule.hpp"
#include "complexity.hpp"
#include "accelerationresult.hpp"

class LoopAcceleration {
public:

    struct AcceleratedRules {
        const std::vector<Rule> rules;
        const unsigned int validityBound;
    };

    static AccelerationResult accelerate(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx);

    static const std::pair<LinearRule, unsigned> chain(const LinearRule &rule, ITSProblem &its);

private:
    LoopAcceleration(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx);

    /**
     * Main function, just calls the methods below in the correct order
     */
    AccelerationResult run();

    /**
     * Checks whether the backward acceleration technique might be applicable.
     */
    bool shouldAccelerate() const;

    static LinearRule renameTmpVars(const LinearRule &rule, ITSProblem &its);

private:
    ITSProblem &its;
    const LinearRule &rule;
    LocationIdx sink;
    Complexity cpx;
};
