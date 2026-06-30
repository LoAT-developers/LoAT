#include "itstosafetyproblem.hpp"

#include <utility>
#include "formulapreprocessing.hpp"
#include "config.hpp"

ITSToSafety::ITSToSafety(ITSPtr its)
    : its(std::move(its)) {}

Bools::Expr ITSToSafety::rule_to_formula(const RulePtr& r) {
    Subs subs;
    std::vector<Bools::Expr> conjuncts;
    conjuncts.push_back(r->getGuard());
    for (const auto& x : prog_vars) {
        theory::apply(
            x,
            [&](const Bools::Var& x) {
                const auto up{r->getUpdate().get(x)};
                if (const auto y{up->isVar()}; y && (*y)->isTempVar() && !subs.contains(*y)) {
                    subs.put(*y, Bools::varToExpr(x->postVar()));
                } else {
                    conjuncts.push_back(Bools::mkEq(bools::mkLit(bools::mk(x->postVar())), up));
                }
            },
            [&](const Arrays<Arith>::Var& x) {
                const auto up{r->getUpdate().get(x)};
                if (x->dim() == 0) {
                    // we write to a scalar
                    if (const auto &y{up->isArrayWrite()}) {
                        // we write the array-write y to x
                        const auto val {(*y)->val()};
                        // the value that is being written to y
                        if (const auto var{val->isVar()}; var && (*var)->dim() == 0 && (*var)->isTempVar()) {
                            // the value that is being written to y is a temporary scalar
                            if (!subs.contains((*var)->var())) {
                                subs.put((*var)->var(), Arrays<Arith>::varToExpr(x->postVar()));
                                return;
                            }
                        }
                    }
                }
                if (const auto y{up->isVar()}; y && (*y)->isTempVar() && !subs.contains(*y)) {
                    subs.put(*y, Arrays<Arith>::varToExpr(x->postVar()));
                } else {
                    conjuncts.push_back(bools::mkLit(arrays::mkEq(x->postVar(), up)));
                }
            });
    }
    const auto res {bools::mkAnd(conjuncts)->subs(subs)};
    if (Config::Analysis::model) {
        rev_map.emplace(res, r);
    }
    return res;
}

RulePtr ITSToSafety::formula_to_rule(const Bools::Expr& t) {
    if (rev_map.contains(t)) {
        return rev_map.at(t);
    }
    Subs post_to_tmp;
    Subs up;
    for (const auto& pre: prog_vars) {
        Var post = theory::postVar(pre);
        theory::apply(
            post,
            [&](const auto &post) {
                using T = decltype(theory::theory(post));
                const auto tmp = T::varToExpr(T::next(post->dim()));
                up.put(std::get<typename T::Var>(pre), tmp);
                post_to_tmp.put(post, tmp);
            });
    }
    auto res = Preprocess::preprocessRule(Rule::mk(t->subs(post_to_tmp), up));
    rev_map.emplace(t, res);
    return res;
}

SafetyProblem ITSToSafety::transform() {
    SafetyProblem sp;
    for (const auto &x: its->getVars()) {
        if (theory::isProgVar(x)) {
            sp.add_pre_var(x);
            sp.add_post_var(theory::postVar(x));
        }
    }
    prog_vars = sp.pre_vars();
    for (const auto& y : sp.post_vars()) {
        theory::apply(
            y,
            [&](const auto& y) {
                using T = decltype(theory::theory(y));
                const auto x{y->progVar()};
                post_to_pre.insert(y, x);
                post_to_pre.insert(x, T::next(x->dim()));
            });
    }
    std::vector<Bools::Expr> init;
    std::vector<Bools::Expr> err;
    linked_hash_map<RulePtr, Bools::Expr> map;
    for (const auto &r: its->getAllTransitions()) {
        if (its->isInitialTransition(r)) {
            const auto b {Preprocess::preprocessFormula(rule_to_formula(r)->renameVars(post_to_pre))};
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
            const auto t {rule_to_formula(r)};

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
    ITSSafetyCex res(its->getAllTransitions());
    const auto init_model{cex.get_state(0)->composeBackwards(post_to_pre)};
    res.set_initial_state(init_model);
    const auto& fst {cex.get_state(0)};
    for (const auto &[b,t]: rev_init_map) {
        if (fst->eval(b)) {
            res.do_step(t, fst);
            break;
        }
    }
    assert(res.num_transitions() == 1);
    const auto steps{cex.num_transitions()};
    Renaming pre_to_post;
    for (const auto& x : its->getVars()) {
        theory::apply(
            x,
            [&](const auto& x) {
                if (x->isProgVar()) {
                    pre_to_post.insert(x, x->postVar());
                }
            });
    }
    for (size_t i = 0; i < steps; ++i) {
        const auto& [model, transition]{cex.get_step(i)};
        const auto rule = rev_map.at(transition);
        res.do_step(rule, model->composeBackwards(pre_to_post));
    }
    const auto& last {cex.get_state(steps)};
    for (const auto &[b,t]: rev_err_map) {
        if (last->eval(b)) {
            res.add_final_transition(t);
            break;
        }
    }
    assert(res.num_transitions() == steps + 2);
    return res;
}
