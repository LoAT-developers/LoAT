#pragma once

#include "itheory.hpp"
#include "boollit.hpp"
#include "boolvar.hpp"
#include "boolsubs.hpp"
#include "boolexpr.hpp"
#include "inttheory.hpp"

#include <memory>

struct BoolBaseTheory {
    using Lit = BoolLit;
    using Var = BoolVar;
    using Val = bool;
};

struct BoolTheory: public BoolBaseTheory {
    using Expression = std::shared_ptr<const BoolExpression<IntTheory, BoolTheory>>;
    using Subs = BoolSubs<IntTheory, BoolTheory>;

    static Expression valToExpr(const Val &val) {
        return val ? BoolExpression<IntTheory, BoolTheory>::True : BoolExpression<IntTheory, BoolTheory>::False;
    }

    static Expression varToExpr(const Var &val) {
        return BoolExpression<IntTheory, BoolTheory>::buildTheoryLit(Lit(val));
    }

    static Expression anyValue() {
        return BoolExpression<IntTheory, BoolTheory>::False;
    }

};

static_assert(IBaseTheory<BoolBaseTheory>);
static_assert(ITheory<BoolTheory>);
