#include "redundantinequations.hpp"
#include "smtfactory.hpp"

void removeRedundantInequations(Conjunction &lits) {
    // collect linear bounds of the form b >= 0
    auto &arith_lits {lits.get<Arith::Lit>()};
    const auto arith_vars {lits.vars().get<Arith::Var>()};
    ArithExprVec bounded;
    for (auto it = arith_lits.begin(); it != arith_lits.end();) {
        const auto lit {*it};
        const auto lhs {lit->lhs()};
        if (lhs->isLinear()) {
            if (lit->isGt()) {
                bounded.push_back(lhs - arith::mkConst(1));
                it = arith_lits.erase(it);
            } else if (lit->isEq()) {
                bounded.push_back(lhs);
                bounded.push_back(-lhs);
                it = arith_lits.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
    // set up one non-negative multiplier for each bound
    auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    std::vector<Arith::Var> factors;
    for (size_t i = 0; i < bounded.size(); ++i) {
        const auto f {Arith::next()};
        factors.push_back(f);
        solver->add(arith::mkGeq(f, arith::mkConst(0)));
    }
    for (auto it = bounded.begin(); it != bounded.end();) {
        solver->push();
        // set up one equation for each variable
        for (const auto &x: arith_vars) {
            ArithExprVec addends;
            for (unsigned idx = 0; idx < bounded.size(); ++idx) {
                if (*it != bounded[idx] && bounded[idx]->has(x)) {
                    addends.push_back(*bounded[idx]->coeff(x) * factors[idx]);
                }
            }
            const auto coeff {*(*it)->coeff(x)};
            const auto sum {arith::mkPlus(std::move(addends))};
            const auto eq {arith::mkEq(coeff, sum)};
            solver->add(eq);
        }
        // and one equation for the constant part
        ArithExprVec addends;
        for (unsigned idx = 0; idx < bounded.size(); ++idx) {
            if (*it != bounded[idx]) {
                addends.push_back(arith::mkConst(bounded[idx]->getConstantAddend()) * factors[idx]);
            }
        }
        solver->add(arith::mkGeq(arith::mkConst((*it)->getConstantAddend()), arith::mkPlus(std::move(addends))));
        if (solver->check() == SmtResult::Sat) {
            it = bounded.erase(it);
        } else {
            arith_lits.insert(arith::mkGeq(*it, arith::mkConst(0)));
            ++it;
        }
        solver->pop();
    }
}
