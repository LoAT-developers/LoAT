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

#include "numvar.hpp"

class Expr;
class NumVar;
class Recurrence;
class Rel;
class ExprSubs;

// Specifies for which coefficients c we can solve "c*x == t" for x.
enum SolvingLevel {
    TrivialCoeffs = 0, // only c=1 and c=-1 is allowed
    ResultMapsToInt = 1, // c can be any rational constant, as long as x = t/c maps to int
    ConstantCoeffs = 2, // c can be any rational constant (the result may not map to int, use with caution!)
};

using Num = GiNaC::numeric;

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

    friend class ExprSubs;

public:

    /**
     * possible types of variables
     */
    enum Type {Int, Rational, Bool};

    /**
     * @return A wildcard for constructing patterns.
     */
    static Expr wildcard(unsigned int label);

    Expr() : Expr(GiNaC::ex()) {}
    Expr(const GiNaC::basic &other) : Expr(GiNaC::ex(other)) {}
    Expr(const GiNaC::ex &ex) : ex(ex) {}
    Expr(long i): ex(i) {}
    Expr(const NumVar &var): ex(*var) {}

    /**
     * @brief Applies a substitution via side-effects.
     * @deprecated use subs instead
     */
    void applySubs(const ExprSubs &subs);

    /**
     * @brief Computes all matches of the given pattern.
     * @return True iff there was at least one match.
     */
    bool findAll(const Expr &pattern, std::set<Expr> &found) const;

    /**
     * @return True iff this expression is equal (resp. evaluates) to the given variable
     */
    bool equals(const NumVar &var) const;

    /**
     * @return True iff this expression is a linear polynomial wrt. the given variables (resp. all variables, if vars is empty).
     */
    bool isLinear(const std::optional<std::set<NumVar>> &vars = std::optional<std::set<NumVar>>()) const;

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
    unsigned maxDegree() const;

    Num totalDegree() const;

    /**
     * @brief Collects all variables that occur in this expression.
     */
    void collectVars(std::set<NumVar> &res) const;

    /**
     * @return The set of all variables that occur in this expression.
     */
    std::set<NumVar> vars() const;

    /**
     * @return True iff this expression contains a variable that satisfies the given predicate.
     * @param A function of type `const Var & => bool`.
     */
    template <typename P>
    bool hasVarWith(P predicate) const {
        struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
            SymbolVisitor(P predicate) : predicate(predicate) {}
            void visit(const GiNaC::symbol &sym) {
                if (!res && predicate(NumVar(sym.get_name()))) {
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
    NumVar someVar() const;

    /**
     * @return True iff this expression is ground or univariate.
     */
    bool isNotMultivariate() const;

    /**
     * @return True iff this expression contains at least two variable.
     */
    bool isMultivariate() const;

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
    unsigned degree(const NumVar &var) const;

    /**
     * @return The minimal degree of all monomials wrt. var.
     */
    unsigned ldegree(const NumVar &var) const;

    /**
     * @return The coefficient of the monomial where var occurs with the given degree (which defaults to 1).
     */
    Expr coeff(const NumVar &var, int degree = 1) const;

    /**
     * @return The coefficient of the monomial whose degree wrt. var is ldegree(var).
     */
    Expr lcoeff(const NumVar &var) const;

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
    NumVar toVar() const;

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
    Expr subs(const ExprSubs &map) const;

    /**
     * @brief Provides a total order for expressions.
     */
    int compare(const Expr &that) const;

    size_t hash() const;

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
    bool isPoly(const NumVar &n) const;

    bool isIntegral() const;

    Expr toIntPoly() const;

    Num denomLcm() const;

    std::optional<std::string> toQepcad() const;

    std::optional<Expr> solveTermFor(const NumVar &var, SolvingLevel level) const;

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
    friend bool operator<(const Expr &x, const Expr &y);
    friend bool operator==(const Expr &x, const Expr &y);

private:

    GiNaC::ex ex;

    bool match(const Expr &pattern) const;
    void traverse(GiNaC::visitor & v) const;

};

class ExprSubs {

    friend class Expr;

public:

    using const_iterator = typename std::map<NumVar, Expr>::const_iterator;

    ExprSubs();

    ExprSubs(std::initializer_list<std::pair<const NumVar, Expr>> init);

    Expr get(const NumVar &key) const;

    void put(const NumVar &key, const Expr &val);

    const_iterator begin() const;

    const_iterator end() const;

    const_iterator find(const NumVar &e) const;

    bool contains(const NumVar &e) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const NumVar &key);

    ExprSubs compose(const ExprSubs &that) const;

    ExprSubs concat(const ExprSubs &that) const;

    ExprSubs unite(const ExprSubs &that) const;

    ExprSubs project(const std::set<NumVar> &vars) const;

    ExprSubs setminus(const std::set<NumVar> &vars) const;

    bool changes(const NumVar &key) const;

    bool isLinear() const;

    bool isPoly() const;

    bool isOctagon() const;

    std::set<NumVar> domain() const;

    std::set<NumVar> coDomainVars() const;

    std::set<NumVar> allVars() const;

    void collectDomain(std::set<NumVar> &vars) const;

    void collectCoDomainVars(std::set<NumVar> &vars) const;

    void collectVars(std::set<NumVar> &vars) const;

    size_t hash() const;

    int compare(const ExprSubs &that) const;

private:
    void putGinac(const NumVar &key, const Expr &val);
    void eraseGinac(const NumVar &key);
    GiNaC::exmap ginacMap;
    std::map<NumVar, Expr> map;

};

bool operator==(const ExprSubs &m1, const ExprSubs &m2);

std::ostream& operator<<(std::ostream &s, const ExprSubs &map);

bool operator<(const ExprSubs &x, const ExprSubs &y);
