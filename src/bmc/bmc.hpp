#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproof.hpp"
#include "smtfactory.hpp"

class BMC {

private:

    explicit BMC(ITSProblem &its);

    void analyze();

    ITSProblem &its;
    Z3<Arith, Bools> solver{};
    bool approx {false};
    VarSet vars {};
    std::unordered_map<Var, Var> post_vars {};
    unsigned depth {0};
    ITSProof proof {};

    BoolExpr encode_transition(const TransIdx idx);
    void unsat();
    void sat();

public:

    static void analyze(ITSProblem &its);

};
