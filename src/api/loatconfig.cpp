#include "loatconfig.hpp"
#include "config.hpp"
#include <stdexcept>
#include <typeinfo>

// Helper functions to Map API-Enums to Config Enums
namespace
{

    // Format
    Config::Input::Format mapFormat(LoatConfig::InitialConfig::Format in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::Format::Horn:
            return Config::Input::Format::Horn;
        case LoatConfig::InitialConfig::Format::Koat:
            return Config::Input::Format::Koat;
        case LoatConfig::InitialConfig::Format::Its:
            return Config::Input::Format::Its;
        default:
            throw std::invalid_argument("Invalid Format");
        }
    }

    // Engine
    Config::Analysis::Engine mapEngine(LoatConfig::InitialConfig::Engine in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::Engine::ADCL:
            return Config::Analysis::Engine::ADCL;
        case LoatConfig::InitialConfig::Engine::BMC:
            return Config::Analysis::Engine::BMC;
        case LoatConfig::InitialConfig::Engine::ABMC:
            return Config::Analysis::Engine::ABMC;
        case LoatConfig::InitialConfig::Engine::TRL:
            return Config::Analysis::Engine::TRL;
        case LoatConfig::InitialConfig::Engine::KIND:
            return Config::Analysis::Engine::KIND;
        case LoatConfig::InitialConfig::Engine::ADCLSAT:
            return Config::Analysis::Engine::ADCLSAT;
        default:
            throw std::invalid_argument("Invalid Engine");
        }
    }

    // Mode
    Config::Analysis::Mode mapMode(LoatConfig::InitialConfig::Mode in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::Mode::Complexity:
            return Config::Analysis::Mode::Complexity;
        case LoatConfig::InitialConfig::Mode::Termination:
            return Config::Analysis::Mode::Termination;
        case LoatConfig::InitialConfig::Mode::Safety:
            return Config::Analysis::Mode::Safety;
        default:
            throw std::invalid_argument("Invalid Mode");
        }
    }

    // Solver
    Config::Analysis::SmtSolver mapSolver(LoatConfig::InitialConfig::SmtSolver in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::SmtSolver::Z3:
            return Config::Analysis::SmtSolver::Z3;
        case LoatConfig::InitialConfig::SmtSolver::CVC5:
            return Config::Analysis::SmtSolver::CVC5;
        case LoatConfig::InitialConfig::SmtSolver::Swine:
            return Config::Analysis::SmtSolver::Swine;
        case LoatConfig::InitialConfig::SmtSolver::Yices:
            return Config::Analysis::SmtSolver::Yices;
        case LoatConfig::InitialConfig::SmtSolver::Heuristic:
            return Config::Analysis::SmtSolver::Heuristic;
        default:
            throw std::invalid_argument("Invalid SmtSolver");
        }
    }

    // Direction
    Config::Analysis::Direction mapDirection(LoatConfig::InitialConfig::Direction in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::Direction::Forward:
            return Config::Analysis::Direction::Forward;
        case LoatConfig::InitialConfig::Direction::Backward:
            return Config::Analysis::Direction::Backward;
        case LoatConfig::InitialConfig::Direction::Interleaved:
            return Config::Analysis::Direction::Interleaved;
        default:
            throw std::invalid_argument("Invalid Direction");
        }
    }

    // MbpKind
    Config::TRPConfig::MbpKind mapMbpKind(LoatConfig::InitialConfig::MbpKind in)
    {
        switch (in)
        {
        case LoatConfig::InitialConfig::MbpKind::LowerIntMbp:
            return Config::TRPConfig::LowerIntMbp;
        case LoatConfig::InitialConfig::MbpKind::UpperIntMbp:
            return Config::TRPConfig::UpperIntMbp;
        case LoatConfig::InitialConfig::MbpKind::IntMbp:
            return Config::TRPConfig::IntMbp;
        case LoatConfig::InitialConfig::MbpKind::RealMbp:
            return Config::TRPConfig::RealMbp;
        case LoatConfig::InitialConfig::MbpKind::RealQe:
            return Config::TRPConfig::RealQe;
        default:
            throw std::invalid_argument("Invalid MbpKind");
        }
    }

}

// Constructors
LoatConfig::LoatConfig(const InitialConfig &init)
    : m_initial(init), m_dynamic() {}

LoatConfig::LoatConfig(const InitialConfig &init, const DynamicConfig &dyn)
    : m_initial(init), m_dynamic(dyn) {}

// Getter for entire (sub) config objegts
const LoatConfig::InitialConfig &LoatConfig::getInitial() const
{
    return m_initial;
}

const LoatConfig::DynamicConfig &LoatConfig::getDynamic() const
{
    return m_dynamic;
}

LoatConfig::DynamicConfig &LoatConfig::getDynamic()
{
    return m_dynamic;
}

