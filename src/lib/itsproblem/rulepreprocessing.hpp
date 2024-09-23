#pragma once

#include "rule.hpp"

namespace Preprocess {

    std::optional<RulePtr> preprocessRule(const RulePtr &rule);

    RulePtr chain(const std::vector<RulePtr> &);

}
