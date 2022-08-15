#ifndef ACCELERATION_RESULT_HPP
#define ACCELERATION_RESULT_HPP

#include "status.hpp"
#include "proof.hpp"
#include "rule.hpp"

struct AccelerationResult {
    std::vector<Rule> rules;
    Status status;
    Proof proof;
};

#endif // ACCELERATION_RESULT_HPP
