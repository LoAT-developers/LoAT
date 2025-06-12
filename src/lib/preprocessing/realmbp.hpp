#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "conjunction.hpp"

namespace mbp {
    Conjunction real_mbp(const Conjunction &trans, const Model &model, const std::function<bool(const Var&)> &eliminate);
}