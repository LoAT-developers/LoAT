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

#include "complexity.hpp"
#include "option.hpp"
#include "exceptions.hpp"

class Expr;
template<class Key, class Key_is_less> class KeyToExprMap;
class Recurrence;
class Rel;
class Subs;
class ExprMap;

namespace Monotonicity {

enum T {
    Increasing, Decreasing, Constant, Unknown
};

std::ostream& operator<<(std::ostream &s, const T e);

}

namespace Sign {

enum T {
    Positive, Negative, Zero, Unknown
};

}

struct Expr_is_less {
    bool operator() (const Expr &lh, const Expr &rh) const;
};

using Var = GiNaC::symbol;

struct Var_is_less {
    bool operator() (const Var &lh, const Var &rh) const;
};

using VarSet = std::set<Var, Var_is_less>;
using ExprSet = std::set<Expr, Expr_is_less>;
template <typename T>
using VarMap = std::map<Var, T, Var_is_less>;

/**
 * Class for arithmetic expressions.
 * Just a wrapper for GiNaC expressions.
 */
class Expr {

    /*
     * We use PURRS to solve recurrence relatios, which also uses GiNaC.
     * Declaring it as a friend allows us to direclty work on the encapsulated GiNaC::ex when constructing recurrence relations.
     */
    friend class Recurrence;

    /*
     * An ExprMap encapsulates a GiNaC::exmap, which can directly be applied to the encapsulated GiNaC::ex.
     */
    friend class Subs;
    friend class ExprMap;

public:

    /**
     * possible types of variables
     */
    enum Type {Int, Rational, Bool};

    /**
     * Special variable that represents the cost of non-terminating computations.
     */
    static const Var NontermSymbol;

    /**
     * @return A wildcard for constructing patterns.
     */
    static Expr wildcard(unsigned int label);

    Expr() : Expr(GiNaC::ex()) {}
    Expr(const GiNaC::basic &other) : Expr(GiNaC::ex(other)) {}
    Expr(const GiNaC::ex &ex) : ex(ex) {}
    Expr(long i): ex(i) {}

    /**
     * @brief Applies a substitution via side-effects.
     * @deprecated use subs instead
     */
    void applySubs(const Subs &subs);

    /**
     * @brief Computes all matches of the given pattern.
     * @return True iff there was at least one match.
     */
    bool findAll(const Expr &pattern, ExprSet &found) const;

    /**
     * @return True iff this expression is equal (resp. evaluates) to the given variable
     */
    bool equals(const Var &var) const;

    /**
     * @return True iff this expression is equal to NontermSymbol.
     */
    bool isNontermSymbol() const;

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    bool isLinear(const option<VarSet> &vars = option<VarSet>()) const;

    /**
     * @return True iff this expression is a polynomial.
     */
    bool isPoly() const;

    /**
     * @return True iff this expression is polynomial where all coefficients are integers.
     */
    bool isIntPoly() const;

    /**
     * @return True iff this expression is an integer value (and thus a constant).
     */
    bool isInt() const;

    /**
     * @return True iff this expression is a rational number (and thus a constant).
     */
    bool isRationalConstant() const;

    /**
     * @return True iff this expression is a rational number, but no integer constant.
     */
    bool isNonIntConstant() const;

    /**
     * @return True iff this expression is a power where the exponent is a natural number > 1.
     */
    bool isNaturalPow() const;

    bool isOctagon() const;

    /**
     * @return The highest degree of any variable in this expression.
     * @note For polynomials only.
     */
    int maxDegree() const;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    void collectVars(VarSet &res) const;

    /**
     * @return The set of all variables that occur in this expression.
     */
    VarSet vars() const;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    template <typename P>
    bool hasVarWith(P predicate) const {
        struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
            SymbolVisitor(P predicate) : predicate(predicate) {}
            void visit(const Var &sym) {
                if (!res && predicate(sym)) {
                    res = true;
                }
            }
            bool result() const {
                return res;
            }
        private:
            bool res = false;
            P predicate;
        };

