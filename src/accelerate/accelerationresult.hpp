#pragma once

#include "itsproof.hpp"
#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    Unsat, Nondet, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed
};

struct Result {
    std::optional<Status> status;
    std::optional<Rule> rule;
    std::optional<Rule> nontermRule;
    unsigned period = 1;
    bool strengthened = false;
    ITSProof preprocessingProof;
    ITSProof accelerationProof;
    ITSProof nontermProof;
    std::optional<NumVar> n;

    bool successful() const;
    bool inexact() const;
    std::vector<Rule> rules() const;

};

}
