#pragma once

#include "itsproblem.hpp"

class ITSModel {

    friend std::ostream& operator<<(std::ostream &s, const ITSModel &);

    linked_hash_map<LocationIdx, Bools::Expr> invariants;

public:

    Bools::Expr get_invariant(LocationIdx) const;

    void  set_invariant(LocationIdx loc, const Bools::Expr& inv);

};
