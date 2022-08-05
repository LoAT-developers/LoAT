#ifndef ACCELERATION_PROBLEM
#define ACCELERATION_PROBLEM

#include "../../its/types.hpp"
#include "../../its/rule.hpp"
#include "../../util/option.hpp"
#include "../../its/itsproblem.hpp"
#include "../../util/proof.hpp"
#include "../../smt/smt.hpp"

class AccelerationProblem {

private:

    option<Subs> closed;
    Expr iteratedCost;
    Var n;
    LinearRule rule;
    unsigned int validityBound;
    ITSProblem &its;

    AccelerationProblem(
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

    static option<AccelerationProblem> init(const LinearRule &r, ITSProblem &its);
    static AccelerationProblem initForRecurrentSet(const LinearRule &r, ITSProblem &its);
    std::vector<Result> computeRes();
    Expr getAcceleratedCost() const;
    option<Subs> getClosedForm() const;
    Var getIterationCounter() const;
    unsigned int getValidityBound() const;

};

#endif
