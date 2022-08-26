#include "boolexpr.hpp"
#include "guardtoolbox.hpp"
#include "redlogparsevisitor.h"

#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <numeric>

BoolExpression::~BoolExpression() {}

RelSet BoolExpression::lits() const {
    RelSet res;
    collectLits(res);
    return res;
}

Guard BoolExpression::conjunctionToGuard() const {
    const RelSet &lits = this->lits();
    return Guard(lits.begin(), lits.end());
}

VarSet BoolExpression::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

std::vector<Guard> BoolExpression::dnf() const {
    std::vector<Guard> res;
    dnf(res);
    return res;
}

QuantifiedFormula BoolExpression::quantify(const std::vector<Quantifier> &prefix) const {
    return QuantifiedFormula(prefix, shared_from_this());
}

BoolLit::BoolLit(const Rel &lit): lit(lit.makeRhsZero()) {}

bool BoolLit::isAnd() const {
    return false;
}

bool BoolLit::isOr() const {
    return false;
}

option<Rel> BoolLit::getLit() const {
    return {lit};
}

BoolExprSet BoolLit::getChildren() const {
    return {};
}

const BoolExpr BoolLit::negation() const {
    return BoolExpr(new BoolLit(!lit));
}

bool BoolLit::isLinear() const {
    return lit.isLinear();
}

bool BoolLit::isPolynomial() const {
    return lit.isPoly();
}

BoolExpr BoolLit::subs(const Subs &subs) const {
    return buildLit(lit.subs(subs));
}

BoolExpr BoolLit::toG() const {
    if (lit.isEq()) {
        std::vector<Rel> lits = {lit.lhs() - lit.rhs() >= 0, lit.rhs() - lit.lhs() >= 0};
        return buildAnd(lits);
    } else if (lit.isNeq()) {
        std::vector<Rel> lits = {lit.lhs() - lit.rhs() > 0, lit.rhs() - lit.lhs() > 0};
        return buildOr(lits);
    } else if (lit.isGZeroConstraint()) {
        return shared_from_this();
    } else {
        return buildLit(lit.makeRhsZero().toG());
    }
}

bool BoolLit::isConjunction() const {
    return true;
}

size_t BoolLit::size() const {
    return 1;
}

std::string BoolLit::toRedlog() const {
    return lit.toString();
}

RelSet BoolLit::universallyValidLits() const {
    return {lit};
}

void BoolLit::collectLits(RelSet &res) const {
    res.insert(lit);
}

void BoolLit::collectVars(VarSet &res) const {
    const VarSet &litVars = lit.vars();
    res.insert(litVars.begin(), litVars.end());
}

BoolExpr BoolLit::replaceRels(const RelMap<BoolExpr> map) const {
    if (map.find(lit) != map.end()) {
        return map.at(lit);
    } else {
        return shared_from_this();
    }
}

void BoolLit::dnf(std::vector<Guard> &res) const {
    if (res.empty()) {
        res.push_back({lit});
    } else {
        for (Guard &g: res) {
            g.push_back(lit);
        }
    }
}

unsigned BoolLit::hash() const {
    return lit.hash();
}

