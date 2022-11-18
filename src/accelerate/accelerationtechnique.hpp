#pragma once

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

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
    const AccelConfig config;

    AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result> closed, ITSProblem &its, const AccelConfig &config):
        rule(rule),
        closed(closed),
        its(its),
        config(config){}

public:

    virtual AcceleratorPair computeRes() = 0;

};
