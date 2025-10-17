#pragma once

#include "itheory.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "boolexpr.hpp"

#include <variant>
#include <tuple>

using BoolExprSet = BoolExprSet;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using Expr = TheTheory::Expr;
using Theories = TheTheory::Theories;

constexpr size_t num_theories {std::tuple_size_v<Theories>};

Bools::Expr top();
Bools::Expr bot();

namespace bools {

template <class Children>
Bools::Expr mkAnd(const Children &lits) {
    using Elem = std::remove_cvref_t<decltype(*lits.begin())>;
    static_assert(std::is_same_v<Elem, Bools::Expr> || std::is_constructible_v<Lit, Elem>);
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
Var next(const Var &var);
Var postVar(const Var &var);
Var progVar(const Var &var);
Expr toExpr(const Var &var);
void collectVars(const Expr &expr, VarSet &vars);
VarSet vars(const Expr &e);
Bools::Expr mkEq(const Expr &e1, const Expr &e2);
Bools::Expr mkNeq(const Expr &e1, const Expr &e2);
Arith theory(const Arith::Var&);
Bools theory(const Bools::Var&);
Arrays<Arith> theory(const Arrays<Arith>::Var&);
Arith theory(const Arith::Expr&);
Bools theory(const Bools::Expr&);
Arrays<Arith> theory(const Arrays<Arith>::Expr&);
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
Type to_type(const Expr &x);
Type to_type(const Var &x);
Type to_type(const std::string &x);
std::optional<Var> is_var(const Expr &x);

template <class Int, class Bool, class IntArray, class ... Ts>
auto apply(const std::variant<Int, Bool, IntArray> &x, Ts... f) noexcept {
    if (std::holds_alternative<Int>(x)) {
        return Overload{f...}(*std::get_if<Int>(&x));
    }
    if (std::holds_alternative<Bool>(x)) {
        return Overload{f...}(*std::get_if<Bool>(&x));
    }
    return Overload{f...}(*std::get_if<IntArray>(&x));
}

template <class Int, class Bool, class IntArray, class... Ts>
void iter(const std::tuple<Int, Bool, IntArray>& x, Ts... f) noexcept {
    Overload{f...}(std::get<Int>(x));
    Overload{f...}(std::get<Bool>(x));
    Overload{f...}(std::get<IntArray>(x));
}

template <class Int, class Bool, class IntArray, class... Ts>
bool all_of(const std::tuple<Int, Bool, IntArray>& x, Ts... f) noexcept {
    if (!Overload{f...}(std::get<Int>(x))) {
        return false;
    }
    if (!Overload{f...}(std::get<Bool>(x))) {
        return false;
    }
    return Overload{f...}(std::get<IntArray>(x));
}

template <size_t I, ITheory T>
constexpr bool is() {
    return std::same_as<std::tuple_element_t<I, Theories>, T>;
}

std::ostream& operator<<(std::ostream& s, const Type& e);

}

std::ostream& operator<<(std::ostream &s, const Var &e);

std::ostream& operator<<(std::ostream &s, const Expr &e);

std::ostream& operator<<(std::ostream &s, const Lit &e);
