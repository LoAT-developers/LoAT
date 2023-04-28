#include "accelerationfactory.hpp"
#include "accelerationproblem.hpp"

using AT = std::unique_ptr<AccelerationTechnique<IntTheory, BoolTheory>>;

AT AccelerationFactory::get(
        const Rule &rule,
        std::optional<Recurrence::Result> closed,
        const Subs &sample_point,
        const AccelConfig &config) {
//    if (closed && rule.getGuard()->isPoly() && closed->update.isPoly()) {
//        return AT(new AccelerationViaQE(rule, *closed, its));
//    } else {
        return AT(new AccelerationProblem(rule, closed, sample_point, config));
//    }
}
