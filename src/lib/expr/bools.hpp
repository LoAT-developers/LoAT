#pragma once

#include "itheory.hpp"
#include "boollit.hpp"
#include "boolvar.hpp"
#include "notnull.hpp"

#include <memory>

class BoolExpr;
class BoolSubs;

struct BoolsBase {
    using Lit = BoolLit;
    using Var = BoolVarPtr;
    using Const = bool;
    using Expr = cpp::not_null<std::shared_ptr<const BoolExpr>>;
    using Model = linked_hash_map<Var, Const>;

    static Expr constToExpr(const Const val);
    static Expr varToExpr(const Var var);
    static Expr anyValue();
    static Var next();
};

struct Bools: public BoolsBase {
    using Subs = BoolSubs;
};

namespace bools {

extern Bools t;

}

static_assert(IBaseTheory<BoolsBase>);
static_assert(ITheory<Bools>);
