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

#include "z3context.hpp"
#include "theory.hpp"

using namespace std;

Z3Context::Z3Context(z3::context& ctx): ctx(ctx) {}

Z3Context::~Z3Context() { }

z3::expr Z3Context::buildVar(const Var &var) {
    const auto name {theory::getName(var)};
    return std::visit(
        Overload{
            [&](const ArithVarPtr&) {
                return ctx.int_const(name.c_str());
            },
            [&](const BoolVarPtr&) {
                return ctx.bool_const(name.c_str());
            }
        }, var);
}

z3::expr Z3Context::getInt(const Int &val) {
    return ctx.int_val(val.convert_to<int64_t>());
}

z3::expr Z3Context::getReal(const Int &num, const Int &denom) {
    return ctx.real_val(num.convert_to<int64_t>(), denom.convert_to<int64_t>());
}

z3::expr Z3Context::pow(const z3::expr &base, const z3::expr &exp) {
    return z3::pw(base, exp);
}

z3::expr Z3Context::plus(const z3::expr &x, const z3::expr &y) {
    return x + y;
}

z3::expr Z3Context::times(const z3::expr &x, const z3::expr &y) {
    return x * y;
}

z3::expr Z3Context::eq(const z3::expr &x, const z3::expr &y) {
    return x == y;
}

z3::expr Z3Context::lt(const z3::expr &x, const z3::expr &y) {
    return x < y;
}

z3::expr Z3Context::le(const z3::expr &x, const z3::expr &y) {
    return x <= y;
}

z3::expr Z3Context::gt(const z3::expr &x, const z3::expr &y) {
    return x > y;
}

z3::expr Z3Context::ge(const z3::expr &x, const z3::expr &y) {
    return x >= y;
}

z3::expr Z3Context::neq(const z3::expr &x, const z3::expr &y) {
    return x != y;
}

z3::expr Z3Context::bAnd(const z3::expr &x, const z3::expr &y) {
    return x && y;
}

z3::expr Z3Context::bOr(const z3::expr &x, const z3::expr &y) {
    return x || y;
}

z3::expr Z3Context::bTrue() const {
    return ctx.bool_val(true);
}

z3::expr Z3Context::bFalse() const {
    return ctx.bool_val(false);
}

z3::expr Z3Context::negate(const z3::expr &x) {
    return !x;
}

bool Z3Context::isTrue(const z3::expr &e) const {
    return e.is_true();
}

bool Z3Context::isFalse(const z3::expr &e) const {
    return e.is_false();
}

bool Z3Context::isNot(const z3::expr &e) const {
    return e.is_not();
}

std::vector<z3::expr> Z3Context::getChildren(const z3::expr &e) const {
    std::vector<z3::expr> res;
    unsigned arity = e.num_args();
    for (unsigned i = 0; i < arity; ++i) {
        res.push_back(e.arg(i));
    }
    return res;
}

bool Z3Context::isAnd(const z3::expr &e) const {
    return e.is_and();
}

bool Z3Context::isAdd(const z3::expr &e) const {
    return e.is_app() && e.decl().decl_kind() == Z3_OP_ADD;
}

bool Z3Context::isMul(const z3::expr &e) const {
    return e.is_app() && e.decl().decl_kind() == Z3_OP_MUL;
}

bool Z3Context::isPow(const z3::expr &e) const  {
    return e.is_app() && e.decl().decl_kind() == Z3_OP_POWER;
}

bool Z3Context::isVar(const z3::expr &e) const  {
    return e.is_const() && !e.is_numeral();
}

bool Z3Context::isRationalConstant(const z3::expr &e) const {
    return e.is_numeral();
}

bool Z3Context::isInt(const z3::expr &e) const {
    return e.is_numeral() && e.is_int();
}

long Z3Context::toInt(const z3::expr &e) const {
    return e.get_numeral_int64();
}

z3::expr Z3Context::lhs(const z3::expr &e) const {
    assert(e.num_args() == 2);
    return e.arg(0);
}

z3::expr Z3Context::rhs(const z3::expr &e) const {
    assert(e.num_args() == 2);
    return e.arg(1);
}

void Z3Context::printStderr(const z3::expr &e) const {
    std::cerr << e << std::endl;
}
