#pragma once

#include "exprconversioncontext.hpp"

#include <gmp.h>
#include <yices.h>

class YicesError final : public std::exception {
public:
    YicesError();
};

class YicesContext final : public ExprConversionContext<term_t, term_t, std::vector<term_t>, std::vector<term_t>> {

public:
    ~YicesContext() override;
    term_t getInt(const Int &val) override;
    term_t getReal(const Int &num, const Int &denom) override;
    term_t pow(const term_t &base, const term_t &exp) override;
    term_t plus(const std::vector<term_t> &args) override;
    term_t times(const std::vector<term_t> &args) override;
    term_t mod(const term_t &x, const term_t &y) override;
    term_t eq(const term_t &x, const term_t &y) override;
    term_t lt(const term_t &x, const term_t &y) override;
    term_t le(const term_t &x, const term_t &y) override;
    term_t gt(const term_t &x, const term_t &y) override;
    term_t ge(const term_t &x, const term_t &y) override;
    term_t neq(const term_t &x, const term_t &y) override;
    term_t bAnd(std::vector<term_t> &args) override;
    term_t bOr(std::vector<term_t> &args) override;
    term_t bTrue() const override;
    term_t bFalse() const override;
    term_t negate(const term_t &x) override;
    std::vector<term_t> exprVec() override;
    std::vector<term_t> formulaVec() override;
    term_t arrayRead(const term_t& arr, const std::vector<term_t>& indices) override;
    term_t arrayWrite(const term_t& arr, const std::vector<term_t>& indices, const term_t &value) override;

    void printStderr(const term_t &e) const override;

protected:
    term_t buildVar(const Arith::Var &var) override;
    term_t buildVar(const Bools::Var &var) override;
    term_t buildVar(const Arrays<Arith>::Var &var) override;

private:
    static Int numerator(const term_t &e);
    static Int denominator(const term_t &e);

};
