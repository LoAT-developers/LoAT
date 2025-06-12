#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "config.hpp"
#include "conjunction.hpp"

namespace mbp {

    // compute model based projection as in the [Spacer](https://doi.org/10.48550/arXiv.1405.4028)
    Conjunction int_mbp(const Conjunction &trans, const Model &model, const Config::TRPConfig::MbpKind mode, const std::function<bool(const Var&)> &eliminate = theory::isTempVar);
    Bools::Expr int_qe(const Bools::Expr trans, const std::function<bool(const Var&)> &eliminate = theory::isTempVar);
}
