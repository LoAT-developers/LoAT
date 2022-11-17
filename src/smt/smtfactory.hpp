#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "config.hpp"
#include "itheory.hpp"
#include "theory.hpp"

namespace SmtFactory {

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> solver(Logic logic, const VariableManager &varMan, unsigned int timeout = Config::Smt::DefaultTimeout) {
        std::unique_ptr<Smt<Th...>> res;
        switch (logic) {
        case QF_LA:
            res = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(varMan, logic));
            break;
        case QF_NA:
        case QF_NAT:
            res = std::unique_ptr<Smt<Th...>>(new Z3<Th...>(varMan));
            break;
        }
        res->setTimeout(timeout);
        return res;
    }

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> modelBuildingSolver(Logic logic, const VariableManager &varMan, unsigned int timeout = Config::Smt::DefaultTimeout) {
        std::unique_ptr<Smt<Th...>> res = solver<Th...>(logic, varMan, timeout);
        res->enableModels();
        return res;
    }

    template<ITheory... Th>
    static SmtResult check(const BExpr<Th...> e, const VariableManager &varMan) {
        std::unique_ptr<Smt<Th...>> s = SmtFactory::solver<Th...>(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{e}), varMan);
        s->add(e);
        return s->check();
    }

    template<ITheory... Th>
    bool isImplication(const BExpr<Th...> lhs, const BExpr<Th...> rhs, const VariableManager &varMan) {
        std::unique_ptr<Smt<Th...>> s = SmtFactory::solver<Th...>(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{lhs, rhs}), varMan);
        s->add(lhs);
        s->add(!rhs);
        return s->check() == Unsat;
    }

    template<ITheory... Th>
    BoolExpressionSet<Th...> unsatCore(const BoolExpressionSet<Th...> &assumptions, VariableManager &varMan) {
        const auto logic = Smt<Th...>::chooseLogic(assumptions);
        if (logic == QF_LA) {
            return Yices<Th...>(varMan, QF_LA)._unsatCore(assumptions).second;
        } else {
            // as far as I can tell, yices' mcsat for NA does not support unsat cores
            return Z3<Th...>(varMan)._unsatCore(assumptions).second;
        }
    }

}
