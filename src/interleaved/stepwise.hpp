#pragma once
#include "itssafetycex.hpp"
#include "itsmodel.hpp"
#include "smt.hpp"

class StepwiseAnalysis {

public:

    virtual ~StepwiseAnalysis();

    virtual void init() = 0;
    virtual std::optional<SmtResult> do_step() = 0;
    virtual ITSModel get_model() = 0;
    virtual ITSSafetyCex get_cex() = 0;

    SmtResult analyze();

};
