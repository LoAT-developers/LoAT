#pragma once

#include "rule.hpp"

namespace Chaining {

    std::pair<Rule, Subs> chain(const Rule &fst, const Rule &snd);

}
