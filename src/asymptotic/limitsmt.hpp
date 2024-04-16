#pragma once

#include "arith.hpp"
#include "boolexpr.hpp"
#include "complexity.hpp"

namespace LimitSmtEncoding {

Complexity applyEncoding(const Bools::Expr exp, const Arith::Expr cost, Complexity currentRes);

}

