#include "arithlit.hpp"
#include "arithsubs.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>
#include <algorithm>
#include <unordered_set>

std::size_t hash_value(const Bound &bound) {
    std::size_t hash {42};
    boost::hash_combine(hash, bound.bound);
    boost::hash_combine(hash, bound.kind);
    return hash;
}

std::size_t hash_value(const Divisibility &d) {
    std::size_t hash {42};
    boost::hash_combine(hash, d.factor);
    boost::hash_combine(hash, d.modulo);
    boost::hash_combine(hash, d.res);
    return hash;
}

std::ostream& operator<<(std::ostream &s, const ArithLitSet &set) {
    s << "{";
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (it != set.begin()) {
            s << ", ";
        }
        s << *it;
    }
    s << "}";
    return s;
}

ArithLit::ArithLit(const ArithExprPtr l, const Kind kind): l(l), kind(kind) { }

ArithLit mk(const ArithExprPtr lhs, const ArithLit::Kind kind) {
    auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    const auto factor {lhs_integral->getConstantFactor()};
    if (factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    return ArithLit(lhs_integral, kind);
}

ArithExprPtr ArithLit::lhs() const {
    return l;
}

bool ArithLit::isPoly() const {
    return l->isPoly().has_value();
}

bool ArithLit::isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars) const {
    return l->isLinear(vars);
}

void ArithLit::getBounds(const ArithVarPtr n, linked_hash_set<Bound> &res) const {
    if (l->isPoly(n) == 1 && kind != Kind::Neq) {
        const auto t = kind == Kind::Eq ? l : l - arith::mkConst(1);
        const auto coeff{*t->coeff(n)};
        const auto optSolved{t->solve(n)};
        if (optSolved) {
            switch (kind) {
            case Kind::Eq:
                res.emplace(*optSolved, BoundKind::Equality);
                break;
            case Kind::Gt: {
                const auto r{***coeff->isRational()};
                if (r > 0) {
                    res.emplace(*optSolved, BoundKind::Lower);
                } else {
                    res.emplace(*optSolved, BoundKind::Upper);
                }
                break;
            }
            default:
                throw std::invalid_argument("unexpected relation");
            }
        }
    }
}

std::optional<Divisibility> ArithLit::isDivisibility(const ArithVarPtr n) const {
    linked_hash_set<Divisibility> res;
    getDivisibility(n, res);
    using opt = std::optional<Divisibility>;
    return res.empty() ? opt{} : opt{*res.begin()};
}

