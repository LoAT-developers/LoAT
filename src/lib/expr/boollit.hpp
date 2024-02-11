#pragma once

#include "boolvar.hpp"
#include "set.hpp"

class BoolLit {
    BoolVar var;
    bool negated;

    friend auto operator<=>(const BoolLit &x, const BoolLit &y) = default;

public:

    explicit BoolLit(const BoolVar &var, bool negated = false);
    bool isNegated() const;
    bool isPoly() const;
    bool isLinear() const;
    bool isWellformed() const;
    BoolVar getBoolVar() const;
    void collectVars(linked_hash_set<BoolVar> &res) const;
    BoolLit normalize() const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    std::size_t hash() const;

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
