#pragma once

#include "smt.hpp"
#include "swinecontext.hpp"
#include "theory.hpp"
#include "z3.hpp"

class Swine: public Smt {

public:

    Swine(swine::Config config = swine::Config());
    void add(const Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult check() override;
    Model model(const std::optional<const VarSet> &vars = std::nullopt) override;
    void enableModels() override;
    void resetSolver() override;
    ~Swine() override;
    std::ostream& print(std::ostream& os) const override;
    void randomize(unsigned seed) override;

private:

    z3::context z3ctx{};
    swine::Swine solver;
    swine::Swine printer;
    SwineContext ctx;
    int exp {-1};
    unsigned level {0};
    static unsigned counter;

    Rational getRealFromModel(const z3::model &model, const z3::expr &symbol);

};
