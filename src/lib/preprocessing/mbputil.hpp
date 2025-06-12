#pragma once

#include "theory.hpp"
#include "model.hpp"
#include "conjunction.hpp"

namespace mbp {

std::optional<Arith::Expr> closest_lower_bound(const linked_hash_set<Bound> &bounds, const Arith::Model &model, const Arith::Var &x);

void bool_mbp(Conjunction &t, const Bools::Var x);

Bools::Expr bool_qe(const Bools::Expr &t, const Bools::Var x);

}
