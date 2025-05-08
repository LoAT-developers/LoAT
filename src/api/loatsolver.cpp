#include "loatsolver.hpp"
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
    m_start = location.getName();
}

bool LoatSolver::isStartLocation(const LoatLocation &location) const
{
    return m_start == location.getName();
}

void LoatSolver::addSinkLocation(const LoatLocation &location)
{
    m_sinks.insert(location.getName());
}

bool LoatSolver::isSinkLocation(const LoatLocation &location) const
{
    return m_sinks.count(location.getName()) > 0;
}