#pragma once

#include "boolvar.hpp"
#include "boolexpr.hpp"
#include "itheory.hpp"

template <IBaseTheory... Th>
class BoolSubs {

    using BoolExpr = BExpr<Th...>;
    using T = Theory<Th...>;
    using VarSet = theory::VarSet<Th...>;

    std::map<BoolVar, BoolExpr> map;

public:

    using const_iterator = typename std::map<BoolVar, BoolExpr>::const_iterator;

    BoolSubs() {}

    BoolSubs(const BoolVar &key, const BoolExpr &val): map({{key, val}}) {}

    void put(const BoolVar &key, const BoolExpr &val) {
        map[key] = val;
    }

    BoolExpr get(const BoolVar &var) const {
        const auto it = map.find(var);
        return it == map.end() ? BoolExpression<Th...>::buildTheoryLit(var) : it->second;
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
                const auto it = find(var);
                if (it == end()) {
                    return e;
                } else {
                    return blit.isNegated() ? !it->second : it->second;
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

    bool contains(const BoolVar &var) const {
        return map.find(var) != map.end();
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

    BoolSubs project(const std::set<BoolVar> &vars) const {
        BoolSubs res;
        if (size() < vars.size()) {
            for (const auto &p: *this) {
                if (vars.find(p.first) != vars.end()) {
                    res.put(p.first, p.second);
                }
            }
        } else {
            for (const auto &x: vars) {
                const auto it {find(x)};
                if (it != end()) {
                    res.put(it->first, it->second);
                }
            }
        }
        return res;
    }

    BoolSubs setminus(const std::set<BoolVar> &vars) const {
        if (size() < vars.size()) {
            BoolSubs res;
            for (const auto &p: *this) {
                if (vars.find(p.first) == vars.end()) {
                    res.put(p.first, p.second);
                }
            }
            return res;
        } else {
            BoolSubs res(*this);
            for (const auto &x: vars) {
                res.erase(x);
            }
            return res;
        }
    }

    bool changes(const BoolVar &key) const {
        if (!contains(key)) {
            return false;
        }
        return BoolExpression<Th...>::buildTheoryLit(BoolLit(key)) != map.at(key);
    }

    std::set<BoolVar> domain() const {
        std::set<BoolVar> res;
        collectDomain(res);
        return res;
    }

    std::set<BoolVar> allVars() const {
        std::set<BoolVar> res;
        collectVars(res);
        return res;
    }

    void collectDomain(std::set<BoolVar> &vars) const {
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

    const_iterator find(const BoolVar &var) const {
        return map.find(var);
    }

    size_t size() const {
        return map.size();
    }

    void erase(const BoolVar &var) {
        map.erase(var);
    }

    template <ITheory... Th_>
    friend auto operator<=>(const BoolSubs<Th_...> &e1, const BoolSubs<Th_...> &e2);

    template <ITheory... Th_>
    friend bool operator==(const BoolSubs<Th_...> &e1, const BoolSubs<Th_...> &e2);

    bool isLinear() const {
        return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isLinear();});
    }

    bool isPoly() const {
        return std::all_of(map.begin(), map.end(), [](const auto &p){return p.second->isPoly();});
    }

    template <ITheory T>
    unsigned nextVarIdx() const {
        const auto variables {allVars().template get<T::Var>()};
        return variables.empty() ? 1 : variables.rbegin()->getIndex() + 1;
    }

};

template <ITheory... Th>
auto operator<=>(const BoolSubs<Th...> &e1, const BoolSubs<Th...> &e2) {
    return e1.map <=> e2.map;
}

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
            s << p.first << " -> " << p.second;
        }
        return s << "}";
    }
}
