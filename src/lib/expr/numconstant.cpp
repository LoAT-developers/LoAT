#include "numexpression.hpp"

#include <purrs.hh>

ConsHash<Expr, NumConstant, NumConstant::CacheHash, NumConstant::CacheEqual, Rational> NumConstant::cache;

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

std::optional<Int> NumConstant::intValue() const {
    if (mp::denominator(t) == 1) {
        return mp::numerator(t);
    } else if (mp::denominator(t) == -1) {
        return -mp::numerator(t);
    } else {
        return {};
    }
}

const Rational& NumConstant::operator*() const {
    return t;
}

const NumConstantPtr NumConstant::denominator() const {
    return *ne::buildConstant(mp::denominator(t))->isRational();
}

const NumConstantPtr NumConstant::numerator() const {
    return *ne::buildConstant(mp::numerator(t))->isRational();
}
