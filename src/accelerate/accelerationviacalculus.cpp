#include "accelerationviacalculus.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

AccelerationViaCalculus::AccelerationViaCalculus(
        const LinearRule &rule,
        const option<Recurrence::Result> closed,
        ITSProblem &its,
        const Approx approx): AccelerationTechnique(rule, closed, its, approx) {}


AccelerationViaCalculus::AcceleratorPair AccelerationViaCalculus::computeRes() {
    return AccelerationProblem::init(rule, closed, its, approx).computeRes();
}
