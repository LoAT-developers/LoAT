#include "redundantinequations.hpp"
#include "smtfactory.hpp"

Bools::Expr removeRedundantInequations(const Bools::Expr& e) {
    if (!e->isConjunction()) {
        return e;
    }
    auto children = e->getChildren();
    auto solver{SmtFactory::solver(Logic::QF_LA)};
    for (auto it = children.begin(); it != children.end();) {
        if (const auto lit = (*it)->getTheoryLit(); lit && std::holds_alternative<Arith::Lit>(*lit)) {
            solver->push();
            solver->add(theory::negate(*lit));
            if (solver->check() != SmtResult::Unsat) {
                solver->pop();
                solver->add(*lit);
            } else {
                solver->pop();
                it = children.erase(it);
                continue;
            }
        }
        ++it;
    }
    return bools::mkAnd(children);
}
