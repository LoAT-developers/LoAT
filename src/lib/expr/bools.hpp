#pragma once

#include "itheory.hpp"
#include "boollit.hpp"
#include "exprfwd.hpp"

class BoolExpr;
class BoolSubs;

struct Bools {
    using Lit = BoolLitPtr;
    using Var = BoolVarPtr;
    using Const = bool;
    using Expr = cpp::not_null<std::shared_ptr<const BoolExpr>>;
    using Model = linked_hash_map<Var, Const>;
    using Renaming = boost::bimap<boost::bimaps::unordered_set_of<Var>, boost::bimaps::unordered_set_of<Var>>;
    using Subs = BoolSubs;

    static Expr constToExpr(const Const val);
    static Expr varToExpr(const Var var);
    static Expr anyValue();
    static Var next();
    static BoolExprPtr mkEq(const Var, const Const);
};

namespace bools {

extern Bools t;

}

std::size_t hash_value(const Bools::Expr &x);

static_assert(ITheory<Bools>);
