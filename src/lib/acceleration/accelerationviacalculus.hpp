#pragma once

#include <optional>

#include "rule.hpp"
#include "variablemanager.hpp"
#include "accelerationtechnique.hpp"
#include "accelconfig.hpp"

class AccelerationViaCalculus: public AccelerationTechnique<IntTheory, BoolTheory> {

public:

    AccelerationViaCalculus(
            const Rule &rule,
            const std::optional<Recurrence::Result> closed,
            VarMan &its,
            const AccelConfig &config);

    AcceleratorPair computeRes() override;

};
