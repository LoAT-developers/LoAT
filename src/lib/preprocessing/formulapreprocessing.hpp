#pragma once

#include "subs.hpp"
#include "theory.hpp"

namespace Preprocess {
    Bools::Expr preprocessFormula(
        Bools::Expr,
        const std::function<bool(const ArithVarPtr&)>& allow = [](const auto& x) {
            return x->isTempVar();
        });

    Bools::Expr simplifyAnd(const Bools::Expr& e);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);
}
