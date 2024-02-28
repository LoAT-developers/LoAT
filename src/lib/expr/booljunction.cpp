#include "boolexpr.hpp"

ConsHash<BoolExpression, BoolJunction, typename BoolJunction::CacheHash, typename BoolJunction::CacheEqual, linked_hash_set<BExpr>, ConcatOperator> BoolJunction::cache{};

bool BoolJunction::CacheEqual::operator()(const std::tuple<BES, ConcatOperator> &args1, const std::tuple<BES, ConcatOperator> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolJunction::CacheHash::operator()(const std::tuple<BES, ConcatOperator> &args) const noexcept {
    const auto &[children, op] {args};
    size_t hash {0};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    boost::hash_combine(hash, op);
    return hash;
}

BExpr BoolJunction::from_cache(const BES &children, ConcatOperator op) {
    return cache.from_cache(children, op);
}

BoolJunction::BoolJunction(const BES &children, ConcatOperator op): children(children), op(op) { }

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

BoolExpressionSet BoolJunction::getChildren() const {
    return children;
}

const BExpr BoolJunction::negation() const {
    BES newChildren;
    for (const BE &c: children) {
        newChildren.insert(c->negation());
    }
    switch (op) {
    case ConcatOr: return BoolExpression::mkAnd(newChildren);
    case ConcatAnd: return BoolExpression::mkOr(newChildren);
    }
    throw std::invalid_argument("unknown junction");
}

bool BoolJunction::forall(const std::function<bool(const Lit&)> &pred) const {
    for (const BE &e: children) {
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
    return isAnd() && std::all_of(children.begin(), children.end(), [](const BE c){
               return c->isConjunction();
           });
}

BoolJunction::LS BoolJunction::universallyValidLits() const {
    LS res;
    if (isAnd()) {
        for (const BE &c: children) {
            if (c->isTheoryLit()) {
                res.insert(*c->getTheoryLit());
            }
        }
    }
    return res;
}

void BoolJunction::collectLits(LS &res) const {
    for (const BE &c: children) {
        c->collectLits(res);
    }
}

size_t BoolJunction::size() const {
    size_t res = 1;
    for (const BE &c: children) {
        res += c->size();
    }
    return res;
}

void BoolJunction::getBounds(const ArithVarPtr n, Bounds &res) const {
    if (isAnd()) {
        for (const auto &c: children) {
            c->getBounds(n, res);
        }
    } else if (isOr()) {
        bool first = true;
        for (const auto &c: children) {
            if (first) {
                c->getBounds(n, res);
                first = false;
            } else {
                Bounds cres = res;
                c->getBounds(n, cres);
                for (auto it = res.lowerBounds.begin(); it != res.lowerBounds.end();) {
                    if (!cres.lowerBounds.contains(*it)) {
                        it = res.lowerBounds.erase(it);
                    } else {
                        ++it;
                    }
                }
                for (auto it = res.upperBounds.begin(); it != res.upperBounds.end();) {
                    if (!cres.upperBounds.contains(*it)) {
                        it = res.upperBounds.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
    }
}
