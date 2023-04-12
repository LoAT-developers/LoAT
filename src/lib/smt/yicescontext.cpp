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

#include "yicescontext.hpp"

#include <assert.h>

using namespace std;

YicesError::YicesError() : std::exception() {
    yices_print_error(stderr);
}

YicesContext::~YicesContext() { }

term_t YicesContext::buildVar(const std::string &name, Expr::Type type) {
    type_t t;
    switch (type) {
    case Expr::Int: t = yices_int_type();
        break;
    case Expr::Rational: t = yices_real_type();
        break;
    case Expr::Bool: t = yices_bool_type();
        break;
    default: throw std::invalid_argument("unknown type");
    }
    term_t res = yices_new_uninterpreted_term(t);
    yices_set_term_name(res, name.c_str());
    varNames[res] = name;
    return res;
}

term_t YicesContext::getInt(long val) {
    return yices_int64(val);
}

term_t YicesContext::getReal(long num, long denom) {
    assert(denom != 0);
    if (denom > 0) {
        return yices_rational64(num, denom);
    } else {
        return yices_rational64(-num, -denom);
    }
}

term_t YicesContext::pow(const term_t &base, const term_t &exp) {
    assert(denominator(exp) == 1);
    return yices_power(base, numerator(exp));
}

term_t YicesContext::plus(const term_t &x, const term_t &y) {
    return yices_add(x, y);
}

term_t YicesContext::times(const term_t &x, const term_t &y) {
    return yices_mul(x, y);
}

term_t YicesContext::eq(const term_t &x, const term_t &y) {
    return yices_arith_eq_atom(x, y);
}

term_t YicesContext::lt(const term_t &x, const term_t &y) {
    return yices_arith_lt_atom(x, y);
}

term_t YicesContext::le(const term_t &x, const term_t &y) {
    return yices_arith_leq_atom(x, y);
}

term_t YicesContext::gt(const term_t &x, const term_t &y) {
    return yices_arith_gt_atom(x, y);
}

term_t YicesContext::ge(const term_t &x, const term_t &y) {
    return yices_arith_geq_atom(x, y);
}

term_t YicesContext::neq(const term_t &x, const term_t &y) {
    return yices_arith_neq_atom(x, y);
}

term_t YicesContext::bAnd(const term_t &x, const term_t &y) {
    return yices_and2(x, y);
}

term_t YicesContext::bOr(const term_t &x, const term_t &y) {
    return yices_or2(x, y);
}

term_t YicesContext::bTrue() const {
    return yices_true();
}

term_t YicesContext::bFalse() const {
    return yices_false();
}

term_t YicesContext::negate(const term_t &x) {
    return yices_not(x);
}

bool YicesContext::isAnd(const term_t &e) const {
    return false; // yices represents x /\ y as !(x \/ y)
}

bool YicesContext::isAdd(const term_t &e) const {
    return yices_term_is_sum(e) && yices_term_num_children(e) > 1;
}

bool YicesContext::isMul(const term_t &e) const {
    return yices_term_is_product(e) || (yices_term_num_children(e) == 1 && yices_term_is_sum(e));
}

bool YicesContext::isPow(const term_t &e) const {
    // yices does not support exponentiation
    // it has a special internal representation for polynomials, though
    // I'm not sure if we need special handling for that
    return false;
}

bool YicesContext::isVar(const term_t &e) const {
    return yices_term_constructor(e) == YICES_UNINTERPRETED_TERM;
}

bool YicesContext::isRationalConstant(const term_t &e) const {
    return yices_term_constructor(e) == YICES_ARITH_CONSTANT;
}

bool YicesContext::isInt(const term_t &e) const {
    return yices_is_int_atom(e);
}

long YicesContext::toInt(const term_t &e) const {
    long res = numerator(e);
    assert(denominator(e) == 1);
    return res;
}

long YicesContext::numerator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_num(res, frac);
        return mpz_get_si(res);
    } else {
        throw YicesError();
    }
}

long YicesContext::denominator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_den(res, frac);
        return mpz_get_si(res);
    } else {
        throw YicesError();
    }
}

term_t YicesContext::lhs(const term_t &e) const {
    return yices_term_child(e, 0);
}

term_t YicesContext::rhs(const term_t &e) const {
    return yices_term_child(e, 1);
}

bool YicesContext::isTrue(const term_t &e) const {
    if (yices_term_is_atomic(e) && yices_term_is_bool(e)) {
        int32_t res;
        yices_bool_const_value(e, &res);
        return res;
    } else {
        return false;
    }
}

bool YicesContext::isFalse(const term_t &e) const {
    if (yices_term_is_atomic(e) && yices_term_is_bool(e)) {
        int32_t res;
        yices_bool_const_value(e, &res);
        return !res;
    } else {
        return false;
    }
}

bool YicesContext::isNot(const term_t &e) const {
    return yices_term_constructor(e) == YICES_NOT_TERM;
}

std::vector<term_t> YicesContext::getChildren(const term_t &e) const {
    int children = yices_term_num_children(e);
    std::vector<term_t> res;
    if (yices_term_is_sum(e)) {
        for (int i = 0; i < children; ++i) {
            mpq_t coeff;
            mpz_t numerator;
            mpz_t denominator;
            mpq_init(coeff);
            mpz_init(numerator);
            mpz_init(denominator);
            term_t child;
            if (yices_sum_component(e, i, coeff, &child) != 0) {
                throw YicesError();
            }
            mpq_get_num(numerator, coeff);
            mpq_get_den(denominator, coeff);
            long num = mpz_get_si(numerator);
            long den = mpz_get_si(denominator);
            if (den < 0) {
                num = -num;
                den = -den;
            }
            if (children == 1) {
                res.push_back(yices_rational64(num, den));
                if (child != NULL_TERM) {
                    res.push_back(child);
                }
            } else {
                if (child == NULL_TERM) {
                    res.push_back(yices_rational64(num, den));
                } else {
                    res.push_back(yices_mul(yices_rational64(num, den), child));
                }
            }
        }
    } else if (yices_term_is_product(e)) {
        for (int i = 0; i < children; ++i) {
            uint32_t exp;
            term_t child;
            if (yices_product_component(e, i, &child, &exp) != 0) {
                throw YicesError();
            }
            for (unsigned int j = 0; j < exp; ++j) {
                res.push_back(child);
            }
        }
    } else {
        for (int i = 0; i < children; ++i) {
            res.push_back(yices_term_child(e, i));
        }
    }
    return res;
}

Rel::RelOp YicesContext::relOp(const term_t &e) const {
    switch (yices_term_constructor(e)) {
    case YICES_ARITH_GE_ATOM: return Rel::RelOp::geq;
    case YICES_EQ_TERM: return Rel::RelOp::eq;
    default: throw std::invalid_argument("unknown relation"); // yices normalizes all other relations to >= or =
    }
}

std::string YicesContext::getName(const term_t &e) const {
    return varNames.at(e);
}

void YicesContext::printStderr(const term_t &e) const {
    yices_pp_term(stderr, e, 80, 20, 0);
}
