#include "loatexpression.hpp"
#include <boost/multiprecision/cpp_int.hpp>

ConsHash<LoatExpr, LoatConst, LoatConst::CacheHash, LoatConst::CacheEqual, Rational> LoatConst::cache;

LoatConst::LoatConst(const Rational &t) : LoatExpr(LoatExpression::Kind::Constant), m_value(t) {}

LoatConst::~LoatConst()
{
    cache.erase(m_value);
}

const Rational &LoatConst::operator*() const
{
    return m_value;
}

const Rational &LoatConst::getValue() const
{
    return m_value;
}

bool LoatConst::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept
{
    return std::get<0>(args1) == std::get<0>(args2);
}

size_t LoatConst::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept
{
    return std::hash<Rational>{}(std::get<0>(args));
}

LoatExprPtr LoatExpression::mkConst(const Rational &r)
{
    return LoatConst::cache.from_cache(r);
}

LoatExprPtr LoatExpression::mkConst(const Rational &&r)
{
    return mkConst(r);
}