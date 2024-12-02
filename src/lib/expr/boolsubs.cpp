#include "boolsubs.hpp"

BoolSubs::BoolSubs() {}

BoolSubs::BoolSubs(const BoolVarPtr key, const Bools::Expr val): map({{key, val}}) {}

void BoolSubs::put(const BoolVarPtr key, const Bools::Expr val) {
    map.put(key, val);
}

Bools::Expr BoolSubs::get(const BoolVarPtr var) const {
    const auto res {map.get(var)};
    return res ? *res : bools::mkLit(bools::mk(var));
}

Bools::Expr BoolSubs::subs(const Bools::Lit lit) const {
    return lit->isNegated() ? !get(lit->getBoolVar()) : get(lit->getBoolVar());
}

Bools::Expr BoolSubs::operator()(const Bools::Expr e) const {
    const auto lit = e->getTheoryLit();
    if (lit) {
        if (std::holds_alternative<Bools::Lit>(*lit)) {
            const auto &blit {std::get<Bools::Lit>(*lit)};
            const auto var {blit->getBoolVar()};
            const auto res {map.get(var)};
            if (res) {
                return blit->isNegated() ? !*res : *res;
            } else {
                return e;
            }
        } else {
            return e;
        }
    } else if (e->isAnd() || e->isOr()) {
        std::vector<Bools::Expr> children;
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

BoolSubs BoolSubs::project(const std::function<bool(BoolVarPtr)> &keep) const {
    BoolSubs res;
    for (const auto &p : *this) {
        if (keep(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

bool BoolSubs::changes(const BoolVarPtr key) const {
    if (!contains(key)) {
        return false;
    }
    return bools::mkLit(bools::mk(key)) != map.at(key);
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

size_t hash_value(const BoolSubs &x) {
    return x.hash();
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
