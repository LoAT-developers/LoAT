#ifndef ACCELERATION_VIA_QE
#define ACCELERATION_VIA_QE

#include "types.hpp"
#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "smt.hpp"
#include "accelerationtechnique.hpp"
#include "recurrence.hpp"

class AccelerationViaQE: public AccelerationTechnique {

public:

    AccelerationViaQE(
            const LinearRule &rule,
            const Recurrence::Result closed,
            ITSProblem &its);

    std::vector<Accelerator> computeRes() override;

};

#endif
