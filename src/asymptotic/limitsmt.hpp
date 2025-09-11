#pragma once

#include "arith.hpp"
#include "boolexpr.hpp"
#include "complexity.hpp"

namespace LimitSmtEncoding {

struct ComplexityWitness {
    Complexity cpx;
    ArithSubs subs;
    Arith::Var param;
};

ComplexityWitness applyEncoding(const Bools::Expr& expr, const Arith::Expr& cost, const Complexity& currentRes);

}
