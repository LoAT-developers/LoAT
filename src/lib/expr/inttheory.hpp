#pragma once

#include "itheory.hpp"
#include "numexpression.hpp"
#include "rel.hpp"
#include "exprsubs.hpp"

struct IntTheory {

    using Lit = Rel;
    using Var = NumVarPtr;
    using Subs = ExprSubs;
    using Expression = ExprPtr;
    using Val = Int;

    static Expression valToExpr(const Val &val) {
        return arith::mkConst(val);
    }

    static Expression varToExpr(const Var &var) {
        return var->toExpr();
    }

    static Expression anyValue() {
        return 0;
    }

    static Var next() {
        return NumVar::next();
    }

};

namespace intTheory {

extern IntTheory t;

}

static_assert(ITheory<IntTheory>);
