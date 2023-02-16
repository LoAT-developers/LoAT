#pragma once

#include "theory.hpp"

namespace literal {

void collectVariables(VarSet &res, const Lit &e);

VarSet variables(const Lit &e);

bool isTriviallyTrue(const Lit &lit);

Lit negate(const Lit &lit);

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2);

}

std::ostream& operator<<(std::ostream &s, const Lit &e);
