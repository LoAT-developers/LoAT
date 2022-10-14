#include "accelerationfactory.hpp"
#include "accelerationviacalculus.hpp"
#include "accelerationviaqe.hpp"

std::unique_ptr<AccelerationTechnique<IntTheory>> AccelerationFactory::get(const LinearRule &rule, option<Recurrence::Result> closed, ITSProblem &its) {
    if (closed && rule.getGuard()->isPoly() && closed->update.isPoly()) {
        return std::unique_ptr<AccelerationTechnique<IntTheory>>(new AccelerationViaQE(rule, *closed, its));
    } else {
        return std::unique_ptr<AccelerationTechnique<IntTheory>>(new AccelerationViaCalculus(rule, closed, its));
    }
}
