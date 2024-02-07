#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "swine.hpp"
#include "cvc5.hpp"
#include "config.hpp"

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
    std::unique_ptr<Smt<Th...>> solver() {
        std::unique_ptr<Smt<Th...>> solver;
        switch (Config::Analysis::smtSolver) {
        case Config::Analysis::Z3:
            solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new Z3<IntTheory, BoolTheory>());
            break;
        case Config::Analysis::CVC5:
            solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new CVC5<IntTheory, BoolTheory>());
            break;
        case Config::Analysis::Yices:
            solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new Yices<IntTheory, BoolTheory>(Logic::QF_NA));
            break;
        case Config::Analysis::Swine:
            solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new Swine<IntTheory, BoolTheory>());
            break;
        }
        return solver;
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
