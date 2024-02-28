#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "subs.hpp"
#include "boolexpr.hpp"
#include "boolsubs.hpp"

#include <variant>
#include <tuple>

using TheTheory = Theory<Arith, Bools>;
using BoolExpr = BExpr;
using BoolExprSet = BoolExpressionSet;
using Guard = Conjunction<Arith, Bools>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expr;
using Theories = TheTheory::Theories;
using VarSet = theories::VarSet<Arith, Bools>;
using LitSet = theories::LitSet<Arith, Bools>;
using Subs = theories::Subs<Arith, Bools>;
using BSubs = BoolSubs;

const BoolExpr top();
const BoolExpr bot();

namespace bools {

template <class Lits>
Bools::Expr mkAndFromLits(const Lits &lits) {
    return BoolExpression::mkAndFromLits(lits);
}

template <class Children>
Bools::Expr mkAnd(const Children &lits) {
    return BoolExpression::mkAnd(lits);
}

template <class Lits>
Bools::Expr mkOrFromLits(const Lits &lits) {
    return BoolExpression::mkOrFromLits(lits);
}

template <class Children>
Bools::Expr mkOr(const Children &lits) {
    return BoolExpression::mkOr(lits);
}

Bools::Expr mkLit(const TheTheory::Lit &lit);

}

namespace theories {

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, TheTheory::Theories>, T>;
}

template<std::size_t I = 0, ITheory... Th>
inline BExpr subsImpl(const typename Theory<Th...>::Lit &lit, const theories::Subs<Th...> &s) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            using T = typename std::tuple_element_t<I, std::tuple<Th...>>;
            if constexpr (std::same_as<typename T::Var, Bools::Var>) {
                return s.template get<T>().subs(std::get<I>(lit));
            } else {
                return BoolExpression::mkLit(std::get<I>(lit).subs(s.template get<T>()));
            }
        } else {
            return subsImpl<I+1, Th...>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

template<ITheory... Th>
BExpr subs(const typename Theory<Th...>::Lit &lit, const theories::Subs<Th...> &s) {
    return subsImpl<0, Th...>(lit, s);
}

}

template<>
struct std::hash<BoolExpr> {
    std::size_t operator()(const BoolExpr x) const noexcept {
        return boost::hash_value(x);
    }
};
