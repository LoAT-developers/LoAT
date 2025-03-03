#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "boolexpr.hpp"
#include "visit.hpp"

#include <variant>
#include <tuple>
#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

using TheTheory = Theory<Arith, Bools>;
using BoolExprSet = BoolExprSet;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using Expr = TheTheory::Expr;
using Const = TheTheory::Const;
using Theories = TheTheory::Theories;
using VarSet = VariantSet<Arith::Var, Bools::Var>;
using LitSet = VariantSet<Arith::Lit, Bools::Lit>;

constexpr size_t num_theories {std::tuple_size_v<Theories>};

const Bools::Expr top();
const Bools::Expr bot();

namespace bools {

template <class Lits>
Bools::Expr mkAndFromLits(const Lits &lits) {
    return BoolExpr::mkAndFromLits(lits);
}

Bools::Expr mkAndFromLits(const std::initializer_list<Lit> &lits);

template <class Children>
Bools::Expr mkAnd(const Children &lits) {
    return BoolExpr::mkAnd(lits);
}

template <class Children>
Bools::Expr mkOr(const Children &lits) {
    return BoolExpr::mkOr(lits);
}

Bools::Expr mkLit(const Lit &lit);

}

namespace theory {

std::string getName(const Var &var);
bool isTempVar(const Var &var);
bool isProgVar(const Var &var);
bool isPostVar(const Var &var);
Var next(const Type t, const unsigned dimension);
Var postVar(const Var &var);
Var progVar(const Var &var);
Expr toExpr(const Var &var);
Expr toExpr(const Const &var);
void collectVars(const Expr &expr, VarSet &vars);
VarSet vars(const Expr &e);
Bools::Expr mkEq(const Expr &e1, const Expr &e2);
Bools::Expr mkNeq(const Expr &e1, const Expr &e2);
Arith theory(const Arith::Var);
Bools theory(const Bools::Var);
Arith theory(const Arith::Expr);
Bools theory(const Bools::Expr);
bool isLinear(const Lit &lit);
bool isPoly(const Lit &lit);
void collectVars(const Lit &lit, VarSet &s);
VarSet vars(const Lit &lit);
bool isTriviallyTrue(const Lit &lit);
bool isTriviallyFalse(const Lit &lit);
Lit negate(const Lit &lit);
size_t hash(const Lit &lit);
sexpresso::Sexp to_smtlib(const Lit &l);
sexpresso::Sexp to_smtlib(const Expr &e);
void simplifyAnd(LitSet&);
ArrayType to_type(const Expr &x);
ArrayType to_type(const Var &x);
std::optional<Var> is_var(const Expr &x);

template <class Int, class Bool, class ... Ts>
auto apply(const std::variant<Int, Bool> &x, Ts... f) {
    return std::visit(Overload{f...}, x);
}

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, Theories>, T>;
}

std::ostream& operator<<(std::ostream &s, const theory::Type &e);

}

std::ostream& operator<<(std::ostream &s, const Var &e);

std::ostream& operator<<(std::ostream &s, const Expr &e);

std::ostream& operator<<(std::ostream &s, const Lit &e);
