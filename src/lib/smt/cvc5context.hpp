#pragma once

#include "smtcontext.hpp"

#include <cvc5/cvc5.h>
#include <map>


class CVC5Context : public SmtContext<cvc5::Term> {

public:
    CVC5Context(cvc5::Solver& ctx);
    ~CVC5Context() override;
    cvc5::Term getInt(long val) override;
    cvc5::Term getReal(long num, long denom) override;
    cvc5::Term pow(const cvc5::Term &base, const cvc5::Term &exp) override;
    cvc5::Term plus(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term times(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term eq(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term lt(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term le(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term gt(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term ge(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term neq(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term bAnd(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term bOr(const cvc5::Term &x, const cvc5::Term &y) override;
    cvc5::Term bTrue() const override;
    cvc5::Term bFalse() const override;
    cvc5::Term negate(const cvc5::Term &x) override;

    bool isTrue(const cvc5::Term &e) const override;
    bool isFalse(const cvc5::Term &e) const override;
    bool isNot(const cvc5::Term &e) const override;
    std::vector<cvc5::Term> getChildren(const cvc5::Term &e) const override;
    bool isAnd(const cvc5::Term &e) const override;
    bool isAdd(const cvc5::Term &e) const override;
    bool isMul(const cvc5::Term &e) const override;
    bool isPow(const cvc5::Term &e) const override;
    bool isVar(const cvc5::Term &e) const override;
    bool isRationalConstant(const cvc5::Term &e) const override;
    bool isInt(const cvc5::Term &e) const override;
    long toInt(const cvc5::Term &e) const override;
    cvc5::Term lhs(const cvc5::Term &e) const override;
    cvc5::Term rhs(const cvc5::Term &e) const override;
    Rel::RelOp relOp(const cvc5::Term &e) const override;

    void printStderr(const cvc5::Term &e) const override;

    cvc5::Term clearRefinement();

private:

    cvc5::Solver &ctx;
    cvc5::Term buildVar(const Var &var) override;
    cvc5::Term refinement;

};
