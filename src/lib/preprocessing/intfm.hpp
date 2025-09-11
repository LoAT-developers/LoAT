#pragma once

#include "theory.hpp"
#include "subs.hpp"

/**
 * Fourier-Motzkin, restricted to the case that all coefficients are 1 or -1, so that it can be used for integers.
 */
Bools::Expr integerFourierMotzkin(const Bools::Expr& e, const std::function<bool(const Var &)> &allow);
