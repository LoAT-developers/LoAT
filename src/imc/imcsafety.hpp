#pragma once

#include "renamingcentral.hpp"
#include "safetyproblem.hpp"
#include "smt.hpp"
#include "opensmt.hpp"

class IMCSafety {

private:

    unsigned lookahead {0};
    SafetyProblem t;
    RenamingCentral renaming_central;
    Bools::Expr step {top()};
    Bools::Expr itp {bot()};
    Model model;
    OpenSmt solver {true};

public:

    IMCSafety(const SafetyProblem&);
    std::optional<SmtResult> do_step();
    SmtResult analyze();
    Bools::Expr get_itp() const;
    Model get_model();

};