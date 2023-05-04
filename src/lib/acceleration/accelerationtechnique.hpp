#pragma once

#include <optional>

#include "boolexpr.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"
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

    const std::optional<Recurrence::Result> closed;
    Subs update;
    BoolExpr guard;
    const AccelConfig config;
    Proof proof;

    AccelerationTechnique(const Rule &rule, const std::optional<Recurrence::Result> closed, const AccelConfig &config):
        closed(closed),
        update(rule.getUpdate()),
        guard(rule.getGuard()->toG()),
        config(config) {
        if (closed) {
            update.get<IntTheory>() = closed->refined_equations;
            proof.append(std::stringstream() << "refined update: " << update);
        }
    }

public:

    virtual AcceleratorPair computeRes() = 0;

};
