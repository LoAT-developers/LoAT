#pragma once

#include "chcproblem.hpp"
#include "chccex.hpp"
#include "chcmodel.hpp"

class Reverse {

    CHCPtr orig;
    std::unordered_map<ClausePtr, ClausePtr> rev_map;

public:
    explicit Reverse(CHCPtr );

    CHCPtr reverse();
    CHCCex transform_cex(const CHCCex&);
    static CHCModel transform_model(const CHCModel&) ;

};
