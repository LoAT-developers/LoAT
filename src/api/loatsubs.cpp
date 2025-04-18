#include "loatsubs.hpp"

void LoatSubs::put(const LoatIntExprPtr &var, const LoatIntExprPtr &expr)
{
    intSubs.put(var, expr);
}

void LoatSubs::put(const LoatBoolExprPtr &var, const LoatBoolExprPtr &expr)
{
    boolSubs.put(var, expr);
}

const LoatIntSubs &LoatSubs::getIntSubs() const
{
    return intSubs;
}

const LoatBoolSubs &LoatSubs::getBoolSubs() const
{
    return boolSubs;
}

std::ostream &operator<<(std::ostream &os, const LoatSubs &subs)
{
    os << subs.intSubs;
    os << subs.boolSubs;
    return os;
}