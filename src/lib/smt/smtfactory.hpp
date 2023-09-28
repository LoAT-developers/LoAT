#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"

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

}
