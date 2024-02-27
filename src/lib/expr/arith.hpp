#pragma once

#include "itheory.hpp"
#include "arithexpr.hpp"
#include "arithlit.hpp"
#include "arithsubs.hpp"

struct Arith {

    using Lit = ArithLit;
    using Var = NumVarPtr;
    using Subs = ArithSubs;
    using Expr = ExprPtr;
    using Val = Int;

    static Expr valToExpr(const Val &val) {
        return arith::mkConst(val);
    }

    static Expr varToExpr(const Var &var) {
        return var->toExpr();
    }

    static Expr anyValue() {
        return 0;
    }

    static Var next() {
        return ArithVar::next();
    }

};

namespace arith {

extern Arith t;

}

static_assert(ITheory<Arith>);
