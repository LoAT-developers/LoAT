#pragma once

#include "exprconversioncontext.hpp"

#include <z3++.h>


/**
 * Wrapper around z3 context to allow convenient variable handling.
 *
 * Note that z3 identifies symbols with the same name, whereas GiNaC considers two symbols with the same name
 * as different. This context does thus map GiNaC symbols to z3 symbols (instead of mapping names to z3 symbols).
 *
 * For convenience, it is also possible to create z3 symbols not associated to any GiNaC symbol,
 * but these symbols cannot be looked up later (as they are not associated to any GiNaC symbol).
 */
class Z3Context : public ExprConversionContext<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector> {

public:
    Z3Context(z3::context& ctx);
    ~Z3Context() override;
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

    void printStderr(const z3::expr &e) const override;

private:

    z3::context &ctx;

    z3::expr buildVar(const Arith::Var &var) override;
    z3::expr buildVar(const Bools::Var &var) override;

};
