#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "smtfactory.hpp"
#include "itsmodel.hpp"

class BMC {

private:

    ITSProblem &its;
    SmtPtr solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    bool approx {false};
    VarSet vars;
    std::unordered_map<Var, Var> post_vars {};
    unsigned depth {0};
    std::vector<Renaming> renamings;

    Bools::Expr encode_transition(const TransIdx idx);

public:

    explicit BMC(ITSProblem &its);
    SmtResult analyze();
    ITSModel get_model() const;

};
