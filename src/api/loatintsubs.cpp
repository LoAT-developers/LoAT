#include "loatintsubs.hpp"
#include <ostream>

LoatIntSubs::LoatIntSubs(const std::unordered_map<LoatIntExprPtr, LoatIntExprPtr> &subsmap)
{
    for (const auto &[var, expr] : subsmap)
    {
        put(var, expr);
    }
}

void LoatIntSubs::put(const LoatIntExprPtr &var, const LoatIntExprPtr &expr)
{
    if (var->getKind() != LoatIntExpression::Kind::Variable)
    {
        throw std::invalid_argument("LoatIntSubs: left-hand side must be a variable");
    }
    m_subsmap.insert({var, expr});
}

const std::unordered_map<LoatIntExprPtr, LoatIntExprPtr> &LoatIntSubs::getSubsMap() const
{
    return m_subsmap;
}

std::ostream &operator<<(std::ostream &os, const LoatIntSubs &subs)
{
    os << "{";
    bool first = true;
    for (const auto &[var, expr] : subs.m_subsmap)
    {
        if (!first)
            os << ", ";
        os << var << " := " << expr;
        first = false;
    }
    os << "}";
    return os;
}