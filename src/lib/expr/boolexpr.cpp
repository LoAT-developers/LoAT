#include "boolexpr.hpp"
#include "theory.hpp"

const BoolExprPtr BoolExpr::from_cache(const BoolExprSet &children, ConcatOperator op) {
    return BoolJunction::from_cache(children, op);
}

const BoolExprPtr BoolExpr::top() {
    const static auto res {from_cache(BoolExprSet{}, ConcatAnd)};
    return res;
}

const BoolExprPtr BoolExpr::bot() {
    const static auto res {from_cache(BoolExprSet{}, ConcatOr)};
    return res;
}

const BoolExprPtr BoolExpr::mkLit(const Lit &lit) {
    return BoolTheoryLit::from_cache(lit);
}

bool BoolExpr::isTriviallyTrue() const {
    if (isTheoryLit()) {
        return theory::isTriviallyTrue(*getTheoryLit());
    } else {
        const auto children = getChildren();
        if (isAnd()) {
            return std::all_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyTrue();});
        } else if (isOr()) {
            return std::any_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyTrue();});
        } else {
            throw std::logic_error("unknown junctor");
        }
    }
}

bool BoolExpr::isTriviallyFalse() const {
    if (isTheoryLit()) {
        return theory::isTriviallyFalse(*getTheoryLit());
    } else {
        const auto children = getChildren();
        if (isAnd()) {
            return std::any_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyFalse();});
        } else if (isOr()) {
            return std::all_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyFalse();});
        } else {
            throw std::logic_error("unknown junctor");
        }
    }
}

Bounds BoolExpr::getBounds(const Arith::Var n) const {
    Bounds bounds;
    getBounds(n, bounds);
    return bounds;
}

BoolExprPtr BoolExpr::linearize(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const ArithLit &rel) {
                    const auto ex {rel.lhs()};
                    const auto d {ex->isPoly(n)};
                    if (d == 0) {
                        return mkLit(rel);
                    } else if (d == 1 && (*ex->coeff(n))->isRational()) {
                        return mkLit(rel);
                    } else {
                        return top();
                    }
                },
                [](const auto &lit) {
                    return mkLit(lit);
                }
            }, lit);
    });
}

BoolExprPtr BoolExpr::toInfinity(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const ArithLit &rel) {
                    assert(rel.isLinear({{n}}));
                    if (!rel.has(n)) {
                        return mkLit(rel);
                    }
                    const auto ex {rel.lhs()};
                    if (***(*ex->coeff(n))->isRational() > 0) {
                        return top();
                    } else {
                        return bot();
                    }
                },
                [](const auto &lit) {
                    return mkLit(lit);
                }
            }, lit);
    });
}

BoolExprPtr BoolExpr::toMinusInfinity(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const ArithLit &rel) {
                    assert(rel.isLinear({{n}}));
                    if (!rel.has(n)) {
                        return mkLit(rel);
                    }
                    const auto ex {rel.lhs()};
                    if (***(*ex->coeff(n))->isRational() < 0) {
                        return top();
                    } else {
                        return bot();
                    }
                },
                [](const auto &lit) {
                    return mkLit(lit);
                }
            }, lit);
    });
}

void BoolExpr::iter(const std::function<void(const Lit&)> &f) const {
    if (isTheoryLit()) {
        f(*getTheoryLit());
    } else {
        for (const auto &c: getChildren()) {
            c->iter(f);
        }
    }
}

