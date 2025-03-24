#include <iostream>
#include "loatconfig.hpp"
#include "loatsolver.hpp"

int main()
{
    LoatConfig::InitialConfig initialConfig1(
        LoatConfig::InitialConfig::Format::Koat,
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Complexity,
        LoatConfig::InitialConfig::SmtSolver::Z3);

    LoatConfig::InitialConfig initialConfig2(
        LoatConfig::InitialConfig::Format::Horn,
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Complexity,
        LoatConfig::InitialConfig::SmtSolver::Z3);

    LoatConfig::DynamicConfig dynamicConfig1;
    dynamicConfig1.direction = LoatConfig::DynamicConfig::Direction::Forward;

    LoatConfig config1(initialConfig1, dynamicConfig1);
    LoatConfig config2(initialConfig1);
    LoatConfig config3(LoatConfig::InitialConfig(LoatConfig::InitialConfig::Format::Koat,
                                                 LoatConfig::InitialConfig::Engine::ADCL,
                                                 LoatConfig::InitialConfig::Mode::Complexity,
                                                 LoatConfig::InitialConfig::SmtSolver::Z3));

    LoatSolver solver1(config1);
    LoatSolver solver2(config2);
    LoatSolver solver3(config3);

    solver1.setParameter(DynamicParameterKey::Log, true);
    solver1.refreshConfig();

    return 0;
}