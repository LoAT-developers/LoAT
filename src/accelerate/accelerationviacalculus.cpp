#include "accelerationviacalculus.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

AccelerationViaCalculus::AccelerationViaCalculus(
        const LinearRule &rule,
        const option<Recurrence::Result> closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}


std::vector<AccelerationTechnique<IntTheory>::Accelerator> AccelerationViaCalculus::computeRes() {
    return AccelerationProblem::init(rule, closed, its).computeRes();
}
