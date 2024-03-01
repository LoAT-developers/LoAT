#include "boolsubs.hpp"

BoolSubs::BoolSubs() {}

BoolSubs::BoolSubs(const BoolVarPtr key, const BoolExprPtr val): map({{key, val}}) {}

void BoolSubs::put(const BoolVarPtr key, const BoolExprPtr val) {
    map.put(key, val);
}

BoolExprPtr BoolSubs::get(const BoolVarPtr var) const {
    const auto res {map.get(var)};
    return res ? *res : bools::mkLit(BoolLit(var));
}

BoolExprPtr BoolSubs::subs(const BoolLit &lit) const {
    return lit.isNegated() ? !get(lit.getBoolVar()) : get(lit.getBoolVar());
}

BoolExprPtr BoolSubs::operator()(const BoolExprPtr e) const {
    const auto lit = e->getTheoryLit();
    if (lit) {
        if (std::holds_alternative<BoolLit>(*lit)) {
            const auto &blit {std::get<BoolLit>(*lit)};
            const auto var {blit.getBoolVar()};
            const auto res {map.get(var)};
            if (res) {
                return blit.isNegated() ? !*res : *res;
            } else {
                return e;
            }
        } else {
            return e;
        }
    } else if (e->isAnd() || e->isOr()) {
        std::vector<BoolExprPtr> children;
        for (const auto &c: e->getChildren()) {
            children.push_back((*this)(c));
        }
        return e->isAnd() ? bools::mkAnd(children) : bools::mkOr(children);
    } else {
        return e;
    }
}

bool BoolSubs::contains(const BoolVarPtr var) const {
    return map.contains(var);
}

BoolSubs BoolSubs::unite(const BoolSubs &t) const {
    BoolSubs res = *this;
    for (const auto &p: t) {
        if (!res.contains(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

BoolSubs BoolSubs::project(const linked_hash_set<BoolVarPtr> &vars) const {
    BoolSubs res;
    if (size() < vars.size()) {
        for (const auto &p: *this) {
            if (vars.contains(p.first)) {
                res.put(p.first, p.second);
            }
        }
    } else {
        for (const auto &x: vars) {
            const auto val {map.get(x)};
            if (val) {
                res.put(x, *val);
            }
        }
    }
    return res;
}

bool BoolSubs::changes(const BoolVarPtr key) const {
    if (!contains(key)) {
        return false;
    }
    return bools::mkLit(BoolLit(key)) != map.at(key);
}

linked_hash_set<BoolVarPtr> BoolSubs::domain() const {
    linked_hash_set<BoolVarPtr> res;
    collectDomain(res);
    return res;
}

void BoolSubs::collectDomain(linked_hash_set<BoolVarPtr> &vars) const {
    for (const auto &p: map) {
        vars.insert(p.first);
    }
}

void BoolSubs::collectCoDomainVars(VarSet &vars) const {
    for (const auto &p: map) {
        p.second->collectVars(vars);
    }
}

void BoolSubs::collectVars(VarSet &vars) const {
    for (const auto &p: map) {
        vars.insert(p.first);
        p.second->collectVars(vars);
    }
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

size_t BoolSubs::size() const {
    return map.size();
}

void BoolSubs::erase(const BoolVarPtr var) {
    map.erase(var);
}

bool BoolSubs::isLinear() const {
    return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isLinear();});
}

bool BoolSubs::isPoly() const {
    return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isPoly();});
}

size_t BoolSubs::hash() const {
    return boost::hash_unordered_range(map.begin(), map.end());
}

bool operator==(const BoolSubs &e1, const BoolSubs &e2) {
    return e1.map == e2.map;
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
            s << p.first << " <- " << p.second;
        }
        return s << "}";
    }
}
