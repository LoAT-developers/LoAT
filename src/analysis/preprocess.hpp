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

#pragma once

#include "rule.hpp"
#include "result.hpp"


/**
 * Methods useful for preprocessing / simplifying the transitions
 */
namespace Preprocess
{
    /**
     * Main preprocessing function which combines the methods below in a suitable way.
     * Calls simplifyGuardBySmt, so this method involves many smt queries!
     *
     * @param rule The rule to be simplified, is modified.
     * @returns true iff rule was modified
     */
    Result<Rule> preprocessRule(VarMan &its, const Rule &rule);

    /**
     * A simpler/cheaper version of preprocessRule without any smt queries.
     */
    Result<Rule> simplifyRule(VarMan &its, const Rule &rule);

    /**
     * Removes trivial updates of the form x <- x.
     * @return true iff update was modified
     */
    Result<Rule> removeTrivialUpdates(const Rule &rule);

    bool removeTrivialUpdates(Subs &subs);

    /**
     * Tries to remove as many temporary variables from update right-hand sides
     * and the guard as possible. Temporary variables are eliminated by equality propagation
     * (e.g. for free == 2*x) and transitive elimination (e.g. a <= free <= b becomes a <= b).
     * @param rule the rule, modified
     * @return true iff rule was modified
     */
    Result<Rule> eliminateTempVars(VarMan &its, const Rule &rule);
}
