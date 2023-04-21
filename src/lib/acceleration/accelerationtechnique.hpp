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

    const std::optional<Recurrence::Result> closed;
    Subs update;
    BoolExpr guard;
    VarMan &its;
    const AccelConfig config;
    Proof proof;

    AccelerationTechnique(const Rule &rule, const std::optional<Recurrence::Result> closed, VarMan &its, const AccelConfig &config):
        closed(closed),
        update(rule.getUpdate()),
        its(its),
        config(config){
        if (closed && !closed->refinement.empty()) {
            update.get<IntTheory>() = closed->refined_equations;
            auto conjuncts {closed->refinement};
            conjuncts.push_back(rule.getGuard());
            guard = BExpression::buildAnd(conjuncts);
            proof.append("refinement:");
            for (const auto &r: closed->refinement) {
                proof.append(std::stringstream() << r);
            }
            proof.append(std::stringstream() << "refined guard: " << guard);
            proof.append(std::stringstream() << "refined update: " << update);
        } else {
            guard = rule.getGuard();
        }
        guard = guard->toG();
    }

public:

    virtual AcceleratorPair computeRes() = 0;

};
