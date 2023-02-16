#pragma once

#include "itheory.hpp"
#include "inttheory.hpp"
#include "booltheory.hpp"
#include "subs.hpp"

#include <boost/functional/hash.hpp>
#include <variant>
#include <tuple>

using TheTheory = Theory<IntTheory, BoolTheory>;
using BoolExpr = BExpr<IntTheory, BoolTheory>;
using BExpression = BoolExpression<IntTheory, BoolTheory>;
using QFormula = QuantifiedFormula<IntTheory, BoolTheory>;
using BoolExprSet = BoolExpressionSet<IntTheory, BoolTheory>;
using Guard = Conjunction<IntTheory, BoolTheory>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expression;
using Theories = TheTheory::Theories;
using VarSet = theory::VarSet<IntTheory, BoolTheory>;
using LitSet = theory::LitSet<IntTheory, BoolTheory>;
using Subs = theory::Subs<IntTheory, BoolTheory>;

extern const BoolExpr True;
extern const BoolExpr False;

namespace theory {

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, TheTheory::Theories>, T>;
}

}
