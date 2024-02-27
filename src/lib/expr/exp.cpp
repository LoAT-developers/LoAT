#include "arithexpr.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithExp, ArithExp::CacheHash, ArithExp::CacheEqual, ExprPtr, ExprPtr> ArithExp::cache;

ArithExp::ArithExp(const ExprPtr base, const ExprPtr exponent): ArithExpr(arith::Kind::Exp), base(base), exponent(exponent) {}

bool ArithExp::CacheEqual::operator()(const std::tuple<ExprPtr, ExprPtr> &args1, const std::tuple<ExprPtr, ExprPtr> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithExp::CacheHash::operator()(const std::tuple<ExprPtr, ExprPtr> &args) const noexcept {
    size_t hash {0};
    boost::hash_combine(hash, std::get<0>(args));
    boost::hash_combine(hash, std::get<1>(args));
    return hash;
}

ExprPtr arith::mkExp(const ExprPtr base, const ExprPtr exponent) {
    const auto b_val {base->isInt()};
    const auto e_val {exponent->isInt()};
    if (b_val && e_val) {
        return mkConst(mp::pow(*b_val, std::stoi(e_val->str())));
    }
    if (exponent->is(0) || base->is(1)) {
        return mkConst(1);
    }
    if (exponent->is(1)) {
        return base;
    }
    auto b {base->isPow()};
    if (b) {
        return mkExp((*b)->getBase(), (*b)->getExponent() * exponent);
    }
    if (!base->isIntegral() || !exponent->isIntegral()) {
        throw std::invalid_argument("attempt to create exp with non-int arguments");
    }
    return ArithExp::cache.from_cache(base, exponent);
}

ExprPtr ArithExp::getBase() const {
    return base;
}

ExprPtr ArithExp::getExponent() const {
    return exponent;
}
