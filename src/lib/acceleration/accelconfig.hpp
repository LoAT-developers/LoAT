#pragma once

#include "theory.hpp"

struct AccelConfig {
    bool tryNonterm {true};
    bool tryAccel {true};
    Arith::Var n;
};
