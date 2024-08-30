#pragma once

#include "rule.hpp"

namespace Preprocess {

    std::optional<Rule> preprocessRule(const Rule &rule);

    Rule chain(const std::vector<Rule> &);

}
