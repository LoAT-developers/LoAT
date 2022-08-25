#include "accelerationviacalculus.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

AccelerationViaCalculus::AccelerationViaCalculus(
        const LinearRule &rule,
        const option<Recurrence::Result<NondetUpdate>> closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}


std::vector<AccelerationTechnique::Accelerator> AccelerationViaCalculus::computeRes() {
    AccelerationProblem ap = AccelerationProblem::init(rule, closed.flat_map(Recurrence::toDeterministic), its);
    return ap.computeRes();
}
