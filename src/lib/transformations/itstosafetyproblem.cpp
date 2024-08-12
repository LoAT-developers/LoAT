#include "itstosafetyproblem.hpp"

ReversibleITSToSafety::ReversibleITSToSafety(const SafetyProblem &sp, const linked_hash_set<LocationIdx> &locations, const Arith::Var &loc_var): Reversible<SafetyProblem, Bools::Expr, ITSModel>(sp), locations(locations), loc_var(loc_var) {}

ITSModel ReversibleITSToSafety::revert_model(const Bools::Expr &e) const {
    ITSModel res;
    for (const auto &x : locations) {
        Subs s{Subs::build<Arith>(loc_var, arith::mkConst(x))};
        res.set_invariant(x, s(e));
    }
    return res;
}

Bools::Expr rule_to_formula(const Rule &r, const VarSet &prog_vars) {
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r.getGuard());
    for (const auto &x : prog_vars) {
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r.getUpdate().get(x)));
    }
    return bools::mkAnd(conjuncts);
}

ReversibleITSToSafety its_to_safetyproblem(const ITSPtr its) {
    SafetyProblem sp;
    const auto vars {its->getVars()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            sp.add_pre_var(x);
            sp.add_post_var(theory::postVar(x));
        } else if (theory::isPostVar(x)) {
            sp.add_pre_var(theory::progVar(x));
            sp.add_post_var(x);
        }
    }
    Subs init_map;
    for (const auto &y: sp.post_vars()) {
        const auto x {theory::progVar(y)};
        init_map.put(y, theory::toExpr(x));
        init_map.put(x, theory::toExpr(theory::next(x)));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(&r)) {
            init.emplace_back(init_map(rule_to_formula(r, sp.pre_vars())));
        } else if (its->isSinkTransition(&r)) {
            err.emplace_back(r.getGuard());
        } else {
            sp.add_transition(rule_to_formula(r, sp.pre_vars()));
        }
    }
    sp.set_init(bools::mkOr(init));
    sp.set_err(bools::mkOr(err));
    return ReversibleITSToSafety(sp, its->getLocations(), its->getLocVar());
}