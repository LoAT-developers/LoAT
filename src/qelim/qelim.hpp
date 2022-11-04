#pragma once

#include "proof.hpp"

template <ITheory... Th>
class Qelim {

public:

    struct Result {
        BExpr<Th...> qf;
        Proof proof;
        bool exact;
        Result(const BExpr<Th...> &qf, const Proof &proof, bool exact): qf(qf), proof(proof), exact(exact) {}
    };

    virtual option<Result> qe(const QuantifiedFormula<Th...> &qf) = 0;

};
