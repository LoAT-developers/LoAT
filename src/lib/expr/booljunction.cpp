#include "boolexpr.hpp"

ConsHash<BoolExpr, BoolJunction, BoolJunction::CacheHash, BoolJunction::CacheEqual, BoolExprSet, ConcatOperator> BoolJunction::cache{};

bool BoolJunction::CacheEqual::operator()(const std::tuple<BoolExprSet, ConcatOperator> &args1, const std::tuple<BoolExprSet, ConcatOperator> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolJunction::CacheHash::operator()(const std::tuple<BoolExprSet, ConcatOperator> &args) const noexcept {
    const auto &[children, op] {args};
    size_t hash {0};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    boost::hash_combine(hash, op);
    return hash;
}

Bools::Expr BoolJunction::from_cache(const BoolExprSet &children, const ConcatOperator op) {
    return cache.from_cache(children, op);
}

BoolJunction::BoolJunction(const BoolExprSet &children, const ConcatOperator op): children(children), op(op) { }

bool BoolJunction::isAnd() const {
    return op == ConcatAnd;
}

bool BoolJunction::isOr() const {
    return op == ConcatOr;
}

bool BoolJunction::isTheoryLit() const {
    return false;
}

const Lit* BoolJunction::getTheoryLit() const {
    return nullptr;
}

BoolExprSet BoolJunction::getChildren() const {
    return children;
}

Bools::Expr BoolJunction::negation() const {
    BoolExprSet newChildren;
    for (const auto &c: children) {
        newChildren.insert(c->negation());
    }
    switch (op) {
    case ConcatOr: return mkAnd(newChildren);
    case ConcatAnd: return mkOr(newChildren);
    }
    throw std::invalid_argument("unknown junction");
}

bool BoolJunction::forall(const std::function<bool(const Lit&)> &pred) const {
    for (const auto &e: children) {
        if (!e->forall(pred)) {
            return false;
        }
    }
    return true;
}

BoolJunction::~BoolJunction() {
    cache.erase(children, op);
}

bool BoolJunction::isConjunction() const {
    return isAnd() && std::ranges::all_of(children, [](const auto c){
               return c->isConjunction();
           });
}

LitSet BoolJunction::universallyValidLits() const {
    LitSet res;
    if (isAnd()) {
        for (const auto &c: children) {
            if (c->isTheoryLit()) {
                res.insert(*c->getTheoryLit());
            }
        }
    }
    return res;
}

void BoolJunction::collectLits(LitSet &res) const {
    for (const auto &c: children) {
        c->collectLits(res);
    }
}

size_t BoolJunction::size() const {
    size_t res = 1;
    for (const auto &c: children) {
        res += c->size();
    }
    return res;
}
