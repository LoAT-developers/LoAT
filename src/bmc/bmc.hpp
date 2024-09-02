#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "smtfactory.hpp"

class BMC {

private:

    explicit BMC(ITSProblem &its);

    void analyze();

    ITSProblem &its;
    SmtPtr solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    bool approx {false};
    VarSet vars {};
    std::unordered_map<Var, Var> post_vars {};
    unsigned depth {0};

    Bools::Expr encode_transition(const TransIdx idx);
    void unsat();
    void sat();

public:

    static void analyze(ITSProblem &its);

};
