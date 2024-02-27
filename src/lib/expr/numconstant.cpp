#include "arithexpr.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithVal, ArithVal::CacheHash, ArithVal::CacheEqual, Rational> ArithVal::cache;

ArithVal::ArithVal(const Rational &t): ArithExpr(arith::Kind::Constant), t(t) {}

bool ArithVal::CacheEqual::operator()(const std::tuple<Rational> &args1, const std::tuple<Rational> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithVal::CacheHash::operator()(const std::tuple<Rational> &args) const noexcept {
    return std::hash<Rational>{}(std::get<0>(args));
}

ExprPtr arith::mkConst(const Rational &r) {
    return ArithVal::cache.from_cache(r);
}

const Rational& ArithVal::getValue() const {
    return t;
}

std::optional<Int> ArithVal::intValue() const {
    if (mp::denominator(t) == 1) {
        return mp::numerator(t);
    } else if (mp::denominator(t) == -1) {
        return -mp::numerator(t);
    } else {
        return {};
    }
}

const Rational& ArithVal::operator*() const {
    return t;
}

const NumConstantPtr ArithVal::denominator() const {
    return *arith::mkConst(mp::denominator(t))->isRational();
}

const NumConstantPtr ArithVal::numerator() const {
    return *arith::mkConst(mp::numerator(t))->isRational();
}
