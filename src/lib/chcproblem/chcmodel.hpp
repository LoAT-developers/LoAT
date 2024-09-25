#pragma once

#include "theory.hpp"
#include "chcproblem.hpp"
#include "sexpresso.hpp"

class CHCModel {

    friend std::ostream& operator<<(std::ostream &s, const CHCModel &m);

    linked_hash_map<LhsPtr, Bools::Expr> interpretations;

public:

    void set_interpretation(const LhsPtr f, const Bools::Expr interp);

    sexpresso::Sexp to_smtlib() const;

};