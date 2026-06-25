#include <utility>

#include "arithexpr.hpp"

ConsHash<ArithMod, ArithExprPtr, ArithExprPtr> ArithMod::cache;

ArithMod::ArithMod(ArithExprPtr lhs, ArithExprPtr rhs): ArithExpr(arith::Kind::Mod), lhs(std::move(lhs)), rhs(std::move(rhs)) {}

ArithMod::~ArithMod() {
    cache.erase(lhs, rhs);
}

bool ArithMod::CacheEqual::operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args1, const std::tuple<ArithExprPtr, ArithExprPtr> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithMod::CacheHash::operator()(const std::tuple<ArithExprPtr, ArithExprPtr> &args) const noexcept {
    size_t hash {23};
    boost::hash_combine(hash, std::get<0>(args));
    boost::hash_combine(hash, std::get<1>(args));
    return hash;
}

ArithExprPtr arith::mkMod(ArithExprPtr x, ArithExprPtr y) {
    if (y->is(0)) {
        throw std::invalid_argument("mod 0");
    }
    if (y->isInt() && y->isNegated()) {
        y = -y;
    }
    if (x->is(0) || y->is(1)) {
        return zero();
    }
    if (const auto c2 {y->isInt()}) {
        const auto eval = [](const Int &c1, const Int &c2) -> Int {
            if (auto mod {mp::abs(c1) % c2}; mod == 0 || c1 >= 0) {
                return mod;
            } else {
                return c2 - mod;
            }
        };
        if (const auto c1 {x->isInt()}) {
            // both arguments are integers --> evaluate
            return mkConst(eval(*c1, *c2));
        } else if (x->isMult()) {
            const auto c1 {x->getConstantFactor()};
            if (const auto mod {eval(mp::numerator(c1), *c2)}; mp::denominator(c1) == 1 && mod != c1) {
                x = x->divide(c1) * mkConst(mod);
                return mkMod(x, y);
            }
        } else if (const auto add {x->isAdd()}) {
            std::vector<ArithExprPtr> addends;
            auto changed {false};
            for (const auto &a: (*add)->getArgs()) {
                const auto c1 {a->getConstantFactor()};
                if (const auto mod {eval(mp::numerator(c1), *c2)}; mp::denominator(c1) == 1 && mod != c1) {
                    addends.push_back(a->divide(c1) * mkConst(mod));
                    changed = true;
                } else {
                    addends.push_back(a);
                }
            }
            if (changed) {
                return mkMod(mkPlus(std::move(addends)), y);
            }
        }
    }
    return ArithMod::cache.from_cache(x, y);
}

ArithExprPtr ArithMod::getLhs() const {
    return lhs;
}

ArithExprPtr ArithMod::getRhs() const {
    return rhs;
}
