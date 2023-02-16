#include "boolexpression.hpp"

namespace boolExpression {

const BoolExpr build(const Lit &lit) {
    return BoolExpression<IntTheory, BoolTheory>::buildTheoryLit(lit);
}

}
