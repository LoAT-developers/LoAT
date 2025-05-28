#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace mbp {
    Bools::Expr real_mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate);
}