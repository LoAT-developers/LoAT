#pragma once

#include "arrayexpr.hpp"
#include "linkedhashmap.hpp"

template <ITheory T>
using array_var_map = boost::bimap<boost::bimaps::unordered_set_of<ArrayVarPtr<T>>, boost::bimaps::unordered_set_of<ArrayVarPtr<T>>>;

template <ITheory T>
bool operator==(const ArraySubs<T> &m1, const ArraySubs<T> &m2);

template <ITheory T>
class ArraySubs {

    using Self = ArraySubs;
    using Expr = ArrayPtr<T>;
    using Var = ArrayVarPtr<T>;

    friend bool operator==<T>(const ArraySubs &m1, const ArraySubs &m2);

    explicit ArraySubs(const linked_hash_map<Var, Expr>& map);

public:

    typedef linked_hash_map<Var, Expr>::const_iterator const_iterator;

    ArraySubs() = default;

    ArraySubs(std::initializer_list<std::pair<const Var, Expr>> init);

    Expr get(const Var& x) const;

    void put(const Var& x, const Expr& e);

    const_iterator begin() const;

    const_iterator end() const;

    bool contains(const Var& x) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const Var& x);

    Self compose(const Self &that) const;

    Self concat(const ArithSubs &that) const;

    Self concat(const Self &that) const;

    Self concat(const array_var_map<T> &that) const;

    Self concat(const arith_var_map &that) const;

    Self project(const linked_hash_set<Var> &vars) const;

    Self project(const std::function<bool(Var)> &keep) const;

    bool changes(const Var& x) const;

    static bool isLinear();

    static bool isPoly();

    void collectCoDomainVars(linked_hash_set<Var> &vars, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var> &tvars) const;

    void collectVars(linked_hash_set<Var> &vars, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var> &tvars) const;

    linked_hash_set<Var> domain() const;

    std::tuple<linked_hash_set<Var>, linked_hash_set<Arith::Var>, linked_hash_set<typename T::Var>> coDomainVars() const;

    size_t hash() const;

private:

    linked_hash_map<Var, Expr> map{};

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArraySubs<T> &map) {
    if (map.empty()) {
        return s << "{}";
    }
    s << "{";
    bool fst = true;
    for (const auto & [k, v]: map) {
        if (!fst) {
            s << ", ";
        } else {
            fst = false;
        }
        s << k << " <- " << v;
    }
    return s << "}";
}
