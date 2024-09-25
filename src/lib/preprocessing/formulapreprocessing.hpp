#pragma once

#include "subs.hpp"
#include "theory.hpp"
#include "model.hpp"

#include <vector>

class FormulaPreprocessor {

private:

    Bools::Expr e {top()};
    std::function<bool(const Var &)> allow;
    Subs equiv;

    bool propagateEquivalences();
    bool propagateEqualities();

public:

    FormulaPreprocessor(const std::function<bool(const Var &)> &allow);

    Bools::Expr run(const Bools::Expr);

    Model transform_model(const Model &) const;
    static Model transform_model(const Model&, const Subs&);

};

namespace Preprocess {

    Bools::Expr simplifyAnd(const Bools::Expr e);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);
}
