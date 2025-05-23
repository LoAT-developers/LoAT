#pragma once

#include "stepwise.hpp"
#include "renamingcentral.hpp"
#include "safetyproblem.hpp"
#include "itsproblem.hpp"
#include "itstosafetyproblem.hpp"

class IMC: public StepwiseAnalysis {

private:

    unsigned lookahead {0};
    ITSToSafety its2safety;
    SafetyProblem t;
    RenamingCentral renaming_central;
    Bools::Expr step {top()};

public:

    IMC(const ITSPtr);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};