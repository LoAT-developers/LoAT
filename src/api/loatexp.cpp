#include "loatexpression.hpp"
#include <boost/functional/hash.hpp>

ConsHash<LoatExpr, LoatExp, LoatExp::CacheHash, LoatExp::CacheEqual, LoatExprPtr, LoatExprPtr> LoatExp::cache;

LoatExp::LoatExp(const LoatExprPtr base, const LoatExprPtr exponent)
    : LoatExpr(LoatExpression::Kind::Exp), m_base(base), m_exponent(exponent) {}

LoatExp::~LoatExp()
{
    cache.erase(m_base, m_exponent);
}

LoatExprPtr LoatExp::getBase() const
{
    return m_base;
}

LoatExprPtr LoatExp::getExponent() const
{
    return m_exponent;
}

bool LoatExp::CacheEqual::operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a,
                                     const std::tuple<LoatExprPtr, LoatExprPtr> &b) const noexcept
{
    return a == b;
}

size_t LoatExp::CacheHash::operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &a) const noexcept
{
    size_t hash = {0};
    boost::hash_combine(hash, std::get<0>(a));
    boost::hash_combine(hash, std::get<1>(a));
    return hash;
}

LoatExprPtr LoatExpression::mkExp(const LoatExprPtr base, const LoatExprPtr exponent)
{
    return LoatExp::cache.from_cache(base, exponent)->toPtr();
}