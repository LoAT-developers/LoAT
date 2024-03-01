#pragma once

#include "boolexpr.hpp"
#include "theory.hpp"

#include <variant>
#include <vector>

class Conjunction : public std::vector<Lit> {

public:
    // inherit constructors of base class
    using std::vector<Lit>::vector;

    bool isLinear() const;
    void collectVars(VarSet &vars) const;
    VarSet vars() const;
    static Conjunction fromBoolExpr(const Bools::Expr &);

};

std::ostream& operator<<(std::ostream &s, const Conjunction &l);
Conjunction operator&&(const Conjunction &fst, const Conjunction &snd);
