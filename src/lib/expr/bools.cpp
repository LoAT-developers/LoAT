#include "bools.hpp"
#include "theory.hpp"

BoolsBase::Expr BoolsBase::constToExpr(const Const val) {
    return val ? top() : bot();
}

BoolsBase::Expr BoolsBase::varToExpr(const Var var) {
    return bools::mkLit(bools::mk(var));
}

BoolsBase::Expr BoolsBase::anyValue() {
    return bot();
}

BoolsBase::Var BoolsBase::next() {
    return BoolVar::next();
}

std::size_t hash_value(const Bools::Expr &x) {
    return std::hash<const BoolExpr*>{}(x.as_nullable());
}

namespace bools {

Bools t {};

}
