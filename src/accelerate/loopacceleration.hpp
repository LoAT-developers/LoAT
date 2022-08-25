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
#include "option.hpp"
#include "accelerationresult.hpp"
#include "nondetupdate.hpp"

class LoopAcceleration {
public:

    struct AcceleratedRules {
        const std::vector<Rule> rules;
        const unsigned int validityBound;
    };

    static AccelerationResult accelerate(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx);

private:
    LoopAcceleration(ITSProblem &its, const LinearRule &rule, LocationIdx sink, Complexity cpx);

    LinearRule buildNontermRule(const BoolExpr &guard) const;

    LinearRule buildRule(LocationIdx lhs, BoolExpr guard, const Expr &cost, LocationIdx rhs, const NondetUpdate &up);

    /**
     * Main function, just calls the methods below in the correct order
     */
    AccelerationResult run();

    /**
     * Checks whether the backward acceleration technique might be applicable.
     */
    bool shouldAccelerate() const;

    /**
     * If possible, replaces N by all its upper bounds from the guard of the given rule.
     * For every upper bound, a separate rule is created.
     *
     * If this is not possible (i.e., there is at least one upper bound that is too difficult
     * to compute like N^2 <= X or there are too many upper bounds), then N is not replaced
     * and a vector consisting only of the given rule is returned.
     *
     * @return A list of rules, either with N eliminated or only containing the given rule
     */
    std::vector<Rule> replaceByUpperbounds(const Var &N, const Rule &rule);

private:
    ITSProblem &its;
    const LinearRule &rule;
    LocationIdx sink;
    Complexity cpx;
};
