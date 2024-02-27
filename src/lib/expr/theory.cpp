#include "theory.hpp"

const BoolExpr top() {
    return BoolExpression<Arith, Bools>::top();
}

const BoolExpr bot() {
    return BoolExpression<Arith, Bools>::bot();
}

Bools::Expr bools::mkLit(const TheTheory::Lit &lit) {
    return BoolExpression<Arith, Bools>::mkLit(lit);
}
