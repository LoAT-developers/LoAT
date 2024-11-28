#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace qe {
    Bools::Expr real_qe(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate);
}