#pragma once

#include "exprmap.hpp"
#include "theory.hpp"

class Valuation: public ExprMap<Arith::Var, Arith::Const, Bools::Var, Bools::Const, ArrayReadPtr<Arith>, Arith::Const> {

public:

    LitSet lits() const;
    Valuation composeBackwards(const Renaming&) const;

};
