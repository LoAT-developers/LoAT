#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "booltheory.hpp"
#include "subs.hpp"

#include <variant>
#include <tuple>

using TheTheory = Theory<Arith, BoolTheory>;
using BoolExpr = BExpr<Arith, BoolTheory>;
using BExpression = BoolExpression<Arith, BoolTheory>;
using BoolExprSet = BoolExpressionSet<Arith, BoolTheory>;
using Guard = Conjunction<Arith, BoolTheory>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expression;
using Theories = TheTheory::Theories;
using VarSet = theory::VarSet<Arith, BoolTheory>;
using LitSet = theory::LitSet<Arith, BoolTheory>;
using Subs = theory::Subs<Arith, BoolTheory>;
using BSubs = BoolSubs<Arith, BoolTheory>;

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
