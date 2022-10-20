#include "expression.hpp"

namespace expression {

void collectVars(const ThExpr &e, VarSet &res) {
    expression::collectVars<IntTheory, BoolTheory>(e, res);
}
VarSet variables(const ThExpr &e) {
    return expression::vars<IntTheory, BoolTheory>(e);
}

}

std::ostream& operator<<(std::ostream &s, const ThExpr &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}

bool operator==(const ThExpr &e, const Var &var) {
    return e == TheTheory::varToExpr(var);
}
