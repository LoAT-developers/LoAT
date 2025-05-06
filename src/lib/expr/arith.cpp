#include "arith.hpp"
#include "arithexpr.hpp"
#include "theory.hpp"

Arith::Expr Arith::constToExpr(const Const &val) {
    return arith::mkConst(val);
}

Arith::Expr Arith::varToExpr(const Var &var) {
    return var;
}

Arith::Expr Arith::anyValue() {
    return arith::mkConst(0);
}

Arith::Var Arith::next() {
    return ArithVar::next();
}

BoolExprPtr Arith::mkEq(const Var x, const Const& y) {
    return bools::mkLit(arith::mkEq(x, arith::mkConst(y)));
}

namespace arith {

Arith t {};

}
