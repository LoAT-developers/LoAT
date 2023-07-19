#pragma once

#include "approx.hpp"

struct AccelConfig {
    Approx approx {UnderApprox};
    bool tryNonterm {true};
};
