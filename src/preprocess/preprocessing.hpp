#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "chcproblem.hpp"
#include "smt.hpp"

namespace Preprocess {

std::optional<SmtResult> preprocess(ITSProblem &its);

}
