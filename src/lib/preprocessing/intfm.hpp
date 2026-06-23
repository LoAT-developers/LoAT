#pragma once

#include "theory.hpp"
#include "subs.hpp"

/**
 * Fourier-Motzkin, restricted to the case that all coefficients are 1 or -1, so that it can be used for integers.
 */
std::pair<Bools::Expr, std::vector<std::pair<ArithVarPtr, std::vector<Arith::Expr>>>> integerFourierMotzkin(const Bools::Expr& e, const std::function<bool(const ArrayVarPtr<Arith> &)> &allow);
