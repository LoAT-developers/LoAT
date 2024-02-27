#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "subs.hpp"

#include <variant>
#include <tuple>

using TheTheory = Theory<Arith, Bools>;
using BoolExpr = BExpr<Arith, Bools>;
using BExpression = BoolExpression<Arith, Bools>;
using BoolExprSet = BoolExpressionSet<Arith, Bools>;
using Guard = Conjunction<Arith, Bools>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expr;
using Theories = TheTheory::Theories;
using VarSet = theory::VarSet<Arith, Bools>;
using LitSet = theory::LitSet<Arith, Bools>;
using Subs = theory::Subs<Arith, Bools>;
using BSubs = BoolSubs<Arith, Bools>;

const BoolExpr top();
const BoolExpr bot();

namespace theory {

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
