#pragma once

#include "itheory.hpp"
#include "numexpression.hpp"
#include "rel.hpp"

struct IntTheory {
    using Lit = Rel;
    using Var = NumVar;
    using Subs = ExprSubs;
    using Expression = Expr;
    using Val = Num;

    static Expression valToExpr(const Val &val) {
        return val;
    }

    static Expression varToExpr(const Var &var) {
        return var;
    }

    static Expression anyValue() {
        return 0;
    }

};

static_assert(ITheory<IntTheory>);
