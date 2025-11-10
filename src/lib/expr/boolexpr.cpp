#include "boolexpr.hpp"
#include "theory.hpp"
#include "conjunction.hpp"
#include "renaming.hpp"
#include "subs.hpp"
#include "model.hpp"

Bools::Expr BoolExpr::from_cache(const BoolExprSet &children, const ConcatOperator op) {
    return BoolJunction::from_cache(children, op);
}

template <class Children>
Bools::Expr BoolExpr::build(const Children& lits, const ConcatOperator op) {
    using Elem = std::remove_cvref_t<decltype(*lits.begin())>;
    static_assert(std::is_same_v<Elem, Bools::Expr> || std::is_constructible_v<Lit, Elem>);
    BoolExprSet children;
    if constexpr (std::is_same_v<Elem, Bools::Expr>) {
        if (op == ConcatAnd && std::find(lits.begin(), lits.end(), bot()) != lits.end()) {
            return bot();
        }
        if (op == ConcatOr && std::find(lits.begin(), lits.end(), top()) != lits.end()) {
            return top();
        }
        for (const auto &x: lits) {
            if (op == ConcatAnd && x->isAnd() || op == ConcatOr && x->isOr()) {
                const auto cs {x->getChildren()};
                children.insert(cs.begin(), cs.end());
            } else {
                children.insert(x);
            }
        }
        switch (children.size()) {
        case 0:
            return op == ConcatAnd ? top() : bot();
        case 1:
            return *children.begin();
        default:
            return from_cache(children, op);
        }
    } else {
        for (const auto &lit : lits) {
            children.insert(mkLit(lit));
        }
        return build(children, op);
    }
}

Bools::Expr BoolExpr::top() {
    const static auto res {from_cache(BoolExprSet{}, ConcatAnd)};
    return res;
}

Bools::Expr BoolExpr::bot() {
    const static auto res {from_cache(BoolExprSet{}, ConcatOr)};
    return res;
}

template <class Children>
Bools::Expr BoolExpr::mkAnd(const Children& lits) {
    return build(lits, ConcatAnd);
}

template Bools::Expr BoolExpr::mkAnd<std::vector<Bools::Expr>>(const std::vector<Bools::Expr> &lits);
template Bools::Expr BoolExpr::mkAnd<linked_hash_set<Bools::Expr>>(const linked_hash_set<Bools::Expr> &lits);
template Bools::Expr BoolExpr::mkAnd<std::vector<Arith::Lit>>(const std::vector<Arith::Lit> &lits);
template Bools::Expr BoolExpr::mkAnd<linked_hash_set<Arith::Lit>>(const linked_hash_set<Arith::Lit> &lits);
template Bools::Expr BoolExpr::mkAnd<Conjunction>(const Conjunction &lits);
template Bools::Expr BoolExpr::mkAnd<LitSet>(const LitSet &lits);

template <class Children>
Bools::Expr BoolExpr::mkOr(const Children& lits) {
    return build(lits, ConcatOr);
}

template Bools::Expr BoolExpr::mkOr<std::vector<Bools::Expr>>(const std::vector<Bools::Expr> &lits);
template Bools::Expr BoolExpr::mkOr<linked_hash_set<Bools::Expr>>(const linked_hash_set<Bools::Expr> &lits);

Bools::Expr BoolExpr::mkLit(const Lit& lit) {
    if (theory::isTriviallyTrue(lit)) {
        return top();
    }
    if (theory::isTriviallyFalse(lit)) {
        return bot();
    }
    return BoolTheoryLit::from_cache(lit);
}

sexpresso::Sexp BoolExpr::to_smtlib() const {
    if (const auto lit {getTheoryLit()}) {
        return theory::to_smtlib(*lit);
    }
    sexpresso::Sexp res;
    if (isAnd()) {
        if (getChildren().empty()) {
            res = sexpresso::Sexp("true");
        } else {
            res = sexpresso::Sexp("and");
        }
    } else {
        if (getChildren().empty()) {
            res = sexpresso::Sexp("false");
        } else {
            res = sexpresso::Sexp("or");
        }
    }
    for (const auto &c: getChildren()) {
        res.addChild(c->to_smtlib());
    }
    return res;
}

BoolExprSet BoolExpr::get_disjuncts() const {
    if (isOr()) {
        return getChildren();
    }
    if (isAnd()) {
        const auto children {getChildren()};
        std::optional<Bools::Expr> disj;
        BoolExprSet lits;
        for (const auto &x: children) {
            if (x->isOr()) {
                if (disj) {
                    disj.reset();
                    break;
                }
                disj = x;
            } else {
                assert(x->isTheoryLit());
                lits.insert(x);
            }
        }
        if (disj) {
            BoolExprSet res;
            const auto l {bools::mkAnd(lits)};
            for (const auto &x: (*disj)->getChildren()) {
                res.insert(l && x);
            }
            return res;
        }
    }
    return BoolExprSet({cpp::assume_not_null(shared_from_this())});
}

