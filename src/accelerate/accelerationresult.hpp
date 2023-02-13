#pragma once

#include "proof.hpp"
#include "rule.hpp"

namespace acceleration {

enum Status {
    Unsat, Nondet, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed
};

struct Result {
    option<Status> status;
    option<Rule> rule;
    option<Rule> nontermRule;
    unsigned period = 1;
    bool strengthened = false;
    Proof preprocessingProof;
    Proof accelerationProof;
    Proof nontermProof;
    option<NumVar> n;

    bool successful() const;
    bool inexact() const;
    std::vector<Rule> rules() const;

};

}
