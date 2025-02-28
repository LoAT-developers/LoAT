#include "bools.hpp"
#include "theory.hpp"

Bools::Expr Bools::constToExpr(const Const val) {
    return val ? top() : bot();
}

Bools::Expr Bools::varToExpr(const Var var) {
    return bools::mkLit(bools::mk(var));
}

Bools::Expr Bools::anyValue() {
    return bot();
}

Bools::Var Bools::next(const unsigned d) {
    return BoolVar::next(d);
}

std::size_t hash_value(const Bools::Expr &x) {
    return std::hash<std::shared_ptr<const BoolExpr>>{}(x.as_nullable());
}

namespace bools {

Bools t {};

}
