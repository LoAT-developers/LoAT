#pragma once

#include "itsproblem.hpp"
#include "smtfactory.hpp"
#include "itsmodel.hpp"
#include "itssafetycex.hpp"
#include "itstosafetyproblem.hpp"

class BMC {

    enum class Winner {
        BMC, BKIND, KIND
    };

    ITSToSafety to_safety;
    SafetyProblem sp;
    SmtPtr solver {SmtFactory::modelBuildingSolver(QF_LA)};
    SmtPtr kind {SmtFactory::modelBuildingSolver(QF_LA)};
    SmtPtr bkind {SmtFactory::modelBuildingSolver(QF_LA)};
    bool approx {false};
    VarSet vars;
    Renaming pre_to_post {};
    unsigned depth {0};
    std::vector<Renaming> renamings;
    bool do_kind;
    Winner winner {Winner::BMC};

public:
    explicit BMC(const ITSPtr& its, bool do_kind = true);
    SmtResult analyze();
    ITSModel get_model() const;
    ITSSafetyCex get_cex() const;

};
