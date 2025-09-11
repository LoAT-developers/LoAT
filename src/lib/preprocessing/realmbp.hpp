#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace mbp {
    Bools::Expr real_mbp(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Var&)> &eliminate);
    Bools::Expr real_qe(const Bools::Expr &t, const std::function<bool(const Var &)> &eliminate);
}
