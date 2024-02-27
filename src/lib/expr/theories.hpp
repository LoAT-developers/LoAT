#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "subs.hpp"

#include <variant>
#include <tuple>

using TheTheory = Theory<Arith, Bools>;
using BoolExpr = BExpr<Arith, Bools>;
using BoolExprSet = BoolExpressionSet<Arith, Bools>;
using Guard = Conjunction<Arith, Bools>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expr;
using Theories = TheTheory::Theories;
using VarSet = theories::VarSet<Arith, Bools>;
using LitSet = theories::LitSet<Arith, Bools>;
using Subs = theories::Subs<Arith, Bools>;
using BSubs = BoolSubs<Arith, Bools>;

const BoolExpr top();
const BoolExpr bot();

namespace bools {

template <class Lits>
Bools::Expr mkAndFromLits(const Lits &lits) {
    return BoolExpression<Arith, Bools>::mkAndFromLits(lits);
}

template <class Children>
Bools::Expr mkAnd(const Children &lits) {
    return BoolExpression<Arith, Bools>::mkAnd(lits);
}

template <class Lits>
Bools::Expr mkOrFromLits(const Lits &lits) {
    return BoolExpression<Arith, Bools>::mkOrFromLits(lits);
}

template <class Children>
Bools::Expr mkOr(const Children &lits) {
    return BoolExpression<Arith, Bools>::mkOr(lits);
}

Bools::Expr mkLit(const TheTheory::Lit &lit);

}

namespace theories {

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, TheTheory::Theories>, T>;
}

}

template<>
struct std::hash<BoolExpr> {
    std::size_t operator()(const BoolExpr x) const noexcept {
        return boost::hash_value(x);
    }
};
