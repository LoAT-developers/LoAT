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
#include "boolexpr.hpp"
#include "numexpression.hpp"

#include <map>
#include <sstream>
#include <map>

template<typename EXPR, ITheory... Th> class ExprToSmt {
public:

    static EXPR convert(const BExpr<Th...> e, SmtContext<EXPR> &ctx) {
        ExprToSmt<EXPR, Th...> converter(ctx);
        return converter.convertBoolEx(e);
    }

    static EXPR convert(const Expr e, SmtContext<EXPR> &ctx) {
        ExprToSmt<EXPR, Th...> converter(ctx);
        return converter.convertEx(e);
    }


protected:
    ExprToSmt(SmtContext<EXPR> &context): context(context) {}

    EXPR convertBoolEx(const BExpr<Th...> e) {
        if (e->getTheoryLit()) {
            const auto lit = *e->getTheoryLit();
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<Rel>(lit)) {
                    return convertRelational(std::get<Rel>(lit));
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolLit>(lit)) {
                    return convertLit(std::get<BoolLit>(lit));
                }
            }
            throw std::logic_error("unsupported theory in exprtosmt");
        }
        EXPR res = e->isAnd() ? context.bTrue() : context.bFalse();
        bool first = true;
        for (const BExpr<Th...> &c: e->getChildren()) {
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
        throw std::invalid_argument(ss.str());
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
            throw std::invalid_argument("Numeric constant too large, cannot convert");
        }
    }

    EXPR convertSymbol(const Var &e) {
        auto optVar = context.getVariable(e);
        if (optVar) {
            return *optVar;
        }
        return context.addNewVariable(e);
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
        auto optVar = context.getVariable(lit.getBoolVar());
        if (!optVar) {
            optVar = context.addNewVariable(lit.getBoolVar());
        }
        return lit.isNegated() ? context.negate(*optVar) : *optVar;
    }

private:
    SmtContext<EXPR> &context;
};
