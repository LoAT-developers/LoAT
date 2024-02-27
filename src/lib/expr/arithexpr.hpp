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
class ArithLit;
class ArithSubs;
class ArithExpr;
class ArithVal;
class ArithExp;
class ArithAdd;
class ArithMult;
using ArithExprPtr = std::shared_ptr<const ArithExpr>;
using ArithVarPtr = std::shared_ptr<const ArithVar>;
using ArithValPtr = std::shared_ptr<const ArithVal>;
using ArithAddPtr = std::shared_ptr<const ArithAdd>;
using ArithMultPtr = std::shared_ptr<const ArithMult>;
using ArithExpPtr = std::shared_ptr<const ArithExp>;


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
using purrs_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArithVarPtr>, boost::bimaps::unordered_set_of<Purrs::Symbol, SymbolHasher, SymbolEqual>>;

namespace arith {

ArithExprPtr mkPlus(std::vector<ArithExprPtr> args);
ArithExprPtr mkTimes(std::vector<ArithExprPtr> args);
ArithExprPtr mkConst(const Rational &r);
ArithExprPtr mkExp(const ArithExprPtr base, const ArithExprPtr exponent);
ArithExprPtr mkVar(const int idx);

enum class Kind {
    Plus, Times, Exp, Constant, Variable
};

}

class ArithExpr: public std::enable_shared_from_this<ArithExpr> {

    friend class ArithExp;
    friend ArithExprPtr arith::mkPlus(std::vector<ArithExprPtr> args);
    friend ArithExprPtr arith::mkTimes(std::vector<ArithExprPtr> args);

protected:

    ArithExpr(const arith::Kind kind);

private:

    arith::Kind kind;

    void exps(linked_hash_set<ArithExpPtr> &acc) const;
    /**
     * @return [a,b] s.t. a*b = *this
     */
    std::pair<Rational, std::optional<ArithExprPtr>> decompose() const;
    bool isUnivariate(std::optional<ArithVarPtr> &) const;
    bool isMultivariate(std::optional<ArithVarPtr> &) const;

public:

    template <class T>
    T map(const std::function<T(const ArithValPtr)> &constant,
          const std::function<T(const ArithVarPtr)> &var,
          const std::function<T(const ArithAddPtr)> &add,
          const std::function<T(const ArithMultPtr)> &mult,
          const std::function<T(const ArithExpPtr)> &exp) const {
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
    std::optional<ArithVarPtr> isVar() const;

    /**
     * @return True iff this is of the form x^y for some expressions x, y.
     */
    std::optional<ArithExpPtr> isPow() const;

    /**
     * @return True iff this is of the form x*y for some expressions x, y.
     */
    const std::optional<ArithMultPtr> isMult() const;

    /**
     * @return True iff this is of the form x+y for some expressions x, y.
     */
    const std::optional<ArithAddPtr> isAdd() const;

    /**
     * @return The set of all variables that occur in this expression.
     */
    linked_hash_set<ArithVarPtr> vars() const;

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
    bool has(const ArithVarPtr) const;

    ArithExprPtr divide(const Rational &d) const;

    std::pair<Purrs::Expr, purrs_var_map> toPurrs() const;

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    bool isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars = {}) const;

    /**
     * @return True iff this expression is a polynomial.
     */
    bool isPoly() const;

    std::optional<Int> totalDegree() const;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    void collectVars(linked_hash_set<ArithVarPtr> &res) const;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    bool hasVarWith(const std::function<bool(const ArithVarPtr)> predicate) const;

    /**
     * @return The degree wrt. var.
     * @note For polynomials only.
     */
    std::optional<Int> degree(const ArithVarPtr var) const;

    std::optional<ArithValPtr> isRational() const;

    /**
     * @return True iff this expression is an integer value (and thus a constant).
     */
    std::optional<Int> isInt() const;

    Int denomLcm() const;

    /**
     * @return True iff this is a polynomial wrt. the given variable.
     */
    bool isPoly(const ArithVarPtr n) const;

    std::optional<ArithVarPtr> someVar() const;

    linked_hash_set<ArithExpPtr> exps() const;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    std::optional<ArithExprPtr> coeff(const ArithVarPtr var, const Int &degree = 1) const;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is minimal.
     */
    std::optional<ArithExprPtr> lcoeff(const ArithVarPtr var) const;

    bool isIntegral() const;

    Rational eval(const std::function<Rational(const ArithVarPtr)> &valuation) const;

