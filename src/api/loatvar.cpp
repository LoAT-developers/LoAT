#include "loatintexpr.hpp"
#include <string>

ConsHash<LoatIntExpr, LoatIntVar, LoatIntVar::CacheHash, LoatIntVar::CacheEqual, std::string> LoatIntVar::cache;

LoatIntVar::LoatIntVar(const std::string &name) : LoatIntExpr(LoatIntExpression::Kind::Variable), m_name(name) {}

LoatIntVar::~LoatIntVar()
{
    cache.erase(m_name);
}

std::string LoatIntVar::getName() const
{
    return m_name;
}

bool LoatIntVar::CacheEqual::operator()(const std::tuple<std::string> &a, const std::tuple<std::string> &b) const noexcept
{
    return a == b;
}

size_t LoatIntVar::CacheHash::operator()(const std::tuple<std::string> &a) const noexcept
{
    return std::hash<std::string>{}(std::get<0>(a));
}

// Factory Method to create Variable
LoatIntExprPtr LoatIntExpression::mkVar(const std::string &name)
{
    return LoatIntVar::cache.from_cache(name)->toPtr();
}