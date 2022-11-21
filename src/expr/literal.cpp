#include "literal.hpp"
#include "literaltemplates.hpp"
#include "substitution.hpp"

namespace literal {

void collectVariables(VarSet &res, const Lit &e) {
    literal_t::collectVars<IntTheory, BoolTheory>(e, res);
}

VarSet variables(const Lit &e) {
    return literal_t::vars<IntTheory, BoolTheory>(e);
}

bool isTriviallyTrue(const Lit &lit) {
    return literal_t::isTriviallyTrue<IntTheory, BoolTheory>(lit);
}

Lit negate(const Lit &lit) {
    return literal_t::negate<IntTheory, BoolTheory>(lit);
}

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
                Overload{
                    [&e2](const Expr &e1){
                        return BExpression::buildTheoryLit(Rel::buildEq(e1, std::get<Expr>(e2)));
                    },
                    [&e2](const BoolExpr &lhs){
                        const auto rhs = std::get<BoolExpr>(e2);
                        return (lhs & rhs) | ((!lhs) & (!rhs));
                    }
                }, e1);
}

}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
