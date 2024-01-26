#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "swine.hpp"

namespace SmtFactory {

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> solver(Logic logic) {
        std::unique_ptr<Smt<Th...>> res;
        switch (logic) {
        case QF_LA:
            res = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(logic));
            break;
        case QF_NA:
            res = std::unique_ptr<Smt<Th...>>(new Z3<Th...>());
            break;
        case QF_NAT:
            res = std::unique_ptr<Smt<Th...>>(new Swine<Th...>());
            break;
        }
        return res;
    }

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> modelBuildingSolver(Logic logic) {
        std::unique_ptr<Smt<Th...>> res = solver<Th...>(logic);
        res->enableModels();
        return res;
    }

    template<ITheory... Th>
    static SmtResult check(const BExpr<Th...> e) {
        std::unique_ptr<Smt<Th...>> s = SmtFactory::solver<Th...>(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{e}));
        s->add(e);
        return s->check();
    }

}
