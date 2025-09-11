#pragma once

#include "itheory.hpp"
#include "arrayexpr.hpp"
#include "arraylit.hpp"
#include "exprfwd.hpp"
#include "bools.hpp"
#include "arraysubs.hpp"

template <ITheory T>
struct Arrays {

    using Lit = ArrayLitPtr<T>;
    using Var = ArrayVarPtr<T>;
    using Lval = ArrayReadPtr<T>;
    using Subs = ArraySubs<T>;
    using Expr = ArrayPtr<T>;
    using Renaming = array_var_map<T>;

    static Expr varToExpr(const Var &var) {
        return var;
    }

    static Expr lvalToExpr(const Lval &lval) {
        return lval;
    }

    static Var next() {
        return ArrayVar<T>::next();
    }

};

namespace arrays {

extern Arrays<Arith> arith;
extern Arrays<Bools> bools;

}

static_assert(ITheory<Arrays<Arith>>);
static_assert(ITheory<Arrays<Bools>>);
