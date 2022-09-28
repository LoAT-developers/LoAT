/*  This file is part of LoAT.
 *  Copyright (c) 2019 Florian Frohn
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

#include "expression.hpp"
#include "rule.hpp"

namespace util {

    class RelevantVariables {

    public:

        static const VarSet find(
                const VarSet &varsOfInterest,
                const std::vector<ExprSubs> &updates,
                const BoolExpr guard);

        static const VarSet find(
                const Guard &constraints,
                const std::vector<ExprSubs> &updates,
                const BoolExpr guard);

        static const VarSet find(
                const Guard &constraints,
                const std::vector<RuleRhs> &rhss,
                const BoolExpr guard);

    };

}
