#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace mbp {
    Bools::Expr int_mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate, const bool upper = false);
}