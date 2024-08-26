#pragma once

#include "rule.hpp"
#include "accelerationresult.hpp"
#include "accelconfig.hpp"
#include "recurrence.hpp"
#include "accelerationproblem.hpp"

class LoopAcceleration {
public:

    static acceleration::Result accelerate(const Rule &rule, const Subs &sample_point, const AccelConfig &config);

    static acceleration::Result accelerate(const Rule &rule, const AccelConfig &config);

    static std::pair<Rule, unsigned> chain(const Rule &rule);

private:

    LoopAcceleration(const Rule &rule, const std::optional<Subs> &sample_point, const AccelConfig &config);

    void chain();
    void removeTrivialUpdates();
    void run();
    void store_nonterm(const AccelerationProblem::Accelerator &accel);
    void try_nonterm();
    void compute_closed_form();
    void accelerate();
    void prepend_prefix();

    Rule rule;
    const std::optional<Subs> sample_point;
    const AccelConfig config;
    acceleration::Result res {};
    std::optional<Recurrence::Result> rec {};

};
