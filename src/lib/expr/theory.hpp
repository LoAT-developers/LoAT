#pragma once

#include "theories.hpp"

namespace theory {

std::string getName(const Var &var);

bool isTempVar(const Var &var);

bool isProgVar(const Var &var);

Var next(const Var &var);

ThExpr toExpr(const Var &var);

void collectVars(const ThExpr &expr, VarSet &vars);

VarSet vars(const ThExpr &e);

using Pair = Subs::Pair;

Var first(const Pair &p);

ThExpr second(const Pair &p);

void collectVars(const Subs &subs, VarSet &vars);

VarSet vars(const Subs &e);

template<std::size_t I = 0>
inline void collectCoDomainVars(const Subs &subs, VarSet &res) {
    if constexpr (I < std::tuple_size_v<TheTheory::Theories>) {
        if constexpr (theories::is<I, Bools>()) {
            subs.get<I>().collectCoDomainVars(res);
        } else {
            subs.get<I>().collectCoDomainVars(res.get<I>());
        }
        collectCoDomainVars<I+1>(subs, res);
    }
}

VarSet coDomainVars(const Subs &subs);

void collectVariables(VarSet &res, const Lit &e);

VarSet variables(const Lit &e);

bool isTriviallyTrue(const Lit &lit);

Lit negate(const Lit &lit);

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2);

BoolExpr mkNeq(const ThExpr &e1, const ThExpr &e2);

Arith theory(const ArithVarPtr&);

Bools theory(const BoolVarPtr&);

Arith theory(const ArithExprPtr&);

Bools theory(const BoolExpr&);

template <class ... Ts>
auto apply(const Var &x, Ts... f) {
    return std::visit(Overload{f...}, x);
}

bool isLinear(const Lit &lit);

bool isPoly(const Lit &lit);

Subs impliedEqualities(const BoolExpr e);

}

std::ostream& operator<<(std::ostream &s, const Var &e);

std::ostream& operator<<(std::ostream &s, const ThExpr &e);

std::ostream& operator<<(std::ostream &s, const Lit &e);

namespace std {

template<>
struct tuple_size<Subs::Pair> {
    static constexpr size_t value = 2;
};


template<>
struct tuple_element<0, Subs::Pair> {
    using type = Var;
};

template<>
struct tuple_element<1, Subs::Pair> {
    using type = ThExpr;
};

template<std::size_t Index>
std::tuple_element_t<Index, Subs::Pair> get(const Subs::Pair& p) {
    if constexpr (Index == 0) {
        return theory::first(p);
    }
    if constexpr (Index == 1) {
        return theory::second(p);
    }
}

}
