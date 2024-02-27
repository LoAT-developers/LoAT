#pragma once

#include "transition.hpp"
#include "theories.hpp"
#include "itsproblem.hpp"

class SafetyProblem {

    linked_hash_set<Transition> transitions;
    std::shared_ptr<const linked_hash_map<Var, Var>> variables;
    VarSet pre_variables;
    VarSet post_variables;
    BoolExpr initial_states;
    BoolExpr error_states;

public:

    SafetyProblem(const ITSProblem &its);

    const linked_hash_set<Transition> &trans() const;
    std::shared_ptr<const linked_hash_map<Var, Var>> var_map() const;
    void replace_transition(const Transition &old_trans, const Transition &new_trans);
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    VarSet vars() const;
    BoolExpr init() const;
    BoolExpr err() const;
    void set_init(const BoolExpr e);

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
