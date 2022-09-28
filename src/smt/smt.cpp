#include "smt.hpp"
#include "smtfactory.hpp"

Smt::~Smt() {}

void Smt::add(const Rel &e) {
    return this->add(buildTheoryLit(e));
}

Smt::Result Smt::check(const BoolExpr e, const VariableManager &varMan) {
    std::unique_ptr<Smt> s = SmtFactory::solver(Smt::chooseLogic(BoolExprSet{e}), varMan);
    s->add(e);
    return s->check();
}

bool Smt::isImplication(const BoolExpr lhs, const BoolExpr rhs, const VariableManager &varMan) {
    std::unique_ptr<Smt> s = SmtFactory::solver(Smt::chooseLogic(BoolExprSet{lhs, rhs}), varMan);
    s->add(lhs);
    s->add(!rhs);
    return s->check() == Smt::Unsat;
}

BoolExprSet Smt::unsatCore(const BoolExprSet &assumptions, VariableManager &varMan) {
    std::unique_ptr<Smt> solver = SmtFactory::solver(Smt::chooseLogic(assumptions), varMan);
    return solver->_unsatCore(assumptions).second;
}

Smt::Logic Smt::chooseLogic(const std::vector<BoolExpr> &xs, const std::vector<Subs> &up) {
    Smt::Logic res = Smt::QF_LA;
    for (const BoolExpr &x: xs) {
        if (!(x->isLinear())) {
            if (!(x->isPolynomial())) {
                return Smt::QF_ENA;
            }
            res = Smt::QF_NA;
        }
    }
    for (const Subs &u: up) {
        if (!u.getExprSubs().isLinear()) {
            if (!u.getExprSubs().isPoly()) {
                return Smt::QF_ENA;
            }
            res = Smt::QF_NA;
        }
    }
    return res;
}

Smt::Logic Smt::chooseLogic(const BoolExprSet &xs) {
    Smt::Logic res = Smt::QF_LA;
    for (const BoolExpr &x: xs) {
        if (!(x->isLinear())) {
            if (!(x->isPolynomial())) {
                return Smt::QF_ENA;
            }
            res = Smt::QF_NA;
        }
    }
    return res;
}

void Smt::popAll() {
    while (pushCount > 0) {
        pop();
    }
}

void Smt::pop() {
    pushCount--;
}

void Smt::push() {
    pushCount++;
}
