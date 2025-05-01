#pragma once

#include "boolvar.hpp"
#include "boolexpr.hpp"
#include "linkedhashmap.hpp"

#include <boost/functional/hash.hpp>

template<class... T> class VariantSet;
class ArithVar;
using ArithVarPtr = cpp::not_null<std::shared_ptr<const ArithVar>>;
using VarSet = VariantSet<ArithVarPtr, Bools::Var>;

class BoolSubs {

    linked_hash_map<BoolVarPtr, Bools::Expr> map{};

public:

    typedef typename linked_hash_map<BoolVarPtr, Bools::Expr>::const_iterator const_iterator;

    BoolSubs();
    BoolSubs(const BoolVarPtr key, const Bools::Expr val);
    void put(const BoolVarPtr key, const Bools::Expr val);
    Bools::Expr get(const BoolVarPtr var) const;
    Bools::Expr subs(const Bools::Lit lit) const;
    Bools::Expr operator()(const Bools::Expr e) const;
    bool contains(const BoolVarPtr var) const;
    BoolSubs unite(const BoolSubs &t) const;
    BoolSubs project(const linked_hash_set<BoolVarPtr> &vars) const;
    BoolSubs project(const std::function<bool(BoolVarPtr)> &keep) const;
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

size_t hash_value(const BoolSubs&);

std::ostream& operator<<(std::ostream &s, const BoolSubs &e);
