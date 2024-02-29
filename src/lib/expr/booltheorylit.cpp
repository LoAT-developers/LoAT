#include "boolexpr.hpp"
#include "literal.hpp"

ConsHash<BoolExpression, BoolTheoryLit, typename BoolTheoryLit::CacheHash, typename BoolTheoryLit::CacheEqual, typename BoolTheoryLit::Lit> BoolTheoryLit::cache;

bool BoolTheoryLit::CacheEqual::operator()(const std::tuple<Lit> &args1, const std::tuple<Lit> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolTheoryLit::CacheHash::operator()(const std::tuple<Lit> &args) const noexcept {
    return theories::hash(std::get<0>(args));
}

BoolTheoryLit::BoolTheoryLit(const Lit &lit) : lit(lit) {}

BExpr BoolTheoryLit::from_cache(const Lit &lit) {
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

const BoolTheoryLit::Lit* BoolTheoryLit::getTheoryLit() const {
    return &lit;
}

BoolExpressionSet BoolTheoryLit::getChildren() const {
    return {};
}

const BExpr BoolTheoryLit::negation() const {
    return BoolExpression::mkLit(theories::negate(lit));
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

BoolTheoryLit::LS BoolTheoryLit::universallyValidLits() const {
    LS res;
    res.insert(lit);
    return res;
}

void BoolTheoryLit::collectLits(LS &res) const {
    res.insert(lit);
}

size_t BoolTheoryLit::size() const {
    return 1;
}

void BoolTheoryLit::getBounds(const ArithVarPtr var, Bounds &res) const {
    if (std::holds_alternative<ArithLit>(lit)) {
        std::get<ArithLit>(lit).getBounds(var, res);
    }
}
