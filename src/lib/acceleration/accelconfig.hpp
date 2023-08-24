#pragma once

#include "approx.hpp"
#include "numvar.hpp"

struct AccelConfig {
    Approx approx {UnderApprox};
    bool tryNonterm {true};
    NumVar n;
};
