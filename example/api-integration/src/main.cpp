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

    LoatConfig::DynamicConfig dynamicConfig1;
    dynamicConfig1.direction = LoatConfig::DynamicConfig::Direction::Forward;

    LoatConfig config1(initialConfig1, dynamicConfig1);

    LoatSolver solver1(config1);

    solver1.setParameter(DynamicParameterKey::Log, true);
    solver1.refreshConfig();

    return 0;
}