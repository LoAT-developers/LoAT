#ifndef ACCELERATION_RESULT_HPP
#define ACCELERATION_RESULT_HPP

#include "../util/status.hpp"
#include "../util/proof.hpp"
#include "../its/rule.hpp"

namespace Acceleration {

struct Result {
    std::vector<Rule> rules;
    Status status;
    Proof proof;
};

}

#endif // ACCELERATION_RESULT_HPP
