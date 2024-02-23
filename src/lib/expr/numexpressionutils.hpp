#pragma once

#include "numexpression.hpp"

namespace num_expression {

std::optional<ExprPtr> solveTermFor(const ExprPtr e, const NumVarPtr var);
ExprPtr fromPurrs(const Purrs::Expr &, const purrs_var_map &);

}
