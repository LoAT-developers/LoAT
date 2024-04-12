#include "arithlit.hpp"
#include "arithsubs.hpp"
#include "arithutil.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>
#include <algorithm>

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

Bounds Bounds::intersect(const Bounds &that) const {
    Bounds res;
    const auto intersect = [](const ArithExprSet &xs, const ArithExprSet &ys) {
        ArithExprSet res;
        for (const auto &x: xs) {
            if (ys.contains(x)) {
                res.insert(x);
            }
        }
        return res;
    };
    res.rLowerBounds = intersect(rLowerBounds, that.rLowerBounds);
    res.rUpperBounds = intersect(rUpperBounds, that.rUpperBounds);
    res.rEqualities = intersect(rEqualities, that.rEqualities);
    res.iLowerBounds = intersect(iLowerBounds, that.iLowerBounds);
    res.iUpperBounds = intersect(iUpperBounds, that.iUpperBounds);
    res.iEqualities = intersect(iEqualities, that.iEqualities);
    return res;
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
        const auto coeff {*t->coeff(N)};
        const auto r {***coeff->isRational()};
        switch (kind) {
        case Kind::Eq:
            return {optSolved, optSolved};
        case Kind::Gt:
            if (r > 0) {
                return {optSolved, {}};
            } else {
                return {{}, optSolved};
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
    return ArithLit(map(l), kind);
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
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral + arith::mkConst(1), ArithLit::Kind::Gt);
}

ArithLit arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGeq(-x, -y);
}

ArithLit arith::mkGt(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral, ArithLit::Kind::Gt);
}

ArithLit arith::mkEq(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral, ArithLit::Kind::Eq);
}

ArithLit arith::mkNeq(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral, ArithLit::Kind::Neq);
}

ArithLit arith::mkLt(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGt(-x, -y);
}

ArithLit operator!(const ArithLit &x) {
    switch (x.kind) {
        case ArithLit::Kind::Gt: return ArithLit(arith::mkConst(1) - x.lhs(), ArithLit::Kind::Gt);
        case ArithLit::Kind::Eq: return ArithLit(x.lhs(), ArithLit::Kind::Neq);
        case ArithLit::Kind::Neq: return ArithLit(x.lhs(), ArithLit::Kind::Eq);
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
