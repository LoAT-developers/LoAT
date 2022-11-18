#pragma once

#include "theory.hpp"

namespace literal {

void collectVariables(VarSet &res, const Lit &e);

VarSet variables(const Lit &e);

bool isTriviallyTrue(const Lit &lit);

Lit negate(const Lit &lit);

BoolExpr mkEq(const Var &x, const ThExpr &e);

}

std::ostream& operator<<(std::ostream &s, const Lit &e);