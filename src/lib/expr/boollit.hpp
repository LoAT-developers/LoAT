#pragma once

#include "boolvar.hpp"

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
    void collectVars(std::set<BoolVar> &res) const;
    BoolLit normalize() const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    std::size_t hash() const;

};

BoolLit operator!(const BoolLit &l);

std::ostream& operator<<(std::ostream &s, const BoolLit &e);
