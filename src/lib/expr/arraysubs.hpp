#pragma once

#include "arrayexpr.hpp"
#include "linkedhashmap.hpp"

template <ITheory T>
using array_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArrayVarPtr<T>>, boost::bimaps::unordered_set_of<ArrayVarPtr<T>>>;

template <ITheory T>
class ArraySubs {

    using Self = ArraySubs;
    using Expr = ArrayPtr<T>;
    using Var = ArrayVarPtr<T>;

    friend bool operator==(const Self &m1, const Self &m2);

    explicit ArraySubs(const linked_hash_map<Var, Expr>& map): map(map) {}

public:

    typedef linked_hash_map<Var, Expr>::const_iterator const_iterator;

    ArraySubs() = default;

    ArraySubs(std::initializer_list<std::pair<const Var, Expr>> init): map(init) {}

    Expr get(const Var& x) const {
        return map.get(x).value_or(x);
    }

    void put(const Var& x, const Expr& e) {
        map.put(x, e);
    }

    const_iterator begin() const {
        return map.begin();
    }

    const_iterator end() const {
        return map.end();
    }

    bool contains(const Var& x) const {
        return map.contains(x);
    }

    bool empty() const {
        return map.empty();
    }

    unsigned int size() const {
        return map.size();
    }

    size_t erase(const Var& x) {
        return map.erase(x);
    }

    Self compose(const Self &that) const;

    Self concat(const Self &that) const;

    Self concat(const array_var_map<T> &that) const;

    Self project(const linked_hash_set<Var> &vars) const {
        auto m {map};
        m.project(vars);
        return ArraySubs(m);
    }

    Self project(const std::function<bool(Var)> &keep) const {
        auto m {map};
        m.project(keep);
        return ArraySubs(m);
    }

    bool changes(const Var& x) const {
        const auto opt {map.get(x)};
        return opt && x != *opt;
    }

    static bool isLinear() {
        return false;
    }

    static bool isPoly() {
        return false;
    }

    void collectCoDomainVars(linked_hash_set<Var> &vars, linked_hash_set<typename T::Var> &tvars) const {
        for (const auto &[_,v]: map) {
            v->collectVars(vars, tvars);
        }
    }

    void collectVars(linked_hash_set<Var> &vars, linked_hash_set<typename T::Var> &tvars) const {
        for (const auto &[k,v]: map) {
            vars.insert(k);
            v->collectVars(vars, tvars);
        }
    }

    linked_hash_set<Var> domain() const {
        linked_hash_set<Var> res;
        for (const auto &[k,v]: map) {
            res.insert(k);
        }
        return res;
    }

    std::pair<linked_hash_set<Var>, linked_hash_set<typename T::Var>> coDomainVars() const {
        linked_hash_set<Var> vars;
        linked_hash_set<typename T::Var> tvars;
        collectCoDomainVars(vars, tvars);
        return {vars, tvars};
    }

    size_t hash() const {
        return boost::hash_unordered_range(map.begin(), map.end());
    }

    Expr operator()(const Expr& e) const;

private:

    linked_hash_map<Var, Expr> map{};

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArraySubs<T> &map);
