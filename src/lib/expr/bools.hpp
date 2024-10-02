#pragma once

#include "itheory.hpp"
#include "boollit.hpp"
#include "boolvar.hpp"
#include "notnull.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <memory>

class BoolExpr;
class BoolSubs;

struct BoolsBase {
    using Lit = BoolLitPtr;
    using Var = BoolVarPtr;
    using Const = bool;
    using Expr = cpp::not_null<const BoolExpr*>;
    using Model = linked_hash_map<Var, Const>;
    using Renaming = boost::bimap<boost::bimaps::unordered_set_of<Var>, boost::bimaps::unordered_set_of<Var>>;

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

std::size_t hash_value(const Bools::Expr &x);

static_assert(IBaseTheory<BoolsBase>);
static_assert(ITheory<Bools>);
