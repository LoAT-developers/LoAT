#include "substitution.hpp"

namespace substitution {

Var first(const theory::Subs<IntTheory, BoolTheory>::Pair &p) {
    return theory::first<IntTheory, BoolTheory>(p);
}

ThExpr second(const theory::Subs<IntTheory, BoolTheory>::Pair &p) {
    return theory::second<IntTheory, BoolTheory>(p);
}

void collectVariables(const Subs &subs, VarSet &vars) {
    substitution::collectVars<IntTheory, BoolTheory>(subs, vars);
}


VarSet variables(const Subs &e) {
    return substitution::vars<IntTheory, BoolTheory>(e);
}

}
