#pragma once

#include "arithexpr.hpp"

struct AccelConfig {
    bool tryNonterm {true};
    bool tryAccel {true};
    ArithVarPtr n;
};
