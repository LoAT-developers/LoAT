#include "safetyproblem.hpp"

Bools::Expr rule_to_formula(const Rule &r, const VarSet &prog_vars) {
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r.getGuard());
    for (const auto &x: prog_vars) {
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r.getUpdate().get(x)));
    }
    return bools::mkAnd(conjuncts);
}

SafetyProblem::SafetyProblem() {}

SafetyProblem::SafetyProblem(const ITSProblem &its) {
    const auto vars {its.getVars()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            pre_variables.insert(x);
            post_variables.insert(theory::postVar(x));
        } else if (theory::isPostVar(x)) {
            pre_variables.insert(theory::progVar(x));
            post_variables.insert(x);
        }
    }
    Subs init_map;
    for (const auto &y: post_variables) {
        const auto x {theory::progVar(y)};
        init_map.put(y, theory::toExpr(x));
        init_map.put(x, theory::toExpr(theory::next(x)));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r)) {
            init.emplace_back(init_map(rule_to_formula(r, pre_variables)));
        } else if (its.isSinkTransition(&r)) {
            err.emplace_back(r.getGuard());
        } else {
            transitions.emplace(rule_to_formula(r, pre_variables));
        }
    }
    initial_states = bools::mkOr(init);
    error_states = bools::mkOr(err);
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

void SafetyProblem::set_init(const Bools::Expr e) {
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

SafetyProblem SafetyProblem::reverse() const {
    SafetyProblem res;
    res.initial_states = error_states;
    res.error_states = initial_states;
    res.pre_variables = pre_variables;
    res.post_variables = post_variables;
    Subs swap;
    for (const auto &x: pre_variables) {
        swap.put(x, theory::toExpr(theory::postVar(x)));
        swap.put(theory::postVar(x), theory::toExpr(x));
    }
    for (const auto &t: transitions) {
        res.transitions.insert(swap(t));
    }
    return res;
}