#pragma once

#include "itheory.hpp"
#include "arrayexpr.hpp"
#include "arraylit.hpp"
#include "exprfwd.hpp"
#include "bools.hpp"
#include "arraysubs.hpp"
#include "arrayconst.hpp"

template <ITheory T>
struct Arrays {

    using Lit = ArrayLitPtr<T>;
    using Var = ArrayVarPtr<T>;
    using Subs = ArraySubs<T>;
    using Expr = ArrayPtr<T>;
    using Const = ArrayConst<T>;
    using Model = linked_hash_map<Var, Const>;
    using Renaming = array_var_map<T>;

    static Expr varToExpr(const Var &var);
    static Expr anyValue();
    static Var next();

};

namespace arrays {

extern Arrays<Arith> arith;
extern Arrays<Bools> bools;

}

static_assert(ITheory<Arrays<Arith>>);
static_assert(ITheory<Arrays<Bools>>);
