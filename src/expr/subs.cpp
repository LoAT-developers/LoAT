#include "subs.hpp"
#include "booltheory.hpp"

#include <boost/functional/hash.hpp>

Subs::Subs() {}

Subs::Subs(const BoolVar &key, const BoolExpr &val): boolSubs(key, val) {}

Subs::Subs(const ThSubs &thSubs, const BoolSubs &boolSubs): thSubs(thSubs), boolSubs(boolSubs) {}

void Subs::collectVars(VarSet &vars) const {
    boolSubs.collectVars(vars.get<BoolTheory>());
    thSubs.collectVars(vars);
}

unsigned Subs::hash() const {
    size_t seed = 0;
    boost::hash_combine(seed, thSubs.hash());
    boost::hash_combine(seed, boolSubs.hash());
    return seed;
}

void Subs::put(const BoolVar &var, const BoolExpr &val) {
    boolSubs.put(var, val);
}

ThExpr Subs::get(const Var &var) const {
    return thSubs.get(var);
}

BoolExpr Subs::get(const BoolVar &var) const {
    return boolSubs.get(var);
}

ThSubs& Subs::getThSubs() {
    return thSubs;
}

BoolSubs& Subs::getBoolSubs() {
    return boolSubs;
}

const ThSubs& Subs::getThSubs() const {
    return thSubs;
}

const BoolSubs& Subs::getBoolSubs() const {
    return boolSubs;
}

ThSubs::Iterator Subs::find(const ThVar& v) const {
    return std::visit([this](const auto &v){return thSubs.find(v);}, v);
}

BoolSubs::const_iterator Subs::find(const BoolVar& v) const {
    return boolSubs.find(v);
}

bool Subs::isEnd(const std::variant<ThSubs::Iterator, BoolSubs::const_iterator> &it) const {
    return std::visit(Overload{
                          [this](const BoolSubs::const_iterator &it){return it == boolSubs.end();},
                          [this](const auto &it){return it == thSubs.end();},
                      }, it);
}

BoolExpr Subs::operator()(const BoolExpr &e) const {
    if (e->getTheoryLit()) {
        const auto &lit = *e->getTheoryLit();
        if (std::holds_alternative<BoolLit>(lit)) {
            return boolSubs(e);
        } else  {
            return buildTheoryLit(thSubs.subs(*e->getTheoryLit()));
        }
    } else {
        BoolExprSet newChildren;
        for (const auto &c: e->getChildren()) {
            newChildren.insert((*this)(c));
        }
        return e->isAnd() ? buildAnd(newChildren) : buildOr(newChildren);
    }
}

Subs Subs::compose(const Subs &that) const {
    return Subs(thSubs.compose(that.thSubs), boolSubs.compose(that.boolSubs));
}

Subs Subs::concat(const Subs &that) const {
    return Subs(thSubs.concat(that.thSubs), boolSubs.concat(that.boolSubs));
}

bool Subs::changes(const Var &var) const {
    return thSubs.changes(var);
}

bool Subs::changes(const BoolVar &var) const {
    return boolSubs.changes(var);
}

bool Subs::empty() const {
    return thSubs.empty() && boolSubs.empty();
}

size_t Subs::size() const {
    return thSubs.size() + boolSubs.size();
}

Subs Subs::project(const VarSet &vars) const {
    return Subs(thSubs.project(vars), boolSubs.project(vars.get<BoolTheory>()));
}

void Subs::erase(const Var &var) {
    thSubs.erase(var);
}

void Subs::erase(const BoolVar &var) {
    boolSubs.erase(var);
}

int Subs::compare(const Subs &that) const {
    int cmp = thSubs.compare(that.thSubs);
    if (cmp != 0) {
        return cmp;
    }
    return boolSubs.compare(that.boolSubs);
}

bool Subs::isLinear() const {
    return thSubs.isLinear() && boolSubs.isLinear();
}

bool Subs::isPoly() const {
    return thSubs.isPoly() && boolSubs.isPoly();
}

std::ostream& operator<<(std::ostream &s, const Subs &e) {
    if (e.getBoolSubs().empty()) {
        return s << e.getThSubs();
    } else if (e.getThSubs().empty()) {
        return s << e.getBoolSubs();
    } else {
        return s << e.getThSubs() << " u " << e.getBoolSubs();
    }
}

bool operator==(const Subs &s1, const Subs &s2) {
    return s1.getThSubs() == s2.getThSubs() && s1.getBoolSubs() == s2.getBoolSubs();
}

bool operator<(const Subs &s1, const Subs &s2) {
    return s1.compare(s2) < 0;
}
