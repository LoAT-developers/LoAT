#include "exprsubs.hpp"
#include "numexpression.hpp"

ExprSubs::ExprSubs() {}

ExprSubs::ExprSubs(std::initializer_list<std::pair<const NumVarPtr, ExprPtr>> init): map(init) {}

ExprPtr ExprSubs::get(const NumVarPtr key) const {
    const auto res {map.get(key)};
    return res ? *res : key->toExpr();
}

void ExprSubs::put(const NumVarPtr key, const ExprPtr val) {
    map.put(key, val);
}

ExprSubs::const_iterator ExprSubs::begin() const {
    return map.begin();
}

ExprSubs::const_iterator ExprSubs::end() const {
    return map.end();
}

bool ExprSubs::contains(const NumVarPtr e) const {
    return map.contains(e);
}

bool ExprSubs::empty() const {
    return map.empty();
}

unsigned int ExprSubs::size() const {
    return map.size();
}

size_t ExprSubs::erase(const NumVarPtr key) {
    return map.erase(key);
}

ExprSubs ExprSubs::compose(const ExprSubs &that) const {
    ExprSubs res;
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

ExprSubs ExprSubs::concat(const ExprSubs &that) const {
    ExprSubs res;
    for (const auto &p: *this) {
        res.put(p.first, that(p.second));
    }
    return res;
}

void ExprSubs::concatInPlace(const ExprSubs &that) {
    std::vector<std::pair<NumVarPtr, ExprPtr>> changed;
    for (const auto &[key, val]: *this) {
        const auto new_val {that(val)};
        if (val != new_val) {
            changed.emplace_back(key, new_val);
        }
    }
    for (const auto &[key, val]: changed) {
        put(key, val);
    }
}

ExprSubs ExprSubs::unite(const ExprSubs &that) const {
    ExprSubs res;
    for (const auto &p: *this) {
        res.put(p.first, p.second);
    }
    for (const auto &p: that) {
        if (res.contains(p.first)) {
            throw std::invalid_argument("union of substitutions is only defined if their domain is disjoint");
        }
        res.put(p.first, p.second);
    }
    return res;
}

ExprSubs ExprSubs::project(const linked_hash_set<NumVarPtr> &vars) const {
    ExprSubs res;
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

bool ExprSubs::changes(const NumVarPtr key) const {
    return contains(key) && get(key) != key;
}

bool ExprSubs::isLinear() const {
    return std::all_of(begin(), end(), [](const auto &p) {
        return p.second->isLinear();
    });
}

bool ExprSubs::isPoly() const {
    return std::all_of(begin(), end(), [](const auto &p) {
        return p.second->isPoly();
    });
}

void ExprSubs::collectDomain(linked_hash_set<NumVarPtr> &vars) const {
    for (const auto &p: *this) {
        vars.insert(p.first);
    }
}

void ExprSubs::collectCoDomainVars(linked_hash_set<NumVarPtr> &vars) const {
    for (const auto &p: *this) {
        p.second->collectVars(vars);
    }
}

void ExprSubs::collectVars(linked_hash_set<NumVarPtr> &vars) const {
    collectCoDomainVars(vars);
    collectDomain(vars);
}

linked_hash_set<NumVarPtr> ExprSubs::domain() const {
    linked_hash_set<NumVarPtr> res;
    collectDomain(res);
    return res;
}

linked_hash_set<NumVarPtr> ExprSubs::coDomainVars() const {
    linked_hash_set<NumVarPtr> res;
    collectCoDomainVars(res);
    return res;
}

linked_hash_set<NumVarPtr> ExprSubs::allVars() const {
    linked_hash_set<NumVarPtr> res;
    collectVars(res);
    return res;
}

size_t ExprSubs::hash() const {
    return boost::hash_unordered_range(map.begin(), map.end());
}

bool operator==(const ExprSubs &m1, const ExprSubs &m2) {
    return m1.map == m2.map;
}

std::ostream& operator<<(std::ostream &s, const ExprSubs &map) {
    if (map.empty()) {
        return s << "{}";
    } else {
        s << "{";
        bool fst = true;
        for (const auto &p: map) {
            if (!fst) {
                s << ", ";
            } else {
                fst = false;
            }
            s << p.first << " <- " << p.second;
        }
        return s << "}";
    }
}
