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

#ifndef Z3CONTEXT_H
#define Z3CONTEXT_H

#include "smtcontext.hpp"
#include "expression.hpp"

#include <z3++.h>
#include <map>


/**
 * Wrapper around z3 context to allow convenient variable handling.
 *
 * Note that z3 identifies symbols with the same name, whereas GiNaC considers two symbols with the same name
 * as different. This context does thus map GiNaC symbols to z3 symbols (instead of mapping names to z3 symbols).
 *
 * For convenience, it is also possible to create z3 symbols not associated to any GiNaC symbol,
 * but these symbols cannot be looked up later (as they are not associated to any GiNaC symbol).
 */
class Z3Context : public SmtContext<z3::expr> {

public:
    Z3Context(z3::context& ctx);
    ~Z3Context() override;
    z3::expr getInt(long val) override;
    z3::expr getReal(long num, long denom) override;
    z3::expr pow(const z3::expr &base, const z3::expr &exp) override;
    z3::expr plus(const z3::expr &x, const z3::expr &y) override;
    z3::expr times(const z3::expr &x, const z3::expr &y) override;
    z3::expr eq(const z3::expr &x, const z3::expr &y) override;
    z3::expr lt(const z3::expr &x, const z3::expr &y) override;
    z3::expr le(const z3::expr &x, const z3::expr &y) override;
    z3::expr gt(const z3::expr &x, const z3::expr &y) override;
    z3::expr ge(const z3::expr &x, const z3::expr &y) override;
    z3::expr neq(const z3::expr &x, const z3::expr &y) override;
    z3::expr bAnd(const z3::expr &x, const z3::expr &y) override;
    z3::expr bOr(const z3::expr &x, const z3::expr &y) override;
    z3::expr bTrue() const override;
    z3::expr bFalse() const override;
    z3::expr negate(const z3::expr &x) override;

    bool isNoOp(const z3::expr &e) const override;

    bool isLit(const z3::expr &e) const override;
    bool isTrue(const z3::expr &e) const override;
    bool isFalse(const z3::expr &e) const override;
    bool isNot(const z3::expr &e) const override;
    std::vector<z3::expr> getChildren(const z3::expr &e) const override;
    bool isAnd(const z3::expr &e) const override;
    bool isAdd(const z3::expr &e) const override;
    bool isMul(const z3::expr &e) const override;
    bool isDiv(const z3::expr &e) const override;
    bool isPow(const z3::expr &e) const override;
    bool isVar(const z3::expr &e) const override;
    bool isRationalConstant(const z3::expr &e) const override;
    bool isInt(const z3::expr &e) const override;
    bool isITE(const z3::expr &e) const override;
    long toInt(const z3::expr &e) const override;
    long numerator(const z3::expr &e) const override;
    long denominator(const z3::expr &e) const override;
    z3::expr lhs(const z3::expr &e) const override;
    z3::expr rhs(const z3::expr &e) const override;
    Rel::RelOp relOp(const z3::expr &e) const override;
    std::string getName(const z3::expr &x) const override;

    void printStderr(const z3::expr &e) const override;

private:

    z3::context &ctx;

    z3::expr buildVar(const std::string &basename, Expr::Type type) override;
    z3::expr buildConst(const BoolVar &var) override;

};

#endif // Z3CONTEXT_H
