#include "boolexpr.hpp"
#include "guardtoolbox.hpp"
#include "exceptions.hpp"

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

void BoolExpression::findConsequences(const BoolVar &var, BoolExprSet &res) const {
    const auto lit = buildLit(var, false);
    if (isAnd()) {
        for (const auto &c: getChildren()) {
            c->findConsequences(var, res);
        }
    } else if (isOr()) {
        BoolExprSet children = getChildren();
        bool trivial = true;
        for (auto it = children.begin(); it != children.end();) {
            const BoolExpr c = *it;
            if (c == lit || (c->isAnd() && c->getChildren().contains(lit))) {
                it = children.erase(it);
                trivial = false;
            } else {
                ++it;
            }
        }
        if (!trivial) {
            res.insert(buildOr(children));
        }
    }
}

VarSet BoolExpression::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

BoolVarSet BoolExpression::boolVars() const {
    BoolVarSet res;
    collectBoolVars(res);
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

BoolTheoryLit::BoolTheoryLit(const Rel &lit): lit(lit.makeRhsZero()) {}

bool BoolTheoryLit::isAnd() const {
    return false;
}

bool BoolTheoryLit::isOr() const {
    return false;
}

option<Rel> BoolTheoryLit::getTheoryLit() const {
    return {lit};
}

option<BoolLit> BoolTheoryLit::getLit() const {
    return {};
}

BoolExprSet BoolTheoryLit::getChildren() const {
    return {};
}

const BoolExpr BoolTheoryLit::negation() const {
    return BoolExpr(new BoolTheoryLit(!lit));
}

bool BoolTheoryLit::isLinear() const {
    return lit.isLinear();
}

bool BoolTheoryLit::isPolynomial() const {
    return lit.isPoly();
}

BoolExpr BoolTheoryLit::subs(const ExprSubs &subs) const {
    return buildTheoryLit(lit.subs(subs));
}

BoolExpr BoolTheoryLit::toG() const {
    if (lit.isEq()) {
        std::vector<Rel> lits = {lit.lhs() - lit.rhs() >= 0, lit.rhs() - lit.lhs() >= 0};
        return buildAnd(lits);
    } else if (lit.isNeq()) {
        std::vector<Rel> lits = {lit.lhs() - lit.rhs() > 0, lit.rhs() - lit.lhs() > 0};
        return buildOr(lits);
    } else if (lit.isGZeroConstraint()) {
        return shared_from_this();
    } else {
        return buildTheoryLit(lit.makeRhsZero().toG());
    }
}

bool BoolTheoryLit::isConjunction() const {
    return true;
}

size_t BoolTheoryLit::size() const {
    return 1;
}

std::string BoolTheoryLit::toRedlog() const {
    return lit.toString();
}

RelSet BoolTheoryLit::universallyValidLits() const {
    return {lit};
}

void BoolTheoryLit::collectLits(RelSet &res) const {
    res.insert(lit);
}

void BoolTheoryLit::collectVars(VarSet &res) const {
    const VarSet &litVars = lit.vars();
    res.insert(litVars.begin(), litVars.end());
}

void BoolTheoryLit::collectBoolVars(BoolVarSet &res) const {}

BoolExpr BoolTheoryLit::replaceRels(const RelMap<BoolExpr> map) const {
    if (map.find(lit) != map.end()) {
        return map.at(lit);
    } else {
        return shared_from_this();
    }
}

void BoolTheoryLit::dnf(std::vector<Guard> &res) const {
    if (res.empty()) {
        res.push_back({lit});
    } else {
        for (Guard &g: res) {
            g.push_back(lit);
        }
    }
}

unsigned BoolTheoryLit::hash() const {
    return lit.hash();
}

void BoolTheoryLit::getBounds(const Var &n, Bounds &res) const {
    if (lit.has(n)) {
        if (lit.isEq()) {
            const option<Expr> eq = GuardToolbox::solveTermFor(lit.lhs() - lit.rhs(), n, GuardToolbox::ResultMapsToInt);
            if (eq) {
                res.equality = *eq;
                res.lowerBounds.insert(*eq);
                res.upperBounds.insert(*eq);
            }
        } else if (lit.isIneq()) {
            const auto p = GuardToolbox::getBoundFromIneq(lit, n);
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

option<BoolExpr> BoolTheoryLit::simplify() const {
    if (lit.isTriviallyTrue()) {
        return True;
    } else if (lit.isTriviallyFalse()) {
        return False;
    } else if (lit.isNeq()) {
        return buildTheoryLit(lit.lhs() < lit.rhs()) | (lit.lhs() > lit.rhs());
    } else {
        return {};
    }
}

bool BoolTheoryLit::isOctagon() const {
    return lit.isOctagon();
}

int BoolTheoryLit::compare(const BoolExpr that) const {
    if (that->getLit()) {
        return 1;
    }
    if (!that->getTheoryLit()) {
        return -1;
    }
    return lit.compare(*that->getTheoryLit());
}

BoolTheoryLit::~BoolTheoryLit() {}


BoolLit::BoolLit(const BoolVar &var, bool negated): var(var), negated(negated) {}

bool BoolLit::isAnd() const {
    return false;
}

bool BoolLit::isOr() const {
    return false;
}

option<Rel> BoolLit::getTheoryLit() const {
    return {};
}

option<BoolLit> BoolLit::getLit() const {
    return *this;
}

BoolExprSet BoolLit::getChildren() const {
    return {};
}

const BoolExpr BoolLit::negation() const {
    return BoolExpr(new BoolLit(var, !negated));
}

bool BoolLit::isLinear() const {
    return true;
}

BoolExpr BoolLit::subs(const ExprSubs &subs) const {
    return shared_from_this();
}

bool BoolLit::isPolynomial() const {
    return true;
}

BoolExpr BoolLit::toG() const {
    return shared_from_this();
}

bool BoolLit::isConjunction() const {
    return true;
}

size_t BoolLit::size() const {
    return 1;
}

std::string BoolLit::toRedlog() const {
    return var.getName();
}

RelSet BoolLit::universallyValidLits() const {
    return {};
}

void BoolLit::collectLits(RelSet &res) const {}

void BoolLit::collectVars(VarSet &res) const {}

BoolVar BoolLit::getBoolVar() const {
    return var;
}

void BoolLit::collectBoolVars(BoolVarSet &res) const {
    res.insert(this->getBoolVar());
}

BoolExpr BoolLit::replaceRels(const RelMap<BoolExpr> map) const {
    return shared_from_this();
}

void BoolLit::dnf(std::vector<Guard> &res) const {
    throw UnsupportedOperationError();
}

unsigned BoolLit::hash() const {
    return var.hash();
}

void BoolLit::getBounds(const Var &n, Bounds &res) const {}

option<BoolExpr> BoolLit::simplify() const {
    return {};
}

bool BoolLit::isOctagon() const {
    return false;
}

bool BoolLit::isNegated() const {
    return negated;
}

bool operator<(const BoolLit &l1, const BoolLit &l2) {
    if (l1.isNegated() && !l2.isNegated()) {
        return true;
    }
    if (l2.isNegated()) {
        return false;
    }
    return l1.getBoolVar() < l2.getBoolVar();
}

int BoolLit::compare(const BoolExpr that) const {
    if (!that->getLit()) {
        return -1;
    }
    const auto lit = *that->getLit();
    if (negated && !lit.negated) {
        return -1;
    }
    if (!negated && lit.negated) {
        return 1;
    }
    return var.compare(lit.var);
}

BoolLit::~BoolLit() {}

std::ostream& operator<<(std::ostream &s, const BoolLit &e) {
    if (e.isNegated()) {
        s << "!";
    }
    return s << e.getBoolVar();
}


BoolJunction::BoolJunction(const BoolExprSet &children, ConcatOperator op): children(children), op(op) { }

bool BoolJunction::isAnd() const {
    return op == ConcatAnd;
}

bool BoolJunction::isOr() const {
    return op == ConcatOr;
}

option<Rel> BoolJunction::getTheoryLit() const {
    return {};
}

option<BoolLit> BoolJunction::getLit() const {
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

BoolExpr BoolJunction::subs(const ExprSubs &subs) const {
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
            const option<Rel> lit = c->getTheoryLit();
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

void BoolJunction::collectBoolVars(BoolVarSet &res) const {
    for (const BoolExpr &c: children) {
        c->collectBoolVars(res);
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
                }
                if (!res.equality && res.lowerBounds.empty() && res.upperBounds.empty()) {
                    return;
                }
            }
        }
    }
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

int BoolJunction::compare(const BoolExpr that) const {
    if (!that->isAnd() && !that->isOr()) {
        return 1;
    }
    if (isAnd() && that->isOr()) {
        return 1;
    }
    if (isOr() && that->isAnd()) {
        return -1;
    }
    const auto c1 = getChildren();
    const auto c2 = that->getChildren();
    if (c1 == c2) return 0;
    return c1 < c2 ? -1 : 1;
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

QuantifiedFormula QuantifiedFormula::subs(const ExprSubs &subs) const {
    auto dom = subs.domain();
    const ExprSubs projected = subs.project(freeVars());
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

std::pair<QuantifiedFormula, ExprSubs> QuantifiedFormula::normalizeVariables(VariableManager &varMan) const {
    VarSet vars;
    matrix->collectVars(vars);
    ExprSubs normalization, inverse;
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
        children.insert(buildTheoryLit(x));
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

const BoolExpr buildTheoryLit(const Rel &lit) {
    return BoolExpr(new BoolTheoryLit(lit));
}

const BoolExpr buildLit(const BoolVar &var, bool negated) {
    return BoolExpr(new BoolLit(var, negated));
}

const BoolExpr True = buildAnd(std::vector<BoolExpr>());
const BoolExpr False = buildOr(std::vector<BoolExpr>());

const BoolExpr operator &(const BoolExpr a, const BoolExpr b) {
    const BoolExprSet &children = {a, b};
    return buildAnd(children);
}

const BoolExpr operator &(const BoolExpr a, const Rel &b) {
    return a & buildTheoryLit(b);
}

const BoolExpr operator |(const BoolExpr a, const BoolExpr b) {
    const BoolExprSet &children = {a, b};
    return buildOr(children);
}

const BoolExpr operator |(const BoolExpr a, const Rel b) {
    return a | buildTheoryLit(b);
}

const BoolExpr operator !(const BoolExpr a) {
    return a->negation();
}

bool operator ==(const BoolExpr a, const BoolExpr b) {
    if (a->getTheoryLit() != b->getTheoryLit()) {
        return false;
    }
    if (a->getTheoryLit()) {
        return true;
    }
    if (a->getLit().has_value() != b->getLit().has_value()) {
        return false;
    }
    if (a->getLit()) {
        if (a->getLit()->isNegated() != b->getLit()->isNegated()) {
            return false;
        }
        return a->getLit()->getBoolVar().equals(b->getLit()->getBoolVar());
    }
    if (a->isAnd() != b->isAnd()) {
        return false;
    }
    return a->getChildren() == b->getChildren();
}

bool operator !=(const BoolExpr a, const BoolExpr b) {
    return !(a==b);
}

bool boolexpr_compare::operator() (const BoolExpr a, const BoolExpr b) const {
    return a->compare(b) < 0;
}

std::ostream& operator<<(std::ostream &s, const BoolExpr e) {
    if (e->getTheoryLit()) {
        s << *e->getTheoryLit();
    } else if (e->getLit()) {
        s << *e->getLit();
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
