#pragma once

#include "numexpression.hpp"

struct AccelConfig {
    bool tryNonterm {true};
    bool tryAccel {true};
    NumVarPtr n;
};