BoolExprPtr BoolExpr::map(const std::function<BoolExprPtr(const Lit&)> &f, std::unordered_map<BoolExprPtr, BoolExprPtr> &cache) const {
    const auto it {cache.find(this->shared_from_this())};
    if (it != cache.end()) {
        return it->second;
    }
    BoolExprPtr res;
    if (isAnd()) {
        bool changed = false;
        BoolExprSet newChildren;
        for (const auto &c: getChildren()) {
            const auto simp = c->map(f, cache);
            changed |= simp.get() != c.get();
            if (simp == bot()) {
                cache.emplace(this->shared_from_this(), bot());
                return bot();
            } else {
                if (simp != top()) {
                    if (simp->isAnd()) {
                        const auto children = simp->getChildren();
                        newChildren.insert(children.begin(), children.end());
                    } else {
                        newChildren.insert(simp);
                    }
                }
            }
        }
        if (!changed) {
            res = this->shared_from_this();
        } else if (newChildren.empty()) {
            res = top();
        } else {
            for (const auto &c: newChildren) {
                if (c->isTheoryLit()) {
                    if (newChildren.contains(c->negation())) {
                        cache.emplace(this->shared_from_this(), bot());
                        return bot();
                    }
                }
            }
            res = mkAnd(newChildren);
        }
    } else if (isOr()) {
        BoolExprSet newChildren;
        bool changed = false;
        for (const auto &c: getChildren()) {
            const auto simp = c->map(f, cache);
            changed |= simp.get() != c.get();
            if (simp == top()) {
                cache.emplace(this->shared_from_this(), top());
                return top();
            } else {
                if (simp != bot()) {
                    if (simp->isOr()) {
                        const auto children = simp->getChildren();
                        newChildren.insert(children.begin(), children.end());
                    } else {
                        newChildren.insert(simp);
                    }
                }
            }
        }
        if (!changed) {
            res = this->shared_from_this();
        } else if (newChildren.empty()) {
            res = bot();
        } else {
            for (const auto &c: newChildren) {
                if (c->isTheoryLit()) {
                    if (newChildren.contains(c->negation())) {
                        cache.emplace(this->shared_from_this(), top());
                        return top();
                    }
                }
            }
            res = mkOr(newChildren);
        }
    } else if (isTheoryLit()) {
        const auto lit = *getTheoryLit();
        const auto mapped = f(lit);
        const auto mappedLit = mapped->getTheoryLit();
        if (mappedLit && *mappedLit == lit) {
            res = this->shared_from_this();
        } else {
            res = mapped;
        }
    }
    cache.emplace(this->shared_from_this(), res);
    return res;
}

BoolExprPtr BoolExpr::map(const std::function<BoolExprPtr(const Lit&)> &f) const {
    std::unordered_map<BoolExprPtr, BoolExprPtr> cache;
    return map(f, cache);
}

void BoolExpr::collectVars(VarSet &vars) const {
    iter([&](const auto &lit) {
        theory::collectVars(lit, vars);
    });
}

BoolExpr::VarSet BoolExpr::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

BoolExprPtr BoolExpr::simplify() const {
    return map([](const Lit &lit) -> BoolExprPtr {
        if (std::holds_alternative<ArithLit>(lit)) {
            const auto &rel = std::get<ArithLit>(lit);
            if (rel.isTriviallyTrue()) {
                return top();
            } else if (rel.isTriviallyFalse()) {
                return bot();
            }
        }
        return mkLit(lit);
    });
}

BoolExpr::~BoolExpr() {};

BoolExpr::LitSet BoolExpr::lits() const {
    LitSet res;
    collectLits(res);
    return res;
}

bool BoolExpr::isLinear() const {
    return forall([](const auto &lit) {
        return std::visit(
            Overload {
                [](const ArithLit &lit) {
                    return lit.isLinear();
                },
                [](const BoolLit&) {
                    return true;
                }
            }, lit);
    });
}

bool BoolExpr::isPoly() const {
    return forall([](const auto &lit) {
        return std::visit(
            Overload {
                [](const ArithLit &lit) {
                    return lit.isPoly();
                },
                [](const BoolLit&) {
                    return true;
                }
            }, lit);
    });
}

const BoolExprPtr operator&&(const BoolExprPtr a, const BoolExprPtr b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkAnd(children);
}

const BoolExprPtr operator||(const BoolExprPtr a, const BoolExprPtr b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkOr(children);
}

const BoolExprPtr operator!(const BoolExprPtr a) {
    return a->negation();
}

std::ostream& operator<<(std::ostream &s, const BoolExprPtr e) {
    if (e->isTheoryLit()) {
        std::visit([&s](const auto lit){s << lit;}, *e->getTheoryLit());
    } else if (e->getChildren().empty()) {
        if (e->isAnd()) {
            s << "T";
        } else {
            s << "_|_";
        }
    } else {
        bool first = true;
        s << "(";
        for (const auto &c: e->getChildren()) {
            if (first) {
                s << c;
                first = false;
            } else {
                if (e->isAnd()) {
                    s << " /\\ ";
                } else {
                    s << " \\/ ";
                }
                s << c;
            }
        }
        s << ")";
    }
    return s;
}
