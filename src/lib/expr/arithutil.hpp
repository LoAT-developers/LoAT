#pragma once

#include "arithexpr.hpp"

namespace arith {

std::optional<ExprPtr> solveTermFor(const ExprPtr e, const NumVarPtr var);
ExprPtr fromPurrs(const Purrs::Expr &, const purrs_var_map &);

}
