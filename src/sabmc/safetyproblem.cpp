#include "safetyproblem.hpp"

const linked_hash_set<Transition>& SafetyProblem::trans() const {
    return transitions;
}

std::shared_ptr<const linked_hash_map<Var, Var>> SafetyProblem::vars() const {
    return variables;
}

const VarSet& SafetyProblem::pre_vars() const {
    return pre_variables;
}

const VarSet& SafetyProblem::post_vars() const {
    return post_variables;
}

BoolExpr SafetyProblem::init() const {
    return initial_states;
}

BoolExpr SafetyProblem::err() const {
    return error_states;
}

void SafetyProblem::replace_transition(const Transition &old_trans, const Transition &new_trans) {
    transitions.erase(old_trans);
    transitions.insert(new_trans);
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
