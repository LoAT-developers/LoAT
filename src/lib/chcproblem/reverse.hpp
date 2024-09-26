#pragma once

#include "chcproblem.hpp"
#include "chccex.hpp"
#include "chcmodel.hpp"

class Reverse {

private:

    CHCPtr orig;
    std::unordered_map<ClausePtr, ClausePtr> rev_map;

public:

    Reverse(const CHCPtr);

    CHCPtr reverse();
    CHCCex transform_cex(const CHCCex&) const;
    CHCModel transform_model(const CHCModel&) const;

};
