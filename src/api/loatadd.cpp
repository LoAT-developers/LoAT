#include "loatintexpr.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

ConsHash<LoatIntExpr, LoatAdd, LoatAdd::CacheHash, LoatAdd::CacheEqual, LoatIntExprSet> LoatAdd::cache;

LoatAdd::LoatAdd(const LoatIntExprSet &args) : LoatIntExpr(LoatIntExpression::Kind::Plus), m_args(args) {}

LoatAdd::~LoatAdd()
{
    cache.erase(m_args);
}

bool LoatAdd::CacheEqual::operator()(const std::tuple<LoatIntExprSet> &args1, const std::tuple<LoatIntExprSet> &args2) const noexcept
{
    return args1 == args2;
}

size_t LoatAdd::CacheHash::operator()(const std::tuple<LoatIntExprSet> &args) const noexcept
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
    return LoatAdd::cache.from_cache(std::move(arg_set));
}

const LoatIntExprSet &LoatAdd::getArgs() const
{
    return m_args;
}
