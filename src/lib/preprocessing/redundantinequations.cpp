#include "redundantinequations.hpp"
#include "smtfactory.hpp"

Bools::Expr removeRedundantInequations(const Bools::Expr& e) {
    if (!e->isConjunction()) {
        return e;
    }
    const auto children = e->getChildren();
    std::vector<Bools::Expr> child_vec {children.begin(), children.end()};
    // the sorting determines the order in which we try to remove literals
    std::ranges::sort(child_vec, [](const auto x, const auto y) {
        const auto xvars = x->vars();
        const auto yvars = y->vars();
        const auto x_just_prog = std::ranges::all_of(xvars, theory::isProgVar);
        const auto y_just_prog = std::ranges::all_of(yvars, theory::isProgVar);
        // if y is a guard literal (that just contains pre-variables) and x is not, try to remove x first
        if (x_just_prog != y_just_prog) {
            return !x_just_prog && y_just_prog;
        }
        const auto x_just_post = std::ranges::all_of(xvars, theory::isPostVar);
        const auto y_just_post = std::ranges::all_of(yvars, theory::isPostVar);
        // if y is a "co-guard" literal (that just contains post-variables) and x is not, try to remove x first
        if (x_just_post != y_just_post) {
            return !x_just_post && y_just_post;
        }
        // if x has more variables than y, try to remove x first
        return x->vars().size() > y->vars().size();
    });
    auto solver{SmtFactory::solver(Logic::QF_LA)};
    for (auto it = child_vec.begin(); it != child_vec.end();) {
        if (const auto lit = (*it)->getTheoryLit(); lit && std::holds_alternative<Arith::Lit>(*lit)) {
            solver->push();
            solver->add(theory::negate(*lit));
            if (solver->check() != SmtResult::Unsat) {
                solver->pop();
                solver->add(*lit);
            } else {
                solver->pop();
                it = child_vec.erase(it);
                continue;
            }
        }
        ++it;
    }
    return bools::mkAnd(child_vec);
}
