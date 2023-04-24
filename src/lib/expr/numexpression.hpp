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
#include <initializer_list>
#include <optional>
#include <boost/multiprecision/cpp_int.hpp>

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

public:

    using Monomial = std::map<NumVar, integer>;

    Polynomial(const std::map<Monomial, rational> &addends);

    bool isLinear() const;
    integer maxDegree() const;
    integer totalDegree() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isConstant() const;
    bool isInt() const;
    bool isRational() const;
    bool isUnivariate() const;
    NumVar someVar() const;
    bool isNotMultivariate() const;
    bool isMultivariate() const;
    unsigned degree(const NumVar &var) const;
    Polynomial coeff(const NumVar &var, int degree = 1) const;
    Polynomial lcoeff(const NumVar &var) const;
    bool isVar() const;
    NumVar toVar() const;
    rational toRational() const;
//    Expr subs(const ExprSubs &map) const;
    std::optional<std::string> toQepcad() const;
    std::optional<Polynomial> solveFor(const NumVar &var, SolvingLevel level) const;

    friend bool operator==(const Monomial&, const Monomial&);
    friend std::strong_ordering operator<=>(const Monomial&, const Monomial&);
    friend bool operator==(const Polynomial&, const Polynomial&);
    friend std::strong_ordering operator<=>(const Polynomial&, const Polynomial&);

private:

    std::map<Monomial, mp::cpp_rational> addends;

};

class Expr {

public:

    class Exp {
        mp::cpp_int base;
        Polynomial exponent;
    };

    Expr(const std::map<Exp, Polynomial> &addends);

    bool isLinear() const;
    bool isPoly() const;
    bool isNaturalPow() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isConstant() const;
    bool isInt() const;
    bool isRational() const;
    bool isUnivariate() const;
    NumVar someVar() const;
    bool isNotMultivariate() const;
    bool isMultivariate() const;
    bool isVar() const;
    bool isPow() const;
    NumVar toVar() const;
    rational toRational() const;
//    Expr subs(const ExprSubs &map) const;
    bool isPoly(const NumVar &n) const;
    std::optional<std::string> toQepcad() const;
    std::optional<Expr> solveFor(const NumVar &var, SolvingLevel level) const;

    friend bool operator==(const Expr&, const Expr&);
    friend std::strong_ordering operator<=>(const Expr&, const Expr&);

private:

    std::map<Exp, Polynomial> addends;

};

//class ExprSubs {

//    friend class Expr;
//    friend auto operator<=>(const ExprSubs &m1, const ExprSubs &m2) = default;

//public:

//    using const_iterator = typename std::map<NumVar, Expr>::const_iterator;

//    ExprSubs();

//    ExprSubs(std::initializer_list<std::pair<const NumVar, Expr>> init);

//    Expr get(const NumVar &key) const;

//    void put(const NumVar &key, const Expr &val);

//    const_iterator begin() const;

//    const_iterator end() const;

//    const_iterator find(const NumVar &e) const;

//    bool contains(const NumVar &e) const;

//    bool empty() const;

//    unsigned int size() const;

//    size_t erase(const NumVar &key);

//    ExprSubs compose(const ExprSubs &that) const;

//    ExprSubs concat(const ExprSubs &that) const;

//    ExprSubs unite(const ExprSubs &that) const;

//    ExprSubs project(const std::set<NumVar> &vars) const;

//    ExprSubs setminus(const std::set<NumVar> &vars) const;

//    bool changes(const NumVar &key) const;

//    bool isLinear() const;

//    bool isPoly() const;

//    bool isOctagon() const;

//    std::set<NumVar> domain() const;

//    std::set<NumVar> coDomainVars() const;

//    std::set<NumVar> allVars() const;

//    void collectDomain(std::set<NumVar> &vars) const;

//    void collectCoDomainVars(std::set<NumVar> &vars) const;

//    void collectVars(std::set<NumVar> &vars) const;

//private:
//    void putGinac(const NumVar &key, const Expr &val);
//    void eraseGinac(const NumVar &key);
//    GiNaC::exmap ginacMap;
//    std::map<NumVar, Expr> map;

//};

//std::ostream& operator<<(std::ostream &s, const ExprSubs &map);
