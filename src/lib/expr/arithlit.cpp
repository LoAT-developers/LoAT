#include "arithlit.hpp"
#include "arithsubs.hpp"
#include "arithutil.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>
#include <algorithm>
#include <unordered_set>

void Bounds::addUpperBound(const ArithExprPtr e) {
    rUpperBounds.insert(e);
    if (e->isIntegral()) {
        iUpperBounds.insert(e);
    }
}

void Bounds::addLowerBound(const ArithExprPtr e) {
    rLowerBounds.insert(e);
    if (e->isIntegral()) {
        iLowerBounds.insert(e);
    }
}
void Bounds::addEquality(const ArithExprPtr e) {
    addLowerBound(e);
    addUpperBound(e);
    rEqualities.insert(e);
    if (e->isIntegral()) {
        iEqualities.insert(e);
    }
}

const ArithExprSet& Bounds::realUpperBounds() const {
    return rUpperBounds;
}

const ArithExprSet& Bounds::realLowerBounds() const {
    return rLowerBounds;
}

const ArithExprSet& Bounds::realEqualities() const {
    return rEqualities;
}

const ArithExprSet& Bounds::integralUpperBounds() const {
    return iUpperBounds;
}

const ArithExprSet& Bounds::integralLowerBounds() const {
    return iLowerBounds;
}

const ArithExprSet& Bounds::integralEqualities() const {
    return iEqualities;
}

void Bounds::intersect(const Bounds &that) {
    const auto intersect = [](ArithExprSet &xs, const ArithExprSet &ys) {
        for (auto it = xs.begin(); it != xs.end();) {
            if (ys.contains(*it)) {
                it = xs.erase(it);
            } else {
                ++it;
            }
        }
    };
    intersect(rLowerBounds, that.rLowerBounds);
    intersect(rUpperBounds, that.rUpperBounds);
    intersect(rEqualities, that.rEqualities);
    intersect(iLowerBounds, that.iLowerBounds);
    intersect(iUpperBounds, that.iUpperBounds);
    intersect(iEqualities, that.iEqualities);
}

void Bounds::unite(const Bounds &that) {
    const auto unite = [](ArithExprSet &xs, const ArithExprSet &ys) {
        for (const auto &y: ys) {
            xs.insert(y);
        }
    };
    unite(rLowerBounds, that.rLowerBounds);
    unite(rUpperBounds, that.rUpperBounds);
    unite(rEqualities, that.rEqualities);
    unite(iLowerBounds, that.iLowerBounds);
    unite(iUpperBounds, that.iUpperBounds);
    unite(iEqualities, that.iEqualities);
}

bool Bounds::empty() const {
    return rLowerBounds.empty() && rUpperBounds.empty() && rEqualities.empty();
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

std::pair<std::optional<ArithExprPtr>, std::optional<ArithExprPtr>> ArithLit::getBoundFromIneq(const ArithVarPtr N) const {
    if (l->isPoly(N) != 1 || kind == Kind::Neq) return {};
    const auto t = kind == Kind::Eq ? l : l - arith::mkConst(1);
    const auto optSolved {arith::solveTermFor(t, N)};
    if (optSolved) {
        switch (kind) {
        case Kind::Eq:
            return {optSolved, optSolved};
        case Kind::Gt: {
            const auto coeff {*t->coeff(N)};
            const auto r {***coeff->isRational()};
            if (r > 0) {
                return {optSolved, {}};
            } else {
                return {{}, optSolved};
            }
        }
        default:
            throw std::invalid_argument("unexpected relation");
        }
    }
    return {};
}

void ArithLit::getBounds(const ArithVarPtr n, Bounds &res) const {
    if (has(n)) {
        const auto p {getBoundFromIneq(n)};
        if (p.first) {
            if (p.first == p.second) {
                res.addEquality(*p.first);
            }
            auto add {true};
            for (const auto &b: res.realLowerBounds()) {
                const auto diff {b - *p.first};
                const auto r {diff->isInt()};
                if (r && *r >= 0) {
                    add = false;
                    break;
                }
            }
            if (add) {
                res.addLowerBound(*p.first);
            }
        }
        if (p.second) {
            auto add {true};
            for (const auto &b: res.realUpperBounds()) {
                const auto diff {b - *p.second};
                const auto r {diff->isInt()};
                if (r && *r <= 0) {
                    add = false;
                    break;
                }
            }
            if (add) {
                res.addUpperBound(*p.second);
            }
        }
    }
}

std::optional<ArithExprPtr> ArithLit::getEquality(const ArithVarPtr n) const {
    if (isEq() && has(n) && isLinear({{n}})) {
        const auto eq {getBoundFromIneq(n).first};
        if (eq && (*eq)->isIntegral()) {
            return eq;
        }
    }
    return {};
}

void ArithLit::propagateEquality(ArithSubs &subs, const std::function<bool(const ArithVarPtr &)> &allow) const {
    if (isEq()) {
        for (const auto &x: vars()) {
            if (allow(x) && !subs.contains(x) && l->isLinear({{x}})) {
                const auto coeff {l->coeff(x)};
                if ((*coeff)->is(1) || (*coeff)->is(-1)) {
                    const auto t {*arith::solveTermFor(l, x)};
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
    std::unordered_set<ArithLit> add;
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
