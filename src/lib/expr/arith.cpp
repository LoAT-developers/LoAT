#include "arith.hpp"
#include "arithexpr.hpp"
#include "theory.hpp"

Arith::Expr Arith::varToExpr(const Var &var) {
    return var;
}

Arith::Expr Arith::cellToExpr(const Cell &cell) {
    return cell;
}

Arith::Expr Arith::anyValue() {
    return arith::mkConst(0);
}

Arith::Var Arith::next() {
    return ArithVar::next();
}

BoolExprPtr Arith::mkEq(const Var& x, const Const& y) {
    return bools::mkLit(arith::mkEq(x, arith::mkConst(y)));
}

Arith::Subs Arith::modelToSubs(const Model &m) {
    Subs res;
    for (const auto &[k,v]: m) {
        res.put(k, arith::mkConst(v));
    }
    return res;
}

namespace arith {

Arith t {};

}
