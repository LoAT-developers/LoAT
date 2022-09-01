#include "rel.hpp"

#include <sstream>

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

Rel operator<(const Expr &x, const Expr &y) {
    return Rel(x.ex, Rel::lt, y.ex);
}

Rel operator>(const Expr &x, const Expr &y) {
    return Rel(x.ex, Rel::gt, y.ex);
}

Rel operator<=(const Expr &x, const Expr &y) {
    return Rel(x.ex, Rel::leq, y.ex);
}

Rel operator>=(const Expr &x, const Expr &y) {
    return Rel(x.ex, Rel::geq, y.ex);
}

Rel Rel::buildNeq(const Expr &x, const Expr &y) {
    return Rel(x, Rel::neq, y);
}

Rel Rel::buildEq(const Expr &x, const Expr &y) {
    return Rel(x, Rel::eq, y);
}

std::ostream& operator<<(std::ostream &s, const Expr &e) {
    s << e.ex;
    return s;
}

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

bool Rel::isLinear(const option<VarSet> &vars) const {
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

    option<Rel> res;
    if (isStrict()) {
        GiNaC::numeric lcm = GiNaC::lcm(l.denomLcm(), r.denomLcm());
        res = lcm == 1 ? *this : Rel(l * lcm, op, r * lcm);
    } else {
        res = *this;
    }
    //flip > or >=
    if (res->op == Rel::gt) {
        res = res->rhs() < res->lhs();
    } else if (op == Rel::geq) {
        res = res->rhs() <= res->lhs();
    }

    if (res->op == Rel::lt) {
        res = res->lhs() <= (res->rhs() - 1);
    }

    assert(res->op == Rel::leq);
    return res.get();
}

Rel Rel::toGt() const {
    assert(isIneq());
    assert(isPoly() || isStrict());

    option<Rel> res;
    if (!isStrict()) {
        GiNaC::numeric lcm = GiNaC::lcm(l.denomLcm(), r.denomLcm());
        res = lcm == 1 ? *this : Rel(l * lcm, op, r * lcm);
    } else {
        res = *this;
    }
    if (res->op == Rel::lt) {
        res = res->rhs() > res->lhs();
    } else if (op == Rel::leq) {
        res = res->rhs() >= res->lhs();
    }

    if (res->op == Rel::geq) {
        res = res->lhs() + 1 > res->rhs();
    }

    assert(res->op == Rel::gt);
    return res.get();
}

Rel Rel::toL() const {
    assert(isIneq());
    if (op == Rel::gt) {
        return r < l;
    } else if (op == Rel::geq) {
        return r <= l;
    } else {
        return *this;
    }
}

Rel Rel::toG() const {
    assert(isIneq());
    if (op == Rel::lt) {
        return r > l;
    } else if (op == Rel::leq) {
        return r >= l;
    } else {
        return *this;
    }
}

bool Rel::isStrict() const {
    assert(isIneq());
    return op == lt || op == gt;
}

bool Rel::isOctagon() const {
    return op != neq && (lhs() - rhs()).expand().isOctagon();
}

Boundedness::Kind Rel::getBoundedness(const Var &x) const {
    if (!has(x)) return Boundedness::None;
    if (isEq()) return Boundedness::Both;
    if (!isPoly()) return Boundedness::Unknown;
    const Rel normalized = toG();
    const Expr e = (normalized.lhs() - normalized.rhs()).expand();
    Boundedness::Kind res = Boundedness::None;
    for (int d = 1; d <= e.degree(x); ++d) {
        const Expr coeff = e.coeff(x, d);
        if (!coeff.isRationalConstant()) {
            return Boundedness::Unknown;
        } else {
            Boundedness::Kind expected = coeff.toNum().is_positive() ? Boundedness::Lower : Boundedness::Upper;
            if (res == Boundedness::None) {
                res = expected;
            } else if (res != expected) {
                return Boundedness::Unknown;
            }
        }
    }
    return res;
}

