#pragma once

#include <poly/algebraic_number.h>
#include <yices.h>
#include <future>
#include <stdexcept>

#include "smt.hpp"
#include "yicescontext.hpp"
#include "theory.hpp"

namespace yices {

extern void init();

extern void exit();

}

class Yices : public Smt {

public:

    Yices(const Yices &that) = delete;
    Yices(Yices &&that) = delete;
    Yices& operator=(const Yices &that) = delete;
    Yices& operator=(Yices &&that) = delete;

    Yices(Logic logic, const bool interpolation);
    void add(const Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult processResult(smt_status status);
    SmtResult check() override;
    SmtResult checkWithAssumptions(const BoolExprSet&);
    Model model(const std::optional<const VarSet> &vars = std::nullopt) override;
    void randomize(unsigned seed) override;
    void resetSolver() override;
    ~Yices() override;
    std::ostream& print(std::ostream& os) const override;
    void enableModels() override;

    std::optional<Bools::Expr> interpolate(const BoolExprSet&) override;
    BoolExprSet unsatCore();

private:
    YicesContext ctx;
    ctx_config_t *config;
    context_t *solver{};

    Rational getRealFromModel(model_t *model, type_t symbol);

};
