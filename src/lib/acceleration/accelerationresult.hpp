#pragma once

#include "proof.hpp"
#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    Unsat, Nondet, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed
};

std::ostream& operator<<(std::ostream &s, const Status x);

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
    unsigned prefix = 0;
    unsigned period = 1;
    std::optional<NumVar> n;

};

}
