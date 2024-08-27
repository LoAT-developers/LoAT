#include "redundantinequations.hpp"
#include "smtfactory.hpp"

Bools::Expr removeRedundantInequations(const Bools::Expr e) {
    if (!e->isConjunction()) {
        return e;
    }
    auto solver {SmtFactory::solver(Logic::QF_LA)};
    LitSet res;
    for (const auto &lit: e->lits()) {
        solver->push();
        solver->add(!bools::mkLit(lit));
        if (solver->check() != SmtResult::Unsat) {
            res.insert(lit);
            solver->pop();
            solver->add(bools::mkLit(lit));
        } else  {
            solver->pop();
        }
    }
    return bools::mkAndFromLits(res);
}
