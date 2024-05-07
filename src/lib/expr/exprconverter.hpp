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

#include "exprconversioncontext.hpp"
#include "theory.hpp"

#include <sstream>

template<class Expr, class Formula>
class ExprConverter {
public:

    static Formula convert(const Bools::Expr e, ExprConversionContext<Expr, Formula> &ctx) {
        ExprConverter<Expr, Formula> converter(ctx);
        return converter.convertBoolEx(e);
    }

    static Expr convert(const Arith::Expr e, ExprConversionContext<Expr, Formula> &ctx) {
        ExprConverter<Expr, Formula> converter(ctx);
        return converter.convertEx(e);
    }


protected:
    ExprConverter(ExprConversionContext<Expr, Formula> &context): context(context) {}

    Formula convertBoolEx(const Bools::Expr e) {
        if (e->getTheoryLit()) {
            return std::visit(
                Overload {
                    [&](const ArithLit &lit) {
                        return convertRelational(lit);
                    },
                    [&](const BoolLit &lit) {
                        return convertLit(lit);
                    }
                }, *e->getTheoryLit());
        }
        auto res = e->isAnd() ? context.bTrue() : context.bFalse();
        auto first = true;
        for (const auto &c: e->getChildren()) {
            if (first) {
                res = convertBoolEx(c);
                first = false;
            } else {
                res = e->isAnd() ? context.bAnd(res, convertBoolEx(c)) : context.bOr(res, convertBoolEx(c));
            }
        }
        return res;
    }

    Expr convertEx(const Arith::Expr e){
        return e->apply<Expr>(
            [&](const ArithConstPtr &r) {
                if (const auto i{r->intValue()}) {
                    return context.getInt(*i);
                } else {
                    return context.getReal(*r->numerator()->intValue(), *r->denominator()->intValue());
                }
            },
            [&](const Arith::Var x) {
                return context.getVariable(x);
            },
            [&](const ArithAddPtr a) {
                const auto args {a->getArgs()};
                const auto res {std::accumulate(args.begin(), args.end(), context.getInt(0), [&](const auto &x, const auto y) {
                    return context.plus(x, convertEx(y));
                })};
                return res;
            },
            [&](const ArithMultPtr m) {
                const auto args {m->getArgs()};
                return std::accumulate(args.begin(), args.end(), context.getInt(1), [&](const auto &x, const auto y) {
                    return context.times(x, convertEx(y));
                });
            },
            [&](const ArithModPtr m) {
                return context.mod(convertEx(m->getLhs()), convertEx(m->getRhs()));
            },
            [&](const ArithExpPtr e) {
                const auto base {e->getBase()};
                const auto exp {e->getExponent()};
                if (const auto int_exp {exp->isInt()}) {
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

    Formula convertRelational(const ArithLit &rel) {
        const auto lhs {convertEx(rel.lhs())};
        const auto rhs {context.getInt(0)};
        if (rel.isGt()) {
            return context.gt(lhs, rhs);
        } else if (rel.isEq()) {
            return context.eq(lhs, rhs);
        } else if (rel.isNeq()) {
            return context.neq(lhs, rhs);
        }
        throw std::invalid_argument("unknown relation");
    }

    Formula convertLit(const BoolLit &lit) {
        auto var {context.getVariable(lit.getBoolVar())};
        return lit.isNegated() ? context.negate(var) : var;
    }

private:
    ExprConversionContext<Expr, Formula> &context;
};
