#pragma once

#include "itheory.hpp"
#include "expression.hpp"
#include "rel.hpp"

struct IntTheory {
    using Lit = Rel;
    using Var = NumVar;
    using Subs = ExprSubs;
    using Expression = Expr;
    using Val = Num;
};

static_assert(INonBoolTheory<IntTheory>);
