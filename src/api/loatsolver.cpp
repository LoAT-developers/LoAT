#include "loatsolver.hpp"
#include "config.hpp"

#include "abmc.hpp"
#include "bmc.hpp"
#include "adcl.hpp"

#include <stdexcept>
#include <any>

void LoatSolver::setParameter(DynamicParameterKey key, const std::any &value)
{
    try
    {
        m_config.getDynamic().set(key, value);
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

void LoatSolver::refreshConfig()
{
    m_config.applyToGlobalConfig();
}

void LoatSolver::add(const LoatTransition &transition)
{
    m_transitions.push_back(transition);
}

void LoatSolver::setStartLocation(const LoatLocation &location)
{
    m_start = location;
}

void LoatSolver::addSinkLocation(const LoatLocation &location)
{
    m_sink = location;
}

void LoatSolver::produceITS()
{
    m_its = m_converter.convertTransitionsToITS(m_transitions, m_start, m_sink);
}

bool LoatSolver::check()
{
    // Refresh the config to be up to date
    refreshConfig();

    // Produce the required its
    produceITS();

    // Dispatch selected function
    SmtResult res = SmtResult::Unknown;

    // LoatConfig::InitialConfig::Engine engine = m_config.getInitial().get(InitialParameterKey::Engine);
    return true;
}