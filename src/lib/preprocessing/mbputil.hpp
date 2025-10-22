#pragma once

#include "model.hpp"

namespace mbp {

std::optional<Arith::Expr> closest_lower_bound(const linked_hash_set<Bound> &bounds, const ModelPtr& model, const ArithVarPtr &x);

Bools::Expr bool_mbp(const Bools::Expr &t, const ModelPtr& model, const Bools::Var& x);

Bools::Expr bool_qe(const Bools::Expr &t, const Bools::Var& x);

}
