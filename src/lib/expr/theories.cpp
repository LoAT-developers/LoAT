#include "theories.hpp"

const BoolExpr top() {
    return BoolExpression::top();
}

const BoolExpr bot() {
    return BoolExpression::bot();
}

namespace bools {

Bools::Expr mkLit(const TheTheory::Lit &lit) {
    return BoolExpression::mkLit(lit);
}

Bools::Expr mkAndFromLits(const std::initializer_list<Lit> &lits) {
    return BoolExpression::mkAndFromLits(lits);
}

}
