#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "boolexpr.hpp"

namespace theories {

template<std::size_t I = 0, ITheory... Th>
inline void collectVarsImpl(const typename Theory<Th...>::Lit &lit, theories::VarSet<Th...> &s) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).collectVars(s.template get<I>());
        } else {
            return collectVarsImpl<I+1, Th...>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

template<IBaseTheory... Th>
void collectVars(const typename BaseTheory<Th...>::Lit &lit, theories::VarSet<Th...> &s) {
    collectVarsImpl<0, Th...>(lit, s);
}

template <IBaseTheory... Th>
theories::VarSet<Th...> vars(const typename BaseTheory<Th...>::Lit &lit) {
    theories::VarSet<Th...> res;
    collectVars<Th...>(lit, res);
    return res;
}

template <size_t I = 0, IBaseTheory... Th>
inline bool isTriviallyTrueImpl(const typename BaseTheory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyTrue();
        }
        return isTriviallyTrueImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <IBaseTheory... Th>
bool isTriviallyTrue(const typename BaseTheory<Th...>::Lit &lit) {
    return isTriviallyTrueImpl<0, Th...>(lit);
}

template <size_t I = 0, IBaseTheory... Th>
inline bool isTriviallyFalseImpl(const typename BaseTheory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyFalse();
        }
        return isTriviallyFalseImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <IBaseTheory... Th>
bool isTriviallyFalse(const typename BaseTheory<Th...>::Lit &lit) {
    return isTriviallyFalseImpl<0, Th...>(lit);
}

template <size_t I = 0, IBaseTheory... Th>
inline typename BaseTheory<Th...>::Lit negateImpl(const typename BaseTheory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return !std::get<I>(lit);
        }
        return negateImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <IBaseTheory... Th>
typename BaseTheory<Th...>::Lit negate(const typename BaseTheory<Th...>::Lit &lit) {
    return negateImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline bool isLinearImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).isLinear();
        }
        return isLinearImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
bool isLinear(const typename Theory<Th...>::Lit &lit) {
    return isLinearImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline bool isPolyImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).isPoly();
        }
        return isPolyImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
bool isPoly(const typename Theory<Th...>::Lit &lit) {
    return isPolyImpl<0, Th...>(lit);
}

template <IBaseTheory... Th>
size_t hash(const typename BaseTheory<Th...>::Lit lit) {
    return std::visit(
        Overload {
            [](const auto &lit) {
                return lit.hash();
            }
        }, lit);
}

template <size_t I = 0, IBaseTheory... Th>
inline bool evalImpl(const typename BaseTheory<Th...>::Lit &lit, const typename BaseTheory<Th...>::Model &m) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).eval(std::get<I>(m));
        }
        return evalImpl<I+1, Th...>(lit, m);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <IBaseTheory... Th>
bool eval(const typename BaseTheory<Th...>::Lit lit, const typename BaseTheory<Th...>::Model &m) {
    return evalImpl<0, Th...>(lit, m);
}

}
