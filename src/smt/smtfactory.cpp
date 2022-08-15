#include "smtfactory.hpp"
#include "config.hpp"
#include "z3.hpp"
#include "yices.hpp"
#include "combined_solver.hpp"

std::unique_ptr<Smt> SmtFactory::solver(Smt::Logic logic, const VariableManager &varMan, unsigned int timeout) {
    std::unique_ptr<Smt> res;
    switch (logic) {
    case Smt::QF_LA:
//    case Smt::QF_NA:
        res = std::unique_ptr<Smt>(new Yices(varMan, logic));
        break;
    case Smt::QF_NA:
    case Smt::QF_ENA:
        res = std::unique_ptr<Smt>(new Z3(varMan));
        break;
    }
    res->setTimeout(timeout);
    return res;
}

std::unique_ptr<Smt> SmtFactory::modelBuildingSolver(Smt::Logic logic, const VariableManager &varMan, unsigned int timeout) {
    std::unique_ptr<Smt> res = solver(logic, varMan, timeout);
    res->enableModels();
    return res;
}
