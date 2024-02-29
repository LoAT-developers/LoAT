#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "boolexpr.hpp"

namespace theories {

using TheTheory = Theory<Arith, Bools>;
using Lit = TheTheory::Lit;
using VS = theories::ThSet<Arith::Var, Bools::Var>;

void collectVars(const Lit &lit, VS &s);
VS vars(const Lit &lit);
bool isTriviallyTrue(const Lit &lit);
bool isTriviallyFalse(const Lit &lit);
Lit negate(const Lit &lit);
size_t hash(const Lit lit);

}
