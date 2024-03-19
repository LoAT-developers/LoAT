#include "boolexpr.hpp"
#include "theory.hpp"

const Bools::Expr BoolExpr::from_cache(const BoolExprSet &children, ConcatOperator op) {
    return BoolJunction::from_cache(children, op);
}

const Bools::Expr BoolExpr::top() {
    const static auto res {from_cache(BoolExprSet{}, ConcatAnd)};
    return res;
}

const Bools::Expr BoolExpr::bot() {
    const static auto res {from_cache(BoolExprSet{}, ConcatOr)};
    return res;
}

const Bools::Expr BoolExpr::mkLit(const Lit &lit) {
    if (theory::isTriviallyTrue(lit)) {
        return top();
    } else if (theory::isTriviallyFalse(lit)) {
        return bot();
    } else {
        return BoolTheoryLit::from_cache(lit);
    }
}

Bounds BoolExpr::getBounds(const Arith::Var n) const {
    Bounds bounds;
    getBounds(n, bounds);
    return bounds;
}

Bools::Expr BoolExpr::linearize(const Arith::Var n) const {
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

Bools::Expr BoolExpr::toInfinity(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const ArithLit &rel) {
                    // TODO handle Eq / Neq
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

Bools::Expr BoolExpr::toMinusInfinity(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const ArithLit &rel) {
                    // TODO handle Eq / Neq
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

Bools::Expr BoolExpr::map(const std::function<Bools::Expr(const Lit&)> &f, std::unordered_map<Bools::Expr, Bools::Expr> &cache) const {
    const auto self {cpp::assume_not_null(shared_from_this())};
    const auto it {cache.find(self)};
    if (it != cache.end()) {
        return it->second;
    }
    std::optional<Bools::Expr> res;
    if (isAnd()) {
        bool changed = false;
        BoolExprSet newChildren;
        for (const auto &c: getChildren()) {
            const auto simp = c->map(f, cache);
            changed |= simp.get() != c.get();
            if (simp == bot()) {
                cache.emplace(self, bot());
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
            res = self;
        } else if (newChildren.empty()) {
            res = top();
        } else {
            for (const auto &c: newChildren) {
                if (c->isTheoryLit()) {
                    if (newChildren.contains(c->negation())) {
                        cache.emplace(self, bot());
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
                cache.emplace(self, top());
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
            res = self;
        } else if (newChildren.empty()) {
            res = bot();
        } else {
            for (const auto &c: newChildren) {
                if (c->isTheoryLit()) {
                    if (newChildren.contains(c->negation())) {
                        cache.emplace(self, top());
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
            res = self;
        } else {
            res = mapped;
        }
    }
    cache.emplace(self, *res);
    return *res;
}

Bools::Expr BoolExpr::map(const std::function<Bools::Expr(const Lit&)> &f) const {
    std::unordered_map<Bools::Expr, Bools::Expr> cache;
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

const Bools::Expr operator&&(const Bools::Expr a, const Bools::Expr b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkAnd(children);
}

const Bools::Expr operator||(const Bools::Expr a, const Bools::Expr b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkOr(children);
}

const Bools::Expr operator!(const Bools::Expr a) {
    return a->negation();
}

std::ostream& operator<<(std::ostream &s, const Bools::Expr e) {
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
        for (const auto &c: e->getChildren()) {
            if (first) {
                if (c->getTheoryLit()) {
                    s << c;
                } else {
                    s << "(" << c << ")";
                }
                first = false;
            } else {
                if (e->isAnd()) {
                    s << " /\\ ";
                } else {
                    s << " \\/ ";
                }
                if (c->getTheoryLit()) {
                    s << c;
                } else {
                    s << "(" << c << ")";
                }
            }
        }
    }
    return s;
}
