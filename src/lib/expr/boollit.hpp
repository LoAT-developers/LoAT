#pragma once

#include "boolvar.hpp"
#include "set.hpp"
#include "map.hpp"

class BoolLit {
    BoolVarPtr var;
    bool negated;

    friend auto operator<=>(const BoolLit &x, const BoolLit &y) = default;

public:

    explicit BoolLit(const BoolVarPtr var, bool negated = false);
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

BoolLit operator!(const BoolLit &l);

std::ostream& operator<<(std::ostream &s, const BoolLit &e);

template<>
struct std::hash<BoolLit> {
    std::size_t operator()(const BoolLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const BoolLit &lit);
