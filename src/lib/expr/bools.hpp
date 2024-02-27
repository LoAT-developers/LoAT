#pragma once

#include "boollit.hpp"
#include "boolvar.hpp"
#include "boolsubs.hpp"
#include "boolexpr.hpp"
#include "arith.hpp"

#include <memory>

struct BoolsBase {
    using Lit = BoolLit;
    using Var = BoolVarPtr;
    using Val = bool;
};

struct Bools: public BoolsBase {
    using BExpression = BoolExpression<Arith, Bools>;
    using Expr = std::shared_ptr<const BExpression>;
    using Subs = BoolSubs<Arith, Bools>;

    static Expr valToExpr(const Val &val) {
        return val ? BExpression::top() : BExpression::bot();
    }

    static Expr varToExpr(const Var &var) {
        return BExpression::mkLit(Lit(var));
    }

    static Expr anyValue() {
        return BExpression::bot();
    }

    static Var next() {
        return BoolVar::next();
    }

};

namespace bools {

extern Bools t;

}

static_assert(IBaseTheory<BoolsBase>);
static_assert(ITheory<Bools>);
