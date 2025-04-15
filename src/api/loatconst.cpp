#include "loatintexpr.hpp"
#include <boost/multiprecision/cpp_int.hpp>

ConsHash<LoatIntExpr, LoatIntConst, LoatIntConst::CacheHash, LoatIntConst::CacheEqual, Rational> LoatIntConst::cache;

LoatIntConst::LoatIntConst(const Rational &t) : LoatIntExpr(LoatIntExpression::Kind::Constant), m_value(t) {}

LoatIntConst::~LoatIntConst()
{
    cache.erase(m_value);
}

const Rational &LoatIntConst::operator*() const
{
    return m_value;
}

const Rational &LoatIntConst::getValue() const
{
    return m_value;
}

bool LoatIntConst::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept
{
    return std::get<0>(args1) == std::get<0>(args2);
}

size_t LoatIntConst::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept
{
    return std::hash<Rational>{}(std::get<0>(args));
}

LoatIntExprPtr LoatIntExpression::mkConst(const Rational &r)
{
    return LoatIntConst::cache.from_cache(r);
}

LoatIntExprPtr LoatIntExpression::mkConst(const Rational &&r)
{
    return mkConst(r);
}