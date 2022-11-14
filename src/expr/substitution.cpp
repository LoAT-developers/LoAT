#include "substitution.hpp"
#include "theory.hpp"

namespace substitution {

Var first(const Pair &p) {
    return theory::first<IntTheory, BoolTheory>(p);
}

ThExpr second(const Pair &p) {
    return theory::second<IntTheory, BoolTheory>(p);
}

void collectVariables(const Subs &subs, VarSet &vars) {
    substitution::collectVars<IntTheory, BoolTheory>(subs, vars);
}


VarSet variables(const Subs &e) {
    return substitution::vars<IntTheory, BoolTheory>(e);
}

}
