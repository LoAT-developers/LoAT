#pragma once

#include "crab.hpp"
#include "exprconversioncontext.hpp"

struct CrabConjunction {
    std::vector<z_lin_cst_t> constraints{};
    std::vector<z_var> positive_lits{};
    std::vector<z_var> negative_lits{};

    bool isTrue() const;
    size_t size() const;
};

class CrabContext: public ExprConversionContext<z_lin_exp_t, CrabConjunction> {

public:

    CrabContext();
    ~CrabContext() override;
    z_lin_exp_t getInt(const Int &val) override;
    z_lin_exp_t getReal(const Int &num, const Int &denom) override;
    z_lin_exp_t pow(const z_lin_exp_t &base, const z_lin_exp_t &exp) override;
    z_lin_exp_t plus(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    z_lin_exp_t times(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction eq(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction lt(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction le(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction gt(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction ge(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction neq(const z_lin_exp_t &x, const z_lin_exp_t &y) override;
    CrabConjunction bAnd(const CrabConjunction &x, const CrabConjunction &y) override;
    CrabConjunction bOr(const CrabConjunction &x, const CrabConjunction &y) override;
    CrabConjunction bTrue() const override;
    CrabConjunction bFalse() const override;
    CrabConjunction negate(const CrabConjunction &x) override;

    void printStderr(const z_lin_exp_t &e) const override;
    variable_factory_t& getVfac();

private:

    z_lin_exp_t buildVar(const Arith::Var &var) override;
    CrabConjunction buildVar(const Bools::Var &var) override;
    variable_factory_t vfac;

};