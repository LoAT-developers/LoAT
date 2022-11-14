#pragma once

#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "accelerationtechnique.hpp"
#include "approx.hpp"

class AccelerationViaCalculus: public AccelerationTechnique<IntTheory, BoolTheory> {

public:

    AccelerationViaCalculus(
            const LinearRule &rule,
            const option<Recurrence::Result> closed,
            ITSProblem &its,
            const Approx approx);

    AcceleratorPair computeRes() override;

};
