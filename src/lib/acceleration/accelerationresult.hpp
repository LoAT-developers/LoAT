#pragma once

#include "proof.hpp"
#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    Unsat, Nondet, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed
};

struct Accel {
    BoolExpr covered;
    Rule rule;
    Proof proof;
};

struct Nonterm {
    BoolExpr covered;
    BoolExpr certificate {BExpression::False};
    Proof proof;
};

struct Result {
    std::optional<Status> status;
    std::optional<Accel> accel;
    std::optional<Nonterm> nonterm;
    unsigned period = 1;
    bool strengthened = false;
    std::optional<NumVar> n;

    bool successful() const;
    bool inexact() const;

};

}
