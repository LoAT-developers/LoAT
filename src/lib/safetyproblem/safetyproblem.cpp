#include "safetyproblem.hpp"
#include "subs.hpp"

SafetyProblem::SafetyProblem() {}

void SafetyProblem::add_pre_var(const Var &x) {
    pre_variables.insert(x);
}

void SafetyProblem::add_post_var(const Var &x) {
    post_variables.insert(x);

}

const linked_hash_set<Bools::Expr>& SafetyProblem::trans() const {
    return transitions;
}

const VarSet& SafetyProblem::pre_vars() const {
    return pre_variables;
}

const VarSet& SafetyProblem::post_vars() const {
    return post_variables;
}

VarSet SafetyProblem::vars() const {
    VarSet res;
    initial_states->collectVars(res);
    for (const auto &t: transitions) {
        t->collectVars(res);
    }
    error_states->collectVars(res);
    return res;
}

Bools::Expr SafetyProblem::init() const {
    return initial_states;
}

Bools::Expr SafetyProblem::err() const {
    return error_states;
}

void SafetyProblem::replace_transition(const Bools::Expr &old_trans, const Bools::Expr &new_trans) {
    transitions.erase(old_trans);
    transitions.insert(new_trans);
}

void SafetyProblem::add_transition(const Bools::Expr e) {
    transitions.insert(e);
}

void SafetyProblem::set_init(const Bools::Expr e) {
    initial_states = e;
}

void SafetyProblem::set_err(const Bools::Expr e) {
    error_states = e;
}

std::ostream& operator<<(std::ostream& s, const SafetyProblem& sp) {
    s << "pre vars: " << sp.pre_vars() << std::endl;
    s << "post vars: " << sp.post_vars() << std::endl;
    s << "initial states: " << sp.init() << std::endl;
    s << "error states: " << sp.err() << std::endl;
    for (const auto &t: sp.trans()) {
        s << t << std::endl;
    }
    return s;
}