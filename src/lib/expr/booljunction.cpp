#include "boolexpr.hpp"

ConsHash<BoolExpr, BoolJunction, typename BoolJunction::CacheHash, typename BoolJunction::CacheEqual, BoolExprSet, ConcatOperator> BoolJunction::cache{};

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

Bools::Expr BoolJunction::from_cache(const BoolExprSet &children, ConcatOperator op) {
    return cache.from_cache(children, op);
}

BoolJunction::BoolJunction(const BoolExprSet &children, ConcatOperator op): children(children), op(op) { }

bool BoolJunction::isAnd() const {
    return op == ConcatAnd;
}

bool BoolJunction::isOr() const {
    return op == ConcatOr;
}

bool BoolJunction::isTheoryLit() const {
    return false;
}

const BoolJunction::Lit* BoolJunction::getTheoryLit() const {
    return nullptr;
}

BoolExprSet BoolJunction::getChildren() const {
    return children;
}

const Bools::Expr BoolJunction::negation() const {
    BoolExprSet newChildren;
    for (const auto &c: children) {
        newChildren.insert(c->negation());
    }
    switch (op) {
    case ConcatOr: return BoolExpr::mkAnd(newChildren);
    case ConcatAnd: return BoolExpr::mkOr(newChildren);
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

BoolJunction::~BoolJunction() {}

bool BoolJunction::isConjunction() const {
    return isAnd() && std::all_of(children.begin(), children.end(), [](const auto c){
               return c->isConjunction();
           });
}

BoolJunction::LitSet BoolJunction::universallyValidLits() const {
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

void BoolJunction::getBounds(const Arith::Var n, Bounds &res) const {
    if (isAnd()) {
        for (const auto &c: children) {
            c->getBounds(n, res);
        }
    } else if (isOr()) {
        bool first = true;
        Bounds intersection;
        for (const auto &c: children) {
            Bounds current;
            if (first) {
                c->getBounds(n, intersection);
                first = false;
            } else {
                if (intersection.lowerBounds.empty() && intersection.upperBounds.empty()) {
                    return;
                }
                const auto current {c->getBounds(n)};
                for (auto it = intersection.lowerBounds.begin(); it != intersection.lowerBounds.end();) {
                    if (!current.lowerBounds.contains(*it)) {
                        it = intersection.lowerBounds.erase(it);
                    } else {
                        ++it;
                    }
                }
                for (auto it = intersection.upperBounds.begin(); it != intersection.upperBounds.end();) {
                    if (!current.upperBounds.contains(*it)) {
                        it = intersection.upperBounds.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
        res.lowerBounds.insert(intersection.lowerBounds.begin(), intersection.lowerBounds.end());
        res.upperBounds.insert(intersection.upperBounds.begin(), intersection.upperBounds.end());
    }
}