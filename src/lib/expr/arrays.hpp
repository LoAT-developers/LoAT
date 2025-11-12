#pragma once

#include "itheory.hpp"
#include "arrayexpr.hpp"
#include "exprfwd.hpp"
#include "bools.hpp"
#include "arraysubs.hpp"

template <ITheory T>
struct Arrays {

    using Lit = ArrayLitPtr<T>;
    using Var = ArrayVarPtr<T>;
    using Subs = ArraySubs<T>;
    using Expr = ArrayPtr<T>;
    using Renaming = array_var_map<T>;

    static Expr varToExpr(const Var &var) {
        return var;
    }

    static Var next(const unsigned p_dim) {
        return ArrayVar<T>::next(p_dim);
    }

};

namespace arrays {

extern Arrays<Arith> arith;
extern Arrays<Bools> bools;

ArithVarPtr array_idx(size_t);

}

static_assert(ITheory<Arrays<Arith>>);
