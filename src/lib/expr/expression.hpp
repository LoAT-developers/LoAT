#pragma once

#include "itheory.hpp"
#include "boolexpr.hpp"
#include "numexpression.hpp"
#include "inttheory.hpp"
#include "booltheory.hpp"
#include "theory.hpp"

namespace expression {

template <ITheory... Th>
typename Theory<Th...>::Expression subs(const typename Theory<Th...>::Expression &expr, const theory::Subs<Th...> &subs) {
    if constexpr ((std::same_as<IntTheory, Th> || ...)) {
        if (std::holds_alternative<Expr>(expr)) {
            return std::get<Expr>(expr).subs(subs.template get<IntTheory>());
        }
    }
    if constexpr ((std::same_as<BoolTheory, Th> || ...)) {
        if (std::holds_alternative<BExpr<Th...>>(expr)) {
            return std::get<BExpr<Th...>>(expr)->subs(subs);
        }
    }
    throw std::logic_error("unknown theory");
}

template <ITheory... Th>
void collectVars(const typename Theory<Th...>::Expression &expr, theory::VarSet<Th...> &vars) {
    if constexpr ((std::same_as<IntTheory, Th> || ...)) {
        if (std::holds_alternative<Expr>(expr)) {
            std::get<Expr>(expr).collectVars(vars.template get<NumVar>());
        }
    }
    if constexpr ((std::same_as<BoolTheory, Th> || ...)) {
        if (std::holds_alternative<BExpr<Th...>>(expr)) {
            std::get<BExpr<Th...>>(expr)->collectVars(vars);
        }
    }
}

template <ITheory... Th>
theory::VarSet<Th...> vars(const typename Theory<Th...>::Expression &e) {
    theory::VarSet<Th...> res;
    collectVars<Th...>(e, res);
    return res;
}

void collectVars(const ThExpr &e, VarSet &res);

VarSet variables(const ThExpr &e);

}

std::ostream& operator<<(std::ostream &s, const ThExpr &e);
