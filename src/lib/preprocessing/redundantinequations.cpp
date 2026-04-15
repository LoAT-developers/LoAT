#include "redundantinequations.hpp"
#include "smtfactory.hpp"

Bools::Expr removeRedundantInequations(const Bools::Expr& e) {
    if (!e->isConjunction()) {
        return e;
    }
    // collect linear bounds of the form b >= 0
    auto lits {e->lits()};
    auto &arith_lits {lits.get<Arith::Lit>()};
    linked_hash_map<Arith::Expr, linked_hash_set<ArithVarPtr>> bounded;
    for (auto it = arith_lits.begin(); it != arith_lits.end();) {
        const auto lit {*it};
        if (const auto lhs {lit->lhs()}; lhs->isLinear()) {
            if (lit->isGt()) {
                bounded.emplace(lhs - arith::one(), lhs->cells());
                it = arith_lits.erase(it);
            } else if (lit->isEq()) {
                const auto cells = lhs->cells();
                bounded.emplace(lhs, cells);
                bounded.emplace(-lhs, cells);
                it = arith_lits.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
    // set up one non-negative multiplier for each bound
    auto solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    std::unordered_map<Arith::Expr, ArithVarPtr> factors;
    for (const auto& b: bounded | std::views::keys) {
        const auto f {arrays::nextConst<Arith>()};
        factors.emplace(b, f);
        solver->add(arith::mkGeq(f, arith::zero()));
    }
    const auto arith_vars {e->cells().get<ArithVarPtr>()};
    for (auto it = bounded.begin(); it != bounded.end();) {
        solver->push();
        // set up one equation for each variable
        for (const auto &x: arith_vars) {
            ArithExprVec addends;
            for (const auto& [b, cells]: bounded) {
                if (it->first != b && cells.contains(x)) {
                    addends.push_back(*b->coeff(x) * factors.at(b));
                }
            }
            solver->add(arith::mkEq(*it->first->coeff(x), arith::mkPlus(std::move(addends))));
        }
        // and one equation for the constant part
        ArithExprVec addends;
        for (const auto& b: bounded | std::views::keys) {
            if (it->first != b) {
                addends.push_back(arith::mkConst(b->getConstantAddend()) * factors.at(b));
            }
        }
        solver->add(arith::mkGeq(arith::mkConst(it->first->getConstantAddend()), arith::mkPlus(std::move(addends))));
        if (solver->check() == SmtResult::Sat) {
            it = bounded.erase(it);
        } else {
            arith_lits.insert(arith::mkGeq(it->first, arith::zero()));
            ++it;
        }
        solver->pop();
    }
    return bools::mkAnd(lits);
}
