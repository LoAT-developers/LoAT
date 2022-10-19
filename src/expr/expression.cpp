#include "expression.hpp"

namespace expression {

void collectVars(const ThExpr &e, VarSet &res) {
    expression::collectVars<IntTheory, BoolTheory>(e, res);
}
VarSet variables(const ThExpr &e) {
    return expression::vars<IntTheory, BoolTheory>(e);
}

}

bool operator==(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(Overload{
                          [](const Expr &e1, const Expr &e2) {return e1.equals(e2);},
                          [](const BoolExpr &e1, const BoolExpr &e2) {return e1 == e2;},
                          [](const auto &e1, const auto &e2) {return false;}
                      }, e1, e2);
}

std::ostream& operator<<(std::ostream &s, const ThExpr &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}

bool operator==(const ThExpr &e, const Var &var) {
    return std::visit(Overload{
                          [](const Expr &e, const NumVar &var) {return e.equals(var);},
                          [](const BoolExpr &e1, const BoolVar &e2) {return e1 == e2;},
                          [](const auto &e, const auto &var) {return false;},
                      }, e, var);
}
