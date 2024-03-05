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
#include "expr.hpp"

#include <assert.h>

using namespace std;

YicesError::YicesError() : std::exception() {
    yices_print_error(stderr);
}

YicesContext::~YicesContext() { }

term_t YicesContext::buildVar(const Var &var) {
    type_t t {
        std::visit(Overload{
                       [](const NumVar&) {
                           return yices_int_type();
                       },
                       [](const BoolVar&) {
                           return yices_bool_type();
                       }
                   }, var)};
    term_t res = yices_new_uninterpreted_term(t);
    yices_set_term_name(res, expr::getName(var).c_str());
    return res;
}

term_t YicesContext::getInt(Num val) {
    mpz_t res;
    mpz_init(res);
    mpz_set_str(res, to_string(val).c_str(), 10);
    return yices_mpz(res);
}

term_t YicesContext::getReal(Num num, Num denom) {
    return yices_parse_rational((to_string(num) + " / " + to_string(denom)).c_str());
}

term_t YicesContext::pow(const term_t &base, const term_t &exp) {
    assert(denominator(exp) == 1);
    const auto exponent {numerator(exp)};
    using bounds = std::numeric_limits<int>;
    if (exponent < bounds::min() || bounds::max() < exponent) {
        throw std::invalid_argument("overflow in YicesContext::pow");
    }
    return yices_power(base, exponent.to_int());
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

Num YicesContext::toInt(const term_t &e) const {
    assert(denominator(e) == 1);
    return numerator(e);
}

Num mpz_to_num(const mpz_t &m) {
    const auto str {mpz_get_str(nullptr, 10, m)};
    const Num ret {str};
    free(str);
    return ret;
}

Num YicesContext::numerator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_num(res, frac);
        return mpz_to_num(res);
    } else {
        throw YicesError();
    }
}

Num YicesContext::denominator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_den(res, frac);
        return mpz_to_num(res);
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
            term_t child;
            if (yices_sum_component(e, i, coeff, &child) != 0) {
                throw YicesError();
            }
            if (children == 1) {
                res.push_back(yices_mpq(coeff));
                if (child != NULL_TERM) {
                    res.push_back(child);
                }
            } else {
                if (child == NULL_TERM) {
                    res.push_back(yices_mpq(coeff));
                } else {
                    res.push_back(yices_mul(yices_mpq(coeff), child));
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

void YicesContext::printStderr(const term_t &e) const {
    yices_pp_term(stderr, e, 80, 20, 0);
}
