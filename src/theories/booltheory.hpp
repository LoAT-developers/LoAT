#pragma once

#include "itheory.hpp"
#include "boollit.hpp"
#include "boolvar.hpp"

struct BoolTheory {
    using Lit = BoolLit;
    using Var = BoolVar;
    using Val = bool;
};

static_assert(ITheory<BoolTheory>);

