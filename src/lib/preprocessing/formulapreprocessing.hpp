#pragma once

#include "theory.hpp"
#include "subs.hpp"

#include <vector>

/**
 * Namespace for several functions operating on guards (list of relational expressions) and related helpers.
 * Note: We never allow != in relations.
 */
namespace Preprocess {

    // Shorthand for lambdas that check if a given symbol is accepted/allowed (depending on the context)
    using SymbolAcceptor = std::function<bool(const Var &)>;

    Bools::Expr simplifyAnd(const Bools::Expr e);

    Bools::Expr preprocessFormula(const Bools::Expr e, const SymbolAcceptor &allow);

    std::tuple<Bools::Expr, Renaming, Renaming> chain(const Bools::Expr &fst, const Bools::Expr &snd);

}
