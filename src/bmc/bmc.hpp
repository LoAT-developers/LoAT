#pragma once

#include <limits>

#include "itsproblem.hpp"
#include "z3.hpp"
#include "smtfactory.hpp"
#include "itsmodel.hpp"
#include "itscex.hpp"
#include "itstosafetyproblem.hpp"

class BMC {

private:

    ITSToSafety to_safety;
    SafetyProblem sp;
    SmtPtr solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    SmtPtr kind {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    SmtPtr bkind {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    bool approx {false};
    VarSet vars;
    Renaming pre_to_post {};
    unsigned depth {0};
    std::vector<Renaming> renamings;

public:

    explicit BMC(ITSPtr its);
    SmtResult analyze();
    ITSModel get_model() const;
    ITSCex get_cex() const;

};
