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

    option<Recurrence::Result> getClosed() const;

protected:

    LinearRule rule;
    const option<Recurrence::Result> closed;
    ITSProblem &its;

    AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result> closed, ITSProblem &its);

public:

    virtual std::vector<Accelerator> computeRes() = 0;

};
