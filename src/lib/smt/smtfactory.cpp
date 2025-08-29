#include "smtfactory.hpp"
#include "yices.hpp"
#include "z3.hpp"
#include "swine.hpp"
#include "cvc5.hpp"
#include "opensmt.hpp"
#include "config.hpp"

namespace SmtFactory {

SmtPtr solver(Logic logic) {
    SmtPtr res;
    if (Config::Analysis::smtSolver == Config::Analysis::OpenSmt && logic == QF_LA) {
        return std::unique_ptr<Smt>(new OpenSmt(true));
    }
    switch (Config::Analysis::smtSolver) {
        case Config::Analysis::OpenSmt:
        case Config::Analysis::Heuristic: {
            switch (logic) {
                case QF_LA:
                    res = std::unique_ptr<Smt>(new Yices(logic, false));
                    break;
                case QF_NA:
                    res = std::unique_ptr<Smt>(new Z3());
                    break;
                case QF_NAT:
                    res = std::unique_ptr<Smt>(new Swine());
                    break;
            }
            break;
        }
        case Config::Analysis::Yices: {
            res = std::unique_ptr<Smt>(new Yices(logic, false));
            break;
        }
        default: {
            res = solver();
            break;
        }
    }
    return res;
}

SmtPtr solver() {
    SmtPtr solver;
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Z3:
        solver = std::unique_ptr<Smt>(new Z3());
        break;
    case Config::Analysis::CVC5:
        solver = std::unique_ptr<Smt>(new CVC5());
        break;
    case Config::Analysis::Yices:
        solver = std::unique_ptr<Smt>(new Yices(Logic::QF_NA, false));
        break;
    case Config::Analysis::OpenSmt:
        solver = std::unique_ptr<Smt>(new OpenSmt(true));
        break;
    case Config::Analysis::Swine:
        [[fallthrough]];
    case Config::Analysis::Heuristic:
        solver = std::unique_ptr<Smt>(new Swine());
        break;
    }
    return solver;
}

SmtPtr interpolatingSolver() {
    SmtPtr solver;
    switch (Config::Analysis::smtSolver) {
        case Config::Analysis::Yices:
            solver = std::unique_ptr<Smt>(new Yices(Logic::QF_LA, true));
            break;
        case Config::Analysis::CVC5:
            solver = std::unique_ptr<Smt>(new CVC5());
            break;
        default:
            solver = std::unique_ptr<Smt>(new OpenSmt(true));
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