void ArithLit::getDivisibility(const ArithVarPtr n, linked_hash_set<Divisibility> &res) const {
    if (kind == Kind::Eq) {
        if (const auto mod{l->isMod()}) {
            if (const auto modulo{(*mod)->getRhs()->isInt()}) {
                if ((*mod)->getLhs() == n) {
                    // n % modulo == 0
                    res.emplace(1, *modulo, arith::mkConst(0));
                } else if (const auto sum{(*mod)->getLhs()->isAdd()}) {
                    auto args{(*sum)->getArgs()};
                    std::optional<Int> factor;
                    if (args.contains(n)) {
                        factor = 1;
                    } else {
                        for (const auto &arg : args) {
                            if (arg->has(n)) {
                                if (const auto mul{arg->isMult()}) {
                                    auto mul_args{(*mul)->getArgs()};
                                    if (mul_args.size() == 2 && mul_args.contains(n)) {
                                        mul_args.erase(n);
                                        factor = (*mul_args.begin())->isInt();
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if (!factor) {
                        return;
                    }
                    args.erase(arith::mkConst(*factor) * n);
                    const auto mres{arith::mkPlus(std::vector<ArithExprPtr>(args.begin(), args.end()))};
                    if (mres->has(n)) {
                        return;
                    }
                    // (factor * n + mres) % modulo = 0
                    // ==> n % modulo = -mres
                    res.emplace(1, *modulo, -mres);
                    return;
                } else if (const auto mul{(*mod)->getLhs()->isMult()}) {
                    auto mul_args{(*mul)->getArgs()};
                    if (mul_args.contains(n) && mul_args.contains(n)) {
                        mul_args.erase(n);
                        if (const auto factor{(*mul_args.begin())->isInt()}) {
                            // factor * n % modulo = 0
                            res.emplace(*factor, *modulo, arith::mkConst(0));
                        }
                    }
                }
            }
        }
    }
}

std::optional<ArithExprPtr> ArithLit::getEquality(const ArithVarPtr n) const {
    if (isEq()) {
        return l->solve(n);
    }
    return {};
}

void ArithLit::propagateEquality(ArithSubs &subs, const std::function<bool(const ArithVarPtr &)> &allow) const {
    if (isEq()) {
        for (const auto &x: vars()) {
            if (allow(x) && !subs.contains(x) && l->isLinear({{x}})) {
                const auto coeff {l->coeff(x)};
                if ((*coeff)->is(1) || (*coeff)->is(-1)) {
                    const auto t {*l->solve(x)};
                    subs = subs.compose(ArithSubs{{x, t}});
                    return;
                }
            }
        }
    }
}

bool ArithLit::isTriviallyTrue() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && *optTrivial;
}

bool ArithLit::isTriviallyFalse() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && !*optTrivial;
}

bool ArithLit::isGt() const {
    return kind == Kind::Gt;
}

bool ArithLit::isEq() const {
    return kind == Kind::Eq;
}

bool ArithLit::isNeq() const {
    return kind == Kind::Neq;
}

std::optional<bool> ArithLit::checkTrivial() const {
    if (const auto r {l->isRational()}) {
        switch (kind) {
            case Kind::Eq: return ***r == 0;
            case Kind::Gt: return ***r > 0;
            case Kind::Neq: return ***r != 0;
        }
    }
    return {};
}

void ArithLit::collectVars(linked_hash_set<ArithVarPtr> &res) const {
    l->collectVars(res);
}

bool ArithLit::has(const ArithVarPtr x) const {
    return l->has(x);
}

ArithLit ArithLit::subs(const ArithSubs &map) const {
    return mk(map(l), kind);
}

linked_hash_set<ArithVarPtr> ArithLit::vars() const {
    return l->vars();
}

std::size_t ArithLit::hash() const {
    size_t seed{0};
    boost::hash_combine(seed, l);
    boost::hash_combine(seed, kind);
    return seed;
}

size_t hash_value(const ArithLit &rel) {
    return rel.hash();
}

ArithLit arith::mkGeq(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    const auto factor {lhs_integral->getConstantFactor()};
    if (factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    return ArithLit(lhs_integral + arith::mkConst(1), ArithLit::Kind::Gt);
}

ArithLit arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGeq(-x, -y);
}

ArithLit arith::mkGt(const ArithExprPtr x, const ArithExprPtr y) {
    return mk(x - y, ArithLit::Kind::Gt);
}

ArithLit arith::mkEq(const ArithExprPtr x, const ArithExprPtr y) {
    return mk(x - y, ArithLit::Kind::Eq);
}

ArithLit arith::mkNeq(const ArithExprPtr x, const ArithExprPtr y) {
    return mk(x - y, ArithLit::Kind::Neq);
}

ArithLit arith::mkLt(const ArithExprPtr x, const ArithExprPtr y) {
    return mk(y - x, ArithLit::Kind::Gt);
}

ArithLit operator!(const ArithLit &x) {
    switch (x.kind) {
        case ArithLit::Kind::Gt: return mk(arith::mkConst(1) - x.lhs(), ArithLit::Kind::Gt);
        case ArithLit::Kind::Eq: return mk(x.lhs(), ArithLit::Kind::Neq);
        case ArithLit::Kind::Neq: return mk(x.lhs(), ArithLit::Kind::Eq);
        default: throw std::invalid_argument("unexpected relation");
    }
}

std::ostream& operator<<(std::ostream &s, const ArithLit &rel) {
    std::string lhs;
    std::string rhs;
    if (const auto add {rel.lhs()->isAdd()}) {
        std::vector<ArithExprPtr> lhs_args;
        std::vector<ArithExprPtr> rhs_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isNegated()) {
                rhs_args.emplace_back(-arg);
            } else {
                lhs_args.emplace_back(arg);
            }
        }
        lhs = toString(arith::mkPlus(std::move(lhs_args)));
        rhs = toString(arith::mkPlus(std::move(rhs_args)));
    } else {
        lhs = toString(rel.lhs());
        rhs = "0";
    }
    switch (rel.kind) {
        case ArithLit::Kind::Gt: return s << lhs << " > " << rhs;
        case ArithLit::Kind::Eq: return s << lhs << " = " << rhs;
        case ArithLit::Kind::Neq: return s << lhs << " != " << rhs;
        default: throw std::invalid_argument("unexpected relation");
    }
}

bool ArithLit::eval(const linked_hash_map<ArithVarPtr, Int> &m) const {
    switch (kind) {
        case Kind::Gt: return l->eval(m) > 0;
        case Kind::Eq: return l->eval(m) == 0;
        case Kind::Neq: return l->eval(m) != 0;
        default: throw std::invalid_argument("unexpected relation");
    }
}

void ArithLit::simplifyAnd(linked_hash_set<ArithLit> &lits) {
    std::unordered_set<ArithLit> remove;
    linked_hash_set<ArithLit> add;
    for (const auto &rel: lits) {
        if (rel.isGt() && !remove.contains(rel)) {
            const auto converse {arith::mkLeq(rel.lhs(), arith::mkConst(1))};
            if (lits.contains(converse)) {
                remove.insert(rel);
                remove.insert(converse);
                add.insert(arith::mkEq(rel.lhs(), arith::mkConst(1)));
            }
        }
    }
    for (const auto &r: remove) {
        lits.erase(r);
    }
    for (const auto &a: add) {
        lits.insert(a);
    }
}

void ArithLit::simplifyOr(linked_hash_set<ArithLit> &lits) {
    std::unordered_set<ArithLit> remove;
    std::unordered_set<ArithLit> add;
    for (const auto &rel: lits) {
        if (rel.isGt() && !remove.contains(rel)) {
            const auto converse {arith::mkLt(rel.lhs(), arith::mkConst(0))};
            if (lits.contains(converse)) {
                remove.insert(rel);
                remove.insert(converse);
                add.insert(arith::mkNeq(rel.lhs(), arith::mkConst(0)));
            }
        }
    }
    for (const auto &r: remove) {
        lits.erase(r);
    }
    for (const auto &a: add) {
        lits.insert(a);
    }
}
