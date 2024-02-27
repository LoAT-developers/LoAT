#pragma once

#include "itheory.hpp"
#include "numexpression.hpp"
#include "rel.hpp"
#include "exprsubs.hpp"

struct Arith {

    using Lit = Rel;
    using Var = NumVarPtr;
    using Subs = ExprSubs;
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
        return NumVar::next();
    }

};

namespace arith {

extern Arith t;

}

static_assert(ITheory<Arith>);
