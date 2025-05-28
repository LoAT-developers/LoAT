#pragma once

#include "subs.hpp"
#include "theory.hpp"
#include "model.hpp"

#include <vector>

namespace Preprocess {

    Bools::Expr preprocessFormula(Bools::Expr, const std::function<bool(const Var &)> &allow = theory::isTempVar);

    Bools::Expr simplifyAnd(const Bools::Expr e);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);
}
