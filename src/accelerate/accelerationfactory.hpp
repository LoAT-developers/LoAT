#pragma once

#include "accelerationtechnique.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

namespace AccelerationFactory {

std::unique_ptr<AccelerationTechnique<IntTheory, BoolTheory>> get(
        const LinearRule &rule,
        option<Recurrence::Result> closed,
        ITSProblem &its,
        const AccelConfig &config);

}
