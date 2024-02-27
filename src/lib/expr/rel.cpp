#include "rel.hpp"
#include "exprsubs.hpp"
#include "numexpressionutils.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>

std::ostream& operator<<(std::ostream &s, const RelSet &set) {
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

Rel::Rel(const ExprPtr l): l(l) { }

ExprPtr Rel::lhs() const {
    return l;
}

bool Rel::isPoly() const {
    return l->isPoly();
}

bool Rel::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    return l->isLinear(vars);
}

std::pair<std::optional<ExprPtr>, std::optional<ExprPtr>> Rel::getBoundFromIneq(const NumVarPtr N) const {
    if (l->degree(N) != 1) return {};
    const auto geq {l - arith::mkConst(1)};
    const auto optSolved {arith::solveTermFor(geq, N)};
    if (optSolved) {
        const auto coeff {*geq->coeff(N)};
        const auto r {coeff->isRational()};
        if (*r > 0) {
            return {{*optSolved}, {}};
        } else {
            return {{}, {*optSolved}};
        }
    }
    return {};
}

void Rel::getBounds(const NumVarPtr n, Bounds &res) const {
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

bool Rel::isTriviallyTrue() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && *optTrivial;
}

bool Rel::isTriviallyFalse() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && !*optTrivial;
}

std::optional<bool> Rel::checkTrivial() const {
    const auto r {l->isRational()};
    if (r) {
        return *r > 0;
    }
    return {};
}

void Rel::collectVars(linked_hash_set<NumVarPtr> &res) const {
    l->collectVars(res);
}

bool Rel::has(const NumVarPtr x) const {
    return l->has(x);
}

Rel Rel::subs(const ExprSubs &map) const {
    return Rel(map(l));
}

linked_hash_set<NumVarPtr> Rel::vars() const {
    return l->vars();
}

std::size_t Rel::hash() const {
    return std::hash<ExprPtr>{}(l);
}

size_t hash_value(const Rel &rel) {
    return rel.hash();
}

Rel Rel::mkGeq(const ExprPtr x, const ExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return Rel(lhs_integral + arith::mkConst(1));
}

Rel Rel::mkLeq(const ExprPtr x, const ExprPtr y) {
    return mkGeq(-x, -y);
}

Rel Rel::mkGt(const ExprPtr x, const ExprPtr y) {
    const auto lhs {x - y};
    const auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    return Rel(lhs_integral);
}

Rel Rel::mkLt(const ExprPtr x, const ExprPtr y) {
    return mkGt(-x, -y);
}

Rel operator!(const Rel &x) { 
    return Rel(arith::mkConst(1) - x.lhs());
}

std::ostream& operator<<(std::ostream &s, const Rel &rel) {
    return s << rel.l << " > 0";
}
