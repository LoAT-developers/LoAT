#pragma once

#include "theory.hpp"
#include "variablemanager.hpp"
#include "proof.hpp"

class Qelim {

public:

    struct Result {
        BExpr<IntTheory> qf;
        Proof proof;
        bool exact;
        Result(const BExpr<IntTheory> &qf, const Proof &proof, bool exact): qf(qf), proof(proof), exact(exact) {}
    };

    virtual option<Result> qe(const QuantifiedFormula<IntTheory> &qf) = 0;

    static std::unique_ptr<Qelim> solver(VarMan& varMan);

};
