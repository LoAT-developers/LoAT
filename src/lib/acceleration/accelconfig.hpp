#pragma once

#include <utility>

#include "theory.hpp"

struct AccelConfig {

    bool tryNonterm;
    bool tryAccel;
    bool tryNonlinear;
    bool tryArrays;
    ArithVarPtr n;
    Arith::Expr cost;

    AccelConfig(
        const bool tryNonterm,
        const bool tryAccel,
        const bool tryNonlinear,
        const bool tryArrays,
        ArithVarPtr n,
        Arith::Expr cost) :
        tryNonterm(tryNonterm),
        tryAccel(tryAccel),
        tryNonlinear(tryNonlinear),
        tryArrays(tryArrays),
        n(std::move(n)),
        cost(std::move(cost)) {}

};
