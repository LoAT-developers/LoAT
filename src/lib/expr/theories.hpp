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
using Guard = Conjunction;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expr;
using Theories = TheTheory::Theories;
using VarSet = theories::ThSet<Arith::Var, Bools::Var>;
using LitSet = theories::ThSet<Arith::Lit, Bools::Lit>;
using Subs = theory::Subs;
using BSubs = BoolSubs;

const BoolExpr top();
const BoolExpr bot();

namespace bools {

template <class Lits>
Bools::Expr mkAndFromLits(const Lits &lits) {
    return BoolExpression::mkAndFromLits(lits);
}

Bools::Expr mkAndFromLits(const std::initializer_list<Lit> &lits);

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

}

template<>
struct std::hash<BoolExpr> {
    std::size_t operator()(const BoolExpr x) const noexcept {
        return boost::hash_value(x);
    }
};
