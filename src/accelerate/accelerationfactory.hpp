#pragma once

#include "accelerationtechnique.hpp"
#include "recurrence.hpp"

namespace AccelerationFactory {

std::unique_ptr<AccelerationTechnique<IntTheory, BoolTheory>> get(const LinearRule &rule, option<Recurrence::Result> closed, ITSProblem &its);

}
