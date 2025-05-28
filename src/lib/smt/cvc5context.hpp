#pragma once

#include "exprconversioncontext.hpp"

#include <cvc5/cvc5.h>


class CVC5Context : public ExprConversionContext<cvc5::Term, cvc5::Term, std::vector<cvc5::Term>, std::vector<cvc5::Term>> {

public:
    CVC5Context(cvc5::Solver& ctx);
    ~CVC5Context() override;
    cvc5::Term getInt(const Int &val) override;
    cvc5::Term getReal(const Int &num, const Int &denom) override;
    cvc5::Term pow(const cvc5::Term &base, const cvc5::Term &exp) override;
    cvc5::Term plus(const std::vector<cvc5::Term> &args) override;
    cvc5::Term times(const std::vector<cvc5::Term> &args) override;
    cvc5::Term mod(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term eq(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term lt(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term le(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term gt(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term ge(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term neq(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term bAnd(std::vector<cvc5::Term> &args) override;
    cvc5::Term bOr(std::vector<cvc5::Term> &args) override;
    cvc5::Term bTrue() const override;
    cvc5::Term bFalse() const override;
    cvc5::Term negate(const cvc5::Term &x) override;
    std::vector<cvc5::Term> exprVec() override;
    std::vector<cvc5::Term> formulaVec() override;

    void printStderr(const cvc5::Term &e) const override;

    cvc5::Term clearRefinement();

    Arith::Var getArithVar(const cvc5::Term&) const;
    Bools::Var getBoolVar(const cvc5::Term&) const;

private:

    cvc5::Solver &ctx;
    cvc5::Term buildVar(const Arith::Var &var) override;
    cvc5::Term buildVar(const Bools::Var &var) override;
    cvc5::Term refinement;
    std::unordered_map<cvc5::Term, Arith::Var> reverseArithVarMap;
    std::unordered_map<cvc5::Term, Bools::Var> reverseBoolVarMap;

};
