#pragma once

#include <optional>

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"
#include "variablemanager.hpp"
#include "rule.hpp"

template <ITheory... Th>
class AccelerationTechnique {

public:

    struct Accelerator {
        BExpr<Th...> formula;
        Proof proof;
        BExpr<Th...> covered;

        Accelerator(const BExpr<Th...> &formula, const Proof &proof, BExpr<Th...> covered):
            formula(formula),
            proof(proof),
            covered(covered) {}

    };

    struct AcceleratorPair {
        std::optional<Accelerator> term;
        std::optional<Accelerator> nonterm;
    };

    std::optional<Recurrence::Result> getClosed() const;

protected:

    const Rule rule;
    const std::optional<Recurrence::Result> closed;
    VarMan &its;
    const AccelConfig config;

    AccelerationTechnique(const Rule &rule, const std::optional<Recurrence::Result> closed, VarMan &its, const AccelConfig &config):
        rule(rule),
        closed(closed),
        its(its),
        config(config){}

public:

    virtual AcceleratorPair computeRes() = 0;

};
