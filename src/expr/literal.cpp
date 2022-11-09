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

BoolExpr mkEq(const Var &x, const ThExpr &e) {
    return std::visit(
                Overload{
                    [&e](const NumVar &x){
                        return BExpression::buildTheoryLit(Rel::buildEq(x, std::get<Expr>(e)));
                    },
                    [&e](const BoolVar &x){
                        const auto lhs = BExpression::buildTheoryLit(BoolLit(x));
                        const auto rhs = std::get<BoolExpr>(e);
                        return (lhs & rhs) | ((!lhs) & (!rhs));
                    }
                }, x);
}

}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
