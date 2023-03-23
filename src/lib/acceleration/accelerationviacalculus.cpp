#include "accelerationviacalculus.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

AccelerationViaCalculus::AccelerationViaCalculus(
        const Rule &rule,
        const std::optional<Recurrence::Result> closed,
        VarMan &its,
        const AccelConfig &config): AccelerationTechnique(rule, closed, its, config) {}


AccelerationViaCalculus::AcceleratorPair AccelerationViaCalculus::computeRes() {
    return AccelerationProblem::init(rule, closed, its, config).computeRes();
}
