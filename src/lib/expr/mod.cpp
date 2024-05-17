#include "arithexpr.hpp"

ConsHash<ArithExpr, ArithMod, ArithMod::CacheHash, ArithMod::CacheEqual, ArithExprPtr, ArithExprPtr> ArithMod::cache;

ArithMod::ArithMod(const ArithExprPtr lhs, ArithExprPtr rhs): ArithExpr(arith::Kind::Mod), lhs(lhs), rhs(rhs) {}

bool ArithMod::CacheEqual::operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args1, const std::tuple<ArithExprPtr, ArithExprPtr> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithMod::CacheHash::operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args) const noexcept {
    size_t hash {23};
    const auto lhs {std::get<0>(args)};
    const auto rhs {std::get<1>(args)};
    boost::hash_combine(hash, lhs);
    boost::hash_combine(hash, rhs);
    return hash;
}

ArithExprPtr arith::mkMod(ArithExprPtr lhs, ArithExprPtr rhs) {
    if (rhs->is(0)) {
        throw std::invalid_argument("mod 0");
    }
    if (rhs->isInt() && rhs->isNegated()) {
        rhs = -rhs;
    }
    if (rhs->is(1)) {
        return arith::mkConst(0);
    }
    if (const auto c2 {rhs->isInt()}) {
        if (const auto c1 {lhs->isInt()}) {
            const auto mod {mp::abs(*c1) % *c2};
            if (mod == 0 || *c1 >= 0) {
                return arith::mkConst(mod);
            } else {
                return arith::mkConst(*c2 - mod);
            }
        }
        const auto c1 {lhs->getConstantFactor()};
        if (mp::denominator(c1) == 1 && mp::numerator(c1) >= *c2) {
            const Int div {mp::numerator(c1) / *c2};
            lhs = lhs - arith::mkConst(div) * rhs;
        }
    }
    return ArithMod::cache.from_cache(lhs, rhs);
}

const ArithExprPtr ArithMod::getLhs() const {
    return lhs;
}

const ArithExprPtr ArithMod::getRhs() const {
    return rhs;
}
