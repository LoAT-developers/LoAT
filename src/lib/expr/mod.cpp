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
    if (lhs->is(0) || rhs->is(1)) {
        return arith::mkConst(0);
    }
    if (const auto c2 {rhs->isInt()}) {
        const auto eval = [](const Int &c1, const Int &c2) -> Int {
            const Int mod {mp::abs(c1) % c2};
            if (mod == 0 || c1 >= 0) {
                return mod;
            } else {
                return c2 - mod;
            }
        };
        if (const auto c1 {lhs->isInt()}) {
            // both arguments are integers --> evaluate
            return arith::mkConst(eval(*c1, *c2));
        } else if (lhs->isMult()) {
            const auto c1 {lhs->getConstantFactor()};
            const auto mod {eval(mp::numerator(c1), *c2)};
            if (mp::denominator(c1) == 1 && mod != c1) {
                lhs = lhs->divide(c1) * arith::mkConst(mod);
                return mkMod(lhs, rhs);
            }
        } else if (const auto add {lhs->isAdd()}) {
            std::vector<ArithExprPtr> addends;
            auto changed {false};
            for (const auto &a: (*add)->getArgs()) {
                const auto c1 {a->getConstantFactor()};
                const auto mod {eval(mp::numerator(c1), *c2)};
                if (mp::denominator(c1) == 1 && mod != c1) {
                    addends.push_back(a->divide(c1) * arith::mkConst(mod));
                    changed = true;
                } else {
                    addends.push_back(a);
                }
            }
            if (changed) {
                return mkMod(arith::mkPlus(std::move(addends)), rhs);
            }
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
