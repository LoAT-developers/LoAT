#pragma once

#include "exprconversioncontext.hpp"

#include <gmp.h>
#include <opensmt/api/Opensmt.h>

template<>
struct std::hash<opensmt::PTRef> {
    std::size_t operator()(const opensmt::PTRef& s) const noexcept {
        return std::hash<uint32_t>{}(s.x);
    }
};

class OpenSmtContext : public ExprConversionContext<opensmt::PTRef, opensmt::PTRef, std::vector<opensmt::PTRef>, std::vector<opensmt::PTRef>> {

public:

    OpenSmtContext(opensmt::ArithLogic&);

    ~OpenSmtContext() override;
    opensmt::PTRef getInt(const Int &val) override;
    opensmt::PTRef getReal(const Int &num, const Int &denom) override;
    opensmt::PTRef pow(const opensmt::PTRef &base, const opensmt::PTRef &exp) override;
    opensmt::PTRef plus(const std::vector<opensmt::PTRef> &args) override;
    opensmt::PTRef times(const std::vector<opensmt::PTRef> &args) override;
    opensmt::PTRef mod(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef eq(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef lt(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef le(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef gt(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef ge(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef neq(const opensmt::PTRef &x, const opensmt::PTRef &y) override;
    opensmt::PTRef bAnd(std::vector<opensmt::PTRef> &args) override;
    opensmt::PTRef bOr(std::vector<opensmt::PTRef> &args) override;
    opensmt::PTRef bTrue() const override;
    opensmt::PTRef bFalse() const override;
    opensmt::PTRef negate(const opensmt::PTRef &x) override;
    std::vector<opensmt::PTRef> exprVec() override;
    std::vector<opensmt::PTRef> formulaVec() override;

    void printStderr(const opensmt::PTRef &e) const override;

    Arith::Var getArithVar(const opensmt::PTRef) const;
    Bools::Var getBoolVar(const opensmt::PTRef) const;

protected:
    opensmt::PTRef buildVar(const Arith::Var &var) override;
    opensmt::PTRef buildVar(const Bools::Var &var) override;

private:

    std::unordered_map<opensmt::PTRef, Arith::Var> reverseArithVarMap;
    std::unordered_map<opensmt::PTRef, Bools::Var> reverseBoolVarMap;
    opensmt::ArithLogic &logic;

};
