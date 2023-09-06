#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "itsproof.hpp"
#include "smtfactory.hpp"

class BMC {

private:

    BMC(ITSProblem &its);

    void analyze();

    ITSProblem &its;
    Z3<IntTheory, BoolTheory> solver{smt::default_timeout};
    bool approx {false};
    VarSet vars;
    std::map<Var, Var> post_vars;
    unsigned depth {0};
    ITSProof proof;

    BoolExpr encode_transition(const TransIdx idx);
    void unsat();
    void sat();

public:

    static void analyze(ITSProblem &its);

};
