#include "bools.hpp"
#include "theory.hpp"

Bools::Expr Bools::constToExpr(const Const val) {
    return val ? top() : bot();
}

Bools::Expr Bools::varToExpr(const Var& var) {
    return bools::mkLit(bools::mk(var));
}

Bools::Expr Bools::lvalToExpr(const Lval& var) {
    return bools::mkLit(bools::mk(var));
}

Bools::Expr Bools::anyValue() {
    return bot();
}

Bools::Var Bools::next() {
    return BoolVar::next();
}

Bools::Expr Bools::mkEq(const Expr &lhs, const Expr &rhs) {
    return (lhs && rhs) || (!lhs && !rhs);
}

std::size_t hash_value(const Bools::Expr &x) {
    return std::hash<std::shared_ptr<const BoolExpr>>{}(x.as_nullable());
}

namespace bools {

Bools t {};

}
