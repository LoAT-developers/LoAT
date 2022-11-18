#pragma once

#include "itheory.hpp"
#include "thset.hpp"

namespace literal_t {

template<std::size_t I = 0, ITheory... Th>
inline void collectVarsImpl(const typename Theory<Th...>::Lit &lit, theory::VarSet<Th...> &s) {
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

template <size_t I = 0, ITheory... Th>
inline typename Theory<Th...>::Lit normalizeImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return typename Theory<Th...>::Lit(std::get<I>(lit).normalize());
        }
        return normalizeImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
typename Theory<Th...>::Lit normalize(const typename Theory<Th...>::Lit &lit) {
    return normalizeImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline bool isTriviallyTrueImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyTrue();
        }
        return isTriviallyTrueImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
bool isTriviallyTrue(const typename Theory<Th...>::Lit &lit) {
    return isTriviallyTrueImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline typename Theory<Th...>::Lit negateImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return !std::get<I>(lit);
        }
        return negateImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
typename Theory<Th...>::Lit negate(const typename Theory<Th...>::Lit &lit) {
    return negateImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline std::string toRedlogImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            return std::get<I>(lit).toRedlog();
        }
        return toRedlogImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
std::string toRedlog(const typename Theory<Th...>::Lit &lit) {
    return toRedlogImpl<0, Th...>(lit);
}

template <size_t I = 0, ITheory... Th>
inline size_t hashImpl(const typename Theory<Th...>::Lit &lit) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            size_t res = std::get<I>(lit).hash();
            boost::hash_combine(res, I);
            return res;
        }
        return hashImpl<I+1, Th...>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
size_t hash(const typename Theory<Th...>::Lit &lit) {
    return hashImpl<0, Th...>(lit);
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

template <size_t I = 0, ITheory... Th>
inline bool impliesImpl(const typename Theory<Th...>::Lit &x, const typename Theory<Th...>::Lit &y) {
    if constexpr (I < sizeof...(Th)) {
        if (x.index() == I) {
            return std::get<I>(x).implies(std::get<I>(y));
        }
        return impliesImpl<I+1, Th...>(x, y);
    } else {
        throw std::logic_error("unknown theory");
    }
}

template <ITheory... Th>
bool implies(const typename Theory<Th...>::Lit &x, const typename Theory<Th...>::Lit &y) {
    if (x.index() != y.index()) {
        return false;
    }
    return impliesImpl<0, Th...>(x, y);
}

}