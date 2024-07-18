#pragma once

#include "theory.hpp"
#include "model.hpp"

namespace mbp {

std::optional<Arith::Expr> closest_lower_bound(const linked_hash_set<Bound> &bounds, const Arith::Model &model, const Arith::Var &x);

Bools::Expr bool_mbp(const Bools::Expr &t, const Model &model, const Bools::Var x);

bool break_tie(const Arith::Expr fst, const Arith::Expr snd);

}