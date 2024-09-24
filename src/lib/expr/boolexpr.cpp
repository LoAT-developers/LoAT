#include "boolexpr.hpp"
#include "theory.hpp"
#include "conjunction.hpp"

const Bools::Expr BoolExpr::from_cache(const BoolExprSet &children, ConcatOperator op) {
    return BoolJunction::from_cache(children, op);
}

template <class Lits>
const Bools::Expr BoolExpr::buildFromLits(const Lits &lits, ConcatOperator op) {
    BoolExprSet children;
    for (const auto &lit : lits) {
        children.insert(mkLit(lit));
    }
    return build(children, op);
}

template <class Children>
const Bools::Expr BoolExpr::build(const Children &lits, ConcatOperator op) {
    if (op == ConcatAnd && std::find(lits.begin(), lits.end(), bot()) != lits.end()) {
        return bot();
    } else if (op == ConcatOr && std::find(lits.begin(), lits.end(), top()) != lits.end()) {
        return top();
    }
    BoolExprSet children;
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
}

const Bools::Expr BoolExpr::top() {
    const static auto res {from_cache(BoolExprSet{}, ConcatAnd)};
    return res;
}

const Bools::Expr BoolExpr::bot() {
    const static auto res {from_cache(BoolExprSet{}, ConcatOr)};
    return res;
}

template <class Lits>
const Bools::Expr BoolExpr::mkAndFromLits(const Lits &lits) {
    return buildFromLits(lits, ConcatAnd);
}

template const Bools::Expr BoolExpr::mkAndFromLits<std::vector<Arith::Lit>>(const std::vector<Arith::Lit> &lits);
template const Bools::Expr BoolExpr::mkAndFromLits<linked_hash_set<Arith::Lit>>(const linked_hash_set<Arith::Lit> &lits);
template const Bools::Expr BoolExpr::mkAndFromLits<Conjunction>(const Conjunction &lits);
template const Bools::Expr BoolExpr::mkAndFromLits<LitSet>(const LitSet &lits);
template const Bools::Expr BoolExpr::mkAndFromLits<std::initializer_list<Lit>>(const std::initializer_list<Lit> &lits);

template <class Children>
const Bools::Expr BoolExpr::mkAnd(const Children &lits) {
    return build(lits, ConcatAnd);
}

template const Bools::Expr BoolExpr::mkAnd<std::vector<Bools::Expr>>(const std::vector<Bools::Expr> &lits);
template const Bools::Expr BoolExpr::mkAnd<linked_hash_set<Bools::Expr>>(const linked_hash_set<Bools::Expr> &lits);

template <class Children>
const Bools::Expr BoolExpr::mkOr(const Children &lits) {
    return build(lits, ConcatOr);
}

template const Bools::Expr BoolExpr::mkOr<std::vector<Bools::Expr>>(const std::vector<Bools::Expr> &lits);
template const Bools::Expr BoolExpr::mkOr<linked_hash_set<Bools::Expr>>(const linked_hash_set<Bools::Expr> &lits);

const Bools::Expr BoolExpr::mkLit(const Lit &lit) {
    if (theory::isTriviallyTrue(lit)) {
        return top();
    } else if (theory::isTriviallyFalse(lit)) {
        return bot();
    } else {
        return BoolTheoryLit::from_cache(lit);
    }
}

sexpresso::Sexp BoolExpr::to_smtlib(const std::function<std::string(const Var &)> &var_map) const {
    if (const auto lit {getTheoryLit()}) {
        return theory::to_smtlib(*lit, var_map);
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
        res.addChild(c->to_smtlib(var_map));
    }
    return res;
}

BoolExprSet BoolExpr::get_disjuncts() const {
    if (isOr()) {
        return getChildren();
    } else if (isAnd()) {
        const auto children {getChildren()};
        std::optional<Bools::Expr> disj;
        BoolExprSet lits;
        for (const auto &x: children) {
            if (x->isOr()) {
                if (disj) {
                    disj.reset();
                    break;
                } else {
                    disj = x;
                }
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
    } else {
        return opt{};
    }
}

linked_hash_set<Bound> BoolExpr::getBounds(const Arith::Var n) const {
    linked_hash_set<Bound> bounds;
    getBounds(n, bounds);
    return bounds;
}

void BoolExpr::getBounds(const Arith::Var var, linked_hash_set<Bound> &res) const {
    const auto lit {getTheoryLit()};
    if (lit) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->getBounds(var, res);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->getBounds(var, res);
        }
    } else if (isOr()) {
        bool first = true;
        linked_hash_set<Bound> intersection;
        for (const auto &c: getChildren()) {
            if (first) {
                c->getBounds(var, intersection);
                first = false;
            } else {
                const auto other {c->getBounds(var)};
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

linked_hash_set<Divisibility> BoolExpr::getDivisibility(const Arith::Var n) const {
    linked_hash_set<Divisibility> res;
    getDivisibility(n, res);
    return res;
}

void BoolExpr::getDivisibility(const Arith::Var var, linked_hash_set<Divisibility> &res) const {
    const auto lit {getTheoryLit()};
    if (lit) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->getDivisibility(var, res);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->getDivisibility(var, res);
        }
    } else if (isOr()) {
        bool first = true;
        linked_hash_set<Divisibility> intersection;
        for (const auto &c: getChildren()) {
            if (first) {
                c->getDivisibility(var, intersection);
                first = false;
            } else {
                const auto other {c->getDivisibility(var)};
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

std::optional<Arith::Expr> BoolExpr::getEquality(const Arith::Var var) const {
    if (const auto lit {getTheoryLit()}) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            return std::get<Arith::Lit>(*lit)->getEquality(var);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            if (const auto eq {c->getEquality(var)}) {
                return eq;
            }
        }
    }
    return {};
}

void BoolExpr::propagateEqualities(Arith::Subs &subs, const std::function<bool(const Var &)> &allow) const {
    const auto lit {getTheoryLit()};
    if (lit) {
        if (std::holds_alternative<Arith::Lit>(*lit)) {
            std::get<Arith::Lit>(*lit)->subs(subs)->propagateEquality(subs, allow);
        }
    } else if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->propagateEqualities(subs, allow);
        }
    }
}

Arith::Subs BoolExpr::propagateEqualities(const std::function<bool(const Var &)> &allow) const {
    Arith::Subs subs;
    propagateEqualities(subs, allow);
    return subs;
}

Bools::Expr BoolExpr::toInfinity(const Arith::Var n) const {
    return map([&n](const Lit &lit){
        return std::visit(
            Overload{
                [&n](const Arith::Lit &rel) {
                    // TODO handle Eq / Neq
                    assert(rel->isLinear({{n}}));
                    if (!rel->has(n)) {
                        return mkLit(rel);
                    }
                    const auto ex {rel->lhs()};
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
                    const auto ex {rel->lhs()};
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
            // for (const auto &c: newChildren) {
            //     if (c->isTheoryLit()) {
            //         if (newChildren.contains(c->negation())) {
            //             cache.emplace(self, top());
            //             return top();
            //         }
            //     }
            // }
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
                [](const Arith::Lit &lit) {
                    return lit->isLinear();
                },
                [](const Bools::Lit&) {
                    return true;
                }
            }, lit);
    });
}

bool BoolExpr::isPoly() const {
    return forall([](const auto &lit) {
        return std::visit(
            Overload {
                [](const Arith::Lit &lit) {
                    return lit->isPoly();
                },
                [](const Bools::Lit&) {
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
