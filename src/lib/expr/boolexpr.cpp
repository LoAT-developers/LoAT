#include "boolexpr.hpp"
#include "theory.hpp"

const BExpr BoolExpression::from_cache(const BES &children, ConcatOperator op) {
    return BoolJunction::from_cache(children, op);
}

const BExpr BoolExpression::top() {
    const static auto res {from_cache(BoolExpressionSet{}, ConcatAnd)};
    return res;
}

const BExpr BoolExpression::bot() {
    const static auto res {from_cache(BoolExpressionSet{}, ConcatOr)};
    return res;
}

const BExpr BoolExpression::mkLit(const Lit &lit) {
    return BoolTheoryLit::from_cache(lit);
}

bool BoolExpression::isTriviallyTrue() const {
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

bool BoolExpression::isTriviallyFalse() const {
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

Bounds BoolExpression::getBounds(const ArithVarPtr n) const {
    Bounds bounds;
    getBounds(n, bounds);
    return bounds;
}

BExpr BoolExpression::linearize(const ArithVarPtr n) const {
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

BExpr BoolExpression::toInfinity(const ArithVarPtr n) const {
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

BExpr BoolExpression::toMinusInfinity(const ArithVarPtr n) const {
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

void BoolExpression::iter(const std::function<void(const Lit&)> &f) const {
    if (isTheoryLit()) {
        f(*getTheoryLit());
    } else {
        for (const auto &c: getChildren()) {
            c->iter(f);
        }
    }
}

BExpr BoolExpression::map(const std::function<BE(const Lit&)> &f, std::unordered_map<BE, BE> &cache) const {
    const auto it {cache.find(this->shared_from_this())};
    if (it != cache.end()) {
        return it->second;
    }
    BE res;
    if (isAnd()) {
        bool changed = false;
        BoolExpressionSet newChildren;
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
        BoolExpressionSet newChildren;
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

BExpr BoolExpression::map(const std::function<BE(const Lit&)> &f) const {
    std::unordered_map<BE, BE> cache;
    return map(f, cache);
}

void BoolExpression::collectVars(VS &vars) const {
    iter([&](const auto &lit) {
        theory::collectVars(lit, vars);
    });
}

BoolExpression::VS BoolExpression::vars() const {
    VS res;
    collectVars(res);
    return res;
}

BExpr BoolExpression::simplify() const {
    return map([](const Lit &lit) -> BE {
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

BoolExpression::~BoolExpression() {};

BoolExpression::LS BoolExpression::lits() const {
    LS res;
    collectLits(res);
    return res;
}

bool BoolExpression::isLinear() const {
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

bool BoolExpression::isPoly() const {
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

const BExpr operator&&(const BExpr a, const BExpr b) {
    const BoolExpressionSet children{a, b};
    return BoolExpression::mkAnd(children);
}

const BExpr operator||(const BExpr a, const BExpr b) {
    const BoolExpressionSet children{a, b};
    return BoolExpression::mkOr(children);
}

const BExpr operator!(const BExpr a) {
    return a->negation();
}

std::ostream& operator<<(std::ostream &s, const BExpr e) {
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
