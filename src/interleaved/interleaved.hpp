#pragma once

#include "itsproblem.hpp"
#include "stepwise.hpp"

class Interleaved {

StepwiseAnalysis &f;
StepwiseAnalysis &b;
StepwiseAnalysis *active;
StepwiseAnalysis *passive;

public:

    Interleaved(StepwiseAnalysis &f, StepwiseAnalysis &b);

    SmtResult analyze();

    ITSModel get_model();

    ITSSafetyCex get_cex();

    bool is_forward() const;

};
