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
#include "arithexpr.hpp"

#include <sstream>

template<typename EXPR> class ExprToSmt {
public:

    static EXPR convert(const BoolExprPtr e, SmtContext<EXPR> &ctx) {
        ExprToSmt<EXPR> converter(ctx);
        return converter.convertBoolEx(e);
    }

    static EXPR convert(const ArithExprPtr e, SmtContext<EXPR> &ctx) {
        ExprToSmt<EXPR> converter(ctx);
        return converter.convertEx(e);
    }


protected:
    ExprToSmt(SmtContext<EXPR> &context): context(context) {}

    EXPR convertBoolEx(const BoolExprPtr e) {
        if (e->getTheoryLit()) {
            std::visit(
                Overload {
                    [&](const ArithLit &lit) {
                        return convertRelational(lit);
                    },
                    [&](const BoolLit &lit) {
                        return convertLit(lit);
                    }
                }, *e->getTheoryLit());
        }
        EXPR res = e->isAnd() ? context.bTrue() : context.bFalse();
        bool first = true;
        for (const BoolExprPtr &c: e->getChildren()) {
            if (first) {
                res = convertBoolEx(c);
                first = false;
            } else {
                res = e->isAnd() ? context.bAnd(res, convertBoolEx(c)) : context.bOr(res, convertBoolEx(c));
            }
        }
        return res;
    }

    EXPR convertEx(const ArithExprPtr e){
        return e->apply<EXPR>(
            [this](const ArithConstPtr &r) {
                return context.getReal(*r->numerator()->intValue(), *r->denominator()->intValue());
            },
            [this](const ArithVarPtr x) {
                auto optVar = context.getVariable(x);
                if (optVar) {
                    return *optVar;
                }
                return context.addNewVariable(x);
            },
            [this](const ArithAddPtr a) {
                const auto args {a->getArgs()};
                return std::accumulate(args.begin(), args.end(), context.getInt(0), [this](const auto &x, const auto y) {
                    return context.plus(x, convertEx(y));
                });
            },
            [this](const ArithMultPtr m) {
                const auto args {m->getArgs()};
                return std::accumulate(args.begin(), args.end(), context.getInt(1), [this](const auto &x, const auto y) {
                    return context.times(x, convertEx(y));
                });
            },
            [this](const ArithExpPtr e) {
                const auto base {e->getBase()};
                const auto exp {e->getExponent()};
                const auto int_exp {exp->isInt()};
                if (int_exp) {
                    // Z3 still prefers x*x*...*x over x^c...
                    if (1 <= *int_exp && *int_exp <= 10) {
                        auto factor {convertEx(base)};
                        auto res {factor};
                        for (unsigned i = 1; i < *int_exp; ++i) {
                            res = context.times(res, factor);
                        }
                        return res;
                    }
                }
                return context.pow(convertEx(base), convertEx(exp));
            });
    }

    EXPR convertRelational(const ArithLit &rel) {
        return context.gt(convertEx(rel.lhs()), context.getInt(0));
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
