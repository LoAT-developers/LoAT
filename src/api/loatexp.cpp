#include "loatintexpr.hpp"
#include <boost/functional/hash.hpp>

ConsHash<LoatIntExpr, LoatExp, LoatExp::CacheHash, LoatExp::CacheEqual, LoatIntExprPtr, LoatIntExprPtr> LoatExp::cache;

LoatExp::LoatExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent)
    : LoatIntExpr(LoatIntExpression::Kind::Exp), m_base(base), m_exponent(exponent) {}

LoatExp::~LoatExp()
{
    cache.erase(m_base, m_exponent);
}

LoatIntExprPtr LoatExp::getBase() const
{
    return m_base;
}

LoatIntExprPtr LoatExp::getExponent() const
{
    return m_exponent;
}

bool LoatExp::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a,
                                     const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &b) const noexcept
{
    return a == b;
}

size_t LoatExp::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a) const noexcept
{
    size_t hash = {0};
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent)
{
    return LoatExp::cache.from_cache(base, exponent)->toPtr();
}