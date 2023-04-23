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

class NumVar;
class _Integer;
class _Rational;
class Monomial;
class Polynomial;
class ExponentialPolynomial;
class _Expr;
using Integer = std::shared_ptr<const _Integer>;
using Rational = std::shared_ptr<const _Rational>;
using Expr = std::shared_ptr<const _Expr>;

// Specifies for which coefficients c we can solve "c*x == t" for x.
enum SolvingLevel {
    TrivialCoeffs = 0, // only c=1 and c=-1 is allowed
    ResultMapsToInt = 1, // c can be any rational constant, as long as x = t/c maps to int
    ConstantCoeffs = 2, // c can be any rational constant (the result may not map to int, use with caution!)
};

class _Expr {

    friend bool operator==(const Expr&, const Expr&);
    friend std::strong_ordering operator<=>(const Expr &x, const Expr &y);

public:

    /**
     * possible types of variables
     */
    enum Type {Int, Rational, Bool};

    virtual bool isLinear() const;
    virtual bool isPoly() const;
    virtual bool isNaturalPow() const;
    virtual unsigned maxDegree() const;
    virtual Integer totalDegree() const;
    virtual void collectVars(std::set<NumVar> &res) const;
    virtual std::set<NumVar> vars() const;
    virtual bool isConstant() const;
    virtual bool isInt() const;
    virtual bool isRational() const;
    virtual bool isUnivariate() const;
    virtual NumVar someVar() const;
    virtual bool isNotMultivariate() const;
    virtual bool isMultivariate() const;
    virtual unsigned degree(const NumVar &var) const;
    virtual Expr coeff(const NumVar &var, int degree = 1) const;
    virtual Expr lcoeff(const NumVar &var) const;
    virtual bool isVar() const;
    virtual bool isPow() const;
    virtual bool isMul() const;
    virtual bool isAdd() const;
    virtual NumVar toVar() const;
    virtual ::Rational toRational() const;
    virtual Expr op(unsigned int i) const;
    virtual size_t arity() const;
//    virtual Expr subs(const ExprSubs &map) const;
    virtual bool isPoly(const NumVar &n) const;
    virtual Integer denomLcm() const;
    virtual std::optional<std::string> toQepcad() const;
    virtual std::optional<Expr> solveTermFor(const NumVar &var, SolvingLevel level) const;

    /**
     * @brief exponentiation
     */
    friend Expr operator^(const Expr &x, const Expr &y);
    friend Expr operator-(const Expr &x);
    friend Expr operator-(const Expr &x, const Expr &y);
    friend Expr operator+(const Expr &x, const Expr &y);
    friend Expr operator*(const Expr &x, const Expr &y);
    friend Expr operator/(const Expr &x, const Expr &y);
    friend std::ostream& operator<<(std::ostream &s, const Expr &e);

};

class RationalNumber {

    RationalNumber(const mp::cpp_rational &val);

    Integer numerator() const;
    Integer denominator() const;
    virtual bool isLinear() const;
    virtual bool isPoly() const;
    virtual bool isNaturalPow() const;
    virtual unsigned maxDegree() const;
    virtual Integer totalDegree() const;
    virtual void collectVars(std::set<NumVar> &res) const;
    virtual std::set<NumVar> vars() const;
    virtual bool isConstant() const;
    virtual bool isInt() const;
    virtual bool isRational() const;
    virtual bool isUnivariate() const;
    virtual NumVar someVar() const;
    virtual bool isNotMultivariate() const;
    virtual bool isMultivariate() const;
    virtual unsigned degree(const NumVar &var) const;
    virtual Expr coeff(const NumVar &var, int degree = 1) const;
    virtual Expr lcoeff(const NumVar &var) const;
    virtual bool isVar() const;
    virtual bool isPow() const;
    virtual bool isMul() const;
    virtual bool isAdd() const;
    virtual NumVar toVar() const;
    virtual ::Rational toRational() const;
    virtual Expr op(unsigned int i) const;
    virtual size_t arity() const;
//    virtual Expr subs(const ExprSubs &map) const;
    virtual bool isPoly(const NumVar &n) const;
    virtual Integer denomLcm() const;
    virtual std::optional<std::string> toQepcad() const;
    virtual std::optional<Expr> solveTermFor(const NumVar &var, SolvingLevel level) const;

private:

    const mp::cpp_rational val;

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
