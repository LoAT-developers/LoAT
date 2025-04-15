#include "loatintexpr.hpp"
#include <boost/functional/hash.hpp>

ConsHash<LoatIntExpr, LoatIntExp, LoatIntExp::CacheHash, LoatIntExp::CacheEqual, LoatIntExprPtr, LoatIntExprPtr> LoatIntExp::cache;

LoatIntExp::LoatIntExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent)
    : LoatIntExpr(LoatIntExpression::Kind::Exp), m_base(base), m_exponent(exponent) {}

LoatIntExp::~LoatIntExp()
{
    cache.erase(m_base, m_exponent);
}

LoatIntExprPtr LoatIntExp::getBase() const
{
    return m_base;
}

LoatIntExprPtr LoatIntExp::getExponent() const
{
    return m_exponent;
}

bool LoatIntExp::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a,
                                        const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &b) const noexcept
{
    return a == b;
}

size_t LoatIntExp::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &a) const noexcept
{
    size_t hash = {0};
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkExp(const LoatIntExprPtr base, const LoatIntExprPtr exponent)
{
    return LoatIntExp::cache.from_cache(base, exponent)->toPtr();
}