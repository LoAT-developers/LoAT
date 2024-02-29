#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "boolexpr.hpp"

#include <variant>
#include <tuple>

using TheTheory = Theory<Arith, Bools>;
using BoolExprSet = BoolExpressionSet;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheTheory::Expr;
using Theories = TheTheory::Theories;
using VarSet = VariantSet<Arith::Var, Bools::Var>;
using LitSet = VariantSet<Arith::Lit, Bools::Lit>;

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

namespace theory {

std::string getName(const Var &var);
bool isTempVar(const Var &var);
bool isProgVar(const Var &var);
Var next(const Var &var);
ThExpr toExpr(const Var &var);
void collectVars(const ThExpr &expr, VarSet &vars);
VarSet vars(const ThExpr &e);
BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2);
BoolExpr mkNeq(const ThExpr &e1, const ThExpr &e2);
Arith theory(const ArithVarPtr&);
Bools theory(const BoolVarPtr&);
Arith theory(const ArithExprPtr&);
Bools theory(const BoolExpr&);
bool isLinear(const Lit &lit);
bool isPoly(const Lit &lit);
void collectVars(const Lit &lit, VarSet &s);
VarSet vars(const Lit &lit);
bool isTriviallyTrue(const Lit &lit);
bool isTriviallyFalse(const Lit &lit);
Lit negate(const Lit &lit);
size_t hash(const Lit lit);

template <class ... Ts>
auto apply(const Var &x, Ts... f) {
    return std::visit(Overload{f...}, x);
}

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, TheTheory::Theories>, T>;
}

}

std::ostream& operator<<(std::ostream &s, const Var &e);

std::ostream& operator<<(std::ostream &s, const ThExpr &e);

std::ostream& operator<<(std::ostream &s, const Lit &e);
