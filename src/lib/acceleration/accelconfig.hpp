#pragma once

#include <utility>

#include "theory.hpp"

struct AccelConfig {

    bool tryNonterm;
    bool tryAccel;
    bool tryNonlinear;
    ArithVarPtr n;
    Arith::Expr cost;

    AccelConfig(
        const bool tryNonterm,
        const bool tryAccel,
        const bool tryNonlinear,
        ArithVarPtr n,
        Arith::Expr cost) :
        tryNonterm(tryNonterm),
        tryAccel(tryAccel),
        tryNonlinear(tryNonlinear),
        n(std::move(n)),
        cost(std::move(cost)) {}

};
