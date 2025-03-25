#include "loatsolver.hpp"
#include <stdexcept>
#include <any>

void LoatSolver::setParameter(DynamicParameterKey key, const std::any &value)
{
    auto &dyn = config.getDynamic();

    try
    {
        switch (key)
        {
        case DynamicParameterKey::Log:
            dyn.log = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::LogAccel:
            dyn.logAccel = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::LogPreproc:
            dyn.logPreproc = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::PrintDependencyGraph:
            dyn.printDependencyGraph = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::BlockingClauses:
            dyn.blocking_clauses = std::any_cast<bool>(value);
            break;

        // TRP Subfields
        case DynamicParameterKey::TRP_RecurrentCycles:
            dyn.trp.recurrent_cycles = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentExps:
            dyn.trp.recurrent_exps = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentPseudoDivs:
            dyn.trp.recurrent_pseudo_divs = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentPseudoBounds:
            dyn.trp.recurrent_pseudo_bounds = std::any_cast<bool>(value);
            break;
        case DynamicParameterKey::TRP_RecurrentBounds:
            dyn.trp.recurrent_bounds = std::any_cast<bool>(value);
            break;

        default:
            throw std::invalid_argument("Unsupported parameter key");
        }
    }
    catch (const std::bad_any_cast &e)
    {
        throw std::invalid_argument("Type mismatch when setting parameter");
    }
}

void LoatSolver::refreshConfig()
{
    config.applyToGlobalConfig();
}