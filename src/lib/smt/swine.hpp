#pragma once

#include "smt.hpp"
#include "swinecontext.hpp"

class Swine final : public Smt {

public:
    explicit Swine(const swine::Config& config = swine::Config());
    void add(Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult check() override;
    ModelPtr model(const std::optional<const VarSet> &vars) override;
    void enableModels() override;
    void resetSolver() override;
    ~Swine() override = default;
    std::ostream& print(std::ostream& os) const override;
    void randomize(unsigned seed) override;

private:

    z3::context z3ctx{};
    swine::Swine solver;
    SwineContext ctx;

    static Rational getRealFromModel(const z3::model &model, const z3::expr &symbol);

};
