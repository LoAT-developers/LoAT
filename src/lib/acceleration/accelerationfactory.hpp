#pragma once

#include "accelerationtechnique.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

#include <optional>

namespace AccelerationFactory {

std::unique_ptr<AccelerationTechnique<IntTheory, BoolTheory>> get(
        const Rule &rule,
        std::optional<Recurrence::Result> closed,
        VarMan &its,
        const AccelConfig &config);

}
