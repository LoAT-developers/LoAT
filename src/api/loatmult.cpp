#include "loatintexpr.hpp"
#include <boost/functional/hash.hpp>
#include <sstream>

ConsHash<LoatIntExpr, LoatIntMult, LoatIntMult::CacheHash, LoatIntMult::CacheEqual, LoatIntExprSet> LoatIntMult::cache;

LoatIntMult::LoatIntMult(const LoatIntExprSet &args) : LoatIntExpr(LoatIntExpression::Kind::Times), m_args(args) {}

LoatIntMult::~LoatIntMult()
{
    cache.erase(m_args);
}

const LoatIntExprSet &LoatIntMult::getArgs() const
{
    return m_args;
}

bool LoatIntMult::CacheEqual::operator()(const std::tuple<LoatIntExprSet> &a, const std::tuple<LoatIntExprSet> &b) const noexcept
{
    return a == b;
}

size_t LoatIntMult::CacheHash::operator()(const std::tuple<LoatIntExprSet> &a) const noexcept
{
    size_t hash = {23};
    const auto &children{std::get<0>(a)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkTimes(LoatIntExprVec &&args)
{
    if (args.empty())
        return mkConst(1);
    if (args.size() == 1)
        return args[0];
    return LoatIntMult::cache.from_cache(LoatIntExprSet(args.begin(), args.end()))->toPtr();
}

LoatIntExprPtr LoatIntExpression::mkTimes(const LoatIntExprPtr a, const LoatIntExprPtr b)
{
    return mkTimes(LoatIntExprVec{a, b});
}