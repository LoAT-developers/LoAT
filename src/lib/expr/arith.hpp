#pragma once

#include "itheory.hpp"
#include "arithlit.hpp"
#include "exprfwd.hpp"

struct Arith {

    using Lit = ArithLitPtr;
    using Var = ArithVarPtr;
    using Lval = ArithVarPtr;
    using Subs = ArithSubs;
    using Expr = ArithExprPtr;
    using Const = Int;
    using Model = linked_hash_map<Var, Const>;
    using Renaming = arith_var_map;

    static Expr varToExpr(const Var &var);
    static Expr lvalToExpr(const Lval &lval);
    static Expr anyValue();
    static Var next();
    static BoolExprPtr mkEq(const Var&, const Const&);
    static Subs modelToSubs(const Model&);

};

namespace arith {

extern Arith t;

}

static_assert(ITheory<Arith>);
