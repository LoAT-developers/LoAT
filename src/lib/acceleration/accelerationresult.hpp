#pragma once

#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    NotSat, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed, Success, Nonterminating
};

std::ostream& operator<<(std::ostream &s, const Status x);

struct Accel {
    Rule rule;
    Bools::Expr covered {bot()};

    Accel(const Rule &rule): rule(rule) {}

};

struct Result {
    Status status {};
    std::optional<Accel> accel {};
    Bools::Expr nonterm {bot()};
    unsigned prefix {0};
    unsigned period {1};

};

}
