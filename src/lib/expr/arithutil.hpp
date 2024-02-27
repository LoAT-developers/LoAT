#pragma once

#include "arithexpr.hpp"

namespace arith {

std::optional<ArithExprPtr> solveTermFor(const ArithExprPtr e, const ArithVarPtr var);
ArithExprPtr fromPurrs(const Purrs::Expr &, const purrs_var_map &);

}
