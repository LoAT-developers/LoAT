#pragma once

#include "types.hpp"
#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"

class AccelerationViaCalculus: public AccelerationTechnique {

public:

    AccelerationViaCalculus(
            const LinearRule &rule,
            const option<Recurrence::Result<NondetUpdate>> closed,
            ITSProblem &its);

    std::vector<Accelerator> computeRes() override;

};
