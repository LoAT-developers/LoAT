#pragma once

#include "itheory.hpp"
#include "inttheory.hpp"
#include "expression.hpp"

namespace substitution {

using TheTheory = Theory<IntTheory, BoolTheory>;
using TheSubs = theory::Subs<IntTheory, BoolTheory>;
using Pair = TheSubs::Pair;

Var first(const Pair &p);

ThExpr second(const Pair &p);

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

template<std::size_t I = 0>
inline void concatImpl(const TheSubs &fst, const TheSubs &snd, TheSubs &res) {
    if constexpr (I < std::tuple_size_v<TheTheory::Theories>) {
        if constexpr (theory::is<I, BoolTheory>()) {
            res.get<I>() = fst.get<I>().concat(snd);
        } else {
            res.get<I>() = fst.get<I>().concat(snd.get<I>());
        }
        concatImpl<I+1>(fst, snd, res);
    }
}

template<std::size_t I = 0>
inline void composeImpl(const TheSubs &fst, const TheSubs &snd, TheSubs &res) {
    if constexpr (I < std::tuple_size_v<TheTheory::Theories>) {
        if constexpr (theory::is<I, BoolTheory>()) {
            res.get<I>() = fst.get<I>().concat(snd).unite(snd.get<I>());
        } else {
            res.get<I>() = fst.get<I>().compose(snd.get<I>());
        }
        composeImpl<I+1>(fst, snd, res);
    }
}

TheSubs compose(const TheSubs &fst, const TheSubs &snd);

TheSubs concat(const TheSubs &fst, const TheSubs &snd);

}