// Write the solvers individual (local) config to the global config
void LoatConfig::applyToGlobalConfig() const
{
    using namespace Config;

    // Initial config
    Input::format = mapFormat(std::any_cast<LoatConfig::InitialConfig::Format>(m_initial.get(InitialParameterKey::Format)));
    Analysis::engine = mapEngine(std::any_cast<LoatConfig::InitialConfig::Engine>(m_initial.get(InitialParameterKey::Engine)));
    Analysis::mode = mapMode(std::any_cast<LoatConfig::InitialConfig::Mode>(m_initial.get(InitialParameterKey::Mode)));
    Analysis::smtSolver = mapSolver(std::any_cast<LoatConfig::InitialConfig::SmtSolver>(m_initial.get(InitialParameterKey::SmtSolver)));
    Analysis::dir = mapDirection(std::any_cast<LoatConfig::InitialConfig::Direction>(m_initial.get(InitialParameterKey::Direction)));
    Analysis::model = std::any_cast<bool>(m_initial.get(InitialParameterKey::Model));
    trp.mbpKind = mapMbpKind(std::any_cast<LoatConfig::InitialConfig::MbpKind>(m_initial.get(InitialParameterKey::MbpKind)));

    // Dynamic config
    Analysis::log = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::Log));
    Analysis::logAccel = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::LogAccel));
    Analysis::logPreproc = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::LogPreproc));
    Output::PrintDependencyGraph = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::PrintDependencyGraph));
    ABMC::blocking_clauses = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::BlockingClauses));

    trp.recurrent_cycles = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::TRP_RecurrentCycles));
    trp.recurrent_exps = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::TRP_RecurrentExps));
    trp.recurrent_pseudo_divs = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::TRP_RecurrentPseudoDivs));
    trp.recurrent_pseudo_bounds = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::TRP_RecurrentPseudoBounds));
    trp.recurrent_bounds = std::any_cast<bool>(m_dynamic.get(DynamicParameterKey::TRP_RecurrentBounds));
}

// Getter for initial config
std::any LoatConfig::InitialConfig::get(InitialParameterKey key) const
{
    switch (key)
    {
    case InitialParameterKey::Format:
        return m_format;
    case InitialParameterKey::Engine:
        return m_engine;
    case InitialParameterKey::Mode:
        return m_mode;
    case InitialParameterKey::SmtSolver:
        return m_solver;
    case InitialParameterKey::Direction:
        return m_direction;
    case InitialParameterKey::MbpKind:
        return m_mbpKind;
    case InitialParameterKey::Model:
        return m_model;
    default:
        throw std::invalid_argument("Unknown InitialParameterKey");
    }
}

// Getter for values of Dynamic Config
std::any LoatConfig::DynamicConfig::get(DynamicParameterKey key) const
{
    switch (key)
    {
    case DynamicParameterKey::Log:
        return m_log;
    case DynamicParameterKey::LogAccel:
        return m_logAccel;
    case DynamicParameterKey::LogPreproc:
        return m_logPreproc;
    case DynamicParameterKey::PrintDependencyGraph:
        return m_printDependencyGraph;
    case DynamicParameterKey::BlockingClauses:
        return m_blocking_clauses;
    case DynamicParameterKey::TRP_RecurrentCycles:
        return m_trp.m_recurrent_cycles;
    case DynamicParameterKey::TRP_RecurrentExps:
        return m_trp.m_recurrent_exps;
    case DynamicParameterKey::TRP_RecurrentPseudoDivs:
        return m_trp.m_recurrent_pseudo_divs;
    case DynamicParameterKey::TRP_RecurrentPseudoBounds:
        return m_trp.m_recurrent_pseudo_bounds;
    case DynamicParameterKey::TRP_RecurrentBounds:
        return m_trp.m_recurrent_bounds;
    default:
        throw std::invalid_argument("Unknown DynamicParameterKey");
    }
}

// Setter for values of Config
void LoatConfig::DynamicConfig::set(DynamicParameterKey key, const std::any &value)
{
    try
    {
        switch (key)
        {
        case DynamicParameterKey::Log:
            m_log = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::LogAccel:
            m_logAccel = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::LogPreproc:
            m_logPreproc = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::PrintDependencyGraph:
            m_printDependencyGraph = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::BlockingClauses:
            m_blocking_clauses = std::any_cast<bool>(value);
            break;

        case DynamicParameterKey::TRP_RecurrentCycles:
            m_trp.m_recurrent_cycles = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentExps:
            m_trp.m_recurrent_exps = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentPseudoDivs:
            m_trp.m_recurrent_pseudo_divs = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentPseudoBounds:
            m_trp.m_recurrent_pseudo_bounds = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentBounds:
            m_trp.m_recurrent_bounds = std::any_cast<bool>(value);
            break;

        default:
            throw std::invalid_argument("Unknown DynamicParameterKey");
        }
    }
    catch (const std::bad_any_cast &e)
    {
        throw std::invalid_argument("Type mismatch when setting parameter");
    }
}