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
#include "theory.hpp"

#include <assert.h>

using namespace std;

YicesError::YicesError() : std::exception() {
    yices_print_error(stderr);
}

YicesContext::~YicesContext() { }

term_t YicesContext::buildVar(const Arith::Var &var) {
    term_t res = yices_new_uninterpreted_term(yices_int_type());
    yices_set_term_name(res, var->getName().c_str());
    return res;
}

term_t YicesContext::buildVar(const Bools::Var &var) {
    term_t res = yices_new_uninterpreted_term(yices_bool_type());
    yices_set_term_name(res, var->getName().c_str());
    return res;
}

term_t YicesContext::getInt(const Int &val) {
    mpz_t res;
    mpz_init(res);
    mpz_set_str(res, val.str().c_str(), 10);
    return yices_mpz(res);
}

term_t YicesContext::getReal(const Int &num, const Int &denom) {
    return yices_parse_rational((num.str() + " / " + denom.str()).c_str());
}

term_t YicesContext::pow(const term_t &base, const term_t &exp) {
    assert(denominator(exp) == 1);
    const auto exponent {numerator(exp)};
    using bounds = std::numeric_limits<int>;
    if (exponent < bounds::min() || bounds::max() < exponent) {
        throw std::invalid_argument("overflow in YicesContext::pow");
    }
    return yices_power(base, exponent.convert_to<int>());
}

term_t YicesContext::plus(const term_t &x, const term_t &y) {
    return yices_add(x, y);
}

term_t YicesContext::times(const term_t &x, const term_t &y) {
    return yices_mul(x, y);
}

term_t YicesContext::mod(const term_t &x, const term_t &y) {
    return yices_imod(x, y);
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

Int mpz_to_int(const mpz_t &m) {
    const auto str {mpz_get_str(nullptr, 10, m)};
    const Int ret {str};
    free(str);
    return ret;
}

Int YicesContext::numerator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_num(res, frac);
        return mpz_to_int(res);
    } else {
        throw YicesError();
    }
}

Int YicesContext::denominator(const term_t &e) const {
    mpq_t frac;
    mpz_t res;
    mpq_init(frac);
    mpz_init(res);
    if (yices_rational_const_value(e, frac) == 0) {
        mpq_get_den(res, frac);
        return mpz_to_int(res);
    } else {
        throw YicesError();
    }
}

void YicesContext::printStderr(const term_t &e) const {
    yices_pp_term(stderr, e, 80, 20, 0);
}
