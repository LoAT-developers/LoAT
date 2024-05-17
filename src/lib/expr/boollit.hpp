#pragma once

#include "boolvar.hpp"
#include "linkedhashset.hpp"
#include "linkedhashmap.hpp"

class BoolLit;

using BoolLitPtr = cpp::not_null<std::shared_ptr<const BoolLit>>;

namespace bools {
    BoolLitPtr mk(const BoolVarPtr var, bool negated = false);
}

class BoolLit {

    friend BoolLitPtr bools::mk(const BoolVarPtr var, bool negated);

    BoolVarPtr var;
    bool negated;

    struct CacheEqual {
        bool operator()(const std::tuple<BoolVarPtr, bool> &args1, const std::tuple<BoolVarPtr, bool> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<BoolVarPtr, bool> &args) const noexcept;
    };
    static ConsHash<BoolLit, BoolLit, CacheHash, CacheEqual, BoolVarPtr, bool> cache;

public:

    BoolLit(const BoolVarPtr var, bool negated);
    bool isNegated() const;
    bool isPoly() const;
    bool isLinear() const;
    BoolVarPtr getBoolVar() const;
    void collectVars(linked_hash_set<BoolVarPtr> &res) const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    std::size_t hash() const;
    bool eval(const linked_hash_map<BoolVarPtr, bool> &model) const;

};

BoolLitPtr operator!(const BoolLitPtr &l);

std::ostream& operator<<(std::ostream &s, const BoolLitPtr &e);

template<>
struct std::hash<BoolLit> {
    std::size_t operator()(const BoolLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const BoolLit &lit);
