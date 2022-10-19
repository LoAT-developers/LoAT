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

#include "option.hpp"
#include "numexpression.hpp"
#include "rel.hpp"
#include "theory.hpp"
#include "variable.hpp"

#include <map>

template<class EXPR>
class SmtContext {

public:

    virtual EXPR getInt(long val) = 0;
    virtual EXPR getReal(long num, long denom) = 0;
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

    virtual bool isNoOp(const EXPR &e) const {
        return false;
    }

    virtual bool isLit(const EXPR &e) const = 0;
    virtual bool isTrue(const EXPR &e) const = 0;
    virtual bool isFalse(const EXPR &e) const = 0;
    virtual bool isNot(const EXPR &e) const = 0;
    virtual std::vector<EXPR> getChildren(const EXPR &e) const = 0;
    virtual bool isAnd(const EXPR &e) const = 0;
    virtual bool isAdd(const EXPR &e) const = 0;
    virtual bool isMul(const EXPR &e) const = 0;
    virtual bool isDiv(const EXPR &e) const = 0;
    virtual bool isPow(const EXPR &e) const = 0;
    virtual bool isVar(const EXPR &e) const = 0;
    virtual bool isRationalConstant(const EXPR &e) const = 0;
    virtual bool isInt(const EXPR &e) const = 0;
    virtual bool isITE(const EXPR &e) const = 0;
    virtual long toInt(const EXPR &e) const = 0;
    virtual long numerator(const EXPR &e) const = 0;
    virtual long denominator(const EXPR &e) const = 0;
    virtual EXPR lhs(const EXPR &e) const = 0;
    virtual EXPR rhs(const EXPR &e) const = 0;
    virtual Rel::RelOp relOp(const EXPR &e) const = 0;
    virtual std::string getName(const EXPR &e) const = 0;

    virtual void printStderr(const EXPR &e) const = 0;

    option<EXPR> getVariable(const Var &symbol) const {
        auto it = varMap.find(symbol);
        if (it != varMap.end()) {
            return it->second;
        }
        return option<EXPR>{};
    }

    option<Var> getVariable(const std::string &name) const {
        auto it = nameMap.find(name);
        if (it != nameMap.end() && varMap.find(it->second) != varMap.end()) {
            return it->second;
        }
        return {};
    }

    EXPR addNewVariable(const Var &symbol, Expr::Type type) {
        assert(varMap.find(symbol) == varMap.end());
        assert(nameMap.find(variable::getName(symbol)) == nameMap.end());
        EXPR res = generateFreshVar(variable::getName(symbol), type);
        varMap.emplace(symbol, res);
        nameMap.emplace(variable::getName(symbol), symbol);
        return res;
    }

    std::map<Var, EXPR> getSymbolMap() const {
        return varMap;
    }

    virtual ~SmtContext() {}

    void reset() {
        varMap.clear();
        nameMap.clear();
        usedNames.clear();
    }

protected:

    std::string generateFreshVarName(const std::string &basename) {
        std::string newname = basename;
        while (usedNames.find(newname) != usedNames.end()) {
            int cnt = usedNames[basename]++;
            newname = basename + "_" + std::to_string(cnt);
        }
        usedNames.emplace(newname, 1); // newname is now used once
        return newname;
    }

    EXPR generateFreshVar(const std::string &basename, Expr::Type type) {
        return buildVar(generateFreshVarName(basename), type);
    }

    virtual EXPR buildVar(const std::string &name, Expr::Type type) = 0;

protected:
    std::map<Var, EXPR> varMap;
    std::map<std::string, Var> nameMap;
    std::map<std::string, int> usedNames;
};
