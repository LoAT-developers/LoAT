#include "itsmodel.hpp"

Bools::Expr ITSModel::get_invariant(const LocationIdx idx) const {
    return invariants.contains(idx) ? invariants.at(idx) : bot();
}

void ITSModel::set_invariant(const LocationIdx loc, const Bools::Expr inv) {
    invariants.put(loc, inv);
}
