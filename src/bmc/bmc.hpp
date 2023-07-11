#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"

class BMC {

private:

    static const bool log;

    BMC(const ITSProblem &its);

    void analyze();

    ITSProblem its;
    Z3<IntTheory, BoolTheory> z3{std::numeric_limits<unsigned>::max()};
    bool approx {false};

public:

    static void analyze(const ITSProblem &its);

};
