#pragma once

#include <optional>

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"
#include "itsproblem.hpp"

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
        std::optional<Accelerator> term;
        std::optional<Accelerator> nonterm;
    };

    std::optional<Recurrence::Result> getClosed() const;

protected:

    Rule rule;
    const std::optional<Recurrence::Result> closed;
    ITSProblem &its;
    const AccelConfig config;

    AccelerationTechnique(const Rule &rule, const std::optional<Recurrence::Result> closed, ITSProblem &its, const AccelConfig &config):
        rule(rule),
        closed(closed),
        its(its),
        config(config){}

public:

    virtual AcceleratorPair computeRes() = 0;

};
