#include "loatexpression.hpp"

#include <sstream>
#include <boost/functional/hash.hpp>

// ==============================
// LoatConstant Implementation
// ==============================

LoatConstant::LoatConstant(int v)
    : LoatExpression(LoatKind::Constant), value(v) {}

LoatConstant::~LoatConstant() = default;

int LoatConstant::getValue() const
{
    return value;
}

std::string LoatConstant::toString() const
{
    return std::to_string(value);
}

bool LoatConstant::CacheEqual::operator()(const std::tuple<int> &a, const std::tuple<int> &b) const noexcept
{
    return std::get<0>(a) == std::get<0>(b);
}

size_t LoatConstant::CacheHash::operator()(const std::tuple<int> &a) const noexcept
{
    return std::hash<int>{}(std::get<0>(a));
}

ConsHash<LoatExpression, LoatConstant, LoatConstant::CacheHash, LoatConstant::CacheEqual, int>
    LoatConstant::cache;

// ==============================
// LoatPlus Implementation
// ==============================

LoatPlus::LoatPlus(const LoatExprVec &arguments)
    : LoatExpression(LoatKind::Plus), args(arguments) {}

LoatPlus::~LoatPlus() = default;

const LoatExprVec &LoatPlus::getArgs() const
{
    return args;
}

std::string LoatPlus::toString() const
{
    std::ostringstream out;
    out << "(";
    for (size_t i = 0; i < args.size(); ++i)
    {
        out << args[i]->toString();
        if (i != args.size() - 1)
        {
            out << " + ";
        }
    }
    out << ")";
    return out.str();
}

bool LoatPlus::CacheEqual::operator()(const std::tuple<LoatExprVec> &a, const std::tuple<LoatExprVec> &b) const noexcept
{
    return std::get<0>(a) == std::get<0>(b);
}

size_t LoatPlus::CacheHash::operator()(const std::tuple<LoatExprVec> &a) const noexcept
{
    size_t hash = 0;
    const auto &vec = std::get<0>(a);
    boost::hash_range(hash, vec.begin(), vec.end());
    return hash;
}

ConsHash<LoatExpression, LoatPlus, LoatPlus::CacheHash, LoatPlus::CacheEqual, LoatExprVec>
    LoatPlus::cache;

// ==============================
// Factory Functions
// ==============================

LoatExprPtr makeConst(int value)
{
    return LoatConstant::cache.from_cache(value)->toPtr();
}

LoatExprPtr makePlus(const LoatExprPtr &a, const LoatExprPtr &b)
{
    return makePlus(LoatExprVec{a, b});
}

LoatExprPtr makePlus(const LoatExprVec &args)
{
    return LoatPlus::cache.from_cache(args)->toPtr();
}