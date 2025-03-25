#include "loatconfig.hpp"
#include "config.hpp"
#include <stdexcept>
#include <typeinfo>

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
    Input::format = static_cast<Input::Format>(m_initial.getFormat());
    Analysis::engine = static_cast<Analysis::Engine>(m_initial.getEngine());
    Analysis::mode = static_cast<Analysis::Mode>(m_initial.getMode());
    Analysis::smtSolver = static_cast<Analysis::SmtSolver>(m_initial.getSolver());
    Analysis::dir = static_cast<Analysis::Direction>(m_initial.getDirection());
    Analysis::model = m_initial.getModel();
    trp.mbpKind = static_cast<TRPConfig::MbpKind>(m_initial.getMbpKind());

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