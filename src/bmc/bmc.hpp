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

    unsigned bound;
    std::optional<ITSToSafety> to_safety;
    SafetyProblem sp;
    Bools::Expr init;
    Bools::Expr err;
    Bools::Expr step;
    Bools::Expr abstraction;
    SmtPtr solver;
    SmtPtr kind;
    SmtPtr bkind;
    VarSet vars;
    Renaming pre_to_post {};
    unsigned depth {0};
    std::vector<Renaming> renamings;
    bool do_kind;
    Winner winner {Winner::BMC};

    Renaming get_renaming(unsigned);
    void initialize();

public:
    explicit BMC(const ITSPtr& its, bool do_kind = true, unsigned bound = 0);
    explicit BMC(const SafetyProblem&, bool do_kind = true, unsigned bound = 0);
    SmtResult analyze();
    ITSModel get_model() const;
    ITSSafetyCex get_cex() const;

};
