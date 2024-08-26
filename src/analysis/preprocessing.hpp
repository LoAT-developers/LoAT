#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "chcproblem.hpp"

namespace Preprocess {

bool preprocess(ITSProblem &its);

bool preprocess(SafetyProblem &);

bool chainLinearPaths(CHCProblem &chcs);

}
