#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "itheory.hpp"
#include "theory.hpp"

namespace smt {

extern const unsigned default_timeout;

}

namespace SmtFactory {

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> solver(Logic logic, unsigned timeout = smt::default_timeout) {
        std::unique_ptr<Smt<Th...>> res;
        switch (logic) {
        case QF_LA:
            res = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(logic, timeout));
            break;
        case QF_NA:
        case QF_NAT:
            res = std::unique_ptr<Smt<Th...>>(new Z3<Th...>(timeout));
            break;
        }
        return res;
    }

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> modelBuildingSolver(Logic logic, unsigned timeout = smt::default_timeout) {
        std::unique_ptr<Smt<Th...>> res = solver<Th...>(logic, timeout);
        res->enableModels();
        return res;
    }

    template<ITheory... Th>
    static SmtResult check(const BExpr<Th...> e, unsigned int timeout = smt::default_timeout) {
        std::unique_ptr<Smt<Th...>> s = SmtFactory::solver<Th...>(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{e}), timeout);
        s->add(e);
        return s->check();
    }

    template<ITheory... Th>
    BoolExpressionSet<Th...> unsatCore(const BoolExpressionSet<Th...> &assumptions, unsigned timeout = smt::default_timeout) {
        const auto logic = Smt<Th...>::chooseLogic(assumptions);
        if (logic == QF_LA) {
            return Yices<Th...>(QF_LA, timeout)._unsatCore(assumptions).second;
        } else {
            // as far as I can tell, yices' mcsat for NA does not support unsat cores
            return Z3<Th...>(timeout)._unsatCore(assumptions).second;
        }
    }

}
