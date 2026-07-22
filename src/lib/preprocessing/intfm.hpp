#pragma once

#include "subs.hpp"

struct IntegerFourierMotzkinResult {

    struct Bounds {
        std::vector<Arith::Expr> lower {};
        std::vector<Arith::Expr> upper {};
    };

    Bools::Expr t;
    std::vector<std::pair<ArithVarPtr, Bounds>> bounds {};

    explicit IntegerFourierMotzkinResult(Bools::Expr);

};

/**
 * Fourier-Motzkin, restricted to the case that all coefficients are 1 or -1, so that it can be used for integers.
 */
IntegerFourierMotzkinResult integerFourierMotzkin(const Bools::Expr& e, const std::function<bool(const ArrayVarPtr<Arith> &)> &allow);
