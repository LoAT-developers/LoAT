#include "loatconfig.hpp"
#include "config.hpp"

LoatConfig::LoatConfig(InitialConfig init)
    : LoatConfig(std::move(init), DynamicConfig{}) {}

LoatConfig::LoatConfig(InitialConfig init, DynamicConfig dyn)
    : initial(std::move(init)), dynamic(std::move(dyn)) {}

// Write the solvers individual (local) config to the global config
void LoatConfig::applyToGlobalConfig() const
{
    using namespace Config;

    // Initial Config
    Input::format = static_cast<Input::Format>(initial.format);
    Analysis::engine = static_cast<Analysis::Engine>(initial.engine);
    Analysis::mode = static_cast<Analysis::Mode>(initial.mode);
    Analysis::smtSolver = static_cast<Analysis::SmtSolver>(initial.solver);

    // Dynamic Config
    Analysis::dir = static_cast<Analysis::Direction>(dynamic.direction);
    Analysis::log = dynamic.log;
    Analysis::logAccel = dynamic.logAccel;
    Analysis::logPreproc = dynamic.logPreproc;
    Analysis::model = dynamic.model;

    Output::PrintDependencyGraph = dynamic.printDependencyGraph;

    trp.mbpKind = static_cast<TRPConfig::MbpKind>(dynamic.trp.mbpKind);
    trp.recurrent_cycles = dynamic.trp.recurrent_cycles;
    trp.recurrent_exps = dynamic.trp.recurrent_exps;
    trp.recurrent_pseudo_divs = dynamic.trp.recurrent_pseudo_divs;
    trp.recurrent_pseudo_bounds = dynamic.trp.recurrent_pseudo_bounds;
    trp.recurrent_bounds = dynamic.trp.recurrent_bounds;

    ABMC::blocking_clauses = dynamic.blocking_clauses;
}