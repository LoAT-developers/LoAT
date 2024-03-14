#include "arithlit.hpp"
#include "arithsubs.hpp"
#include "arithutil.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>

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

ArithLit::ArithLit(const ArithExprPtr l): l(l) { }

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
    if (l->isPoly(N) != 1) return {};
    const auto geq {l - arith::mkConst(1)};
    const auto optSolved {arith::solveTermFor(geq, N)};
    if (optSolved) {
        const auto coeff {*geq->coeff(N)};
        const auto r {***coeff->isRational()};
        if (r > 0) {
            return {{*optSolved}, {}};
        } else {
            return {{}, {*optSolved}};
        }
    }
    return {};
}

void ArithLit::getBounds(const ArithVarPtr n, Bounds &res) const {
    if (has(n)) {
        const auto p {getBoundFromIneq(n)};
        if (p.first) {
            auto add {true};
            for (const auto &b: res.lowerBounds) {
                const auto diff {b - *p.first};
                const auto r {diff->isRational()};
                if (r && *r >= 0) {
                    add = false;
                    break;
                }
            }
            if (add) {
                res.lowerBounds.insert(*p.first);
            }
        }
        if (p.second) {
            auto add {true};
            for (const auto &b: res.upperBounds) {
                const auto diff {b - *p.second};
                const auto r {diff->isRational()};
                if (r && *r <= 0) {
                    add = false;
                    break;
                }
            }
            if (add) {
                res.upperBounds.insert(*p.second);
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

std::optional<bool> ArithLit::checkTrivial() const {
    const auto r {l->isRational()};
    if (r) {
        return *r > 0;
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
    return ArithLit(map(l));
}

linked_hash_set<ArithVarPtr> ArithLit::vars() const {
    return l->vars();
}

std::size_t ArithLit::hash() const {
    return std::hash<ArithExprPtr>{}(l);
}

size_t hash_value(const ArithLit &rel) {
    return rel.hash();
}

ArithLit arith::mkGeq(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral + arith::mkConst(1));
}

ArithLit arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGeq(-x, -y);
}

ArithLit arith::mkGt(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return ArithLit(lhs_integral);
}

ArithLit arith::mkLt(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGt(-x, -y);
}

ArithLit operator!(const ArithLit &x) {
    return ArithLit(arith::mkConst(1) - x.lhs());
}

std::ostream& operator<<(std::ostream &s, const ArithLit &rel) {
    return s << rel.l << " > 0";
}

bool ArithLit::eval(const linked_hash_map<ArithVarPtr, Int> &m) const {
    return l->eval(m) > 0;
}
