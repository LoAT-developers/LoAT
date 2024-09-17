#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "itsmodel.hpp"

class ITSToSafety {

private:

    const ITSProblem &its;

public:

    ITSToSafety(const ITSProblem &its);

    ITSModel transform_model(const Bools::Expr&) const;

    SafetyProblem transform();

};
