#pragma once

#include "theory.hpp"
#include "itsproblem.hpp"

class ITSModel {

    friend std::ostream& operator<<(std::ostream &s, const ITSModel &);

    linked_hash_map<LocationIdx, Bools::Expr> invariants;

public:

    Bools::Expr get_invariant(const LocationIdx) const;

    void  set_invariant(const LocationIdx loc, const Bools::Expr inv);

};
