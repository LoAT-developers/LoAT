#pragma once

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "approx.hpp"

template <ITheory... Th>
class AccelerationTechnique {

public:

    struct Accelerator {
        BExpr<Th...> formula;
        Proof proof;
        bool exact;

        Accelerator(const BExpr<Th...> &formula, const Proof &proof, bool exact):
            formula(formula),
            proof(proof),
            exact(exact) {}

    };

    struct AcceleratorPair {
        option<Accelerator> term;
        option<Accelerator> nonterm;
    };

    option<Recurrence::Result> getClosed() const;

protected:

    LinearRule rule;
    const option<Recurrence::Result> closed;
    ITSProblem &its;
    const Approx approx;

    AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result> closed, ITSProblem &its, const Approx approx):
        rule(rule),
        closed(closed),
        its(its),
        approx(approx){}

public:

    virtual AcceleratorPair computeRes() = 0;

};
