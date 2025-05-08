#pragma once

#include "itheory.hpp"
#include "exprfwd.hpp"
#include "arrayexpr.hpp"

template <ITheory T>
class ArrayConst {

    std::vector<Arith::Var> indices;
    std::unordered_map<Bools::Expr, typename T::Expr> cases;

public:

    const std::unordered_map<Bools::Expr, typename T::Expr>& get_cases() const;
    const std::vector<Arith::Var>& get_indices() const;

};