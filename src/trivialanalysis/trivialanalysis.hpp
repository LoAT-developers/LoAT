#pragma once

#include "itsmodel.hpp"
#include "stepwise.hpp"

class TrivialAnalysis: public StepwiseAnalysis {

    const ITSPtr its;
    ITSSafetyCex cex;

public:

    ~TrivialAnalysis() override;

    explicit TrivialAnalysis(const ITSPtr&);

    void init() override;

    ITSModel get_model() override;

    ITSSafetyCex get_cex() override;

    std::optional<SmtResult> do_step() override;
};
