#pragma once

#include "itheory.hpp"
#include "thset.hpp"

namespace literal {

template<std::size_t I = 0, ITheory... Th>
inline void collectVarsImpl(const typename Theory<Th...>::Lit &lit, theory::VarSet<Th...> &s) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            using T = typename std::tuple_element_t<I, std::tuple<Th...>>;
            return std::get<I>(lit).collectVars(s.template get<typename T::Var>());
        } else {
            return collectVarsImpl<I+1, Th...>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

template<ITheory... Th>
void collectVars(const typename Theory<Th...>::Lit &lit, theory::VarSet<Th...> &s) {
    collectVarsImpl<0, Th...>(lit, s);
}

template <ITheory... Th>
theory::VarSet<Th...> vars(const typename Theory<Th...>::Lit &lit) {
    theory::VarSet<Th...> res;
    collectVars<Th...>(lit, res);
    return res;
}

}
