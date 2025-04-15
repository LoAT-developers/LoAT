#include "loatintexpr.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

ConsHash<LoatIntExpr, LoatIntAdd, LoatIntAdd::CacheHash, LoatIntAdd::CacheEqual, LoatIntExprSet> LoatIntAdd::cache;

LoatIntAdd::LoatIntAdd(const LoatIntExprSet &args) : LoatIntExpr(LoatIntExpression::Kind::Plus), m_args(args) {}

LoatIntAdd::~LoatIntAdd()
{
    cache.erase(m_args);
}

bool LoatIntAdd::CacheEqual::operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatIntAdd::CacheHash::operator()(const std::tuple<LoatIntExprSet> &args) const noexcept
{
    size_t hash{42};
    const auto &children{std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

LoatIntExprPtr LoatIntExpression::mkPlus(LoatIntExprPtr fst, LoatIntExprPtr snd)
{
    return mkPlus({fst, snd});
}

LoatIntExprPtr LoatIntExpression::mkPlus(std::vector<LoatIntExprPtr> &&args)
{
    if (args.empty())
    {
        return mkConst(0);
    }
    if (args.size() == 1)
    {
        return args[0];
    }
    const LoatIntExprSet arg_set{args.begin(), args.end()};
    return LoatIntAdd::cache.from_cache(std::move(arg_set));
}

const LoatIntExprSet &LoatIntAdd::getArgs() const
{
    return m_args;
}
