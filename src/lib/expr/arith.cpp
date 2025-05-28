#include "arith.hpp"
#include "arithexpr.hpp"

Arith::Expr Arith::constToExpr(const Const &val) {
    return arith::mkConst(val);
}

Arith::Expr Arith::varToExpr(const Var &var) {
    return arith::toExpr(var);
}

Arith::Expr Arith::anyValue() {
    return arith::mkConst(0);
}

Arith::Var Arith::next() {
    return ArithVar::next();
}

namespace arith {

Arith t {};

}
