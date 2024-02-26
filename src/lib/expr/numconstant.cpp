#include "numexpression.hpp"

#include <purrs.hh>

NumConstant::NumConstant(const Rational &t): Expr(ne::Kind::Constant), t(t) {}

bool NumConstant::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept {
    return args1 == args2;
}

size_t NumConstant::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept {
    return std::hash<Rational>{}(std::get<0>(args));
}

ExprPtr num_expression::buildConstant(const Rational &r) {
    return NumConstant::cache.from_cache(r);
}

const Rational& NumConstant::getValue() const {
    return t;
}
