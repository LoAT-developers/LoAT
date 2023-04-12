#include "rel.hpp"

#include <sstream>
#include <assert.h>

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

Rel::Rel(const Expr &lhs, RelOp op, const Expr &rhs): l(lhs), r(rhs), op(op) { }

Expr Rel::lhs() const {
    return l;
}

Expr Rel::rhs() const {
    return r;
}

Rel Rel::expand() const {
    return Rel(l.expand(), op, r.expand());
}

bool Rel::isPoly() const {
    return l.isPoly() && r.isPoly();
}

bool Rel::isLinear(const std::optional<std::set<NumVar>> &vars) const {
    return l.isLinear(vars) && r.isLinear(vars);
}

bool Rel::isIneq() const {
    return op != Rel::eq && op != Rel::neq;
}

bool Rel::isEq() const {
    return op == Rel::eq;
}

bool Rel::isNeq() const {
    return op == Rel::neq;
}

bool Rel::isGZeroConstraint() const {
    return (op == Rel::gt || op == Rel::geq) && r.isZero();
}

Rel Rel::toLeq() const {
    assert(isIneq());
    assert(isPoly() || !isStrict());

    std::optional<Rel> res;
    if (isStrict()) {
        Num lcm = GiNaC::lcm(l.denomLcm(), r.denomLcm());
        res = lcm == 1 ? *this : Rel(l * lcm, op, r * lcm);
    } else {
        res = *this;
    }
    //flip > or >=
    if (res->op == Rel::gt) {
        res = Rel(res->rhs(), lt, res->lhs());
    } else if (op == Rel::geq) {
        res = Rel(res->rhs(), leq, res->lhs());
    }

    if (res->op == Rel::lt) {
        res = Rel(res->lhs(), leq, (res->rhs() - 1));
    }

    assert(res->op == Rel::leq);
    return *res;
}

Rel Rel::toGt() const {
    assert(isIneq());
    assert(isPoly() || isStrict());

    std::optional<Rel> res;
    if (!isStrict()) {
        Num lcm = GiNaC::lcm(l.denomLcm(), r.denomLcm());
        res = lcm == 1 ? *this : Rel(l * lcm, op, r * lcm);
    } else {
        res = *this;
    }
    if (res->op == Rel::lt) {
        res = Rel(res->rhs(), gt, res->lhs());
    } else if (op == Rel::leq) {
        res = Rel(res->rhs(), geq, res->lhs());
    }

    if (res->op == Rel::geq) {
        res = Rel(res->lhs() + 1, gt, res->rhs());
    }

    assert(res->op == Rel::gt);
    return *res;
}

Rel Rel::toL() const {
    assert(isIneq());
    if (op == Rel::gt) {
        return Rel(r, lt, l);
    } else if (op == Rel::geq) {
        return Rel(r, leq, l);
    } else {
        return *this;
    }
}

Rel Rel::toG() const {
    assert(isIneq());
    if (op == Rel::lt) {
        return Rel(r, gt, l);
    } else if (op == Rel::leq) {
        return Rel(r, geq, l);
    } else {
        return *this;
    }
}

Rel Rel::normalize() const {
    return makeRhsZero();
}

bool Rel::isStrict() const {
    assert(isIneq());
    return op == lt || op == gt;
}

bool Rel::isOctagon() const {
    return op != neq && (lhs() - rhs()).expand().isOctagon();
}

std::pair<std::optional<Expr>, std::optional<Expr>> Rel::getBoundFromIneq(const NumVar &N) const {
    Rel l = isPoly() ? toLeq() : toL();
    Expr term = (l.lhs() - l.rhs()).expand();
    if (term.degree(N) != 1) return {};

    // compute the upper bound represented by N and check that it is integral
    auto optSolved = term.solveTermFor(N, ResultMapsToInt);
    if (optSolved) {
        const Expr &coeff = term.coeff(N, 1);
        assert(coeff.isRationalConstant());
        if (coeff.toNum().is_negative()) {
            return {{l.isStrict() ? *optSolved + 1 : *optSolved}, {}};
        } else {
            return {{}, {l.isStrict() ? *optSolved - 1 : *optSolved}};
        }
    }
    return {};
}

void Rel::getBounds(const NumVar &n, Bounds &res) const {
    if (has(n)) {
        if (isEq()) {
            const std::optional<Expr> eq = (lhs() - rhs()).solveTermFor(n, ResultMapsToInt);
            if (eq) {
                res.equality = *eq;
                res.lowerBounds.insert(*eq);
                res.upperBounds.insert(*eq);
            }
        } else if (isIneq()) {
            const auto p = getBoundFromIneq(n);
            if (p.first) {
                bool add = true;
                for (const auto &b: res.lowerBounds) {
                    const auto diff = b - *p.first;
                    if (diff.isRationalConstant() && !diff.toNum().is_negative()) {
                        add = false;
                        break;
                    }
                }
                if (add) res.lowerBounds.insert(*p.first);
            }
            if (p.second) {
                bool add = true;
                for (const auto &b: res.upperBounds) {
                    const auto diff = b - *p.second;
                    if (diff.isRationalConstant() && !diff.toNum().is_positive()) {
                        add = false;
                        break;
                    }
                }
                if (add) res.upperBounds.insert(*p.second);
            }
        }
    }
}

