#pragma once

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"

class AccelerationTechnique {

public:

    struct Accelerator {
        BoolExpr formula;
        Proof proof;
        bool exact;
        bool witnessesNonterm;

        Accelerator(const BoolExpr &formula, const Proof &proof, bool exact, bool witnessesNonterm);

    };

    option<Recurrence::Result<NondetUpdate>> getClosed() const;

protected:

    LinearRule rule;
    const option<Recurrence::Result<NondetUpdate>> closed;
    ITSProblem &its;

    AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result<NondetUpdate>> closed, ITSProblem &its);

public:

    virtual std::vector<Accelerator> computeRes() = 0;

};
