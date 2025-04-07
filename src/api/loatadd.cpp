#include "loatexpression.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

ConsHash<LoatExpr, LoatAdd, LoatAdd::CacheHash, LoatAdd::CacheEqual, LoatExprSet> LoatAdd::cache;

LoatAdd::LoatAdd(const LoatExprSet &args) : LoatExpr(LoatExpression::Kind::Plus), m_args(args) {}

LoatAdd::~LoatAdd()
{
    cache.erase(m_args);
}

bool LoatAdd::CacheEqual::operator()(const std::tuple<LoatExprSet> &args1, const std::tuple<LoatExprSet> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatAdd::CacheHash::operator()(const std::tuple<LoatExprSet> &args) const noexcept
{
    size_t hash{42};
    const auto &children{std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatExprPtr LoatExpression::mkPlus(LoatExprPtr fst, LoatExprPtr snd)
{
    return mkPlus({fst, snd});
}

LoatExprPtr LoatExpression::mkPlus(std::vector<LoatExprPtr> &&args)
{
    if (args.empty())
    {
        return mkConst(0);
    }
    if (args.size() == 1)
    {
        return args[0];
    }
    const LoatExprSet arg_set{args.begin(), args.end()};
    return LoatAdd::cache.from_cache(std::move(arg_set));
}

const LoatExprSet &LoatAdd::getArgs() const
{
    return m_args;
}
