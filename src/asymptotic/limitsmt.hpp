#pragma once

#include "arith.hpp"
#include "boolexpr.hpp"
#include "limitproblem.hpp"
#include "complexity.hpp"

namespace LimitSmtEncoding {
/**
 * Tries to solve the given limit problem by an encoding into a SMT query.
 * @returns the found solution (if any), the limit problem is not modified.
 */
std::optional<ArithSubs> applyEncoding(const LimitProblem &currentLP, const Arith::Expr cost, Complexity currentRes);

std::pair<ArithSubs, Complexity> applyEncoding(const Bools::Expr exp, const Arith::Expr cost, Complexity currentRes);

}

