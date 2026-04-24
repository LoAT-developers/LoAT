#pragma once

#include "theory.hpp"

template<class Expr, class Formula, class ExprVec, class FormulaVec>
class ExprConversionContext {

public:

    virtual Expr getInt(const Int &val) = 0;
    virtual Expr getReal(const Int &num, const Int &denom) = 0;
    virtual Expr pow(const Expr &base, const Expr &exp) = 0;
    virtual Expr plus(const ExprVec &args) = 0;
    virtual Expr times(const ExprVec &args) = 0;
    virtual Expr mod(const Expr &x, const Expr &y) = 0;
    virtual Formula eq(const Expr &x, const Expr &y) = 0;
    virtual Formula lt(const Expr &x, const Expr &y) = 0;
    virtual Formula le(const Expr &x, const Expr &y) = 0;
    virtual Formula gt(const Expr &x, const Expr &y) = 0;
    virtual Formula ge(const Expr &x, const Expr &y) = 0;
    virtual Formula neq(const Expr &x, const Expr &y) = 0;
    virtual Formula bAnd(FormulaVec &args) = 0;
    virtual Formula bOr(FormulaVec &args) = 0;
    virtual Formula bTrue() const = 0;
    virtual Formula bFalse() const = 0;
    virtual Formula negate(const Formula &x) = 0;
    virtual ExprVec exprVec() = 0;
    virtual FormulaVec formulaVec() = 0;
    virtual Expr arrayRead(const Expr& arr, const ExprVec& indices) = 0;
    virtual Expr arrayWrite(const Expr& arr, const ExprVec& indices, const Expr &value) = 0;
    virtual Expr ite(const Expr& cond, const Expr& then_case, const Expr& else_case) = 0;
    virtual Expr lambda(const ExprVec& args, const Expr& body) = 0;

    virtual void printStderr(const Expr &e) const = 0;

    Formula getVariable(const Bools::Var &symbol) {
        const auto res {boolVarMap.get(symbol)};
        if (res) {
            return *res;
        }
        const auto it {boolVarMap.emplace(symbol, buildVar(symbol)).first};
        return it->second;
    }

    Expr getVariable(const Arrays<Arith>::Var &symbol) {
        const auto res {intArrayVarMap.get(symbol)};
        if (res) {
            return *res;
        }
        const auto it {intArrayVarMap.emplace(symbol, buildVar(symbol)).first};
        return it->second;
    }

    const linked_hash_map<Bools::Var, Formula> &getBoolSymbolMap() const {
        return boolVarMap;
    }

    const linked_hash_map<Arrays<Arith>::Var, Expr> &getIntArraySymbolMap() const {
        return intArrayVarMap;
    }

    virtual ~ExprConversionContext() = default;

    void reset() {
        boolVarMap.clear();
        intArrayVarMap.clear();
    }

protected:

    virtual Formula buildVar(const Bools::Var &var) = 0;
    virtual Expr buildVar(const Arrays<Arith>::Var &var) = 0;

    linked_hash_map<Bools::Var, Formula> boolVarMap{};
    linked_hash_map<Arrays<Arith>::Var, Expr> intArrayVarMap{};
    VarSet vars;
};
