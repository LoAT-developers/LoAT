#pragma once

#include "theory.hpp"

struct AccelConfig {

    bool tryNonterm;
    bool tryAccel;
    bool tryNonlinear;
    Arith::Var n;
    Arith::Expr cost;

    AccelConfig(const bool tryNonterm, const bool tryAccel, const bool tryNonlinear, const Arith::Var n, const Arith::Expr cost): tryNonterm(tryNonterm), tryAccel(tryAccel), tryNonlinear(tryNonlinear), n(n), cost(cost) {}

};
