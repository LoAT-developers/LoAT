#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "conjunction.hpp"

namespace qe {
    Conjunction real_qe(const Conjunction &trans, const Model &, const std::function<bool(const Var&)> &eliminate);
}