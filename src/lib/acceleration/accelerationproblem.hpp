#pragma once

#include <optional>

#include "rule.hpp"
#include "smt.hpp"
#include "theory.hpp"
#include "proof.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

class AccelerationProblem {

public:

    enum class PolyAccelMode {
        None, LowDegree, Full
    };

    static PolyAccelMode polyaccel;

    struct Accelerator {
        std::vector<BoolExpr> formula{};
        Proof proof{};
        std::vector<BoolExpr> covered{};
        bool nonterm {true};
        bool prependFirst {false};
    };

private:

    const std::optional<Recurrence::Result> closed;
    Subs update;
    BoolExpr guard;
    const AccelConfig config;
    LitSet todo {};
    Accelerator res {};
    const std::optional<Subs> &samplePoint;
    std::unique_ptr<Smt<IntTheory, BoolTheory>> solver {};

    bool trivial(const Lit &lit);
    bool unchanged(const Lit &lit);
    bool polynomial(const Lit &lit);
    bool monotonicity(const Lit &lit);
    bool recurrence(const Lit &lit);
    bool eventualWeakDecrease(const Lit &lit);
    bool eventualIncrease(const Lit &lit, const bool strict);
    bool fixpoint(const Lit &lit);

public:

    AccelerationProblem(
            const Rule &rule,
            const std::optional<Recurrence::Result> &closed,
            const std::optional<Subs> &samplePoint,
            const AccelConfig &config);

    std::optional<Accelerator> computeRes();

};
