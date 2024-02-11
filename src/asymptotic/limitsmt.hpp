#pragma once

#include "numexpression.hpp"
#include "boolexpr.hpp"
#include "limitproblem.hpp"
#include "complexity.hpp"

namespace LimitSmtEncoding {
    /**
     * Tries to solve the given limit problem by an encoding into a SMT query.
     * @returns the found solution (if any), the limit problem is not modified.
     */
    std::optional<ExprSubs> applyEncoding(const LimitProblem &currentLP, const Expr &cost, Complexity currentRes);

    std::pair<ExprSubs, Complexity> applyEncoding(const BExpr<IntTheory> exp, const Expr &cost, Complexity currentRes);
}

