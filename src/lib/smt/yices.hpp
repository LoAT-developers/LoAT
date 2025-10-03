#pragma once

#include <yices.h>
#include <future>

#include "smt.hpp"
#include "yicescontext.hpp"

namespace yices {

extern void init();

extern void exit();

}

class Yices final : public Smt {

public:

    Yices(const Yices &that) = delete;
    Yices(Yices &&that) = delete;
    Yices& operator=(const Yices &that) = delete;
    Yices& operator=(Yices &&that) = delete;

    explicit Yices(Logic logic);
    void add(Bools::Expr e) override;
    void push() override;
    void pop() override;
    static SmtResult processResult(smt_status status);
    SmtResult check() override;
    ModelPtr model() override;
    void randomize(unsigned seed) override;
    void enableModels() override;
    void resetSolver() override;
    ~Yices() override;
    std::ostream& print(std::ostream& os) const override;

private:
    YicesContext ctx;
    ctx_config_t *config;
    context_t *solver{};

    static Rational getRealFromModel(model_t *model, type_t symbol);

};
