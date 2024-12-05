#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "config.hpp"

namespace mbp {

    Bools::Expr int_mbp(const Bools::Expr &trans, const Model &model, const Config::TRPConfig::MbpKind mode, const std::function<bool(const Var&)> &eliminate = theory::isTempVar);
    Bools::Expr int_qe(const Bools::Expr &trans, const std::function<bool(const Var&)> &eliminate = theory::isTempVar);
}
