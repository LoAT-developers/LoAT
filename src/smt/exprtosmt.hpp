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

#ifndef EXPRTOSMT_H
#define EXPRTOSMT_H

#include "exceptions.hpp"
#include "smtcontext.hpp"
#include "config.hpp"
#include "boolexpr.hpp"
#include "variablemanager.hpp"

#include <map>
#include <sstream>

template<typename EXPR> class ExprToSmt {
public:

    static EXPR convert(const BoolExpr e, SmtContext<EXPR> &ctx, const VariableManager &varMan) {
        ExprToSmt<EXPR> converter(ctx, varMan);
        return converter.convertBoolEx(e);
    }


protected:
    ExprToSmt(SmtContext<EXPR> &context, const VariableManager &varMan):
        context(context),
        varMan(varMan) {}

    EXPR convertBoolEx(const BoolExpr e) {
        if (e->getLit()) {
            return convertLit(*e->getLit());
        }
        if (e->getTheoryLit()) {
            return convertRelational(*e->getTheoryLit());
        }
        EXPR res = e->isAnd() ? context.bTrue() : context.bFalse();
        bool first = true;
        for (const BoolExpr &c: e->getChildren()) {
            if (first) {
                res = convertBoolEx(c);
                first = false;
            } else {
                res = e->isAnd() ? context.bAnd(res, convertBoolEx(c)) : context.bOr(res, convertBoolEx(c));
            }
        }
        return res;
    }

    EXPR convertEx(const Expr &e){
        if (e.isAdd()) {
            return convertAdd(e);

        } else if (e.isMul()) {
            return convertMul(e);

        } else if (e.isPow()) {
            return convertPower(e);

        } else if (e.isRationalConstant()) {
            return convertNumeric(e.toNum());

        } else if (e.isVar()) {
            return convertSymbol(e.toVar());

        }

        std::stringstream ss;
        ss << "Error: conversion not implemented for term: " << e << std::endl;
        throw ConversionError(ss.str());
    }

    EXPR convertAdd(const Expr &e){
        assert(e.arity() > 0);

        EXPR res = convertEx(e.op(0));
        for (unsigned int i=1; i < e.arity(); ++i) {
            res = context.plus(res, convertEx(e.op(i)));
        }

        return res;
    }

    EXPR convertMul(const Expr &e) {
        assert(e.arity() > 0);

        EXPR res = convertEx(e.op(0));
        for (unsigned int i=1; i < e.arity(); ++i) {
            res = context.times(res, convertEx(e.op(i)));
        }

        return res;
    }

    EXPR convertPower(const Expr &e) {
        assert(e.arity() == 2);

        //rewrite power as multiplication if possible, which z3 can handle much better (e.g x^3 becomes x*x*x)
        if (e.op(1).isRationalConstant()) {
            Num num = e.op(1).toNum();
            if (num.is_integer() && num.is_positive() && num.to_long() <= Config::Smt::MaxExponentWithoutPow) {
                int exp = num.to_int();
                EXPR base = convertEx(e.op(0));

                EXPR res = base;
                while (--exp > 0) {
                    res = context.times(res, base);
                }

                return res;
            }
        }

        //use z3 power as fallback (only poorly supported)
        return context.pow(convertEx(e.op(0)), convertEx(e.op(1)));
    }

    EXPR convertNumeric(const Num &num) {
        assert(num.is_integer() || num.is_real());

        try {
            // convert integer either as integer or as reals (depending on settings)
            if (num.is_integer()) {
                return context.getInt(num.to_long());
            }

            // always convert real numbers as reals
            return context.getReal(num.numer().to_long(), num.denom().to_long());

        } catch (...) {
            throw LargeConstantError("Numeric constant too large, cannot convert");
        }
    }

    EXPR convertSymbol(const Var &e) {
        auto optVar = context.getVariable(e);
        if (optVar) {
            return optVar.get();
        }
        return context.addNewVariable(e, varMan.getType(e));
    }

    EXPR convertRelational(const Rel &rel) {

        EXPR a = convertEx(rel.lhs());
        EXPR b = convertEx(rel.rhs());

        switch (rel.relOp()) {
        case Rel::eq: return context.eq(a, b);
        case Rel::neq: return context.neq(a, b);
        case Rel::lt: return context.lt(a, b);
        case Rel::leq: return context.le(a, b);
        case Rel::gt: return context.gt(a, b);
        case Rel::geq: return context.ge(a, b);
        }

        throw std::invalid_argument("unreachable");
    }

    EXPR convertLit(const BoolLit &lit) {
        auto optVar = context.getConst(lit.getBoolVar());
        if (!optVar) {
            optVar = context.addNewConst(lit.getBoolVar());
        }
        return lit.isNegated() ? context.negate(*optVar) : *optVar;
    }

private:
    SmtContext<EXPR> &context;
    const VariableManager &varMan;
};

#endif // ExprToSmt_H
