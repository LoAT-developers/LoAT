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

    Yices(Logic logic);
    void add(const Bools::Expr e) override;
    void push() override;
    void pop() override;
    SmtResult processResult(smt_status status);
    SmtResult check() override;
    Model model(const std::optional<const VarSet> &vars = std::nullopt) override;
    void randomize(unsigned seed) override;
    void enableModels() override;
    void resetSolver() override;
    ~Yices() override;
    std::ostream& print(std::ostream& os) const override;

    std::optional<Bools::Expr> interpolate(const Bools::Expr e);

private:
    YicesContext ctx;
    ctx_config_t *config;
    context_t *solver{};

    Rational getRealFromModel(model_t *model, type_t symbol);

};
