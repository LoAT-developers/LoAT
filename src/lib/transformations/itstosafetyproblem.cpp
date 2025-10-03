#include "itstosafetyproblem.hpp"
#include "formulapreprocessing.hpp"
#include "config.hpp"

ITSToSafety::ITSToSafety(const ITSPtr& its)
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

Bools::Expr ITSToSafety::rule_to_formula(const RulePtr& r, const VarSet &prog_vars) {
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
    return res;
}

SafetyProblem ITSToSafety::transform() {
    SafetyProblem sp;
    for (const auto &x: its->getVars()) {
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
        post_to_pre.insert(y, x);
        post_to_pre.insert(x, theory::next(x));
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    linked_hash_map<RulePtr, Bools::Expr> map;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(r)) {
            const auto b {Preprocess::preprocessFormula(post_to_pre(rule_to_formula(r, sp.pre_vars())))};
            init.emplace_back(b);
            if (Config::Analysis::model) {
                rev_init_map.emplace(b, r);
            }
        }
        if (its->isSinkTransition(r)) {
            const auto b {Preprocess::preprocessFormula(r->getGuard())};
            err.emplace_back(b);
            if (Config::Analysis::model) {
                rev_err_map.emplace(b, r);
            }
        }
        if (!its->isInitialTransition(r) && !its->isSinkTransition(r)) {
            const auto t {rule_to_formula(r, sp.pre_vars())};

            map.emplace(r, t);
            sp.add_transition(t);
            for (const auto &p: its->getPredecessors(r)) {
                if (its->isInitialTransition(p)) {
                    sp.mark_initial_transition(t);
                } else if (map.contains(p)) {
                    sp.add_edge(map.at(p), t);
                }
            }
            for (const auto &s: its->getSuccessors(r)) {
                if (its->isSinkTransition(s)) {
                    sp.mark_sink_transition(t);
                } else if (map.contains(s)) {
                    sp.add_edge(t, map.at(s));
                }
            }
        }
    }
    sp.set_init(bools::mkOr(init));
    sp.set_err(bools::mkOr(err));
    return sp;
}

ITSSafetyCex ITSToSafety::transform_cex(const SafetyCex &cex) const {
    ITSSafetyCex res{its};
    const auto init_model{cex.get_state(0)->composeBackwards(post_to_pre)};
    res.set_initial_state(init_model);
    const auto fst {cex.get_state(0)};
    for (const auto &[b,t]: rev_init_map) {
        if (fst->eval(b)) {
            res.do_step(t, fst);
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
        const auto& [model, transition]{cex.get_step(i)};
        res.do_step(rev_map.at(transition), model->composeBackwards(pre_to_post));
    }
    const auto last {cex.get_state(steps - 1)->composeBackwards(post_to_pre)};
    for (const auto &[b,t]: rev_err_map) {
        if (last->eval(b)) {
            res.add_final_transition(t);
            break;
        }
    }
    assert(res.num_transitions() == steps + 2);
    return res;
}