Rel Rel::toIntPoly() const {
    assert(isPoly());
    return Rel((l-r).toIntPoly(), op, 0);
}

Rel Rel::splitVariableAndConstantAddends(const std::set<NumVar> &params) const {
    assert(isIneq());

    //move everything to lhs
    Expr newLhs = l - r;
    Expr newRhs = 0;

    //move all numerical constants back to rhs
    newLhs = newLhs.expand();
    if (newLhs.isAdd()) {
        for (size_t i=0; i < newLhs.arity(); ++i) {
            bool isConstant = true;
            std::set<NumVar> vars = newLhs.op(i).vars();
            for (const NumVar &var: vars) {
                if (params.find(var) == params.end()) {
                    isConstant = false;
                    break;
                }
            }
            if (isConstant) {
                newRhs = newRhs - newLhs.op(i);
            }
        }
    } else {
        std::set<NumVar> vars = newLhs.vars();
        bool isConstant = true;
        for (const NumVar &var: vars) {
            if (params.find(var) == params.end()) {
                isConstant = false;
                break;
            }
        }
        if (isConstant) {
            newRhs = newRhs - newLhs;
        }
    }
    //other cases (mul, pow, sym) should not include numerical constants (only numerical coefficients)

    newLhs = newLhs + newRhs;
    return Rel(newLhs, op, newRhs);
}

bool Rel::isTriviallyTrue() const {
    auto optTrivial = checkTrivial();
    return (optTrivial && *optTrivial);
}

bool Rel::isTriviallyFalse() const {
    auto optTrivial = checkTrivial();
    return (optTrivial && !*optTrivial);
}

std::optional<bool> Rel::checkTrivial() const {
    Expr diff = (l - r).expand();
    if (diff.isRationalConstant()) {
        switch (op) {
        case Rel::eq: return diff.isZero();
        case Rel::neq: return !diff.isZero();
        case Rel::lt: return diff.toNum().is_negative();
        case Rel::leq: return !diff.toNum().is_positive();
        case Rel::gt: return diff.toNum().is_positive();
        case Rel::geq: return !diff.toNum().is_negative();
        }
        assert(false && "unknown relation");
    }
    return {};
}

void Rel::collectVars(std::set<NumVar> &res) const {
    l.collectVars(res);
    r.collectVars(res);
}

bool Rel::has(const Expr &pattern) const {
    return l.has(pattern) || r.has(pattern);
}

Rel Rel::subs(const ExprSubs &map) const {
    return Rel(l.subs(map), op, r.subs(map));
}

void Rel::applySubs(const ExprSubs &subs) {
    l.applySubs(subs);
    r.applySubs(subs);
}

std::string Rel::toString() const {
    std::stringstream s;
    s << *this;
    return s.str();
}

std::string Rel::toRedlog() const {
    return toString();
}

Rel::RelOp Rel::relOp() const {
    return op;
}

std::set<NumVar> Rel::vars() const {
    std::set<NumVar> res;
    collectVars(res);
    return res;
}

Rel Rel::makeRhsZero() const {
    return Rel(l - r, op, 0);
}

std::optional<std::string> Rel::toQepcad() const {
    const Rel gt = this->toGt();
    std::optional<std::string> diff = (gt.l - gt.r).toQepcad();
    if (!diff) return {};
    return *diff + " > 0";
}

bool Rel::isWellformed() const {
    return op != neq;
}

Rel Rel::buildEq(const Expr &x, const Expr &y) {
    return Rel(x, eq, y);
}

Rel Rel::buildNeq(const Expr &x, const Expr &y) {
    return Rel(x, neq, y);
}

Rel Rel::buildGeq(const Expr &x, const Expr &y) {
    return Rel(x, geq, y);
}

Rel Rel::buildLeq(const Expr &x, const Expr &y) {
    return Rel(x, leq, y);
}

Rel Rel::buildGt(const Expr &x, const Expr &y) {
    return Rel(x, gt, y);
}

Rel Rel::buildLt(const Expr &x, const Expr &y) {
    return Rel(x, lt, y);
}

Rel operator!(const Rel &x) {
    switch (x.op) {
    case Rel::eq: return Rel(x.l, Rel::neq, x.r);
    case Rel::neq: return Rel(x.l, Rel::eq, x.r);
    case Rel::lt: return Rel(x.l, Rel::geq, x.r);
    case Rel::leq: return Rel(x.l, Rel::gt, x.r);
    case Rel::gt: return Rel(x.l, Rel::leq, x.r);
    case Rel::geq: return Rel(x.l, Rel::lt, x.r);
    }
    throw std::invalid_argument("unknown relation");
}

std::ostream& operator<<(std::ostream &s, const Rel &rel) {
    s << rel.l;
    switch (rel.op) {
    case Rel::eq: s << " == ";
        break;
    case Rel::neq: s << " != ";
        break;
    case Rel::leq: s << " <= ";
        break;
    case Rel::geq: s << " >= ";
        break;
    case Rel::lt: s << " < ";
        break;
    case Rel::gt: s << " > ";
        break;
    }
    s << rel.r;
    return s;
}
