#pragma once

#include "transition.hpp"
#include "theory.hpp"

class SafetyProblem {

    Transition transitions;
    linked_hash_map<Var, Var> variables;
    BoolExpr initial_states;
    BoolExpr error_states;

public:

    const Transition &trans() const;
    const linked_hash_map<Var, Var> &vars() const;
    VarSet pre_vars() const;
    VarSet post_vars() const;
    BoolExpr init() const;
    BoolExpr err() const;

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
