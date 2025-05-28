#pragma once

#include "rule.hpp"
#include "itscex.hpp"

namespace Preprocess {

    RulePtr preprocessRule(const RulePtr &rule);

    RulePtr chain(const std::vector<RulePtr> &);

}
