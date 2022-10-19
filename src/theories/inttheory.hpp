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

};

static_assert(ITheory<IntTheory>);
