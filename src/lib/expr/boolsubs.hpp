#pragma once

#include "boolvar.hpp"
#include "boolexpr.hpp"
#include "itheory.hpp"
#include "map.hpp"

#include <boost/functional/hash.hpp>

template <IBaseTheory... Th>
class BoolSubs {

    using BoolExpr = BExpr<Th...>;
    using T = Theory<Th...>;
    using VarSet = theory::VarSet<Th...>;

    linked_hash_map<BoolVarPtr, BoolExpr> map{};

public:

    typedef typename linked_hash_map<BoolVarPtr, BoolExpr>::const_iterator const_iterator;

    BoolSubs() {}

    BoolSubs(const BoolVarPtr key, const BoolExpr val): map({{key, val}}) {}

    void put(const BoolVarPtr key, const BoolExpr val) {
        map.put(key, val);
    }

    BoolExpr get(const BoolVarPtr var) const {
        const auto res {map.get(var)};
        return res ? *res : BoolExpression<Th...>::buildTheoryLit(BoolLit(var));
    }

    BoolExpr subs(const BoolLit &lit) const {
        return lit.isNegated() ? !get(lit.getBoolVar()) : get(lit.getBoolVar());
    }

    BoolExpr operator()(const BoolExpr e) const {
        const auto lit = e->getTheoryLit();
        if (lit) {
            if (std::holds_alternative<BoolLit>(*lit)) {
                const auto &blit = std::get<BoolLit>(*lit);
                const BoolVar var = blit.getBoolVar();
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
            std::vector<BoolExpr> children;
            for (const auto &c: e->getChildren()) {
                children.push_back((*this)(c));
            }
            return e->isAnd() ? BoolExpression<Th...>::buildAnd(children) : BoolExpression<Th...>::buildOr(children);
        } else {
            return e;
        }
    }

    bool contains(const BoolVarPtr var) const {
        return map.contains(var);
    }

    BoolSubs concat(const theory::Subs<Th...> &that) const {
        BoolSubs res;
        for (const auto &p: *this) {
            res.put(p.first, p.second->subs(that));
        }
        return res;
    }

    BoolSubs unite(const BoolSubs &t) const {
        BoolSubs res = *this;
        for (const auto &p: t) {
            if (!res.contains(p.first)) {
                res.put(p.first, p.second);
            }
        }
        return res;
    }

    BoolSubs project(const linked_hash_set<BoolVarPtr> &vars) const {
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

    bool changes(const BoolVarPtr key) const {
        if (!contains(key)) {
            return false;
        }
        return BoolExpression<Th...>::buildTheoryLit(BoolLit(key)) != map.at(key);
    }

    linked_hash_set<BoolVar> domain() const {
        linked_hash_set<BoolVar> res;
        collectDomain(res);
        return res;
    }

    linked_hash_set<BoolVarPtr> allVars() const {
        linked_hash_set<BoolVarPtr> res;
        collectVars(res);
        return res;
    }

    void collectDomain(linked_hash_set<BoolVarPtr> &vars) const {
        for (const auto &p: map) {
            vars.insert(p.first);
        }
    }

    void collectCoDomainVars(VarSet &vars) const {
        for (const auto &p: map) {
            p.second->collectVars(vars);
        }
    }

    void collectVars(VarSet &vars) const {
        for (const auto &p: map) {
            vars.insert(p.first);
            p.second->collectVars(vars);
        }
    }

    bool empty() const {
        return map.empty();
    }

    const_iterator begin() const {
        return map.begin();
    }

    const_iterator end() const {
        return map.end();
    }

    size_t size() const {
        return map.size();
    }

    void erase(const BoolVarPtr var) {
        map.erase(var);
    }

    template <ITheory... Th_>
    friend std::strong_ordering operator<=>(const BoolSubs<Th_...> &e1, const BoolSubs<Th_...> &e2);

    template <ITheory... Th_>
    friend bool operator==(const BoolSubs<Th_...> &e1, const BoolSubs<Th_...> &e2);

    bool isLinear() const {
        return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isLinear();});
    }

    bool isPoly() const {
        return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isPoly();});
    }

    size_t hash() const {
        size_t hash {0};
        for (const auto &[key, value]: map) {
            boost::hash_combine(hash, key.hash());
            boost::hash_combine(hash, std::hash<BoolExpr>{}(value));
        }
        return hash;
    }

};

template <ITheory... Th>
bool operator==(const BoolSubs<Th...> &e1, const BoolSubs<Th...> &e2) {
    return e1.map == e2.map;
}

template <ITheory... Th>
std::ostream& operator<<(std::ostream &s, const BoolSubs<Th...> &e) {
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
