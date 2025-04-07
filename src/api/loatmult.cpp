#include "loatexpression.hpp"
#include <boost/functional/hash.hpp>
#include <sstream>

ConsHash<LoatExpr, LoatMult, LoatMult::CacheHash, LoatMult::CacheEqual, LoatExprSet> LoatMult::cache;

LoatMult::LoatMult(const LoatExprSet &args) : LoatExpr(LoatExpression::Kind::Times), m_args(args) {}

LoatMult::~LoatMult()
{
    cache.erase(m_args);
}

const LoatExprSet &LoatMult::getArgs() const
{
    return m_args;
}

bool LoatMult::CacheEqual::operator()(const std::tuple<LoatExprSet> &a, const std::tuple<LoatExprSet> &b) const noexcept
{
    return a == b;
}

size_t LoatMult::CacheHash::operator()(const std::tuple<LoatExprSet> &a) const noexcept
{
    size_t hash = {23};
    const auto &children{std::get<0>(a)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatExprPtr LoatExpression::mkTimes(LoatExprVec &&args)
{
    if (args.empty())
        return mkConst(1);
    if (args.size() == 1)
        return args[0];
    return LoatMult::cache.from_cache(LoatExprSet(args.begin(), args.end()))->toPtr();
}

LoatExprPtr LoatExpression::mkTimes(const LoatExprPtr a, const LoatExprPtr b)
{
    return mkTimes(LoatExprVec{a, b});
}