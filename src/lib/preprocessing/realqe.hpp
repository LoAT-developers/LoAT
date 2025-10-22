#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace qe {
    Bools::Expr real_qe(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Cell&)> &eliminate);
}
