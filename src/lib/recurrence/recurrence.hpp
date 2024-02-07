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

#include <optional>

#include "theory.hpp"
#include "numexpression.hpp"

class Recurrence {
private:

public:

    struct Result {
        Subs closed_form;
        unsigned int prefix = 0;
    };

    static std::optional<Result> solve(const Subs &equations, const NumVar &n);

    static void solve(const std::string &eq);

private:

    Recurrence(const Subs &subs, const NumVar &n);

    bool solve();

    bool solve(const NumVar &lhs, const Expr &rhs);

    bool solve(const BoolVar &lhs, const BoolExpr &rhs);

    Subs equations;

    const NumVar &n;

    /**
     * Substitution map, mapping variables to their recurrence equations
     * @note the recurrence equations are valid *before* the transition is taken,
     * i.e. these are the terms for r(n-1) and _not_ for r(n) where r is the recurrence equation.
     */
    Subs closed_form_pre;

    std::optional<ExprSubs> inverse {ExprSubs()};

    Result result;

    std::unordered_map<Var, unsigned> prefixes;

};
