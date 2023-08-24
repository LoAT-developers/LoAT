#pragma once

#include "proof.hpp"
#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    NotSat, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed, Success, Nonterminating
};

std::ostream& operator<<(std::ostream &s, const Status x);

struct Accel {
    Rule rule;
    Proof proof;
    BoolExpr covered;

};

struct Nonterm {
    BoolExpr certificate {BExpression::False};
    Proof proof;
};

struct Result {
    Status status;
    std::optional<Accel> accel;
    std::optional<Nonterm> nonterm;
    unsigned prefix = 0;
    unsigned period = 1;

};

}
