#pragma once

#include "rule.hpp"

#include <optional>

namespace acceleration {

enum Status {
    NotSat, PseudoLoop, Disjunctive, AccelerationFailed, ClosedFormFailed, Success, Nonterminating, Nonlinear
};

std::ostream& operator<<(std::ostream &s, Status x);

struct Accel {
    RulePtr rule;
    Bools::Expr covered {bot()};

    explicit Accel(const RulePtr& rule): rule(rule) {}

};

struct Result {
    Status status {};
    std::optional<Accel> accel {};
    Bools::Expr nonterm {bot()};
    unsigned prefix {0};
    unsigned period {1};

};

}
