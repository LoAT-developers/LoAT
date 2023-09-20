#include "theory.hpp"

const BoolExpr top() {
    return BoolExpression<IntTheory, BoolTheory>::top();
}

const BoolExpr bot() {
    return BoolExpression<IntTheory, BoolTheory>::bot();
}
