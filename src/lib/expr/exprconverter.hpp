#pragma once

#include "exprconversioncontext.hpp"
#include "theory.hpp"

#include <sstream>
#include <numeric>

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
                    [&](const Arith::Lit &lit) {
                        return convertRelational(lit);
                    },
                    [&](const Bools::Lit &lit) {
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

    Formula convertRelational(const Arith::Lit &rel) {
        const auto lhs {convertEx(rel->lhs())};
        const auto rhs {context.getInt(0)};
        if (rel->isGt()) {
            return context.gt(lhs, rhs);
        } else if (rel->isEq()) {
            return context.eq(lhs, rhs);
        } else if (rel->isNeq()) {
            return context.neq(lhs, rhs);
        }
        throw std::invalid_argument("unknown relation");
    }

    Formula convertLit(const Bools::Lit &lit) {
        auto var {context.getVariable(lit->getBoolVar())};
        return lit->isNegated() ? context.negate(var) : var;
    }

private:
    ExprConversionContext<Expr, Formula> &context;
};
