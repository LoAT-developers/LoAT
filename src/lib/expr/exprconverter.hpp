#pragma once

#include "exprconversioncontext.hpp"
#include "theory.hpp"

#include <sstream>
#include <numeric>

template<class Expr, class Formula, class ExprVec, class FormulaVec>
class ExprConverter {
public:

    static Formula convert(const Bools::Expr e, ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &ctx) {
        ExprConverter<Expr, Formula, ExprVec, FormulaVec> converter(ctx);
        return converter.convertBoolEx(e);
    }

    static Expr convert(const Arith::Expr e, ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &ctx) {
        ExprConverter<Expr, Formula, ExprVec, FormulaVec> converter(ctx);
        return converter.convertEx(e);
    }


protected:
    ExprConverter(ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &context): context(context) {}

    Formula convertBoolEx(const Bools::Expr e) {
        if (e->getTheoryLit()) {
            return theory::apply(
                *e->getTheoryLit(),
                [&](const Arith::Lit &lit) {
                    return convertRelational(lit);
                },
                [&](const Bools::Lit &lit) {
                    return convertLit(lit);
                });
        }
        auto vec {context.formulaVec()};
        for (const auto &c: e->getChildren()) {
            vec.push_back(convertBoolEx(c));
        }
        if (e->isAnd()) {
            return context.bAnd(vec);
        } else {
            assert(e->isOr());
            return context.bOr(vec);
        }
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
                auto vec {context.exprVec()};
                for (const auto &c: a->getArgs()) {
                    vec.push_back(convertEx(c));
                }
                return context.plus(vec);
            },
            [&](const ArithMultPtr m) {
                auto vec {context.exprVec()};
                for (const auto &c: m->getArgs()) {
                    vec.push_back(convertEx(c));
                }
                return context.times(vec);
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
                        auto vec {context.exprVec()};
                        for (unsigned i = 0; i < *int_exp; ++i) {
                            vec.push_back(factor);
                        }
                        return context.times(vec);
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
    ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &context;
};