        SymbolVisitor visitor(predicate);
        traverse(visitor);
        return visitor.result();
    }

    /**
     * @return True iff this expression does not contain any variables.
     */
    bool isGround() const;

    /**
     * @return True iff this expression contains exactly one variable.
     */
    bool isUnivariate() const;

    /**
     * @return Some variable that occurs in this Expression.
     * @note Only for non-ground expressions.
     */
    Var someVar() const;

    /**
     * @return True iff this expression is ground or univariate.
     */
    bool isNotMultivariate() const;

    /**
     * @return True iff this expression contains at least two variable.
     */
    bool isMultivariate() const;

    /**
     * @return An estimate of the asymptotic complexity of this expression.
     * @note This should be an over-approximation, but there are no guarantees.
     * @note May return Complexity::CpxUnknown.
     */
    Complexity toComplexity() const;

    /**
     * @return A string representation of this expression.
     */
    std::string toString() const;

    /**
     * @return True iff this and that are equal.
     */
    bool equals(const Expr &that) const;

    /**
     * @return The degree wrt. var.
     * @note For polynomials only.
     */
    int degree(const Var &var) const;

    /**
     * @return The minimal degree of all monomials wrt. var.
     */
    int ldegree(const Var &var) const;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    Expr coeff(const Var &var, int degree = 1) const;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is ldegree(var).
     */
    Expr lcoeff(const Var &var) const;

    /**
     * @return A normalized version of this expression up to the order of monomials.
     * @note No guarantees for non-polynomial expressions.
     */
    Expr expand() const;

    /**
     * @return True iff some subexpression matches the given pattern.
     */
    bool has(const Expr &pattern) const;

    /**
     * @return True iff this is 0.
     */
    bool isZero() const;

    /**
     * @return True iff this is a variable.
     */
    bool isVar() const;

    /**
     * @return True iff this is of the form x^y for some expressions x, y.
     */
    bool isPow() const;

    /**
     * @return True iff this is of the form x*y for some expressions x, y.
     */
    bool isMul() const;

    /**
     * @return True iff this is of the form x+y for some expressions x, y.
     */
    bool isAdd() const;

    /**
     * @return This as a variable.
     * @note For variables only.
     */
    Var toVar() const;

    /**
     * @return This as a number.
     * @note For constants only.
     */
    GiNaC::numeric toNum() const;

    /**
     * @return The i-th operand.
     * @note For function applications whose root symbol has at least arity i+1 only.
     */
    Expr op(unsigned int i) const;

    /**
     * @return The arity of the root symbol.
     * @note For function applications only.
     */
    size_t arity() const;

    /**
     * @return The result of applying the given substitution to this expression.
     * @note The second argument is deprecated.
     */
    Expr subs(const Subs &map) const;

    /**
     * @brief Provides a total order for expressions.
     */
    int compare(const Expr &that) const;

    unsigned hash() const;

    /**
     * @return The numerator.
     * @note For fractions only.
     */
    Expr numerator() const;

    /**
     * @return The denominator.
     * @note For fractions only.
     */
    Expr denominator() const;

    /**
     * @return True iff this is a polynomial wrt. the given variable.
     */
    bool isPoly(const Var &n) const;

    bool isIntegral() const;

    Expr toIntPoly() const;

    GiNaC::numeric denomLcm() const;

    option<std::string> toQepcad() const;

    Sign::T sign() const;

    Monotonicity::T monotonicity(const Var &x) const;

    /**
     * @brief exponentiation
     */
    friend Expr operator^(const Expr &x, const Expr &y);
    friend Expr operator-(const Expr &x);
    friend Expr operator-(const Expr &x, const Expr &y);
    friend Expr operator+(const Expr &x, const Expr &y);
    friend Expr operator*(const Expr &x, const Expr &y);
    friend Expr operator/(const Expr &x, const Expr &y);
    friend Rel operator<(const Expr &x, const Expr &y);
    friend Rel operator>(const Expr &x, const Expr &y);
    friend Rel operator<=(const Expr &x, const Expr &y);
    friend Rel operator>=(const Expr &x, const Expr &y);
    friend Rel operator!=(const Expr &x, const Expr &y);
    friend Rel operator==(const Expr &x, const Expr &y);
    friend std::ostream& operator<<(std::ostream &s, const Expr &e);

