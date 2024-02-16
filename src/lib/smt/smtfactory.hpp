#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "swine.hpp"
#include "cvc5.hpp"
#include "config.hpp"

namespace SmtFactory {

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> _solver(Logic logic) {
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

    SmtPtr solver(Logic logic);

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> _solver() {
        std::unique_ptr<Smt<Th...>> solver;
        switch (Config::Analysis::smtSolver) {
        case Config::Analysis::Z3:
            solver = std::unique_ptr<Smt<Th...>>(new Z3<Th...>());
            break;
        case Config::Analysis::CVC5:
            solver = std::unique_ptr<Smt<Th...>>(new CVC5<Th...>());
            break;
        case Config::Analysis::Yices:
            solver = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(Logic::QF_NA));
            break;
        case Config::Analysis::Swine:
            solver = std::unique_ptr<Smt<Th...>>(new Swine<Th...>());
            break;
        }
        return solver;
    }

    SmtPtr solver();

    template<ITheory... Th>
    std::unique_ptr<Smt<Th...>> _modelBuildingSolver(Logic logic) {
        auto res {_solver<Th...>(logic)};
        res->enableModels();
        return res;
    }

    SmtPtr modelBuildingSolver(Logic logic);

    template<ITheory... Th>
    static SmtResult _check(const BExpr<Th...> e) {
        auto s {_solver<Th...>(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{e}))};
        s->add(e);
        return s->check();
    }

    SmtResult check(const BoolExpr e);

}
