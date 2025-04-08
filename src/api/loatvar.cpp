#include "loatexpression.hpp"

ConsHash<LoatExpr, LoatVar, LoatVar::CacheHash, LoatVar::CacheEqual, int> LoatVar::cache;

LoatVar::LoatVar(int idx) : LoatExpr(LoatExpression::Kind::Variable), m_idx(idx) {}

LoatVar::~LoatVar()
{
    cache.erase(m_idx);
}

int LoatVar::getIdx() const
{
    return m_idx;
}

std::string LoatVar::getName() const
{
    if (m_idx > 0)
    {
        return "x" + std::to_string(m_idx);
    }
    else
    {
        return "t" + std::to_string(-m_idx);
    }
}

bool LoatVar::CacheEqual::operator()(const std::tuple<int> &a, const std::tuple<int> &b) const noexcept
{
    return a == b;
}

size_t LoatVar::CacheHash::operator()(const std::tuple<int> &a) const noexcept
{
    return std::hash<int>{}(std::get<0>(a));
}

// Factory Method to create Variable
LoatExprPtr LoatExpression::mkVar(const int idx)
{
    if (idx < 0)
    {
        throw std::invalid_argument("Negative variable indices are not allowed.");
    }
    return LoatVar::cache.from_cache(idx)->toPtr();
}