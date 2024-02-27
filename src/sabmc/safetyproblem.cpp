#include "safetyproblem.hpp"
#include "theories.hpp"

BoolExpr rule_to_formula(const Rule &r, const linked_hash_map<Var, Var> &var_map) {
    std::vector<BoolExpr> conjuncts;
    conjuncts.push_back(r.getGuard());
    for (const auto &[x,y]: var_map) {
        conjuncts.push_back(theories::mkEq(theories::toExpr(y), r.getUpdate().get(x)));
    }
    return bools::mkAnd(conjuncts);
}

SafetyProblem::SafetyProblem(const ITSProblem &its) {
    linked_hash_map<Var, Var> var_map;
    const auto vars {its.getVars()};
    for (const auto &x: vars) {
        if (theories::isProgVar(x)) {
            const auto post {theories::next(x)};
            pre_variables.insert(x);
            post_variables.insert(post);
            var_map.emplace(x, post);
        }
    }
    this->variables = std::make_shared<const linked_hash_map<Var, Var>>(var_map);
    Subs init_map;
    for (const auto &[x,y]: var_map) {
        init_map.put(y, theories::toExpr(x));
        init_map.put(x, theories::toExpr(theories::next(x)));
    }
    std::vector<BoolExpr> init;
    std::vector<BoolExpr> err;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r)) {
            init.emplace_back(rule_to_formula(r, var_map)->subs(init_map));
        } else if (its.isSinkTransition(&r)) {
            err.emplace_back(r.getGuard());
        } else {
            transitions.emplace(Transition::build(rule_to_formula(r, var_map), this->variables));
        }
    }
    initial_states = bools::mkOr(init);
    error_states = bools::mkOr(err);
}

const linked_hash_set<Transition>& SafetyProblem::trans() const {
    return transitions;
}

std::shared_ptr<const linked_hash_map<Var, Var>> SafetyProblem::var_map() const {
    return variables;
}

const VarSet& SafetyProblem::pre_vars() const {
    return pre_variables;
}

const VarSet& SafetyProblem::post_vars() const {
    return post_variables;
}

VarSet SafetyProblem::vars() const {
    VarSet res;
    for (const auto &t: transitions) {
        t.collectVars(res);
    }
    return res;
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

void SafetyProblem::set_init(const BoolExpr e) {
    initial_states = e;
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
