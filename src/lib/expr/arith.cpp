#include "arith.hpp"

#include "arrayexpr.hpp"

Arith::Expr Arith::cellToExpr(const ArrayReadPtr<Arith> &var) {
    return var;
}

namespace arith {

Arith t {};

}
