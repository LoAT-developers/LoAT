#include "loatboolsubs.hpp"
#include <ostream>

LoatBoolSubs::LoatBoolSubs(const std::unordered_map<LoatBoolExprPtr, LoatBoolExprPtr> &subsmap)
{
    for (const auto &[var, expr] : subsmap)
    {
        put(var, expr);
    }
}

void LoatBoolSubs::put(const LoatBoolExprPtr &var, const LoatBoolExprPtr &expr)
{
    if (var->getKind() != LoatBoolExpression::Kind::Variable)
    {
        throw std::invalid_argument("LoatBoolSubs: left-hand side must be a variable");
    }
    m_subsmap.insert({var, expr});
}

const std::unordered_map<LoatBoolExprPtr, LoatBoolExprPtr> &LoatBoolSubs::getSubsMap() const
{
    return m_subsmap;
}

std::ostream &operator<<(std::ostream &os, const LoatBoolSubs &subs)
{
    os << "{";
    bool first = true;
    for (const auto &[var, expr] : subs.m_subsmap)
    {
        if (!first)
            os << ", ";
        first = false;
        os << var << " := " << expr;
    }
    return os << "}";
}