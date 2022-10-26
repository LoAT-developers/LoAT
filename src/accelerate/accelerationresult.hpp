#pragma once

#include "proof.hpp"
#include "rule.hpp"

struct AccelerationResult {
    option<Rule> rule;
    option<Rule> nontermRule;
    unsigned period = 1;
    bool strengthened = false;
    Proof proof;
    Proof nontermProof;
    option<NumVar> n;

    bool successful() const;
    bool inexact() const;
    std::vector<Rule> rules() const;

};
