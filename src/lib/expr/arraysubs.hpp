#pragma once

#include "arrayexpr.hpp"
#include "linkedhashmap.hpp"

template <ITheory T>
class ArraySubs {

    using Self = ArraySubs<T>;

    friend bool operator==(const Self &m1, const Self &m2);

public:

    typedef typename linked_hash_map<ArrayVarPtr, ArrayExprPtr>::const_iterator const_iterator;

    ArraySubs();

    ArraySubs(std::initializer_list<std::pair<const ArrayVarPtr, ArrayExprPtr>> init);

    ArrayExprPtr get(const ArrayVarPtr key) const;

    void put(const ArrayVarPtr key, const ArrayExprPtr val);

    const_iterator begin() const;

    const_iterator end() const;

    bool contains(const ArrayVarPtr e) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const ArrayVarPtr key);

    Self compose(const Self &that) const;

    Self concat(const Self &that) const;

    Self concat(const array_var_map &that) const;

    Self unite(const Self &that) const;

    Self project(const linked_hash_set<ArrayVarPtr> &vars) const;

    Self project(const std::function<bool(ArrayVarPtr)> &keep) const;

    bool changes(const ArrayVarPtr key) const;

    bool isLinear() const;

    bool isPoly() const;

    linked_hash_set<ArrayVarPtr> domain() const;

    linked_hash_set<ArrayVarPtr> coDomainVars() const;

    void collectDomain(linked_hash_set<ArrayVarPtr> &vars) const;

    void collectCoDomainVars(linked_hash_set<ArrayVarPtr> &vars) const;

    void collectVars(linked_hash_set<ArrayVarPtr> &vars) const;

    size_t hash() const;

    ArrayExprPtr operator()(const ArrayExprPtr t) const;

private:

    linked_hash_map<ArrayVarPtr, ArrayExprPtr> map{};

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArraySubs<T> &map);
