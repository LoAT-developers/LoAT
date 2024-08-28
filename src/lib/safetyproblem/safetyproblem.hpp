#pragma once

#include "theory.hpp"
#include "dependencygraph.hpp"

class SafetyProblem {

    BoolExprSet transitions;
    VarSet pre_variables;
    VarSet post_variables;
    Bools::Expr initial_states {bot()};
    Bools::Expr error_states {bot()};
    DependencyGraph<Bools::Expr> graph;

public:

    SafetyProblem();

    const BoolExprSet &trans() const;
    const VarSet& pre_vars() const;
    const VarSet& post_vars() const;
    VarSet vars() const;
    Bools::Expr init() const;
    Bools::Expr err() const;
    void add_edge(const Bools::Expr, const Bools::Expr);
    BoolExprSet get_successors(const BoolExprSet &nodes) const;
    void add_transition(const Bools::Expr e);
    void set_init(const Bools::Expr e);
    void set_err(const Bools::Expr e);
    void add_pre_var(const Var &x);
    void add_post_var(const Var &x);
    const DependencyGraph<Bools::Expr> &get_dependency_graph() const;

};

std::ostream& operator<<(std::ostream&, const SafetyProblem&);
