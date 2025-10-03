#pragma once

#include "theory.hpp"
#include "renaming.hpp"
#include "dependencygraph.hpp"

class SafetyProblem {

    BoolExprSet transitions;
    VarSet pre_variables;
    VarSet post_variables;
    Renaming m_pre_to_post;
    Bools::Expr initial_states {bot()};
    Bools::Expr error_states {bot()};
    DependencyGraph<Bools::Expr> graph;

public:

    SafetyProblem();

    const BoolExprSet &trans() const;
    void replace_transition(const Bools::Expr &old_trans, const Bools::Expr &new_trans);
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    const Renaming& pre_to_post() const;
    VarSet vars() const;
    CellSet cells() const;
    Bools::Expr init() const;
    Bools::Expr err() const;
    void add_transition(const Bools::Expr& e);
    void add_edge(const Bools::Expr& from, const Bools::Expr& to);
    void mark_initial_transition(const Bools::Expr& t);
    void mark_sink_transition(const Bools::Expr& t);
    const DependencyGraph<Bools::Expr> &get_dg() const;
    void set_init(const Bools::Expr& e);
    void set_err(const Bools::Expr& e);
    void add_pre_var(const Var &x);
    void add_post_var(const Var &x);

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
