#pragma once

#include "smt.hpp"
#include "cvc5context.hpp"
#include "theory.hpp"

#include <cvc5/cvc5.h>

class CVC5 : public Smt {

public:

    CVC5();
    void add(const Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult check() override;
    Model model(const std::optional<const VarSet> &vars = std::nullopt) override;
    void enableModels() override;
    void resetSolver() override;
    ~CVC5() override;
    std::ostream& print(std::ostream& os) const override;
    void randomize(unsigned seed) override;
    std::optional<Bools::Expr> interpolate(const BoolExprSet& conclusion) override;

private:
    cvc5::Solver solver;
    CVC5Context ctx;
    unsigned seed = 42u;

    Rational getRealFromModel(const cvc5::Term &symbol);
    void updateParams();

};
