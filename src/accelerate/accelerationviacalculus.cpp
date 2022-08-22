#include "accelerationviacalculus.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

AccelerationViaCalculus::AccelerationViaCalculus(
        const LinearRule &rule,
        const option<Recurrence::Result> closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}


std::vector<AccelerationViaCalculus::Accelerator> AccelerationViaCalculus::computeRes() {
    AccelerationProblem ap(rule.getGuard(), rule.getUpdate(), closed, rule.getCost(), its);
    return ap.computeRes();
}
