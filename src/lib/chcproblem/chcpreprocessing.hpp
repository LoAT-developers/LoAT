#pragma once

#include "chcproblem.hpp"

namespace Preprocess {

    std::optional<Clause> preprocess(const Clause &rule);

    Clause chain(const Clause &fst, const Clause &snd);

}
