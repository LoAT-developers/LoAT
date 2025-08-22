#pragma once

#include "stepwise.hpp"
#include "imcsafety.hpp"
#include "itsproblem.hpp"
#include "itstosafetyproblem.hpp"

class IMC: public StepwiseAnalysis {

private:

    ITSToSafety its2safety;
    IMCSafety imc;

public:

    IMC(const ITSPtr);
    std::optional<SmtResult> do_step() override;
    ITSModel get_model() override;
    ITSSafetyCex get_cex() override;

};