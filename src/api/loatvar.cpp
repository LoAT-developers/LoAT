#include "loatexpression.hpp"
#include <string>

ConsHash<LoatExpr, LoatVar, LoatVar::CacheHash, LoatVar::CacheEqual, std::string> LoatVar::cache;

LoatVar::LoatVar(const std::string &name) : LoatExpr(LoatExpression::Kind::Variable), m_name(name) {}

LoatVar::~LoatVar()
{
    cache.erase(m_name);
}

std::string LoatVar::getName() const
{
    return m_name;
}

bool LoatVar::CacheEqual::operator()(const std::tuple<std::string> &a, const std::tuple<std::string> &b) const noexcept
{
    return a == b;
}

size_t LoatVar::CacheHash::operator()(const std::tuple<std::string> &a) const noexcept
{
    return std::hash<std::string>{}(std::get<0>(a));
}

// Factory Method to create Variable
LoatExprPtr LoatExpression::mkVar(const std::string &name)
{
    return LoatVar::cache.from_cache(name)->toPtr();
}