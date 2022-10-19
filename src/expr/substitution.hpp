#pragma once

#include "itheory.hpp"
#include "inttheory.hpp"
#include "expression.hpp"
#include "theory.hpp"

namespace substitution {

Var first(const theory::Subs<IntTheory, BoolTheory>::Pair &p);

ThExpr second(const theory::Subs<IntTheory, BoolTheory>::Pair &p);

template <ITheory... Th>
void collectVars(const theory::Subs<Th...> &subs, theory::VarSet<Th...> &vars) {
    for (const auto &p: subs) {
        vars.insert(first(p));
        expression::collectVars<Th...>(second(p), vars);
    }
}

template <ITheory... Th>
theory::VarSet<Th...> vars(const theory::Subs<Th...> &e) {
    theory::VarSet<Th...> res;
    collectVars<Th...>(e, res);
    return res;
}

void collectVariables(const Subs &subs, VarSet &vars);

VarSet variables(const Subs &e);

}
