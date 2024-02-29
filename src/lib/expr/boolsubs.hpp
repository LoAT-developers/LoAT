#pragma once

#include "boolvar.hpp"
#include "boolexpr.hpp"
#include "itheory.hpp"
#include "linkedhashmap.hpp"
#include "theory.hpp"

#include <boost/functional/hash.hpp>

class BoolSubs {

    linked_hash_map<BoolVarPtr, BoolExprPtr> map{};

public:

    typedef typename linked_hash_map<BoolVarPtr, BoolExprPtr>::const_iterator const_iterator;

    BoolSubs();
    BoolSubs(const BoolVarPtr key, const BoolExprPtr val);
    void put(const BoolVarPtr key, const BoolExprPtr val);
    BoolExprPtr get(const BoolVarPtr var) const;
    BoolExprPtr subs(const BoolLit &lit) const;
    BoolExprPtr operator()(const BoolExprPtr e) const;
    bool contains(const BoolVarPtr var) const;
    BoolSubs unite(const BoolSubs &t) const;
    BoolSubs project(const linked_hash_set<BoolVarPtr> &vars) const;
    bool changes(const BoolVarPtr key) const;
    linked_hash_set<BoolVarPtr> domain() const;
    void collectDomain(linked_hash_set<BoolVarPtr> &vars) const;
    void collectCoDomainVars(VarSet &vars) const;
    void collectVars(VarSet &vars) const;
    bool empty() const;
    const_iterator begin() const;
    const_iterator end() const;
    size_t size() const;
    void erase(const BoolVarPtr var);

    friend bool operator==(const BoolSubs &e1, const BoolSubs &e2);

    bool isLinear() const;
    bool isPoly() const;
    size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const BoolSubs &e);
