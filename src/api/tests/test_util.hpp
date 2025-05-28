#pragma once

#include "loatconfig.hpp"

inline LoatConfig::InitialConfig createSampleInitialConfig()
{
    return LoatConfig::InitialConfig(
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Yices,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        true);
}