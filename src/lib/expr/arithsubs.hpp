#pragma once

#include "arithexpr.hpp"
#include "linkedhashmap.hpp"

class ArithSubs {

    friend bool operator==(const ArithSubs &m1, const ArithSubs &m2);

public:

    typedef typename linked_hash_map<ArithVarPtr, ArithExprPtr>::const_iterator const_iterator;

    ArithSubs();

    ArithSubs(std::initializer_list<std::pair<const ArithVarPtr, ArithExprPtr>> init);

    ArithExprPtr get(const ArithVarPtr key) const;

    void put(const ArithVarPtr key, const ArithExprPtr val);

    const_iterator begin() const;

    const_iterator end() const;

    bool contains(const ArithVarPtr e) const;

    bool empty() const;

    unsigned int size() const;

    size_t erase(const ArithVarPtr key);

    ArithSubs compose(const ArithSubs &that) const;

    ArithSubs concat(const ArithSubs &that) const;

    void concatInPlace(const ArithSubs &that);

    ArithSubs unite(const ArithSubs &that) const;

    ArithSubs project(const linked_hash_set<ArithVarPtr> &vars) const;

    ArithSubs project(const std::function<bool(ArithVarPtr)> &keep) const;

    bool changes(const ArithVarPtr key) const;

    bool isLinear() const;

    bool isPoly() const;

    linked_hash_set<ArithVarPtr> domain() const;

    linked_hash_set<ArithVarPtr> coDomainVars() const;

    void collectDomain(linked_hash_set<ArithVarPtr> &vars) const;

    void collectCoDomainVars(linked_hash_set<ArithVarPtr> &vars) const;

    void collectVars(linked_hash_set<ArithVarPtr> &vars) const;

    size_t hash() const;

    ArithExprPtr operator()(const ArithExprPtr t) const;

private:

    linked_hash_map<ArithVarPtr, ArithExprPtr> map{};

};

std::ostream& operator<<(std::ostream &s, const ArithSubs &map);

template<>
struct std::hash<ArithSubs> {
    std::size_t operator()(const ArithSubs& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const ArithSubs&);
