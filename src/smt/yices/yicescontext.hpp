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

#include "smtcontext.hpp"
#include "expression.hpp"

#include <gmp.h>
#include <yices.h>
#include <map>

class YicesError : public std::exception {
public:
    YicesError();
};

class YicesContext : public SmtContext<term_t> {

public:
    ~YicesContext() override;
    term_t getInt(long val) override;
    term_t getReal(long num, long denom) override;
    term_t pow(const term_t &base, const term_t &exp) override;
    term_t plus(const term_t &x, const term_t &y) override;
    term_t times(const term_t &x, const term_t &y) override;
    term_t eq(const term_t &x, const term_t &y) override;
    term_t lt(const term_t &x, const term_t &y) override;
    term_t le(const term_t &x, const term_t &y) override;
    term_t gt(const term_t &x, const term_t &y) override;
    term_t ge(const term_t &x, const term_t &y) override;
    term_t neq(const term_t &x, const term_t &y) override;
    term_t bAnd(const term_t &x, const term_t &y) override;
    term_t bOr(const term_t &x, const term_t &y) override;
    term_t bTrue() const override;
    term_t bFalse() const override;
    term_t negate(const term_t &x) override;

    bool isLit(const term_t &e) const override;
    bool isTrue(const term_t &e) const override;
    bool isFalse(const term_t &e) const override;
    bool isNot(const term_t &e) const override;
    std::vector<term_t> getChildren(const term_t &e) const override;
    bool isAnd(const term_t &e) const override;
    bool isAdd(const term_t &e) const override;
    bool isMul(const term_t &e) const override;
    bool isDiv(const term_t &e) const override;
    bool isPow(const term_t &e) const override;
    bool isVar(const term_t &e) const override;
    bool isRationalConstant(const term_t &e) const override;
    bool isInt(const term_t &e) const override;
    bool isITE(const term_t &e) const override;
    long toInt(const term_t &e) const override;
    long numerator(const term_t &e) const override;
    long denominator(const term_t &e) const override;
    term_t lhs(const term_t &e) const override;
    term_t rhs(const term_t &e) const override;
    Rel::RelOp relOp(const term_t &e) const override;
    std::string getName(const term_t &e) const override;

    void printStderr(const term_t &e) const override;

protected:
    term_t buildVar(const std::string &basename, Expr::Type type) override;
    term_t buildConst(const std::string &name) override;

private:
    std::map<term_t, std::string> varNames;

};
