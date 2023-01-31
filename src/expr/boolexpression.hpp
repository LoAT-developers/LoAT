#pragma once

#include "boolexpr.hpp"
#include "theory.hpp"

namespace boolExpression {

const BoolExpr build(const Lit &lit);

template <ITheory Th>
BoolExpr transform(const BExpr<Th> &e) {
    static const std::function<BoolExpr(const typename Theory<Th>::Lit&)> mapper = [](const auto &lit) {
        return std::visit([](const auto &rel) -> BoolExpr {return BoolExpression<IntTheory, BoolTheory>::buildTheoryLit(rel);}, lit);
    };
    return e->map(mapper);
}

}
