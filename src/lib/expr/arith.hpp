#pragma once

#include "itheory.hpp"
#include "arithlit.hpp"
#include "exprfwd.hpp"

struct Arith {

    using Lit = ArithLitPtr;
    using Expr = ArithExprPtr;
    using Const = Int;

    static Expr cellToExpr(const ArrayReadPtr<Arith> &var);

};

namespace arith {

extern Arith t;

}

static_assert(ITheory<Arith>);
