#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "chcproblem.hpp"
#include "smt.hpp"
#include "chain.hpp"

namespace Preprocess {

struct Result {
    bool success = false;
    SmtResult status = SmtResult::Unknown;
    std::shared_ptr<ReversiblePreprocessing> reverse;
};

Result preprocess(ITSProblem &its);

}
