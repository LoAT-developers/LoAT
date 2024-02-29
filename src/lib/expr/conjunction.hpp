#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "arith.hpp"
#include "bools.hpp"

#include <variant>
#include <vector>

using TheTheory = Theory<Arith, Bools>;

class Conjunction : public std::vector<TheTheory::Lit> {

    using Lit = TheTheory::Lit;
    using VS = theories::ThSet<Arith::Var, Bools::Var>;

public:
    // inherit constructors of base class
    using std::vector<Lit>::vector;

    bool isLinear() const;
    void collectVars(VS &vars) const;
    VS vars() const;

};

std::ostream& operator<<(std::ostream &s, const Conjunction &l);
Conjunction operator&&(const Conjunction &fst, const Conjunction &snd);
