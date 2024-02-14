#pragma once

#include "transition.hpp"
#include "theory.hpp"

class SafetyProblem {

    linked_hash_set<Transition> transitions;
    std::shared_ptr<const linked_hash_map<Var, Var>> variables;
    VarSet pre_variables;
    VarSet post_variables;
    BoolExpr initial_states;
    BoolExpr error_states;

public:

    const linked_hash_set<Transition> &trans() const;
    std::shared_ptr<const linked_hash_map<Var, Var>> vars() const;
    void replace_transition(const Transition &old_trans, const Transition &new_trans);
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    BoolExpr init() const;
    BoolExpr err() const;

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
