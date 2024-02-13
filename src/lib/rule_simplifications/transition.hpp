#pragma once

#include "theory.hpp"

class Transition {

private:

    BoolExpr formula;
    std::set<std::pair<TheTheory::Expression, TheTheory::Expression>> equalities;

public:

    explicit Transition(const BoolExpr formula);

    Transition subs(const Subs &subs) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    std::strong_ordering operator<=>(const Transition &that) const;

    unsigned getId() const;

    size_t hash() const;

    bool operator==(const Transition &that) const = default;

    BoolExpr toBoolExpr() const;

    Transition syntacticImplicant(const Subs &subs) const;

    Transition linearize(const NumVar &x) const;

    Transition toMinusInfinity(const NumVar &x) const;

    Transition toInfinity(const NumVar &x) const;

};

std::ostream& operator<<(std::ostream &s, const Transition &rule);

template<>
struct std::hash<Transition> {
    std::size_t operator()(const Transition& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Transition &rel);
