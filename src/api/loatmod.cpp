#include "loatexpression.hpp"
#include <boost/functional/hash.hpp>
#include <sstream>

ConsHash<LoatExpr, LoatMod, LoatMod::CacheHash, LoatMod::CacheEqual, LoatExprPtr, LoatExprPtr> LoatMod::cache;

LoatMod::LoatMod(const LoatExprPtr lhs, const LoatExprPtr rhs)
    : LoatExpr(LoatExpression::Kind::Mod), m_lhs(lhs), m_rhs(rhs) {}

LoatMod::~LoatMod()
{
    cache.erase(m_lhs, m_rhs);
}

const LoatExprPtr LoatMod::getLhs() const
{
    return m_lhs;
}

const LoatExprPtr LoatMod::getRhs() const
{
    return m_rhs;
}

bool LoatMod::CacheEqual::operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &args1,
                                     const std::tuple<LoatExprPtr, LoatExprPtr> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatMod::CacheHash::operator()(const std::tuple<LoatExprPtr, LoatExprPtr> &args) const noexcept
{
    size_t hash = 23;
    const auto &lhs = std::get<0>(args);
    const auto &rhs = std::get<1>(args);
    boost::hash_combine(hash, lhs);
    boost::hash_combine(hash, rhs);
    return hash;
}

LoatExprPtr LoatExpression::mkMod(LoatExprPtr lhs, LoatExprPtr rhs)
{
    return LoatMod::cache.from_cache(lhs, rhs)->toPtr();
}