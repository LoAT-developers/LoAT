#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproof.hpp"

class BMC {

private:

    BMC(ITSProblem &its);

    void analyze();

    ITSProblem &its;
    Z3<IntTheory, BoolTheory> z3{std::numeric_limits<unsigned>::max()};
    bool approx {false};
    ITSProof proof;

    void unsat(const unsigned depth);
    void sat(const unsigned depth);

public:

    static void analyze(ITSProblem &its);

};
