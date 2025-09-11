#pragma once

#include "exprconversioncontext.hpp"

#include <z3++.h>
#include <swine/swine.h>

class SwineContext final : public ExprConversionContext<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector> {

public:

    explicit SwineContext(swine::Swine &solver);
    ~SwineContext() override = default;

    z3::expr getInt(const Int &val) override;
    z3::expr getReal(const Int &num, const Int &denom) override;
    z3::expr pow(const z3::expr &base, const z3::expr &exp) override;
    z3::expr plus(const z3::expr_vector &args) override;
    z3::expr times(const z3::expr_vector &args) override;
    z3::expr mod(const z3::expr &x, const z3::expr &y) override;
    z3::expr eq(const z3::expr &x, const z3::expr &y) override;
    z3::expr lt(const z3::expr &x, const z3::expr &y) override;
    z3::expr le(const z3::expr &x, const z3::expr &y) override;
    z3::expr gt(const z3::expr &x, const z3::expr &y) override;
    z3::expr ge(const z3::expr &x, const z3::expr &y) override;
    z3::expr neq(const z3::expr &x, const z3::expr &y) override;
    z3::expr bAnd(z3::expr_vector &args) override;
    z3::expr bOr(z3::expr_vector &args) override;
    z3::expr bTrue() const override;
    z3::expr bFalse() const override;
    z3::expr negate(const z3::expr &x) override;
    z3::expr_vector exprVec() override;
    z3::expr_vector formulaVec() override;
    z3::expr arrayRead(const z3::expr& arr, const z3::expr_vector& indices) override;
    z3::expr arrayWrite(const z3::expr& arr, const z3::expr_vector& indices, const z3::expr &value) override;

    void printStderr(const z3::expr &e) const override;

private:

    z3::expr buildVar(const Arith::Var &var) override;
    z3::expr buildVar(const Bools::Var &var) override;
    z3::expr buildVar(const Arrays<Arith>::Var &var) override;

    z3::context &ctx;
    swine::Swine &solver;

};
