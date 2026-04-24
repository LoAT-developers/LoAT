#include "arith.hpp"

#include "arrayexpr.hpp"
#include "theory.hpp"

Arith::Expr Arith::cellToExpr(const ArrayReadPtr<Arith> &var) {
    return var;
}

BoolExprPtr Arith::mkEq(const Expr& lhs, const Expr& rhs) {
    return bools::mkLit(arith::mkEq(lhs, rhs));
}

namespace arith {

Arith t {};

}
