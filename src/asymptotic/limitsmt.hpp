#ifndef LIMITSMT_H
#define LIMITSMT_H

#include "expression.hpp"
#include "boolexpr.hpp"
#include "variablemanager.hpp"
#include "limitproblem.hpp"

namespace LimitSmtEncoding {
    /**
     * Tries to solve the given limit problem by an encoding into a SMT query.
     * @returns the found solution (if any), the limit problem is not modified.
     */
    option<Subs> applyEncoding(const LimitProblem &currentLP, const Expr &cost, VarMan &varMan, Complexity currentRes, unsigned int timeout);

    std::pair<Subs, Complexity> applyEncoding(const BoolExpr exp, const Expr &cost, VarMan &varMan, Complexity currentRes, unsigned int timeout);
}

#endif //LIMITSMT_H
