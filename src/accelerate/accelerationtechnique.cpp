#include "accelerationtechnique.hpp"

AccelerationTechnique::Accelerator::Accelerator(const BoolExpr &formula, const Proof &proof, bool exact, bool witnessesNonterm):
        formula(formula),
        proof(proof),
        exact(exact),
        witnessesNonterm(witnessesNonterm) {}

AccelerationTechnique::AccelerationTechnique(const LinearRule &rule, const option<Recurrence::Result<NondetUpdate>> closed, ITSProblem &its):
        rule(rule),
        closed(closed),
        its(its) {}
