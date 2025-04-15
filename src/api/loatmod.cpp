#include "loatintexpr.hpp"
#include <boost/functional/hash.hpp>
#include <sstream>

ConsHash<LoatIntExpr, LoatMod, LoatMod::CacheHash, LoatMod::CacheEqual, LoatIntExprPtr, LoatIntExprPtr> LoatMod::cache;

LoatMod::LoatMod(const LoatIntExprPtr lhs, const LoatIntExprPtr rhs)
    : LoatIntExpr(LoatIntExpression::Kind::Mod), m_lhs(lhs), m_rhs(rhs) {}

LoatMod::~LoatMod()
{
    cache.erase(m_lhs, m_rhs);
}

const LoatIntExprPtr LoatMod::getLhs() const
{
    return m_lhs;
}

const LoatIntExprPtr LoatMod::getRhs() const
{
    return m_rhs;
}

bool LoatMod::CacheEqual::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args1,
                                     const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatMod::CacheHash::operator()(const std::tuple<LoatIntExprPtr, LoatIntExprPtr> &args) const noexcept
{
    size_t hash = 23;
    const auto &lhs = std::get<0>(args);
    const auto &rhs = std::get<1>(args);
    boost::hash_combine(hash, lhs);
    boost::hash_combine(hash, rhs);
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkMod(LoatIntExprPtr lhs, LoatIntExprPtr rhs)
{
    return LoatMod::cache.from_cache(lhs, rhs)->toPtr();
}