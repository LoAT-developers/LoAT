#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"

class ABMC {

private:

    static const bool log;

    ABMC(const ITSProblem &its);

    void analyze();

    ITSProblem its;
    Z3<IntTheory, BoolTheory> z3{std::numeric_limits<unsigned>::max()};
    bool approx {false};

public:

    static void analyze(const ITSProblem &its);

};