std::optional<Bools::Var> BoolExpr::isVar() const {
    using opt = std::optional<Bools::Var>;
    if (const auto lit{getTheoryLit()}) {
        return std::visit(
            Overload{
                [&](const Bools::Lit &l) {
                    return l->isNegated() ? opt{} : opt{l->getBoolVar()};
                },
                [&](const auto &) {
                    return opt{};
                }},
            *lit);
    }
    return opt{};
}

Bools::Expr BoolExpr::subs(const Arrays<Arith>::Subs& subs) const {
    return map([&](const auto& lit) {
        return bools::mkLit(theory::apply(
            lit,
            [&](const Bools::Lit&) {
                return lit;
            },
            [&](const auto& lit) {
                return Lit(lit->subs(subs));
            }));
    });
}

Bools::Expr BoolExpr::subs(const Variant<ArithVarPtr, Bools::Var>::Map<Arith::Expr, Bools::Expr>& subs) const {
    return map([&](const auto& lit) {
        return theory::apply(
            lit,
            [&](const Bools::Lit& lit) {
                const auto x {lit->getBoolVar()};
                if (const auto& map {subs.get<Bools::Var, Bools::Expr>()}; map.contains(x)) {
                    const auto res {map.at(x)};
                    return lit->isNegated() ? !res : res;
                }
                return bools::mkLit(lit);
            },
            [&](const Arith::Lit& lit) {
                return bools::mkLit(lit->subs(subs.get<ArithVarPtr, Arith::Expr>()));
            },
            [&](const Arrays<Arith>::Lit&) {
                return cpp::assume_not_null(shared_from_this());
            });
    });
}

Bools::Expr BoolExpr::subs(const Bools::Subs& subs) const {
    return map([&](const auto& lit) {
        return theory::apply(
            lit,
            [&](const Bools::Lit& lit) {
                return lit->subs(subs);
            },
            [&](const auto&) {
                return bools::mkLit(lit);
            });
    });
}

Bools::Expr BoolExpr::subs(const Subs& subs) const {
    return map([&](const auto& lit) {
        return subs(lit);
    });
}

Bools::Expr BoolExpr::renameVars(const Renaming& subs) const {
    return map([&](const auto& lit) {
        return bools::mkLit(theory::apply(
            lit,
            [&](const Bools::Lit& lit) -> Lit {
                return lit->renameVars(subs.get<Bools>());
            },
            [&](const auto& lit) -> Lit {
                return lit->renameVars(subs.get<Arrays<Arith>>());
            }));
    });
}

Bools::Expr BoolExpr::eval(const ModelPtr& model, const ArithVarPtr &keep) const {
    return map([&](const auto& lit) {
        return theory::apply(
            lit,
            [&](const Arith::Lit& lit) -> Bools::Expr {
                return bools::mkLit(lit->eval(model, keep));
            },
            [&](const Bools::Lit& lit) -> Bools::Expr {
                return model->eval(lit) ? top() : bot();
            },
            [&](const Arrays<Arith>::Lit&) -> Bools::Expr {
                throw std::invalid_argument("partial evaluation does not work as intended for arrays");
            });
    });
}

linked_hash_set<Bound> BoolExpr::getBounds(const ArithVarPtr& n) const {
    linked_hash_set<Bound> bounds;
    getBounds(n, bounds);
    return bounds;
}

void BoolExpr::getBounds(const ArithVarPtr& n, linked_hash_set<Bound> &res) const {
    if (const auto lit {getTheoryLit()}) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->getBounds(n, res);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->getBounds(n, res);
        }
    } else if (isOr()) {
        bool first = true;
        linked_hash_set<Bound> intersection;
        for (const auto &c: getChildren()) {
            if (first) {
                c->getBounds(n, intersection);
                first = false;
            } else {
                const auto other {c->getBounds(n)};
                for (auto it = intersection.begin(); it != intersection.end(); ++it) {
                    if (other.contains(*it)) {
                        ++it;
                    } else {
                        it = intersection.erase(it);
                    }
                }
            }
            if (intersection.empty()) {
                return;
            }
        }
        res.insert(intersection.begin(), intersection.end());
    }
}

linked_hash_set<Divisibility> BoolExpr::getDivisibility(const ArithVarPtr& n) const {
    linked_hash_set<Divisibility> res;
    getDivisibility(n, res);
    return res;
}

void BoolExpr::getDivisibility(const ArithVarPtr& n, linked_hash_set<Divisibility> &res) const {
    if (const auto lit {getTheoryLit()}) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->getDivisibility(n, res);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->getDivisibility(n, res);
        }
    } else if (isOr()) {
        bool first = true;
        linked_hash_set<Divisibility> intersection;
        for (const auto &c: getChildren()) {
            if (first) {
                c->getDivisibility(n, intersection);
                first = false;
            } else {
                const auto other {c->getDivisibility(n)};
                for (auto it = intersection.begin(); it != intersection.end(); ++it) {
                    if (other.contains(*it)) {
                        ++it;
                    } else {
                        it = intersection.erase(it);
                    }
                }
            }
            if (intersection.empty()) {
                return;
            }
        }
        res.insert(intersection.begin(), intersection.end());
    }
}

