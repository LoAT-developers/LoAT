#include <utility>

#include "arithexpr.hpp"

ConsHash<ArithConst, Rational> ArithConst::cache;

ArithConst::ArithConst(Rational t): ArithExpr(arith::Kind::Constant), t(std::move(t)) {}

ArithConst::~ArithConst() {
    cache.erase(t);
}

bool ArithConst::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithConst::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept {
    return hasher(std::get<0>(args));
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
    }
    if (mp::denominator(t) == -1) {
        return -mp::numerator(t);
    }
    return {};
}

const Rational& ArithConst::operator*() const {
    return t;
}

ArithConstPtr ArithConst::denominator() const {
    const auto denom {arith::mkConst(mp::denominator(t))};
    return *denom->isRational();
}

ArithConstPtr ArithConst::numerator() const {
    return *arith::mkConst(mp::numerator(t))->isRational();
}
