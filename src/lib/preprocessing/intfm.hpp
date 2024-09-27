#pragma once

#include "theory.hpp"
#include "subs.hpp"
#include "model.hpp"

/**
 * Fourier-Motzkin, restricted to the case that all coefficients are 1 or -1, so that it can be used for integers.
 */
class IntegerFourierMotzkin {

private:

    std::function<bool(const Var &)> allow;

public:

    IntegerFourierMotzkin(const std::function<bool(const Var &)> &allow);

    Bools::Expr run(Bools::Expr e);

};
