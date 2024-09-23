#pragma once

#include "itsproblem.hpp"
#include "safetyproblem.hpp"
#include "itsmodel.hpp"

class ITSToSafety {

private:

    const ITSPtr its;

public:

    ITSToSafety(const ITSPtr its);

    ITSModel transform_model(const Bools::Expr&) const;

    SafetyProblem transform();

};