std::optional<Arith::Expr> BoolExpr::getEquality(const ArithVarPtr& n) const {
    if (const auto lit {getTheoryLit()}) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            return std::get<Arith::Lit>(*lit)->getEquality(n);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            if (const auto eq {c->getEquality(n)}) {
                return eq;
            }
        }
    }
    return {};
}

void BoolExpr::propagateEqualities(ArraySubs<Arith> &subs, const std::function<bool(const ArithVarPtr &)> &allow, std::unordered_set<ArithVarPtr> &blocked) const {
    if (const auto lit {getTheoryLit()}) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->subs(subs)->propagateEquality(subs, allow, blocked);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->propagateEqualities(subs, allow, blocked);
        }
    }
}

ArraySubs<Arith> BoolExpr::propagateEqualities(const std::function<bool(const ArithVarPtr &)> &allow) const {
    ArraySubs<Arith> subs;
    std::unordered_set<ArithVarPtr> blocked;
    propagateEqualities(subs, allow, blocked);
    return subs;
}

Bools::Expr BoolExpr::toInfinity(const ArithVarPtr& n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const Arith::Lit &rel) {
                    // TODO handle Eq / Neq
                    assert(rel->isLinear({{n}}));
                    if (!rel->has(n)) {
                        return mkLit(rel);
                    }
                    if (const auto ex {rel->lhs()}; ***(*ex->coeff(n))->isRational() > 0) {
                        return top();
                    }
                    return bot();
                },
                [](const auto &lit) {
                    return mkLit(lit);
                }
            }, lit);
    });
}

Bools::Expr BoolExpr::toMinusInfinity(const ArithVarPtr& n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const Arith::Lit &rel) {
                    assert(rel->isLinear({{n}}));
                    if (!rel->has(n)) {
                        return mkLit(rel);
                    }
                    if (rel->isEq()) {
                        return bot();
                    }
                    if (rel->isNeq()) {
                        return top();
                    }
                    if (const auto ex {rel->lhs()}; ***(*ex->coeff(n))->isRational() < 0) {
                        return top();
                    }
                    return bot();
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
    if (const auto it {cache.find(self)}; it != cache.end()) {
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
            }
            if (simp != top()) {
                if (simp->isAnd()) {
                    const auto children = simp->getChildren();
                    newChildren.insert(children.begin(), children.end());
                } else {
                    newChildren.insert(simp);
                }
            }
        }
        if (!changed) {
            res = self;
        } else if (newChildren.empty()) {
            res = top();
        } else {
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
            }
            if (simp != bot()) {
                if (simp->isOr()) {
                    const auto children = simp->getChildren();
                    newChildren.insert(children.begin(), children.end());
                } else {
                    newChildren.insert(simp);
                }
            }
        }
        if (!changed) {
            res = self;
        } else if (newChildren.empty()) {
            res = bot();
        } else {
            res = mkOr(newChildren);
        }
    } else if (isTheoryLit()) {
        const auto lit = *getTheoryLit();
        const auto mapped = f(lit);
        if (const auto mappedLit = mapped->getTheoryLit(); mappedLit && *mappedLit == lit) {
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

VarSet BoolExpr::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

CellSet BoolExpr::cells() const {
    CellSet res;
    collectCells(res);
    return res;
}

void BoolExpr::collectCells(CellSet& cells) const {
    iter([&](const auto& lit) {
        theory::collectCells(lit, cells);
    });
}

LitSet BoolExpr::lits() const {
    LitSet res;
    collectLits(res);
    return res;
}

bool BoolExpr::isLinear() const {
    return forall([](const auto &lit) {
        return std::visit(
            Overload {
                [](const Bools::Lit&) {
                    return true;
                },
                [](const auto &lit) {
                    return lit->isLinear();
                }
            }, lit);
    });
}

bool BoolExpr::isPoly() const {
    return forall([](const auto &lit) {
        return std::visit(
            Overload {
                [](const Bools::Lit&) {
                    return true;
                },
                [](const auto &lit) {
                    return lit->isPoly();
                }
            }, lit);
    });
}

Bools::Expr operator&&(const Bools::Expr& a, const Bools::Expr& b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkAnd(children);
}

Bools::Expr operator||(const Bools::Expr& a, const Bools::Expr& b) {
    const BoolExprSet children{a, b};
    return BoolExpr::mkOr(children);
}

Bools::Expr operator!(const Bools::Expr& a) {
    return a->negation();
}

std::ostream& operator<<(std::ostream &s, const Bools::Expr &e) {
    if (e->isTheoryLit()) {
        std::visit([&s](const auto& lit){s << lit;}, *e->getTheoryLit());
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
