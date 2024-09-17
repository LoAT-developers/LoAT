#pragma once

#include "chcmodel.hpp"
#include "chcproblem.hpp"
#include "itsmodel.hpp"
#include "itsproblem.hpp"

class CHCToITS {

private:

    CHCProblem chcs;
    ITSPtr its {std::make_shared<ITSProblem>()};
    std::vector<Arith::Var> vars;
    std::vector<Bools::Var> bvars;

public:
    CHCToITS(const CHCProblem &chcs);

    CHCModel transform_model(const ITSModel &) const;

    ITSPtr transform();
};
