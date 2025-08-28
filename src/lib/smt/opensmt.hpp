#pragma once

#include <poly/algebraic_number.h>
#include <yices.h>
#include <future>
#include <stdexcept>

#include "smt.hpp"
#include "opensmtcontext.hpp"
#include "theory.hpp"

class OpenSmt : public Smt {

public:

    OpenSmt(const OpenSmt &that) = delete;
    OpenSmt(OpenSmt &&that) = delete;
    OpenSmt& operator=(const OpenSmt &that) = delete;
    OpenSmt& operator=(OpenSmt &&that) = delete;

    OpenSmt(const bool model);
    void add(const Bools::Expr e) override;
    void add_named(const Bools::Expr e);
    void push() override;
    void pop() override;
    SmtResult check() override;
    Model model(const std::optional<const VarSet> &vars = std::nullopt) override;
    void randomize(unsigned seed) override;
    void resetSolver() override;
    void enableModels() override;
    ~OpenSmt() override;
    std::ostream& print(std::ostream& os) const override;

    Bools::Expr interpolate(opensmt::ipartitions_t mask);
    std::vector<Bools::Expr> interpolate_path(const std::vector<opensmt::ipartitions_t>&);
    BoolExprSet unsatCore();

private:

    Arith::Expr convertArith(const opensmt::PTRef &t);
    Bools::Expr convertFormula(const opensmt::PTRef &t);

    opensmt::ArithLogic logic {opensmt::Logic_t::QF_LIA};
    std::unique_ptr<OpenSmtContext> ctx;
    opensmt::SMTConfig conf;
    std::unique_ptr<opensmt::MainSolver> solver;

    Rational getRealFromModel(opensmt::Model&, opensmt::PTRef);

};
