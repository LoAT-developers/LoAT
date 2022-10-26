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
#include "variablemanager.hpp"
#include "option.hpp"


namespace Chaining {
    /**
     * Chains all right-hand sides of the first rule that lead to the second rule's lhs location
     * with the second rule. If both rules are linear, a simpler implementation is used for better performance.
     * @return The resulting rule, unless it can be shown to be unsatisfiable.
     */
    option<Rule> chainRules(VarMan &varMan, const Rule &first, const Rule &second, bool checkSat = true);

    /**
     * Specialized implementation for linear rules, for performance only.
     * The implementation is much simpler, but semantically equivalent to chainRules.
     */
    option<LinearRule> chainRules(VarMan &varMan, const LinearRule &first, const LinearRule &second, bool checkSat = true);
}
