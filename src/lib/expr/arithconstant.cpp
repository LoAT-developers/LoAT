#include "arithexpr.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithConst, ArithConst::CacheHash, ArithConst::CacheEqual, Rational> ArithConst::cache;

ArithConst::ArithConst(const Rational &t): ArithExpr(arith::Kind::Constant), t(t) {}

bool ArithConst::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithConst::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept {
    return std::hash<Rational>{}(std::get<0>(args));
}

ArithExprPtr arith::mkConst(const Rational &r) {
    return ArithConst::cache.from_cache(r);
}

ArithExprPtr arith::mkConst(const Rational &&r) {
    return ArithConst::cache.from_cache(r);
}

const Rational& ArithConst::getValue() const {
    return t;
}

std::optional<Int> ArithConst::intValue() const {
    if (mp::denominator(t) == 1) {
        return mp::numerator(t);
    } else if (mp::denominator(t) == -1) {
        return -mp::numerator(t);
    } else {
        return {};
    }
}

const Rational& ArithConst::operator*() const {
    return t;
}

const ArithConstPtr ArithConst::denominator() const {
    const auto denom {arith::mkConst(mp::denominator(t))};
    return *denom->isRational();
}

const ArithConstPtr ArithConst::numerator() const {
    return *arith::mkConst(mp::numerator(t))->isRational();
}
