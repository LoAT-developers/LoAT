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

#include "numexpression.hpp"

#include <purrs.hh>

linked_hash_set<NumVarPtr> Expr::vars() const {
    linked_hash_set<NumVarPtr> res;
    collectVars(res);
    return res;
}

bool Expr::isUnivariate() const {
    std::optional<NumVarPtr> var;
    return isUnivariate(var);
}

bool Expr::isNotMultivariate() const {
    std::optional<NumVarPtr> var;
    return isNotMultivariate(var);
}

bool Expr::isMultivariate() const {
    std::optional<NumVarPtr> var;
    return isMultivariate(var);
}

bool Expr::is(const Rational &val) const {
    return isRational() == std::optional<Rational>{val};
}

std::optional<Int> Expr::maxDegree() const {
    Int max {0};
    for (const auto &x: vars()) {
        const auto deg {degree(x)};
        if (deg) {
            max = mp::max(max, *deg);
        } else {
            return {};
        }
    }
    return max;
}

bool Expr::has(const NumVarPtr x) const {
    return hasVarWith([&x](const auto &y) {
        return x == y;
    });
}

ExprPtr operator-(const ExprPtr x) {
    return ne::buildTimes({ne::buildConstant(-1),x});
}

ExprPtr operator-(const ExprPtr x, const ExprPtr y) {
    return ne::buildPlus({x,-y});
}

ExprPtr operator+(const ExprPtr x, const ExprPtr y) {
    return ne::buildPlus({x,y});
}

ExprPtr operator*(const ExprPtr x, const ExprPtr y) {
    return ne::buildTimes({x,y});
}

ExprPtr Expr::divide(const Rational &y) const {
    return ne::buildTimes({ne::buildConstant(Rational(mp::denominator(y), mp::numerator(y))), shared_from_this()});
}

ExprPtr operator^(const ExprPtr x, const ExprPtr y) {
    return ne::buildExp(x, y);
}
