#pragma once

#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "accelerationtechnique.hpp"
#include "accelconfig.hpp"

class AccelerationViaCalculus: public AccelerationTechnique<IntTheory, BoolTheory> {

public:

    AccelerationViaCalculus(
            const LinearRule &rule,
            const option<Recurrence::Result> closed,
            ITSProblem &its,
            const AccelConfig &config);

    AcceleratorPair computeRes() override;

};
