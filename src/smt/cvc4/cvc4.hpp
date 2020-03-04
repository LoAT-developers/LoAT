#ifdef HAS_CVC4

#ifndef CVC4_HPP
#define CVC4_HPP

#include "../smt.hpp"
#include "cvc4context.hpp"
#include <cvc4/cvc4.h>

class Cvc4: public Smt
{
public:
    Cvc4(const VariableManager &varMan);

    void add(const BoolExpr &e) override;
    void push() override;
    void pop() override;
    Result check() override;
    ExprSymbolMap<GiNaC::numeric> model() override;
    void setTimeout(unsigned int timeout) override;
    void enableModels() override;
    void resetSolver() override;
    ~Cvc4() override;

private:
    uint timeout;
    const VariableManager &varMan;
    CVC4::ExprManager manager;
    Cvc4Context ctx;
    CVC4::SmtEngine solver;
    bool models = false;

    GiNaC::numeric getRealFromModel(const CVC4::Expr &symbol);
};

#endif // CVC4_HPP

#endif