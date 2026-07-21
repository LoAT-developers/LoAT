#include "trivialanalysis.hpp"

#include "config.hpp"
#include "smtfactory.hpp"

TrivialAnalysis::~TrivialAnalysis() {}

TrivialAnalysis::TrivialAnalysis(const ITSPtr& its): its(its), cex(its) {}

void TrivialAnalysis::init() {}

ITSModel TrivialAnalysis::get_model() {
    return {its, 0};
}

ITSSafetyCex TrivialAnalysis::get_cex() {
    return cex;
}

std::optional<SmtResult> TrivialAnalysis::do_step() {
    if (its->isEmpty()) {
        return SmtResult::Sat;
    }
    for (const auto& r: its->getInitialTransitions()) {
        if (its->isSinkTransition(r)) {
            auto solver = SmtFactory::modelBuildingSolver(Smt::chooseLogic(r->getGuard()));
            solver->add(r->getGuard());
            if (solver->check() == SmtResult::Sat) {
                if (Config::Analysis::model) {
                    cex.set_initial_state(solver->model());
                    cex.do_step(r, solver->model());
                }
                return SmtResult::Unsat;
            }
        }
    }
    return SmtResult::Unknown;
}
