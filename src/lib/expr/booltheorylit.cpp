#include <utility>

#include "boolexpr.hpp"
#include "theory.hpp"

ConsHash<BoolTheoryLit, Lit> BoolTheoryLit::cache;

bool BoolTheoryLit::CacheEqual::operator()(const std::tuple<Lit> &args1, const std::tuple<Lit> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolTheoryLit::CacheHash::operator()(const std::tuple<Lit> &args) const noexcept {
    return theory::hash(std::get<0>(args));
}

BoolTheoryLit::BoolTheoryLit(Lit lit) : lit(std::move(lit)) {}

Bools::Expr BoolTheoryLit::from_cache(const Lit &lit) {
    return cache.from_cache(lit);
}

bool BoolTheoryLit::isAnd() const {
    return false;
}

bool BoolTheoryLit::isOr() const {
    return false;
}

bool BoolTheoryLit::isTheoryLit() const {
    return true;
}

const Lit* BoolTheoryLit::getTheoryLit() const {
    return &lit;
}

BoolExprSet BoolTheoryLit::getChildren() const {
    return {};
}

Bools::Expr BoolTheoryLit::negation() const {
    return mkLit(theory::negate(lit));
}

bool BoolTheoryLit::forall(const std::function<bool(const Lit&)> &pred) const {
    return pred(lit);
}

BoolTheoryLit::~BoolTheoryLit() {
    cache.erase(lit);
}

bool BoolTheoryLit::isConjunction() const {
    return true;
}

LitSet BoolTheoryLit::universallyValidLits() const {
    LitSet res;
    res.insert(lit);
    return res;
}

void BoolTheoryLit::collectLits(LitSet &res) const {
    res.insert(lit);
}

size_t BoolTheoryLit::size() const {
    return 1;
}
