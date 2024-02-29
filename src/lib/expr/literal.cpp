#include "literal.hpp"

namespace theories {

constexpr size_t num_theories {std::tuple_size_v<TheTheory::Theories>};

template<std::size_t I = 0>
inline void collectVarsImpl(const Lit &lit, VS &s) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).collectVars(s.template get<I>());
        } else {
            return collectVarsImpl<I+1>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}


void collectVars(const Lit &lit, VS &s) {
    collectVarsImpl<0>(lit, s);
}

VS vars(const Lit &lit) {
    VS res;
    collectVars(lit, res);
    return res;
}

template <size_t I = 0>
inline bool isTriviallyTrueImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyTrue();
        }
        return isTriviallyTrueImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isTriviallyTrue(const Lit &lit) {
    return isTriviallyTrueImpl<0>(lit);
}

template <size_t I = 0>
inline bool isTriviallyFalseImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyFalse();
        }
        return isTriviallyFalseImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isTriviallyFalse(const Lit &lit) {
    return isTriviallyFalseImpl<0>(lit);
}

template <size_t I = 0>
inline Lit negateImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return !std::get<I>(lit);
        }
        return negateImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

Lit negate(const Lit &lit) {
    return negateImpl<0>(lit);
}

size_t hash(const Lit lit) {
    return std::visit(
        Overload {
            [](const auto &lit) {
                return lit.hash();
            }
        }, lit);
}

}
