#pragma once

#include "numvar.hpp"

struct AccelConfig {
    bool tryNonterm {true};
    bool tryAccel {true};
    NumVarPtr n;
};
