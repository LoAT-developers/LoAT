#pragma once

#include "theory.hpp"
#include "itsproblem.hpp"

class SafetyProblem {

    linked_hash_set<Bools::Expr> transitions;
    VarSet pre_variables;
    VarSet post_variables;
    Bools::Expr initial_states {bot()};
    Bools::Expr error_states {bot()};

public:

    SafetyProblem(const ITSProblem &its);

    const linked_hash_set<Bools::Expr> &trans() const;
    void replace_transition(const Bools::Expr &old_trans, const Bools::Expr &new_trans);
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    VarSet vars() const;
    Bools::Expr init() const;
    Bools::Expr err() const;
    void set_init(const Bools::Expr e);

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
