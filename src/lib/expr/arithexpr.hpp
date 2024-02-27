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
#undef EOF
#define EOF (-1)
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <purrs.hh>
#include <functional>

#include "set.hpp"
#include "string.hpp"
#include "conshash.hpp"

class ArithVar;
class Recurrence;
class ArithLit;
class ArithSubs;
class Expr;
class NumConstant;
class Exp;
class ACApplication;
class Add;
class Mult;
using ExprPtr = std::shared_ptr<const Expr>;
using NumVarPtr = std::shared_ptr<const ArithVar>;
using NumConstantPtr = std::shared_ptr<const NumConstant>;
using AddPtr = std::shared_ptr<const Add>;
using MultPtr = std::shared_ptr<const Mult>;
using ExpPtr = std::shared_ptr<const Exp>;


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

namespace arith {

ExprPtr mkPlus(std::vector<ExprPtr> args);
ExprPtr mkTimes(std::vector<ExprPtr> args);
ExprPtr mkConst(const Rational &r);
ExprPtr mkExp(const ExprPtr base, const ExprPtr exponent);
ExprPtr mkVar(const int idx);

enum class Kind {
    Plus, Times, Exp, Constant, Variable
};

}

class Expr: public std::enable_shared_from_this<Expr> {

    friend class Exp;
    friend class ACApplication;
    friend ExprPtr arith::mkPlus(std::vector<ExprPtr> args);
    friend ExprPtr arith::mkTimes(std::vector<ExprPtr> args);

protected:

    Expr(const arith::Kind kind);

private:

    arith::Kind kind;

    void exps(linked_hash_set<ExpPtr> &acc) const;
    /**
     * @return [a,b] s.t. a*b = *this
     */
    std::pair<Rational, std::optional<ExprPtr>> decompose() const;
    bool isUnivariate(std::optional<NumVarPtr> &) const;
    bool isMultivariate(std::optional<NumVarPtr> &) const;

public:

    template <class T>
    T map(const std::function<T(const NumConstantPtr)> &constant,
          const std::function<T(const NumVarPtr)> &var,
          const std::function<T(const AddPtr)> &add,
          const std::function<T(const MultPtr)> &mult,
          const std::function<T(const ExpPtr)> &exp) const {
        const auto c {isRational()};
        if (c) {
            return constant(*c);
        }
        const auto v {isVar()};
        if (v) {
            return var(*v);
        }
        const auto a {isAdd()};
        if (a) {
            return add(*a);
        }
        const auto m {isMult()};
        if (m) {
            return mult(*m);
        }
        const auto e {isPow()};
        if (e) {
            return exp(*e);
        }
        throw std::invalid_argument("unknown expression" + toString(this->shared_from_this()));
    }

    /**
     * @return True iff this is a variable.
     */
    std::optional<NumVarPtr> isVar() const;

    /**
     * @return True iff this is of the form x^y for some expressions x, y.
     */
    std::optional<ExpPtr> isPow() const;

    /**
     * @return True iff this is of the form x*y for some expressions x, y.
     */
    const std::optional<MultPtr> isMult() const;

    /**
     * @return True iff this is of the form x+y for some expressions x, y.
     */
    const std::optional<AddPtr> isAdd() const;

    /**
     * @return The set of all variables that occur in this expression.
     */
    linked_hash_set<NumVarPtr> vars() const;

    /**
     * @return True iff this expression contains exactly one variable.
     */
    bool isUnivariate() const;

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

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars = {}) const;

    /**
     * @return True iff this expression is a polynomial.
     */
    bool isPoly() const;

    std::optional<Int> totalDegree() const;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    void collectVars(linked_hash_set<NumVarPtr> &res) const;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    bool hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const;

    /**
     * @return The degree wrt. var.
     * @note For polynomials only.
     */
    std::optional<Int> degree(const NumVarPtr var) const;

    std::optional<NumConstantPtr> isRational() const;

    /**
     * @return True iff this expression is an integer value (and thus a constant).
     */
    std::optional<Int> isInt() const;

    Int denomLcm() const;

    /**
     * @return True iff this is a polynomial wrt. the given variable.
     */
    bool isPoly(const NumVarPtr n) const;

    std::optional<NumVarPtr> someVar() const;

    linked_hash_set<ExpPtr> exps() const;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    std::optional<ExprPtr> coeff(const NumVarPtr var, const Int &degree = 1) const;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is minimal.
     */
    std::optional<ExprPtr> lcoeff(const NumVarPtr var) const;

    bool isIntegral() const;

    Rational eval(const std::function<Rational(const NumVarPtr)> &valuation) const;

    Purrs::Expr toPurrs(purrs_var_map &) const;

    /**
     * @brief exponentiation
     */
    friend ExprPtr operator^(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator-(const ExprPtr x);
    friend ExprPtr operator-(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator+(const ExprPtr x, const ExprPtr y);
    friend ExprPtr operator*(const ExprPtr x, const ExprPtr y);

};


class NumConstant: public Expr, public std::enable_shared_from_this<NumConstant> {

    friend ExprPtr arith::mkConst(const Rational &r);

private:

    NumConstant(const Rational &t);
    Rational t;

    struct CacheEqual {
        bool operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<Rational> &args) const noexcept;
    };
    friend ConsHash<Expr, NumConstant, CacheHash, CacheEqual, Rational>;
    static ConsHash<Expr, NumConstant, CacheHash, CacheEqual, Rational> cache;

public:

    const Rational& operator*() const;
    const Rational& getValue() const;
    const NumConstantPtr numerator() const;
    const NumConstantPtr denominator() const;
    std::optional<Int> intValue() const;

};


