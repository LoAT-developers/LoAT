#pragma once

#include "arith.hpp"
#include "boolexpr.hpp"
#include "complexity.hpp"
#include "model.hpp"

namespace LimitSmtEncoding {

struct ComplexityWitness {
    Complexity cpx;
    std::optional<ModelPtr> subs;
    Arith::Var param;
};

ComplexityWitness applyEncoding(const Bools::Expr& expr, const Arith::Expr& cost, const Complexity& currentRes);

}
