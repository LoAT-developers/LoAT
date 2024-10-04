#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace mbp {
    Bools::Expr int_mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate = theory::isTempVar, const bool upper = false);
    Bools::Expr int_qe(const Bools::Expr &trans, const std::function<bool(const Var&)> &eliminate = theory::isTempVar);
}
