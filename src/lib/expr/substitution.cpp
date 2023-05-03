#include "substitution.hpp"
#include "theory.hpp"

namespace substitution {

Var first(const Pair &p) {
    return theory::first<IntTheory, BoolTheory>(p);
}

ThExpr second(const Pair &p) {
    return theory::second<IntTheory, BoolTheory>(p);
}

VarSet variables(const Subs &e) {
    return substitution::vars<IntTheory, BoolTheory>(e);
}

TheSubs compose(const TheSubs &fst, const TheSubs &snd) {
    TheSubs res;
    composeImpl(fst, snd, res);
    return res;
}

TheSubs concat(const TheSubs &fst, const TheSubs &snd) {
    TheSubs res;
    concatImpl(fst, snd, res);
    return res;
}

VarSet coDomainVars(const TheSubs &subs) {
    VarSet res;
    collectCoDomainVars(subs, res);
    return res;
}

}
