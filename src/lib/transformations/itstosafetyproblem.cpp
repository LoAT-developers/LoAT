#include "itstosafetyproblem.hpp"
#include "formulapreprocessing.hpp"

ITSToSafety::ITSToSafety(const ITSProblem &its): its(its) {}

ITSModel ITSToSafety::transform_model(const Bools::Expr &e) const {
    ITSModel res;
    const auto loc_var {its.getLocVar()};
    for (const auto &x : its.getLocations()) {
        Subs s{Subs::build<Arith>(loc_var, arith::mkConst(x))};
        res.set_invariant(x, s(e));
    }
    res.set_invariant(its.getInitialLocation(), top());
    return res;
}

Bools::Expr rule_to_formula(const Rule &r, const VarSet &prog_vars) {
    Subs subs;
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r.getGuard());
    for (const auto &x : prog_vars) {
        if (const auto y {theory::is_var(r.getUpdate().get(x))}) {
            if (theory::isTempVar(*y) && !subs.contains(*y)) {
                subs.put(*y, theory::toExpr(theory::postVar(x)));
                continue;
            }
        }
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r.getUpdate().get(x)));
    }
    return subs(bools::mkAnd(conjuncts));
}

SafetyProblem ITSToSafety::transform() {
    SafetyProblem sp;
    const auto vars {its.getVars()};
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
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r)) {
            init.emplace_back(Preprocess::preprocessFormula(init_map(rule_to_formula(r, sp.pre_vars())), theory::isTempVar));
        }
        if (its.isSinkTransition(&r)) {
            err.emplace_back(Preprocess::preprocessFormula(r.getGuard(), theory::isTempVar));
        }
        if (!its.isInitialTransition(&r) && !its.isSinkTransition(&r)) {
            sp.add_transition(rule_to_formula(r, sp.pre_vars()));
        }
    }
    sp.set_init(bools::mkOr(init));
    sp.set_err(bools::mkOr(err));
    return sp;
}
