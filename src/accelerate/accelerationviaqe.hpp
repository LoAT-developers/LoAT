#pragma once

#include "rule.hpp"
#include "itsproblem.hpp"
#include "accelerationtechnique.hpp"
#include "recurrence.hpp"

class AccelerationViaQE: public AccelerationTechnique<IntTheory> {

public:

    AccelerationViaQE(
            const LinearRule &rule,
            const Recurrence::Result closed,
            ITSProblem &its);

    std::vector<Accelerator> computeRes() override;

};
