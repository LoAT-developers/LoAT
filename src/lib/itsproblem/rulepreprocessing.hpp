#pragma once

#include "rule.hpp"

namespace Preprocess {

    std::optional<Rule> preprocessRule(const Rule &rule);

    std::pair<Rule, Subs> chain(const Rule &fst, const Rule &snd);

}
