#pragma once

#include "theory.hpp"

class SafetyProblem {

    linked_hash_set<Bools::Expr> transitions;
    VarSet pre_variables;
    VarSet post_variables;
    Bools::Expr initial_states {bot()};
    Bools::Expr error_states {bot()};

public:

    SafetyProblem();

    const linked_hash_set<Bools::Expr> &trans() const;
    void replace_transition(const Bools::Expr &old_trans, const Bools::Expr &new_trans);
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    VarSet vars() const;
    Bools::Expr init() const;
    Bools::Expr err() const;
    void add_transition(const Bools::Expr e);
    void set_init(const Bools::Expr e);
    void set_err(const Bools::Expr e);
    void add_pre_var(const Var &x);
    void add_post_var(const Var &x);
    SafetyProblem reverse() const;

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
