#pragma once

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"

template <ITheory... Th>
class AccelerationTechnique {

public:

    struct Accelerator {
        BExpr<Th...> formula;
        Proof proof;
        bool exact;
        bool witnessesNonterm;

        Accelerator(const BExpr<Th...> &formula, const Proof &proof, bool exact, bool witnessesNonterm):
            formula(formula),
            proof(proof),
            exact(exact),
            witnessesNonterm(witnessesNonterm) {}

    };

    option<Recurrence::Result> getClosed() const;

protected:

    LinearRule rule;
    const option<Recurrence::Result> closed;
    ITSProblem &its;

    AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result> closed, ITSProblem &its):
        rule(rule),
        closed(closed),
        its(its) {}

public:

    virtual std::vector<Accelerator> computeRes() = 0;

};
