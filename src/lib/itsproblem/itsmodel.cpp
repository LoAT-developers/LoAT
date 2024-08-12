#include "itsmodel.hpp"

Bools::Expr ITSModel::get_invariant(const LocationIdx idx) const {
    return invariants.at(idx);
}

void ITSModel::set_invariant(const LocationIdx loc, const Bools::Expr inv) {
    invariants.emplace(loc, inv);
}