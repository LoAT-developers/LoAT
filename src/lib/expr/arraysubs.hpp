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

public:

    typedef linked_hash_map<Var, Expr>::const_iterator const_iterator;

    ArraySubs();

    ArraySubs(std::initializer_list<std::pair<const Var, Expr>> init);

    Expr get(const Var&) const;

    void put(const Var&, const Expr&);

    const_iterator begin() const;

    const_iterator end() const;

    bool contains(const Var&) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const Var&);

    Self compose(const Self &that) const;

    Self concat(const Self &that) const;

    Self concat(const array_var_map<T> &that) const;

    Self unite(const Self &that) const;

    Self project(const linked_hash_set<Var> &vars) const;

    Self project(const std::function<bool(Var)> &keep) const;

    bool changes(const Var&) const;

    bool isLinear() const;

    bool isPoly() const;

    linked_hash_set<Var> domain() const;

    linked_hash_set<Var> coDomainVars() const;

    void collectDomain(linked_hash_set<Var> &vars) const;

    void collectCoDomainVars(linked_hash_set<Var> &vars) const;

    void collectVars(linked_hash_set<Var> &vars) const;

    size_t hash() const;

    Expr operator()(const Expr&) const;

private:

    linked_hash_map<Var, Expr> map{};

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArraySubs<T> &map);
