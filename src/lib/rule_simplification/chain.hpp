#pragma once

#include "rule.hpp"

namespace Chaining {

    std::pair<Rule, Subs> chain(const Rule &fst, const Rule &snd);
    std::tuple<Bools::Expr, Subs, Subs> chain(const Bools::Expr &fst, const Bools::Expr &snd);

}
