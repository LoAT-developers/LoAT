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

#include <ginac/ginac.h>
#include <variant>
#include <initializer_list>
#include <optional>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <purrs.hh>

#include "set.hpp"

class NumVar;
class Recurrence;
class Rel;
class ExprSubs;
class Expr;
class NumConstant;
class Exp;
class ACApplication;
using ExprPtr = std::shared_ptr<const Expr>;
using NumVarPtr = std::shared_ptr<const NumVar>;


namespace mp = boost::multiprecision;
namespace Purrs = Parma_Recurrence_Relation_Solver;

struct SymbolHasher {
    size_t operator()(const Purrs::Symbol &x) const {
        return std::hash<std::string>{}(x.get_name());
    }
};

struct SymbolEqual {
    bool operator()(const Purrs::Symbol &x, const Purrs::Symbol &y) const {
        return x.get_name() == y.get_name();
    }
};

using Int = mp::cpp_int;
using Rational = mp::cpp_rational;
using purrs_var_map = boost::bimap<boost::bimaps::unordered_set_of<NumVarPtr>, boost::bimaps::unordered_set_of<Purrs::Symbol, SymbolHasher, SymbolEqual>>;

namespace num_expression {

ExprPtr buildPlus(std::vector<ExprPtr> args);
ExprPtr buildTimes(std::vector<ExprPtr> args);
ExprPtr buildConstant(const Rational &r);
ExprPtr buildExp(const ExprPtr base, const ExprPtr exponent);

}

namespace ne = num_expression;

class Expr: public std::enable_shared_from_this<Expr> {

    friend class Exp;
    friend class ACApplication;
    friend ExprPtr ne::buildPlus(std::vector<ExprPtr> args);
    friend ExprPtr ne::buildTimes(std::vector<ExprPtr> args);

public:

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    virtual bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars = {}) const = 0;

    /**
     * @return True iff this expression is a polynomial.
     */
    virtual bool isPoly() const = 0;

    virtual std::optional<Int> totalDegree() const = 0;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    virtual void collectVars(linked_hash_set<NumVarPtr> &res) const = 0;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    virtual bool hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const = 0;

    /**
     * @return The degree wrt. var.
     * @note For polynomials only.
     */
    virtual std::optional<Int> degree(const NumVarPtr var) const = 0;

    virtual Int denomLcm() const = 0;

    /**
     * @return True iff this expression is an integer value (and thus a constant).
     */
    virtual std::optional<Int> isInt() const = 0;

    /**
     * @return True iff this expression is a rational number (and thus a constant).
     */
    virtual std::optional<Rational> isRational() const = 0;

    /**
     * @return True iff this is a variable.
     */
    virtual std::optional<NumVarPtr> isVar() const = 0;

    /**
     * @return True iff this is of the form x^y for some expressions x, y.
     */
    virtual std::optional<std::pair<ExprPtr, ExprPtr>> isPow() const = 0;

    /**
     * @return True iff this is of the form x*y for some expressions x, y.
     */
    virtual const linked_hash_set<ExprPtr>* isMul() const = 0;

    /**
     * @return True iff this is of the form x+y for some expressions x, y.
     */
    virtual const linked_hash_set<ExprPtr>* isAdd() const = 0;

    /**
     * @return True iff this is a polynomial wrt. the given variable.
     */
    virtual bool isPoly(const NumVarPtr n) const = 0;

    virtual std::optional<NumVarPtr> someVar() const = 0;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    virtual std::optional<ExprPtr> coeff(const NumVarPtr var, const Int &degree = 1) const = 0;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is minimal.
     */
    virtual std::optional<ExprPtr> lcoeff(const NumVarPtr var) const = 0;

    virtual bool isIntegral() const = 0;

    virtual Rational eval(const std::function<Rational(const NumVarPtr)> &valuation) const = 0;

    virtual Purrs::Expr toPurrs(purrs_var_map &) const;

    virtual void exps(linked_hash_set<linked_hash_set<std::pair<ExprPtr, ExprPtr>>> &acc) const = 0;

protected:

    /**
     * @return [a,b] s.t. a*b = *this
     */
    virtual std::pair<Rational, std::optional<ExprPtr>> decompose() const = 0;
    virtual bool isUnivariate(std::optional<NumVarPtr> &) const = 0;
    virtual bool isNotMultivariate(std::optional<NumVarPtr> &) const = 0;
    virtual bool isMultivariate(std::optional<NumVarPtr> &) const = 0;

public:

    /**
     * @return The set of all variables that occur in this expression.
     */
    linked_hash_set<NumVarPtr> vars() const;

    /**
     * @return True iff this expression contains exactly one variable.
     */
    bool isUnivariate() const;

    /**
     * @return True iff this expression is ground or univariate.
     */
    bool isNotMultivariate() const;

    /**
     * @return True iff this expression contains at least two variable.
     */
    bool isMultivariate() const;

    bool is(const Rational &val) const;

    /**
     * @return The highest degree of any variable in this expression.
     */
    std::optional<Int> maxDegree() const;

    /**
     * @return True iff the expression contains the given variable.
     */
    bool has(const NumVarPtr) const;

    ExprPtr divide(const Rational &d) const;

    std::pair<Purrs::Expr, purrs_var_map> toPurrs() const;

    linked_hash_set<std::pair<ExprPtr, ExprPtr>> exps() const;

    /**
     * @brief exponentiation
     */
    friend ExprPtr operator^(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator-(const ExprPtr x);
    friend ExprPtr operator-(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator+(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator*(const ExprPtr x, const ExprPtr y);
    friend std::ostream& operator<<(std::ostream &s, const ExprPtr e);

};
