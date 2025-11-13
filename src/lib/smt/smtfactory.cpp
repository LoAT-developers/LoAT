#include "smtfactory.hpp"
#include "yices.hpp"
#include "swine.hpp"
#include "config.hpp"

namespace SmtFactory {

SmtPtr solver(const Logic logic) {
    std::unique_ptr<Smt> res;
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Heuristic: {
        switch (logic) {
        case Logic::QF_LA:
        case Logic::QF_ALA:
            res = std::unique_ptr<Smt>(new Yices(logic));
            break;
        default:
            res = std::unique_ptr<Smt>(new Swine());
            break;
        }
        break;
    }
    case Config::Analysis::Yices: {
        switch (logic) {
        case Logic::QF_EA:
        case Logic::QF_AEA:
            res = std::unique_ptr<Smt>(new Swine());
            break;
        default:
            res = std::unique_ptr<Smt>(new Yices(logic));
            break;
        }
        break;
    }
    case Config::Analysis::Swine: {
        res = std::unique_ptr<Smt>(new Swine());
        break;
    }
    }
    return res;
}

SmtPtr solver() {
    std::unique_ptr<Smt> solver;
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Yices:
        solver = std::unique_ptr<Smt>(new Yices(Logic::QF_ANA));
        break;
    default:
        solver = std::unique_ptr<Smt>(new Swine());
        break;
    }
    return solver;
}

SmtPtr modelBuildingSolver(const Logic logic) {
    auto res {solver(logic)};
    res->enableModels();
    return res;
}

SmtResult check(const Bools::Expr& e) {
    const auto s {solver(Smt::chooseLogic(e))};
    s->add(e);
    return s->check();
}

}
