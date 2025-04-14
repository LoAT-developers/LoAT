#pragma once

#include "theory.hpp"

struct AccelConfig {

    bool tryNonterm;
    bool tryAccel;
    Arith::Var n;
    Arith::Expr cost;

    AccelConfig(const bool tryNonterm, const bool tryAccel, const Arith::Var n, const Arith::Expr cost): tryNonterm(tryNonterm), tryAccel(tryAccel), n(n), cost(cost) {}

};
