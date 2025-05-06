#pragma once

#include "itheory.hpp"
#include "arithlit.hpp"
#include "exprfwd.hpp"

struct Arith {

    using Lit = ArithLitPtr;
    using Var = ArithVarPtr;
    using Subs = ArithSubs;
    using Expr = ArithExprPtr;
    using Const = Int;
    using Model = linked_hash_map<Var, Const>;
    using Renaming = arith_var_map;

    static Expr constToExpr(const Const &val);
    static Expr varToExpr(const Var &var);
    static Expr anyValue();
    static Var next();
    static BoolExprPtr mkEq(const Var, const Const&);

};

namespace arith {

extern Arith t;

}

static_assert(ITheory<Arith>);
