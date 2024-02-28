#include "theories.hpp"

const BoolExpr top() {
    return BoolExpression::top();
}

const BoolExpr bot() {
    return BoolExpression::bot();
}

Bools::Expr bools::mkLit(const TheTheory::Lit &lit) {
    return BoolExpression::mkLit(lit);
}
