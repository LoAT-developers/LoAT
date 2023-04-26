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
#include <boost/multiprecision/cpp_int.hpp>

#include "intsubs.hpp"
#include "numvar.hpp"

namespace mp = boost::multiprecision;
using integer = mp::cpp_int;
using rational = mp::cpp_rational;

// Specifies for which coefficients c we can solve "c*x == t" for x.
enum SolvingLevel {
    TrivialCoeffs = 0, // only c=1 and c=-1 is allowed
    ResultMapsToInt = 1, // c can be any rational constant, as long as x = t/c maps to int
    ConstantCoeffs = 2, // c can be any rational constant (the result may not map to int, use with caution!)
};

class Polynomial {

    using Monomial = std::map<NumVar, integer>;
    using Subs = Substitution<Polynomial>;

    explicit Polynomial(const std::map<Monomial, rational> &addends);

public:

    static Polynomial mk(const std::map<Monomial, rational> &addends);
    static Polynomial mk(const rational &x);
    static Polynomial zero;

    bool isLinear() const;
    integer maxDegree() const;
    integer totalDegree() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isZero() const;
    bool isInt() const;
    bool isRational() const;
    std::optional<NumVar> isUnivariate() const;
    NumVar someVar() const;
    bool isMultivariate() const;
    integer degree(const NumVar &var) const;
    Polynomial coeff(const NumVar &var, integer degree = 1) const;
    bool isVar() const;
    NumVar toVar() const;
    rational toRational() const;
    bool isIntegral() const;
    bool isIntPoly() const;
    Polynomial pow(const integer &exp) const;
    Polynomial subs(const Subs &map) const;
    std::optional<Polynomial> solveFor(const NumVar &var, SolvingLevel level) const;

    static Polynomial add(const std::vector<Polynomial> &polys);
    static Polynomial mult(const std::vector<Polynomial> &polys);

    friend bool operator==(const Polynomial&, const Polynomial&) = default;
    friend std::strong_ordering operator<=>(const Polynomial&, const Polynomial&) = default;
    friend std::ostream& operator<<(std::ostream &s, const Polynomial &p);

private:

    std::map<Monomial, mp::cpp_rational> addends;

};
