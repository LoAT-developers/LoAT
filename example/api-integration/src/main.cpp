#include <iostream>
#include "loatconfig.hpp"
#include "loatsolver.hpp"
#include <any>
#include <stdexcept>

int main()
{
    LoatConfig::InitialConfig initialConfig1(
        LoatConfig::InitialConfig::Format::Koat,
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Complexity,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false);

    LoatConfig::InitialConfig initialConfig2(
        LoatConfig::InitialConfig::Format::Horn,
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Complexity,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false);

    LoatConfig::DynamicConfig dynamicConfig1;
    dynamicConfig1.set(DynamicParameterKey::Log, false);

    try
    {
        dynamicConfig1.set(DynamicParameterKey::Log, 12);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    LoatConfig config1(initialConfig1, dynamicConfig1);
    LoatConfig config2(initialConfig1);

    dynamicConfig1.set(DynamicParameterKey::Log, true);

    try
    {
        dynamicConfig1.set(DynamicParameterKey::Log, 12);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught expected:" << e.what() << std::endl;
    }

    LoatConfig config3(LoatConfig::InitialConfig(LoatConfig::InitialConfig::Format::Koat,
                                                 LoatConfig::InitialConfig::Engine::ADCL,
                                                 LoatConfig::InitialConfig::Mode::Complexity,
                                                 LoatConfig::InitialConfig::SmtSolver::Z3,
                                                 LoatConfig::InitialConfig::Direction::Forward,
                                                 LoatConfig::InitialConfig::MbpKind::IntMbp,
                                                 false));

    LoatSolver solver1(config1);
    LoatSolver solver2(config2);
    LoatSolver solver3(config3);

    solver1.setParameter(DynamicParameterKey::Log, true);
    try
    {
        solver1.setParameter(DynamicParameterKey::Log, 12);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught expected: " << e.what() << std::endl;
    }

    solver1.refreshConfig();

    return 0;
}