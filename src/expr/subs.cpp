#include "subs.hpp"

#include <boost/functional/hash.hpp>

Subs::Subs() {}

Subs::Subs(const Var &key, const Expr &val): exprSubs(key, val) {}

Subs::Subs(const BoolVar &key, const BoolExpr &val): boolSubs(key, val) {}

Subs::Subs(const ExprSubs &exprSubs, const BoolSubs &boolSubs): exprSubs(exprSubs), boolSubs(boolSubs) {}

void Subs::collectVars(BoolVarSet &vars) const {
    boolSubs.collectVars(vars);
}

void Subs::collectVars(VarSet &vars) const {
    return exprSubs.collectVars(vars);
}

unsigned Subs::hash() const {
    size_t seed = 0;
    boost::hash_combine(seed, exprSubs.hash());
    boost::hash_combine(seed, boolSubs.hash());
    return seed;
}

void Subs::put(const Var &var, const Expr &val) {
    exprSubs.put(var, val);
}

void Subs::put(const BoolVar &var, const BoolExpr &val) {
    boolSubs.put(var, val);
}

Expr Subs::get(const Var &var) const {
    return exprSubs.get(var);
}

BoolExpr Subs::get(const BoolVar &var) const {
    return boolSubs.get(var);
}

ExprSubs& Subs::getExprSubs() {
    return exprSubs;
}

BoolSubs& Subs::getBoolSubs() {
    return boolSubs;
}

const ExprSubs& Subs::getExprSubs() const {
    return exprSubs;
}

const BoolSubs& Subs::getBoolSubs() const {
    return boolSubs;
}

ExprSubs::const_iterator Subs::find(const Var& v) const {
    return exprSubs.find(v);
}

BoolSubs::const_iterator Subs::find(const BoolVar& v) const {
    return boolSubs.find(v);
}

BoolExpr Subs::operator()(const BoolExpr &e) const {
    if (e->getLit()) {
        const BoolVar var = e->getLit()->getBoolVar();
        const auto it = boolSubs.find(var);
        if (it == boolSubs.end()) {
            return e;
        } else {
            return e->getLit()->isNegated() ? !it->second : it->second;
        }
    } else if (e->getTheoryLit()) {
        return buildTheoryLit(e->getTheoryLit()->subs(exprSubs));
    } else {
        BoolExprSet newChildren;
        for (const auto &c: e->getChildren()) {
            newChildren.insert((*this)(c));
        }
        return e->isAnd() ? buildAnd(newChildren) : buildOr(newChildren);
    }
}

Expr Subs::operator()(const Expr &e) const {
    return e.subs(exprSubs);
}

Rel Subs::operator()(const Rel &e) const {
    return e.subs(exprSubs);
}

Subs Subs::compose(const Subs &that) const {
    return Subs(exprSubs.compose(that.exprSubs), boolSubs.compose(that.boolSubs));
}

Subs Subs::concat(const Subs &that) const {
    return Subs(exprSubs.concat(that.exprSubs), boolSubs.concat(that.boolSubs));
}

bool Subs::changes(const Var &var) const {
    return exprSubs.changes(var);
}

bool Subs::changes(const BoolVar &var) const {
    return boolSubs.changes(var);
}

bool Subs::empty() const {
    return exprSubs.empty() && boolSubs.empty();
}

size_t Subs::size() const {
    return exprSubs.size() + boolSubs.size();
}

Subs Subs::project(const VarSet &evars, const BoolVarSet &bvars) const {
    return Subs(exprSubs.project(evars), boolSubs.project(bvars));
}

void Subs::erase(const Var &var) {
    exprSubs.erase(var);
}

void Subs::erase(const BoolVar &var) {
    boolSubs.erase(var);
}

int Subs::compare(const Subs &that) const {
    int cmp = exprSubs.compare(that.exprSubs);
    if (cmp != 0) {
        return cmp;
    }
    return boolSubs.compare(that.boolSubs);
}

std::ostream& operator<<(std::ostream &s, const Subs &e) {
    if (e.getBoolSubs().empty()) {
        return s << e.getExprSubs();
    } else if (e.getExprSubs().empty()) {
        return s << e.getBoolSubs();
    } else {
        return s << e.getExprSubs() << " u " << e.getBoolSubs();
    }
}

bool operator==(const Subs &s1, const Subs &s2) {
    return s1.getExprSubs() == s2.getExprSubs() && s1.getBoolSubs() == s2.getBoolSubs();
}

bool operator<(const Subs &s1, const Subs &s2) {
    return s1.compare(s2) < 0;
}
