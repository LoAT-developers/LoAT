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

#include <variant>
#include <optional>
#include <boost/multiprecision/cpp_int.hpp>

#include "intsubs.hpp"
#include "numvar.hpp"
#include "polynomial.hpp"

class Expr {

    using Subs = Substitution<Expr>;

public:

    struct Exp {
        mp::cpp_int base;
        NumVar exponent;
    };

private:

    explicit Expr(const std::map<std::optional<Exp>, Polynomial> &addends);

public:

    static Expr mk(const std::map<std::optional<Exp>, Polynomial> &addends);
    static Expr mk(const rational &x);
    static Expr zero;

    bool isPoly() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isInt() const;
    bool isRational() const;
    std::optional<NumVar> isUnivariate() const;
    NumVar someVar() const;
    bool isMultivariate() const;
    bool isVar() const;
    bool isPow() const;
    NumVar toVar() const;
    rational toRational() const;
    bool isIntegral() const;
    Polynomial pow(const integer &exp) const;
    Expr subs(const Subs &map) const;
    bool isPoly(const NumVar &n) const;
    std::optional<Expr> solveFor(const NumVar &var, SolvingLevel level) const;

    static Expr add(const std::vector<Expr> &exprs);
    static Expr mult(const std::vector<Expr> &exprs);

    friend bool operator==(const Expr&, const Expr&);
    friend std::strong_ordering operator<=>(const Expr&, const Expr&);
    friend std::ostream& operator<<(std::ostream &s, const Expr &p);

private:

    std::map<std::optional<Exp>, Polynomial> addends;

};
