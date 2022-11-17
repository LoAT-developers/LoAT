#pragma once

#include "smt.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "linearizingsolver.hpp"
#include "config.hpp"
#include "itheory.hpp"
#include "theory.hpp"

namespace SmtFactory {

struct SmtConfig {
    Logic logic;
    bool produce_models = false;
    bool incremental = false;
    bool produce_unsat_cores = false;
    unsigned timeout = Config::Smt::DefaultTimeout;

    SmtConfig(Logic logic): logic(logic) {}

};

template<ITheory... Th>
std::unique_ptr<Smt<Th...>> solver(const SmtConfig &config, VariableManager &varMan) {
    std::unique_ptr<Smt<Th...>> res;
    switch (config.logic) {
    case QF_LA:
        res = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(varMan, QF_LA));
        break;
    case QF_NA:
        if (config.incremental || config.produce_unsat_cores) {
            res = std::unique_ptr<Smt<Th...>>(new Z3<Th...>(varMan));
        } else {
            res = std::unique_ptr<Smt<Th...>>(new Yices<Th...>(varMan, QF_NA));
        }
        break;
    case QF_NAT:
        if (config.produce_unsat_cores) {
            res = std::unique_ptr<Smt<Th...>>(new Z3<Th...>(varMan));
        } else {
            res = std::unique_ptr<Smt<Th...>>(new LinearizingSolver<Th...>(varMan));
        }
        break;
    }
    if (config.produce_models) {
        res->enableModels();
    }
    res->setTimeout(config.timeout);
    return res;
}

template<ITheory... Th>
static SmtResult check(const BExpr<Th...> e, VariableManager &varMan) {
    std::unique_ptr<Smt<Th...>> s = SmtFactory::solver<Th...>(SmtConfig(Smt<Th...>::chooseLogic(BoolExpressionSet<Th...>{e})), varMan);
    s->add(e);
    return s->check();
}

template<ITheory... Th>
BoolExpressionSet<Th...> unsatCore(const BoolExpressionSet<Th...> &assumptions, VariableManager &varMan) {
    SmtConfig config(Smt<Th...>::chooseLogic(assumptions));
    config.produce_unsat_cores = true;
    return solver<Th...>(config, varMan)->_unsatCore(assumptions).second;
}

}