    Purrs::Expr toPurrs(purrs_var_map &) const;

    /**
     * @brief exponentiation
     */
    friend ArithExprPtr operator^(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator-(const ArithExprPtr x);
    friend ArithExprPtr operator-(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator+(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithExprPtr operator*(const ArithExprPtr x, const ArithExprPtr y);

};


class ArithVal: public ArithExpr, public std::enable_shared_from_this<ArithVal> {

    friend ArithExprPtr arith::mkConst(const Rational &r);

private:

    ArithVal(const Rational &t);
    Rational t;

    struct CacheEqual {
        bool operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<Rational> &args) const noexcept;
    };
    friend ConsHash<ArithExpr, ArithVal, CacheHash, CacheEqual, Rational>;
    static ConsHash<ArithExpr, ArithVal, CacheHash, CacheEqual, Rational> cache;

public:

    const Rational& operator*() const;
    const Rational& getValue() const;
    const ArithValPtr numerator() const;
    const ArithValPtr denominator() const;
    std::optional<Int> intValue() const;

};


class ArithVar: public ArithExpr, public std::enable_shared_from_this<ArithVar> {

    friend ArithExprPtr arith::mkVar(const int idx);

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
    friend ConsHash<ArithExpr, ArithVar, CacheHash, CacheEqual, int>;
    static ConsHash<ArithExpr, ArithVar, CacheHash, CacheEqual, int> cache;

    ArithVarPtr toPtr() const;

public:

    static const ArithVarPtr loc_var;

    static ArithVarPtr next();
    static ArithVarPtr nextProgVar();

    ArithExprPtr toExpr() const;
    int getIdx() const;
    std::string getName() const;
    bool isTempVar() const;
    size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const ArithVarPtr x);


class ArithAdd: public ArithExpr, public std::enable_shared_from_this<ArithAdd> {

    friend ArithExprPtr arith::mkPlus(std::vector<ArithExprPtr> args);

public:

    const linked_hash_set<ArithExprPtr>& getArgs() const;

private:

    linked_hash_set<ArithExprPtr> args;

    struct CacheEqual {
        bool operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args1, const std::tuple<linked_hash_set<ArithExprPtr>> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args) const noexcept;
    };
    friend ConsHash<ArithExpr, ArithAdd, CacheHash, CacheEqual, linked_hash_set<ArithExprPtr>>;
    static ConsHash<ArithExpr, ArithAdd, CacheHash, CacheEqual, linked_hash_set<ArithExprPtr>> cache;

    ArithAdd(const linked_hash_set<ArithExprPtr> &args);

};


class ArithMult: public ArithExpr, public std::enable_shared_from_this<ArithMult> {

    friend ArithExprPtr arith::mkTimes(std::vector<ArithExprPtr> args);

public:

    const linked_hash_set<ArithExprPtr>& getArgs() const;

private:

    linked_hash_set<ArithExprPtr> args;

    struct CacheEqual {
        bool operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args1, const std::tuple<linked_hash_set<ArithExprPtr>> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args) const noexcept;
    };
    friend ConsHash<ArithExpr, ArithMult, CacheHash, CacheEqual, linked_hash_set<ArithExprPtr>>;
    static ConsHash<ArithExpr, ArithMult, CacheHash, CacheEqual, linked_hash_set<ArithExprPtr>> cache;

    ArithMult(const linked_hash_set<ArithExprPtr> &args);

};


class ArithExp: public ArithExpr, public std::enable_shared_from_this<ArithExp> {

    friend ArithExprPtr arith::mkExp(const ArithExprPtr base, const ArithExprPtr exponent);

private:

    ArithExprPtr base;
    ArithExprPtr exponent;

    ArithExp(const ArithExprPtr base, const ArithExprPtr exponent);

    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args1, const std::tuple<ArithExprPtr, ArithExprPtr> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args) const noexcept;
    };
    friend ConsHash<ArithExpr, ArithExp, CacheHash, CacheEqual, ArithExprPtr, ArithExprPtr>;
    static ConsHash<ArithExpr, ArithExp, CacheHash, CacheEqual, ArithExprPtr, ArithExprPtr> cache;

public:

    ArithExprPtr getBase() const;
    ArithExprPtr getExponent() const;

};

std::ostream& operator<<(std::ostream &s, const ArithExprPtr e);
std::ostream& operator<<(std::ostream &s, const ArithVarPtr e);