Rel Rel::toIntPoly() const {
    assert(isPoly());
    return Rel((l-r).toIntPoly(), op, 0);
}

Rel Rel::splitVariableAndConstantAddends(const VarSet &params) const {
    assert(isIneq());

    //move everything to lhs
    Expr newLhs = l - r;
    Expr newRhs = 0;

    //move all numerical constants back to rhs
    newLhs = newLhs.expand();
    if (newLhs.isAdd()) {
        for (size_t i=0; i < newLhs.arity(); ++i) {
            bool isConstant = true;
            VarSet vars = newLhs.op(i).vars();
            for (const Var &var: vars) {
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
        VarSet vars = newLhs.vars();
        bool isConstant = true;
        for (const Var &var: vars) {
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
    return (optTrivial && optTrivial.get());
}

bool Rel::isTriviallyFalse() const {
    auto optTrivial = checkTrivial();
    return (optTrivial && !optTrivial.get());
}

option<bool> Rel::checkTrivial() const {
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

void Rel::collectVariables(VarSet &res) const {
    l.collectVars(res);
    r.collectVars(res);
}

bool Rel::has(const Expr &pattern) const {
    return l.has(pattern) || r.has(pattern);
}

Rel Rel::subs(const Subs &map) const {
    return Rel(l.subs(map), op, r.subs(map));
}

void Rel::applySubs(const Subs &subs) {
    l.applySubs(subs);
    r.applySubs(subs);
}

std::string Rel::toString() const {
    std::stringstream s;
    s << *this;
    return s.str();
}

Rel::RelOp Rel::relOp() const {
    return op;
}

VarSet Rel::vars() const {
    VarSet res;
    collectVariables(res);
    return res;
}

Rel Rel::makeRhsZero() const {
    return Rel(l - r, op, 0);
}

unsigned Rel::hash() const {
    unsigned hash = 7;
    hash = 31 * hash + l.hash();
    hash = 31 * hash + op;
    hash = 31 * hash + r.hash();
    return hash;
}

option<std::string> Rel::toQepcad() const {
    const Rel gt = this->toGt();
    option<std::string> diff = (gt.l - gt.r).toQepcad();
    if (!diff) return {};
    return diff.get() + " > 0";
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

bool operator==(const Rel &x, const Rel &y) {
    return x.l.equals(y.l) && x.op == y.op && x.r.equals(y.r);
}

bool operator!=(const Rel &x, const Rel &y) {
    return !(x == y);
}

bool operator<(const Rel &x, const Rel &y) {
    int fst = x.lhs().compare(y.lhs());
    if (fst != 0) {
        return fst < 0;
    }
    if (x.relOp() != y.relOp()) {
        return x.relOp() < y.relOp();
    }
    return x.rhs().compare(y.rhs()) < 0;
}

Rel operator<(const Var &x, const Expr &y) {
    return Expr(x) < y;
}

Rel operator<(const Expr &x, const Var &y) {
    return x < Expr(y);
}

Rel operator<(const Var &x, const Var &y) {
    return Expr(x) < Expr(y);
}

Rel operator>(const Var &x, const Expr &y) {
    return Expr(x) > y;
}

Rel operator>(const Expr &x, const Var &y) {
    return x > Expr(y);
}

Rel operator>(const Var &x, const Var &y) {
    return Expr(x) > Expr(y);
}

Rel operator<=(const Var &x, const Expr &y) {
    return Expr(x) <= y;
}

Rel operator<=(const Expr &x, const Var &y) {
    return x <= Expr(y);
}

Rel operator<=(const Var &x, const Var &y) {
    return Expr(x) <= Expr(y);
}

Rel operator>=(const Var &x, const Expr &y) {
    return Expr(x) >= y;
}

Rel operator>=(const Expr &x, const Var &y) {
    return x >= Expr(y);
}

Rel operator>=(const Var &x, const Var &y) {
    return Expr(x) >= Expr(y);
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
