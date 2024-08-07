#include "itstosafetyproblem.hpp"

Bools::Expr rule_to_formula(const Rule &r, const VarSet &prog_vars) {
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r.getGuard());
    for (const auto &x : prog_vars) {
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r.getUpdate().get(x)));
    }
    return bools::mkAnd(conjuncts);
}

SafetyProblem its_to_safetyproblem(const ITSPtr its) {
    SafetyProblem res;
    const auto vars {its->getVars()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            res.add_pre_var(x);
            res.add_post_var(theory::postVar(x));
        } else if (theory::isPostVar(x)) {
            res.add_pre_var(theory::progVar(x));
            res.add_post_var(x);
        }
    }
    Subs init_map;
    for (const auto &y: res.post_vars()) {
        const auto x {theory::progVar(y)};
        init_map.put(y, theory::toExpr(x));
        init_map.put(x, theory::toExpr(theory::next(x)));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(&r)) {
            init.emplace_back(init_map(rule_to_formula(r, res.pre_vars())));
        } else if (its->isSinkTransition(&r)) {
            err.emplace_back(r.getGuard());
        } else {
            res.add_transition(rule_to_formula(r, res.pre_vars()));
        }
    }
    res.set_init(bools::mkOr(init));
    res.set_err(bools::mkOr(err));
    return res;
}