#pragma once

#include "subs.hpp"
#include "theory.hpp"
#include "model.hpp"

#include <vector>

class FormulaPreprocessor {

private:

    Bools::Expr e {top()};
    std::function<bool(const Var &)> allow;

    bool propagateEquivalences();
    bool propagateEqualities();

public:

    FormulaPreprocessor(const std::function<bool(const Var &)> &allow);

    Bools::Expr run(const Bools::Expr);

};

namespace Preprocess {

    Bools::Expr simplifyAnd(const Bools::Expr e);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);
}
