#ifndef ACCELERATION_VIA_QE
#define ACCELERATION_VIA_QE

#include "types.hpp"
#include "rule.hpp"
#include "option.hpp"
#include "itsproblem.hpp"
#include "proof.hpp"
#include "smt.hpp"

class AccelerationViaQE {

private:

    option<Subs> closed;
    Expr iteratedCost;
    Var n;
    LinearRule rule;
    unsigned int validityBound;
    ITSProblem &its;

    AccelerationViaQE(
            const LinearRule &rule,
            option<const Subs&> closed,
            const Expr &iteratedCost,
            const Var &n,
            const unsigned int validityBound,
            ITSProblem &its);

public:

    struct Result {
        BoolExpr newGuard;
        Proof proof;
        bool exact;
        bool witnessesNonterm;

        Result(const BoolExpr &newGuard, const Proof &proof, bool exact, bool witnessesNonterm): newGuard(newGuard), proof(proof), exact(exact), witnessesNonterm(witnessesNonterm) {}

    };

    static option<AccelerationViaQE> init(const LinearRule &r, ITSProblem &its);
    static AccelerationViaQE initForRecurrentSet(const LinearRule &r, ITSProblem &its);
    std::vector<Result> computeRes();
    Expr getAcceleratedCost() const;
    option<Subs> getClosedForm() const;
    Var getIterationCounter() const;
    unsigned int getValidityBound() const;

};

#endif
