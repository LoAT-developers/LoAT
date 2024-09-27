#include "itstosafetyproblem.hpp"
#include "formulapreprocessing.hpp"
#include "config.hpp"

ITSToSafety::ITSToSafety(const ITSPtr its)
    : its(its) {}

ITSModel ITSToSafety::transform_model(const Bools::Expr &e) const {
    ITSModel res;
    const auto loc_var {its->getLocVar()};
    for (const auto &x : its->getLocations()) {
        Subs s{Subs::build<Arith>(loc_var, arith::mkConst(x))};
        res.set_invariant(x, s(e));
    }
    res.set_invariant(its->getInitialLocation(), top());
    return res;
}

Bools::Expr ITSToSafety::rule_to_formula(const RulePtr r, const VarSet &prog_vars) {
    Subs subs;
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r->getGuard());
    for (const auto &x : prog_vars) {
        if (const auto y {theory::is_var(r->getUpdate().get(x))}) {
            if (theory::isTempVar(*y) && !subs.contains(*y)) {
                subs.put(*y, theory::toExpr(theory::postVar(x)));
                continue;
            }
        }
        conjuncts.push_back(theory::mkEq(theory::toExpr(theory::postVar(x)), r->getUpdate().get(x)));
    }
    const auto res {subs(bools::mkAnd(conjuncts))};
    if (Config::Analysis::model) {
        rev_map.emplace(res, r);
    }
    return res;
}

SafetyProblem ITSToSafety::transform() {
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
    for (const auto &y: sp.post_vars()) {
        const auto x {theory::progVar(y)};
        init_map.insert(y, x);
        init_map.insert(x, theory::next(x));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(r)) {
            init.emplace_back(Preprocess::preprocessFormula(init_map(rule_to_formula(r, sp.pre_vars()))));
        }
        if (its->isSinkTransition(r)) {
            err.emplace_back(Preprocess::preprocessFormula(r->getGuard()));
        }
        if (!its->isInitialTransition(r) && !its->isSinkTransition(r)) {
            sp.add_transition(rule_to_formula(r, sp.pre_vars()));
        }
    }
    sp.set_init(bools::mkOr(init));
    sp.set_err(bools::mkOr(err));
    return sp;
}

ITSCex ITSToSafety::transform_cex(const SafetyCex &cex) const {
    ITSCex res{its};
    auto init_model{cex.get_state(0).composeBackwards(init_map)};
    res.set_initial_state(init_model);
    for (const auto &init: its->getInitialTransitions()) {
        if (res.try_step(init, cex.get_state(0))) {
            break;
        }
    }
    assert(res.num_transitions() == 1);
    const auto steps{cex.num_transitions()};
    Renaming pre_to_post;
    for (const auto &x: its->getVars()) {
        if (theory::isProgVar(x)) {
            pre_to_post.insert(x, theory::postVar(x));
        }
    }
    for (size_t i = 0; i < steps; ++i) {
        const auto &[model, transition]{cex.get_step(i)};
        const auto next{model.composeBackwards(pre_to_post)};
        const auto rule{rev_map.at(transition)};
        if (!res.try_step(rule, next)) {
            throw std::logic_error("transform_cex failed");
        }
    }
    const auto sinks{its->getSinkTransitions()};
    if (!std::any_of(sinks.begin(), sinks.end(), [&](const auto &t) {
            return res.try_final_transition(t);
        })) {
        throw std::logic_error("transform_cex failed");
    }
    return res;
}