void BoolLit::getBounds(const Var &n, Bounds &res) const {
    if (lit.has(n)) {
        if (lit.isEq()) {
            const option<Expr> eq = GuardToolbox::solveTermFor(lit.lhs() - lit.rhs(), n, GuardToolbox::ResultMapsToInt);
            if (eq) {
                res.equality = *eq;
                res.lowerBounds.insert(*eq);
                res.upperBounds.insert(*eq);
            } else {
                res.exhaustive = false;
            }
        } else if (lit.isIneq()) {
            const auto p = GuardToolbox::getBoundFromIneq(lit, n);
            res.exhaustive &= (p.first || p.second);
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

Boundedness::Kind BoolLit::getBoundedness(const Var &n) const {
    return lit.getBoundedness(n);
}

option<BoolExpr> BoolLit::simplify() const {
    if (lit.isTriviallyTrue()) {
        return True;
    } else if (lit.isTriviallyFalse()) {
        return False;
    } else if (lit.isNeq()) {
        return buildLit(lit.lhs() < lit.rhs()) | (lit.lhs() > lit.rhs());
    } else {
        return {};
    }
}

bool BoolLit::isOctagon() const {
    return lit.isOctagon();
}

BoolLit::~BoolLit() {}


BoolJunction::BoolJunction(const BoolExprSet &children, ConcatOperator op): children(children), op(op) { }

bool BoolJunction::isAnd() const {
    return op == ConcatAnd;
}

bool BoolJunction::isOr() const {
    return op == ConcatOr;
}

option<Rel> BoolJunction::getLit() const {
    return {};
}

BoolExprSet BoolJunction::getChildren() const {
    return children;
}

const BoolExpr BoolJunction::negation() const {
    BoolExprSet newChildren;
    for (const BoolExpr &c: children) {
        newChildren.insert(!c);
    }
    switch (op) {
    case ConcatOr: return buildAnd(newChildren);
    case ConcatAnd: return buildOr(newChildren);
    }
    throw std::invalid_argument("unknown junction");
}

bool BoolJunction::isLinear() const {
    for (const BoolExpr &e: children) {
        if (!e->isLinear()) {
            return false;
        }
    }
    return true;
}

bool BoolJunction::isPolynomial() const {
    for (const BoolExpr &e: children) {
        if (!e->isPolynomial()) {
            return false;
        }
    }
    return true;
}

BoolExpr BoolJunction::subs(const Subs &subs) const {
    BoolExprSet newChildren;
    for (const BoolExpr &c: children) {
        newChildren.insert(c->subs(subs));
    }
    return isAnd() ? buildAnd(newChildren) : buildOr(newChildren);
}

BoolExpr BoolJunction::toG() const {
    BoolExprSet newChildren;
    for (const BoolExpr &c: children) {
        newChildren.insert(c->toG());
    }
    return isAnd() ? buildAnd(newChildren) : buildOr(newChildren);
}

bool BoolJunction::isConjunction() const {
    return isAnd() && std::all_of(children.begin(), children.end(), [](const BoolExpr c){
        return c->isConjunction();
    });
}

size_t BoolJunction::size() const {
    size_t res = 1;
    for (const BoolExpr &c: children) {
        res += c->size();
    }
    return res;
}

std::string BoolJunction::toRedlog() const {
    std::string infix = isAnd() ? " and " : " or ";
    std::string res;
    bool first = true;
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (first) first = false;
        else res += infix;
        res += (*it)->toRedlog();
    }
    return "(" + res + ")";
}

RelSet BoolJunction::universallyValidLits() const {
    RelSet res;
    if (isAnd()) {
        for (const BoolExpr &c: children) {
            const option<Rel> lit = c->getLit();
            if (lit) {
                res.insert(*lit);
            }
        }
    }
    return res;
}

void BoolJunction::collectLits(RelSet &res) const {
    for (const BoolExpr &c: children) {
        c->collectLits(res);
    }
}

void BoolJunction::collectVars(VarSet &res) const {
    for (const BoolExpr &c: children) {
        c->collectVars(res);
    }
}

BoolExpr BoolJunction::replaceRels(const RelMap<BoolExpr> map) const {
    BoolExprSet newChildren;
    for (const BoolExpr &c: children) {
        const option<BoolExpr> &newC = c->replaceRels(map);
        if (newC) {
            newChildren.insert(newC.get());
        }
    }
    return isAnd() ? buildAnd(newChildren) : buildOr(newChildren);
}

void BoolJunction::dnf(std::vector<Guard> &res) const {
    if (isAnd()) {
        for (const BoolExpr &e: children) {
            e->dnf(res);
        }
    } else {
        std::vector<Guard> oldRes(res);
        res.clear();
        for (const BoolExpr &e: children) {
            std::vector<Guard> newRes(oldRes);
            e->dnf(newRes);
            res.insert(res.end(), newRes.begin(), newRes.end());
        }
    }
}

void BoolJunction::getBounds(const Var &n, Bounds &res) const {
    if (isAnd()) {
        for (const auto &c: children) {
            c->getBounds(n, res);
        }
    } else if (isOr()) {
        bool first = true;
        for (const auto &c: children) {
            if (first) {
                c->getBounds(n, res);
                first = false;
            } else {
                Bounds cres = res;
                c->getBounds(n, cres);
                if (res.equality && (!cres.equality || !(*res.equality - *cres.equality).isZero())) {
                    res.equality = {};
                    res.exhaustive = false;
                }
                const auto intersect = [](ExprSet fst, const ExprSet &snd) {
                    bool changed = false;
                    for (auto it = fst.begin(); it != fst.end();) {
                        bool keep = false;
                        for (const auto &l2: snd) {
                            if ((*it - l2).isZero()) {
                                keep = true;
                                break;
                            }
                        }
                        if (keep) {
                            ++it;
                        } else {
                            changed = true;
                            it = fst.erase(it);
                        }
                    }
                    return changed;
                };
                if (intersect(res.lowerBounds, cres.lowerBounds)) res.exhaustive = false;
                if (intersect(res.upperBounds, cres.upperBounds)) res.exhaustive = false;
                if (!res.equality && res.lowerBounds.empty() && res.upperBounds.empty()) {
                    return;
                }
            }
        }
    }
}

Boundedness::Kind BoolJunction::getBoundedness(const Var &n) const {
    if (isAnd()) {
        Boundedness::Kind res = Boundedness::None;
        for (const auto &c: children) {
            res = Boundedness::unite(res, c->getBoundedness(n));
        }
        return res;
    } else if (isOr()) {
        Boundedness::Kind res = Boundedness::Both;
        for (const auto &c: children) {
            res = Boundedness::intersect(res, c->getBoundedness(n));
        }
        return res;
    }
    return Boundedness::Unknown;
}

option<BoolExpr> BoolJunction::simplify() const {
    if (isAnd()) {
        BoolExprSet newChildren;
        bool changed = false;
        for (const auto &c: children) {
            const auto simp = c->simplify();
            if (simp && *simp == False) {
                return False;
            } else if (simp) {
                if (*simp != True) {
                    newChildren.insert(*simp);
                }
                changed = true;
            } else {
                newChildren.insert(c);
            }
        }
        if (!changed) {
            return {};
        } else if (newChildren.empty()) {
            return True;
        } else {
            return buildAnd(newChildren);
        }
    } else if (isOr()) {
        BoolExprSet newChildren;
        bool changed = false;
        for (const auto &c: children) {
            const auto simp = c->simplify();
            if (simp && *simp == True) {
                return True;
            } else if (simp) {
                if (*simp != False) {
                    newChildren.insert(*simp);
                }
                changed = true;
            } else {
                newChildren.insert(c);
            }
        }
        if (!changed) {
            return {};
        } else if (newChildren.empty()) {
            return False;
        } else {
            return buildOr(newChildren);
        }
    }
    return {};
}

bool BoolJunction::isOctagon() const {
    if (isAnd()) {
        for (const auto &c: children) {
            if (!c->isOctagon()) {
                return false;
            }
        }
        return true;
    }
    return false;
}

unsigned BoolJunction::hash() const {
    unsigned hash = 7;
    for (const BoolExpr& c: children) {
        hash = 31 * hash + c->hash();
    }
    hash = 31 * hash + op;
    return hash;
}

BoolJunction::~BoolJunction() {}


Quantifier::Quantifier(const Type &qType, const VarSet &vars, const VarMap<Expr> &lowerBounds, const VarMap<Expr> &upperBounds): qType(qType), vars(vars), lowerBounds(lowerBounds), upperBounds(upperBounds) {}

option<Expr> Quantifier::lowerBound(const Var &x) const {
    const auto it = lowerBounds.find(x);
    if (it == lowerBounds.end()) {
        return {};
    } else {
        return it->second;
    }
}

option<Expr> Quantifier::upperBound(const Var &x) const {
    const auto it = upperBounds.find(x);
    if (it == upperBounds.end()) {
        return {};
    } else {
        return it->second;
    }
}

Quantifier Quantifier::negation() const {
    auto _qType = qType == Type::Exists ? Type::Forall : Type::Exists;
    return Quantifier(_qType, vars, lowerBounds, upperBounds);
}

const VarSet& Quantifier::getVars() const {
    return vars;
}

Quantifier::Type Quantifier::getType() const {
    return qType;
}

std::string Quantifier::toRedlog() const {
    std::string q = qType == Type::Exists ? "ex" : "all";
    std::string res;
    for (const auto& var: vars) {
        res = q + "(" + var.get_name() + ",";
    }
    return res;
}

Quantifier Quantifier::remove(const Var &x) const {
    VarSet newVars(vars);
    VarMap<Expr> newLowerBounds(lowerBounds);
    VarMap<Expr> newUpperBounds(upperBounds);
    newVars.erase(x);
    newLowerBounds.erase(x);
    newUpperBounds.erase(x);
    return Quantifier(qType, newVars, newLowerBounds, newUpperBounds);
}

QuantifiedFormula::QuantifiedFormula(std::vector<Quantifier> prefix, const BoolExpr &matrix): prefix(prefix), matrix(matrix) {}

const QuantifiedFormula QuantifiedFormula::negation() const {
    std::vector<Quantifier> _prefix;
    std::transform(prefix.begin(), prefix.end(), _prefix.begin(), [](const auto &q ){return q.negation();});
    return QuantifiedFormula(_prefix, matrix->negation());
}

bool QuantifiedFormula::isLinear() const {
    return matrix->isLinear();
}

bool QuantifiedFormula::isPolynomial() const {
    return matrix->isPolynomial();
}

VarSet QuantifiedFormula::boundVars() const {
    VarSet res;
    for (const Quantifier &q: prefix) {
        res.insert(q.getVars().begin(), q.getVars().end());
    }
    return res;
}

QuantifiedFormula QuantifiedFormula::subs(const Subs &subs) const {
    auto dom = subs.domain();
    Subs projected = subs.project(freeVars());
    return QuantifiedFormula(prefix, matrix->subs(projected));
}

QuantifiedFormula QuantifiedFormula::toG() const {
    return QuantifiedFormula(prefix, matrix->toG());
}

void QuantifiedFormula::collectLits(RelSet &res) const {
    matrix->collectLits(res);
}

VarSet QuantifiedFormula::freeVars() const {
    VarSet vars, free;
    VarSet bv = boundVars();
    matrix->collectVars(vars);
    for (const Var& x: vars) {
        if (bv.find(x) == bv.end()) {
            free.insert(x);
        }
    }
    return free;
}

std::string QuantifiedFormula::toRedlog() const {
    std::string res;
    for (const auto &q: prefix) {
        res += q.toRedlog();
    }
    res += matrix->toRedlog();
    for (const auto &q: prefix) {
        unsigned size = q.getVars().size();
        for (unsigned i = 0; i < size; ++i) {
            res += ")";
        }
    }
    return res;
}

std::pair<QuantifiedFormula, Subs> QuantifiedFormula::normalizeVariables(VariableManager &varMan) const {
    VarSet vars;
    matrix->collectVars(vars);
    Subs normalization, inverse;
    unsigned count = 0;
    for (Var x: vars) {
        std::string varName = "x" + std::to_string(count);
        option<Var> replacement = varMan.getVar(varName);
        if (!replacement) replacement = varMan.addFreshTemporaryVariable(varName);
        ++count;
        normalization.put(x, replacement.get());
        inverse.put(replacement.get(), x);
    }
    const auto newMatrix = matrix->subs(normalization);
    std::vector<Quantifier> newPrefix;
    for (const auto& q: prefix) {
        VarSet newVars;
        VarMap<Expr> newLowerBounds;
        VarMap<Expr> newUpperBounds;
        for (const auto& x: q.getVars()) {
            if (vars.find(x) != vars.end()) {
                newVars.insert(normalization.get(x).toVar());
                auto lb = q.lowerBound(x);
                auto ub = q.upperBound(x);
                if (lb) {
                    newLowerBounds[x] = lb.get();
                }
                if (ub) {
                    newUpperBounds[x] = ub.get();
                }
            }
        }
        if (!newVars.empty()) {
            newPrefix.push_back(Quantifier(q.getType(), newVars, newLowerBounds, newUpperBounds));
        }
    }
    return {QuantifiedFormula(newPrefix, newMatrix), inverse};
}

option<QuantifiedFormula> QuantifiedFormula::simplify() const {
    const option<BoolExpr> newMatrix = matrix->simplify();
    if (newMatrix) {
        return QuantifiedFormula(prefix, *newMatrix);
    } else {
        return *this;
    }
}

bool QuantifiedFormula::isTiviallyTrue() const {
    return matrix == True;
}

bool QuantifiedFormula::isTiviallyFalse() const {
    return matrix == False;
}

std::vector<Quantifier> QuantifiedFormula::getPrefix() const {
    return prefix;
}

BoolExpr QuantifiedFormula::getMatrix() const {
    return matrix;
}

bool QuantifiedFormula::isConjunction() const {
    return matrix->isConjunction();
}

BoolExpr build(BoolExprSet xs, ConcatOperator op) {
    std::stack<BoolExpr> todo;
    for (const BoolExpr &x: xs) {
        todo.push(x);
    }
    BoolExprSet children;
    while (!todo.empty()) {
        BoolExpr current = todo.top();
        if ((op == ConcatAnd && current->isAnd()) || (op == ConcatOr && current->isOr())) {
            const BoolExprSet &currentChildren = current->getChildren();
            todo.pop();
            for (const BoolExpr &c: currentChildren) {
                todo.push(c);
            }
        } else {
            children.insert(current);
            todo.pop();
        }
    }
    if (children.size() == 1) {
        return *children.begin();
    }
    return BoolExpr(new BoolJunction(children, op));
}

BoolExpr build(const RelSet &xs, ConcatOperator op) {
    BoolExprSet children;
    for (const Rel &x: xs) {
        children.insert(buildLit(x));
    }
    return build(children, op);
}

const BoolExpr buildAnd(const RelSet &xs) {
    return build(xs, ConcatAnd);
}

const BoolExpr buildAnd(const BoolExprSet &xs) {
    return build(xs, ConcatAnd);
}

const BoolExpr buildConjunctiveClause(const BoolExprSet &xs) {
    return BoolExpr(new BoolJunction(xs, ConcatAnd));
}

const BoolExpr buildOr(const RelSet &xs) {
    return build(xs, ConcatOr);
}

const BoolExpr buildOr(const BoolExprSet &xs) {
    return build(xs, ConcatOr);
}

const BoolExpr buildAnd(const std::vector<Rel> &xs) {
    return build(RelSet(xs.begin(), xs.end()), ConcatAnd);
}

const BoolExpr buildAnd(const std::vector<BoolExpr> &xs) {
    return build(BoolExprSet(xs.begin(), xs.end()), ConcatAnd);
}

const BoolExpr buildOr(const std::vector<Rel> &xs) {
    return build(RelSet(xs.begin(), xs.end()), ConcatOr);
}

const BoolExpr buildOr(const std::vector<BoolExpr> &xs) {
    return build(BoolExprSet(xs.begin(), xs.end()), ConcatOr);
}

const BoolExpr buildLit(const Rel &lit) {
    return BoolExpr(new BoolLit(lit));
}

const BoolExpr True = buildAnd(std::vector<BoolExpr>());
const BoolExpr False = buildOr(std::vector<BoolExpr>());

const BoolExpr operator &(const BoolExpr a, const BoolExpr b) {
    const BoolExprSet &children = {a, b};
    return buildAnd(children);
}

const BoolExpr operator &(const BoolExpr a, const Rel &b) {
    return a & buildLit(b);
}

const BoolExpr operator |(const BoolExpr a, const BoolExpr b) {
    const BoolExprSet &children = {a, b};
    return buildOr(children);
}

const BoolExpr operator |(const BoolExpr a, const Rel b) {
    return a | buildLit(b);
}

const BoolExpr operator !(const BoolExpr a) {
    return a->negation();
}

bool operator ==(const BoolExpr a, const BoolExpr b) {
    if (a->getLit() != b->getLit()) {
        return false;
    }
    if (a->getLit()) {
        return true;
    }
    if (a->isAnd() != b->isAnd()) {
        return false;
    }
    return a->getChildren() == b->getChildren();
}

bool operator !=(const BoolExpr a, const BoolExpr b) {
    return !(a==b);
}

bool boolexpr_compare::operator() (BoolExpr a, BoolExpr b) const {
    if (a->getLit()) {
        if (!b->getLit()) {
            return true;
        } else {
            return a->getLit().get() < b->getLit().get();
        }
    }
    if (a->isAnd() && !b->isAnd()) {
        return true;
    }
    if (!a->isAnd() && b->isAnd()) {
        return false;
    }
    return a->getChildren() < b->getChildren();
}

std::ostream& operator<<(std::ostream &s, const BoolExpr e) {
    if (e->getLit()) {
        s << e->getLit().get();
    } else if (e->getChildren().empty()) {
        if (e->isAnd()) {
            s << "TRUE";
        } else {
            s << "FALSE";
        }
    } else {
        bool first = true;
        s << "(";
        for (const BoolExpr &c: e->getChildren()) {
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

std::ostream& operator<<(std::ostream &s, const QuantifiedFormula &f) {
    for (const auto &q: f.prefix) {
        switch (q.getType()) {
        case Quantifier::Type::Exists:
            s << "EX";
            break;
        case Quantifier::Type::Forall:
            s << "ALL";
            break;
        }
        for (const auto &x: q.getVars()) {
            s << " " << x;
            const auto lb = q.lowerBound(x);
            const auto ub = q.upperBound(x);
            if (lb || ub) {
                s << " in [";
                if (lb) {
                    s << *lb;
                } else {
                    s << "-oo";
                }
                s << ",";
                if (ub) {
                    s << *ub;
                } else {
                    s << "oo";
                }
                s << "]";
            }
        }
        s << " . ";
    }
    s << f.matrix;
    return s;
}
