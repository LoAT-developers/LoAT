#pragma once

#include "exprconversioncontext.hpp"
#include "theory.hpp"

template<class Expr, class Formula, class ExprVec, class FormulaVec>
class ExprConverter {

public:

    static Formula convert(const Bools::Expr& e, ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &ctx) {
        ExprConverter converter(ctx);
        return converter.convertBoolEx(e);
    }

    static Expr convert(const Arith::Expr& e, ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &ctx) {
        ExprConverter converter(ctx);
        return converter.convertEx(e);
    }

    static Expr convert(const ArrayReadPtr<Arith>& e, ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &ctx) {
        ExprConverter converter(ctx);
        return converter.convertArrayRead(e);
    }

protected:

    explicit ExprConverter(ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &context): context(context) {}

    Formula convertBoolEx(const Bools::Expr& e) {
        if (e->getTheoryLit()) {
            return std::visit(
                Overload {
                    [&](const auto &lit) {
                        return convertLit(lit);
                    }
                }, *e->getTheoryLit());
        }
        auto vec {context.formulaVec()};
        for (const auto &c: e->getChildren()) {
            vec.push_back(convertBoolEx(c));
        }
        if (e->isAnd()) {
            return context.bAnd(vec);
        }
        assert(e->isOr());
        return context.bOr(vec);
    }

    Expr convertEx(const Arith::Expr& e){
        return e->apply<Expr>(
            [&](const ArithConstPtr &r) {
                if (const auto i{r->intValue()}) {
                    return context.getInt(*i);
                }
                return context.getReal(*r->numerator()->intValue(), *r->denominator()->intValue());
            },
            [&](const Arith::Var& x) {
                return context.getVariable(x);
            },
            [&](const ArithAddPtr& a) {
                auto vec {context.exprVec()};
                for (const auto &c: a->getArgs()) {
                    vec.push_back(convertEx(c));
                }
                return context.plus(vec);
            },
            [&](const ArithMultPtr& m) {
                auto vec {context.exprVec()};
                for (const auto &c: m->getArgs()) {
                    vec.push_back(convertEx(c));
                }
                return context.times(vec);
            },
            [&](const ArithModPtr& m) {
                return context.mod(convertEx(m->getLhs()), convertEx(m->getRhs()));
            },
            [&](const ArithExpPtr& e) {
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

    Formula convertLit(const Arith::Lit &rel) {
        const auto lhs {convertEx(rel->lhs())};
        const auto rhs {context.getInt(0)};
        if (rel->isGt()) {
            return context.gt(lhs, rhs);
        }
        if (rel->isEq()) {
            return context.eq(lhs, rhs);
        }
        if (rel->isNeq()) {
            return context.neq(lhs, rhs);
        }
        throw std::invalid_argument("unknown relation");
    }

    Formula convertLit(const Bools::Lit &lit) {
        auto var {context.getVariable(lit->getBoolVar())};
        return lit->isNegated() ? context.negate(var) : var;
    }

    Expr convertArrayRead(const ArrayReadPtr<Arith> &read) {
        const auto arr {read->arr()};
        const auto converted_arr {context.getIntArraySymbolMap().at(arr)};
        const auto indices {read->indices()};
        auto converted_indices {context.exprVec()};
        for (const auto &i: indices) {
            converted_indices.push_back(convertEx(i));
        }
        return context.arrayRead(converted_arr, converted_indices);
    }

    Expr convertArrayWrite(const ArrayWritePtr<Arith> &write) {
        const auto arr {write->arr()};
        const auto indices {write->indices()};
        const auto value {write->val()};
        const auto converted_arr {context.getIntArraySymbolMap().at(arr)};
        auto converted_indices {context.exprVec()};
        for (const auto &i: indices) {
            converted_indices.push_back(convertEx(i));
        }
        const auto converted_value {convertEx(value)};
        return context.arrayWrite(converted_arr, converted_indices, converted_value);
    }

    Expr convertArray(const ArrayPtr<Arith> &arr) {
        if (const auto var {arr->isVar()}) {
            return context.getIntArraySymbolMap().at(*var);
        }
        if (const auto write {arr->isArrayWrite()}) {
            return convertArrayWrite(*write);
        }
        throw std::invalid_argument("unknown kind of array expression");
    }

    Formula convertLit(const Arrays<Arith>::Lit &lit) {
        if (const auto eq {lit->isArrayElemEq()}) {
            const auto lhs {(*eq)->lhs()};
            const auto converted_lhs {convertArrayRead(lhs)};
            const auto rhs {(*eq)->rhs()};
            const auto converted_rhs {convertEx(rhs)};
            return context.eq(converted_lhs, converted_rhs);
        }
        if (const auto neq {lit->isArrayElemNeq()}) {
            const auto lhs {(*neq)->lhs()};
            const auto converted_lhs {convertArrayRead(lhs)};
            const auto rhs {(*neq)->rhs()};
            const auto converted_rhs {convertEx(rhs)};
            return context.neq(converted_lhs, converted_rhs);
        }
        if (const auto eq {lit->isArrayEq()}) {
            const auto lhs {(*eq)->lhs()};
            const auto converted_lhs {convertArray(lhs)};
            const auto rhs {(*eq)->rhs()};
            const auto converted_rhs {convertArray(rhs)};
            return context.eq(converted_lhs, converted_rhs);
        }
        if (const auto neq {lit->isArrayNeq()}) {
            const auto lhs {(*neq)->lhs()};
            const auto converted_lhs {convertArray(lhs)};
            const auto rhs {(*neq)->rhs()};
            const auto converted_rhs {convertArray(rhs)};
            return context.neq(converted_lhs, converted_rhs);
        }
        throw std::invalid_argument("unknown kind of array literal");
    }

private:
    ExprConversionContext<Expr, Formula, ExprVec, FormulaVec> &context;
};