class ArithVar: public Expr, public std::enable_shared_from_this<ArithVar> {

    friend ExprPtr arith::mkVar(const int idx);

private:

    static int last_tmp_idx;
    static int last_prog_idx;

    int idx;

    explicit ArithVar(const int idx);

    struct CacheEqual {
        bool operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<int> &args) const noexcept;
    };
    friend ConsHash<Expr, ArithVar, CacheHash, CacheEqual, int>;
    static ConsHash<Expr, ArithVar, CacheHash, CacheEqual, int> cache;

    NumVarPtr toPtr() const;

public:

    static const NumVarPtr loc_var;

    static NumVarPtr next();
    static NumVarPtr nextProgVar();

    ExprPtr toExpr() const;
    int getIdx() const;
    std::string getName() const;
    bool isTempVar() const;
    size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const NumVarPtr x);


class Add: public Expr, public std::enable_shared_from_this<Add> {

    friend ExprPtr arith::mkPlus(std::vector<ExprPtr> args);

public:

    const linked_hash_set<ExprPtr>& getArgs() const;

private:

    linked_hash_set<ExprPtr> args;

    struct CacheEqual {
        bool operator()(const std::tuple<linked_hash_set<ExprPtr>> &args1, const std::tuple<linked_hash_set<ExprPtr>> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<linked_hash_set<ExprPtr>> &args) const noexcept;
    };
    friend ConsHash<Expr, Add, CacheHash, CacheEqual, linked_hash_set<ExprPtr>>;
    static ConsHash<Expr, Add, CacheHash, CacheEqual, linked_hash_set<ExprPtr>> cache;

    Add(const linked_hash_set<ExprPtr> &args);

};


class Mult: public Expr, public std::enable_shared_from_this<Mult> {

    friend ExprPtr arith::mkTimes(std::vector<ExprPtr> args);

public:

    const linked_hash_set<ExprPtr>& getArgs() const;

private:

    linked_hash_set<ExprPtr> args;

    struct CacheEqual {
        bool operator()(const std::tuple<linked_hash_set<ExprPtr>> &args1, const std::tuple<linked_hash_set<ExprPtr>> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<linked_hash_set<ExprPtr>> &args) const noexcept;
    };
    friend ConsHash<Expr, Mult, CacheHash, CacheEqual, linked_hash_set<ExprPtr>>;
    static ConsHash<Expr, Mult, CacheHash, CacheEqual, linked_hash_set<ExprPtr>> cache;

    Mult(const linked_hash_set<ExprPtr> &args);

};


class Exp: public Expr, public std::enable_shared_from_this<Exp> {

    friend ExprPtr arith::mkExp(const ExprPtr base, const ExprPtr exponent);

private:

    ExprPtr base;
    ExprPtr exponent;

    Exp(const ExprPtr base, const ExprPtr exponent);

    struct CacheEqual {
        bool operator()(const std::tuple<ExprPtr, ExprPtr> &args1, const std::tuple<ExprPtr, ExprPtr> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ExprPtr, ExprPtr> &args) const noexcept;
    };
    friend ConsHash<Expr, Exp, CacheHash, CacheEqual, ExprPtr, ExprPtr>;
    static ConsHash<Expr, Exp, CacheHash, CacheEqual, ExprPtr, ExprPtr> cache;

public:

    ExprPtr getBase() const;
    ExprPtr getExponent() const;

};

std::ostream& operator<<(std::ostream &s, const ExprPtr e);
std::ostream& operator<<(std::ostream &s, const NumVarPtr e);
