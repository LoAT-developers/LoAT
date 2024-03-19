#include "smtfactory.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "swine.hpp"
#include "cvc5.hpp"
#include "config.hpp"

namespace SmtFactory {

SmtPtr solver(Logic logic) {
    std::unique_ptr<Smt> res;
    switch (logic) {
    case QF_LA:
        res = std::unique_ptr<Smt>(new Yices(logic));
        break;
    case QF_NA:
        switch (Config::Analysis::smtSolver) {
        case Config::Analysis::Z3:
        [[fallthrough]];
        case Config::Analysis::Swine:
            res = std::unique_ptr<Smt>(new Z3());
            break;
        case Config::Analysis::CVC5:
            res = std::unique_ptr<Smt>(new CVC5());
            break;
        case Config::Analysis::Yices:
            res = std::unique_ptr<Smt>(new Yices(Logic::QF_NA));
            break;
        }
        break;
    case QF_NAT:
        res = std::unique_ptr<Smt>(new Swine());
        break;
    }
    return res;
}

SmtPtr solver() {
    std::unique_ptr<Smt> solver;
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Z3:
        solver = std::unique_ptr<Smt>(new Z3());
        break;
    case Config::Analysis::CVC5:
        solver = std::unique_ptr<Smt>(new CVC5());
        break;
    case Config::Analysis::Yices:
        solver = std::unique_ptr<Smt>(new Yices(Logic::QF_NA));
        break;
    case Config::Analysis::Swine:
        solver = std::unique_ptr<Smt>(new Swine());
        break;
    }
    return solver;
}

SmtPtr modelBuildingSolver(Logic logic) {
    auto res {solver(logic)};
    res->enableModels();
    return res;
}

SmtResult check(const Bools::Expr e) {
    auto s {solver(Smt::chooseLogic(BoolExprSet{e}))};
    s->add(e);
    return s->check();
}

}
