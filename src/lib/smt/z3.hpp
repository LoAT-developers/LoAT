#pragma once

#include "smt.hpp"
#include "z3context.hpp"
#include "theory.hpp"

class Z3 : public Smt {

public:

    void add(const BoolExpr e) override;
    void push() override;
    void pop() override;
    SmtResult check() override;
    Model model(const std::optional<const VarSet> &vars = {}) override;
    void enableModels() override;
    void resetSolver() override;
    ~Z3() override;
    std::ostream& print(std::ostream& os) const override;
    void randomize(unsigned seed) override;
    Z3();

private:
    z3::context z3Ctx{};
    Z3Context ctx;
    z3::solver solver;

    Rational getRealFromModel(const z3::model &model, const z3::expr &symbol);

};
