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

#include <optional>
#include <assert.h>

#include "theories.hpp"

template<class EXPR>
class SmtContext {

public:

    virtual EXPR getInt(const Int &val) = 0;
    virtual EXPR getReal(const Int &num, const Int &denom) = 0;
    virtual EXPR pow(const EXPR &base, const EXPR &exp) = 0;
    virtual EXPR plus(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR times(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR eq(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR lt(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR le(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR gt(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR ge(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR neq(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR bAnd(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR bOr(const EXPR &x, const EXPR &y) = 0;
    virtual EXPR bTrue() const = 0;
    virtual EXPR bFalse() const = 0;
    virtual EXPR negate(const EXPR &x) = 0;

    virtual bool isTrue(const EXPR &e) const = 0;
    virtual bool isFalse(const EXPR &e) const = 0;
    virtual bool isNot(const EXPR &e) const = 0;
    virtual std::vector<EXPR> getChildren(const EXPR &e) const = 0;
    virtual bool isAnd(const EXPR &e) const = 0;
    virtual bool isAdd(const EXPR &e) const = 0;
    virtual bool isMul(const EXPR &e) const = 0;
    virtual bool isPow(const EXPR &e) const = 0;
    virtual bool isVar(const EXPR &e) const = 0;
    virtual bool isRationalConstant(const EXPR &e) const = 0;
    virtual bool isInt(const EXPR &e) const = 0;
    virtual long toInt(const EXPR &e) const = 0;
    virtual EXPR lhs(const EXPR &e) const = 0;
    virtual EXPR rhs(const EXPR &e) const = 0;

    virtual void printStderr(const EXPR &e) const = 0;

    std::optional<EXPR> getVariable(const Var &symbol) const {
        const auto res {varMap.get(symbol)};
        if (res) {
            return *res;
        }
        return std::optional<EXPR>{};
    }

    EXPR addNewVariable(const Var &symbol) {
        assert(!varMap.contains(symbol));
        EXPR res {buildVar(symbol)};
        varMap.emplace(symbol, res);
        return res;
    }

    linked_hash_map<Var, EXPR> getSymbolMap() const {
        return varMap;
    }

    virtual ~SmtContext() {}

    void reset() {
        varMap.clear();
    }

protected:

    virtual EXPR buildVar(const Var &var) = 0;

protected:
    linked_hash_map<Var, EXPR> varMap{};
};
