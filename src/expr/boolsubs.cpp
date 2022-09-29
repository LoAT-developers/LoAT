#include "boolsubs.hpp"

BoolSubs::BoolSubs(){}

BoolSubs::BoolSubs(const BoolVar &key, const BoolExpr &val): map({{key, val}}) {}

void BoolSubs::put(const BoolVar &key, const BoolExpr &val) {
    map[key] = val;
}

BoolExpr BoolSubs::get(const BoolVar &var) const {
    const auto it = map.find(var);
    return it == map.end() ? buildLit(var) : it->second;
}

bool BoolSubs::contains(const BoolVar &var) const {
    return map.find(var) != map.end();
}

BoolExpr BoolSubs::operator()(const BoolExpr e) const {
    const auto lit = e->getLit();
    if (lit) {
        const auto it = map.find(lit->getBoolVar());
        if (it == map.end()) {
            return e;
        } else {
            return lit->isNegated() ? !it->second : it->second;
        }
    } else if (e->isAnd() || e->isOr()) {
        std::vector<BoolExpr> children;
        for (const auto &c: e->getChildren()) {
            children.push_back((*this)(c));
        }
        return e->isAnd() ? buildAnd(children) : buildOr(children);
    } else {
        return e;
    }
}

BoolSubs BoolSubs::compose(const BoolSubs &that) const {
    BoolSubs res;
    for (const auto &p: *this) {
        res.put(p.first, that(p.second));
    }
    for (const auto &p: that) {
        if (!res.contains(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

BoolSubs BoolSubs::concat(const BoolSubs &that) const {
    BoolSubs res;
    for (const auto &p: *this) {
        res.put(p.first, that(p.second));
    }
    return res;
}

BoolSubs BoolSubs::project(const BoolVarSet &vars) const {
    BoolSubs res;
    for (const auto &p: *this) {
        if (vars.find(p.first) != vars.end()) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

bool BoolSubs::changes(const BoolVar &key) const {
    if (!contains(key)) {
        return false;
    }
    return buildLit(key) != map.at(key);
}

BoolVarSet BoolSubs::domain() const {
    BoolVarSet res;
    collectDomain(res);
    return res;
}

BoolVarSet BoolSubs::coDomainVars() const {
    BoolVarSet res;
    collectCoDomainVars(res);
    return res;
}

BoolVarSet BoolSubs::allVars() const {
    BoolVarSet res;
    collectVars(res);
    return res;
}

void BoolSubs::collectDomain(BoolVarSet &vars) const {
    for (const auto &p: map) {
        vars.insert(p.first);
    }
}

void BoolSubs::collectCoDomainVars(BoolVarSet &vars) const {
    for (const auto &p: map) {
        p.second->collectVars(vars);
    }
}

void BoolSubs::collectVars(BoolVarSet &vars) const {
    for (const auto &p: map) {
        vars.insert(p.first);
        p.second->collectVars(vars);
    }
}

unsigned BoolSubs::hash() const {
    unsigned hash = 7;
    for (const auto& p: *this) {
        hash = hash * 31 + p.first.hash();
        hash = hash * 31 + p.second->hash();
    }
    return hash;
}

bool BoolSubs::empty() const {
    return map.empty();
}

BoolSubs::const_iterator BoolSubs::begin() const {
    return map.begin();
}

BoolSubs::const_iterator BoolSubs::end() const {
    return map.end();
}

BoolSubs::const_iterator BoolSubs::find(const BoolVar &var) const {
    return map.find(var);
}

size_t BoolSubs::size() const {
    return map.size();
}

void BoolSubs::erase(const BoolVar &var) {
    map.erase(var);
}

int BoolSubs::compare(const BoolSubs &that) const {
    if (map == that.map) {
        return 0;
    } else if (map < that.map) {
        return -1;
    } else {
        return 1;
    }
}

std::ostream& operator<<(std::ostream &s, const BoolSubs &e) {
    if (e.empty()) {
        return s << "{}";
    } else {
        bool first = true;
        s << "{";
        for (const auto &p: e) {
            if (first) {
                first = false;
            } else {
                s << ", ";
            }
            s << p.first << " -> " << p.second;
        }
        return s << "}";
    }
}

bool operator==(const BoolSubs &s1, const BoolSubs &s2) {
    return s1.map == s2.map;
}

bool operator<(const BoolSubs &s1, const BoolSubs &s2) {
    return s1.compare(s2) < 0;
}
