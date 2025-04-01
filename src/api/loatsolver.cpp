#include "loatsolver.hpp"
#include "loatexpression.hpp"
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

void LoatSolver::add(const LoatExprPtr &expr)
{
    // Save for later
    m_expressions.push_back(expr);
}