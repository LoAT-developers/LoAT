#ifndef QELIM_HPP
#define QELIM_HPP

#include "boolexpr.hpp"
#include "variablemanager.hpp"
#include "exceptions.hpp"
#include "proof.hpp"

class Qelim {

public:

    struct Result {
        BoolExpr qf;
        Proof proof;
        bool exact;
        Result(const BoolExpr &qf, const Proof &proof, bool exact): qf(qf), proof(proof), exact(exact) {}
    };

    virtual option<Result> qe(const QuantifiedFormula &qf) = 0;

    static std::unique_ptr<Qelim> solver(VarMan& varMan);

};

#endif

