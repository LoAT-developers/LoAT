#pragma once

#include "rule.hpp"
#include "transition.hpp"

namespace Chaining {

    std::pair<Rule, Subs> chain(const Rule &fst, const Rule &snd);
    std::tuple<Transition, Subs, Subs> chain(const Transition &fst, const Transition &snd);

}
