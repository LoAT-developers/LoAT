#pragma once

#include "z3context.hpp"
#include <swine/swine.h>

class SwineContext: public Z3Context {

public:

    SwineContext(swine::Swine &solver);

    z3::expr pow(const z3::expr &base, const z3::expr &exp) override;

private:

    swine::Swine &solver;

};
