#pragma once

#include "boollit.hpp"
#include "boolvar.hpp"
#include "boolsubs.hpp"
#include "boolexpr.hpp"
#include "inttheory.hpp"

#include <memory>

struct BoolBaseTheory {
    using Lit = BoolLit;
    using Var = BoolVarPtr;
    using Val = bool;
};

struct BoolTheory: public BoolBaseTheory {
    using BExpression = BoolExpression<IntTheory, BoolTheory>;
    using Expression = std::shared_ptr<const BExpression>;
    using Subs = BoolSubs<IntTheory, BoolTheory>;

    static Expression valToExpr(const Val &val) {
        return val ? BExpression::top() : BExpression::bot();
    }

    static Expression varToExpr(const Var &var) {
        return BExpression::mkLit(Lit(var));
    }

    static Expression anyValue() {
        return BExpression::bot();
    }

    static Var next() {
        return BoolVar::next();
    }

};

namespace boolTheory {

extern BoolTheory t;

}

static_assert(IBaseTheory<BoolBaseTheory>);
static_assert(ITheory<BoolTheory>);
