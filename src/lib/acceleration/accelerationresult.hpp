#pragma once

#include "proof.hpp"
#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    Unsat, Nondet, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed
};

struct Result {
    std::optional<Status> status;
    std::optional<Rule> rule;
    BoolExpr nontermCertificate {BExpression::False};
    unsigned period = 1;
    bool strengthened = false;
    Proof accelerationProof;
    Proof nontermProof;
    std::optional<NumVar> n;

    bool successful() const;
    bool inexact() const;

};

}
