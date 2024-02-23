#pragma once

#include "numexpression.hpp"
#include "map.hpp"

class ExprSubs {

    friend bool operator==(const ExprSubs &m1, const ExprSubs &m2);

public:

    typedef typename linked_hash_map<NumVarPtr, ExprPtr>::const_iterator const_iterator;

    ExprSubs();

    ExprSubs(std::initializer_list<std::pair<const NumVarPtr, ExprPtr>> init);

    ExprPtr get(const NumVarPtr key) const;

    void put(const NumVarPtr key, const ExprPtr val);

    const_iterator begin() const;

    const_iterator end() const;

    bool contains(const NumVarPtr e) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const NumVarPtr key);

    ExprSubs compose(const ExprSubs &that) const;

    ExprSubs concat(const ExprSubs &that) const;

    void concatInPlace(const ExprSubs &that);

    ExprSubs unite(const ExprSubs &that) const;

    ExprSubs project(const linked_hash_set<NumVarPtr> &vars) const;

    bool changes(const NumVarPtr key) const;

    bool isLinear() const;

    bool isPoly() const;

    linked_hash_set<NumVarPtr> domain() const;

    linked_hash_set<NumVarPtr> coDomainVars() const;

    linked_hash_set<NumVarPtr> allVars() const;

    void collectDomain(linked_hash_set<NumVarPtr> &vars) const;

    void collectCoDomainVars(linked_hash_set<NumVarPtr> &vars) const;

    void collectVars(linked_hash_set<NumVarPtr> &vars) const;

    size_t hash() const;

    ExprPtr operator()(const ExprPtr t) const;

private:

    linked_hash_map<NumVarPtr, ExprPtr> map{};

};

std::ostream& operator<<(std::ostream &s, const ExprSubs &map);

template<>
struct std::hash<ExprSubs> {
    std::size_t operator()(const ExprSubs& x) const noexcept {
        return x.hash();
    }
};
