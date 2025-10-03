#pragma once

#include <optional>

#include "rule.hpp"
#include "smt.hpp"
#include "recurrence.hpp"
#include "accelconfig.hpp"

class AccelerationProblem {

public:

    enum class PolyAccelMode {
        None, LowDegree, Full
    };

    static PolyAccelMode polyaccel;

    struct Accelerator {
        std::vector<Bools::Expr> formula{};
        std::vector<Bools::Expr> covered{};
        bool nonterm {true};
    };

private:

    const std::optional<Recurrence::Result> closed;
    Subs update;
    Bools::Expr guard;
    const AccelConfig config;
    LitSet todo {};
    Accelerator res {};
    const std::optional<Subs> &samplePoint;
    SmtPtr solver {};

    bool trivial(const Lit &lit);
    bool unchanged(const Lit &lit);
    bool polynomial(const Lit &lit);
    bool monotonicity(const Lit &lit);
    bool recurrence(const Lit &lit);
    bool eventualWeakDecrease(const Lit &lit);
    bool eventualIncrease(const Lit &lit, bool strict);
    bool fixpoint(const Lit &lit);

public:

    AccelerationProblem(
            const RulePtr& rule,
            const std::optional<Recurrence::Result> &closed,
            const std::optional<Subs> &samplePoint,
            const AccelConfig &config);

    std::optional<Accelerator> computeRes();

};