private:

    GiNaC::ex ex;

    static Complexity toComplexity(const Expr &term);

    bool match(const Expr &pattern) const;
    void traverse(GiNaC::visitor & v) const;

};

template<class Key, class Key_is_less>
class KeyToExprMap {
    friend class Expr;
    using It = typename std::map<Key, Expr, Key_is_less>::const_iterator;

public:

    KeyToExprMap() {}

    virtual ~KeyToExprMap() {}

    Expr get(const Key &key) const {
        return map.at(key);
    }

    void put(const Key &key, const Expr &val) {
        map[key] = val;
        putGinac(key, val);
    }

    It begin() const {
        return map.begin();
    }

    It end() const {
        return map.end();
    }

    It find(const Key &e) const {
        return map.find(e);
    }

    bool contains(const Key &e) const {
        return map.find(e) != map.end();
    }

    bool empty() const {
        return map.empty();
    }

    unsigned int size() const {
        return map.size();
    }

    size_t erase(const Key &key) {
        eraseGinac(key);
        return map.erase(key);
    }

protected:
    std::map<GiNaC::ex, GiNaC::ex, GiNaC::ex_is_less> ginacMap;
    void virtual putGinac(const Key &key, const Expr &val) = 0;
    void virtual eraseGinac(const Key &key) = 0;

private:
    std::map<Key, Expr, Key_is_less> map;

};

template<class S, class T> bool operator<(const KeyToExprMap<S, T> &x, const KeyToExprMap<S, T> &y) {
    auto it1 = x.begin();
    auto it2 = y.begin();
    while (it1 != x.end() && it2 != y.end()) {
        int fst = it1->first.compare(it2->first);
        if (fst != 0) {
            return fst < 0;
        }
        int snd = it1->second.compare(it2->second);
        if (snd != 0) {
            return snd < 0;
        }
        ++it1;
        ++it2;
    }
    return it1 == x.end() && it2 != y.end();
}

template<class S, class T> std::ostream& operator<<(std::ostream &s, const KeyToExprMap<S, T> &map) {
    if (map.empty()) {
        s << "{}";
    } else {
        s << "{";
        bool fst = true;
        for (const auto &p: map) {
            if (!fst) {
                s << ", ";
            } else {
                fst = false;
            }
            s << p.first << ": " << p.second;
        }
    }
    return s << "}";
}

class Subs: public KeyToExprMap<Var, Var_is_less> {

public:

    Subs();

    Subs(const Var &key, const Expr &val);

    Subs compose(const Subs &that) const;

    Subs concat(const Subs &that) const;

    Subs project(const VarSet &vars) const;

    bool changes(const Var &key) const;

    bool isLinear() const;

    bool isPoly() const;

    bool isOctagon() const;

    VarSet domain() const;

    VarSet coDomainVars() const;

    VarSet allVars() const;

    void collectDomain(VarSet &vars) const;

    void collectCoDomainVars(VarSet &vars) const;

    void collectAllVars(VarSet &vars) const;

    unsigned hash() const;

private:
    void putGinac(const Var &key, const Expr &val) override;
    void eraseGinac(const Var &key) override;

};

class ExprMap: public KeyToExprMap<Expr, Expr_is_less> {

public:
    ExprMap();

    ExprMap(const Expr &key, const Expr &val);

private:
    void putGinac(const Expr &key, const Expr &val) override;
    void eraseGinac(const Expr &key) override;

};

bool operator==(const Subs &m1, const Subs &m2);
