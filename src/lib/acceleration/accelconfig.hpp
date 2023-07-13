#pragma once

#include "approx.hpp"

struct AccelConfig {
    Approx approx {UnderApprox};
    bool allowDisjunctions {true};
    bool tryNonterm {true};
    unsigned long smt_timeout;
};
