#include "trp.hpp"
#include "intmbp.hpp"
#include "realmbp.hpp"
#include "realqe.hpp"

TRP::TRP(const Renaming &pre_to_post, const Config::TRPConfig &config):
    pre_to_post(pre_to_post),
    post_to_pre(pre_to_post.invert()),
    config(config) {}

void TRP::recurrent_pseudo_divisibility(const Bools::Expr loop, const Model &model) {
    if (!config.recurrent_pseudo_divs) {
        return;
    }
    assert(loop->isConjunction());
    const auto lits{loop->lits().get<Arith::Lit>()};
    for (const auto &l : lits) {
        if (const auto div{l->isDivisibility()}) {
            const auto &[t, mod]{*div};
            const auto vars{t->vars()};
            if (std::all_of(vars.begin(), vars.end(), theory::isProgVar)) {
                const auto post{t->renameVars(pre_to_post.get<Arith>())};
                auto diff{model.eval<Arith>(t) - model.eval<Arith>(post)};
                if (diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(post, arith::mkConst(mod)), arith::mkConst(0)));
                }
            } else if (std::all_of(vars.begin(), vars.end(), theory::isPostVar)) {
                const auto pre{t->renameVars(post_to_pre.get<Arith>())};
                auto diff{model.eval<Arith>(t) - model.eval<Arith>(pre)};
                if (diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(pre, arith::mkConst(mod)), arith::mkConst(0)));
                }
            }
        }
    }
}

/**
 * handles constraints like x' = 2x
 */
void TRP::recurrent_exps(const Bools::Expr loop, const Model &model) {
    if (!config.recurrent_exps) {
        return;
    }
    assert(loop->isConjunction());
    const auto lits{loop->lits().get<Arith::Lit>()};
    for (const auto &l : lits) {
        if (l->lhs()->isLinear()) {
            auto lhs{l->lhs()};
            const auto vars{lhs->vars()};
            if (l->isEq() && vars.size() == 2) {
                auto pre{*vars.begin()};
                auto post{*std::next(vars.begin())};
                if (!pre->isProgVar()) {
                    const auto tmp{pre};
                    pre = post;
                    post = tmp;
                }
                if (pre->isProgVar() && post == ArithVar::postVar(pre)) {
                    auto pre_coeff{***(*lhs->coeff(pre))->isRational()};
                    auto post_coeff{***(*lhs->coeff(post))->isRational()};
                    if (post_coeff < 0) {
                        lhs = -lhs;
                        pre_coeff = -pre_coeff;
                        post_coeff = -post_coeff;
                    }
                    if (pre_coeff == -post_coeff) {
                        continue;
                    }
                    if (pre_coeff < 0) {
                        const auto val{model.get<Arith>(pre)};
                        if (post_coeff < -pre_coeff) {
                            if (val >= 0) {
                                // x' = 2x ~> x' >= 2x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkGeq(lhs, arith::mkConst(0)));
                            } else {
                                // x' = 2x ~> x' <= 2x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkLeq(lhs, arith::mkConst(0)));
                            }
                        } else {
                            if (val >= 0) {
                                // 2x' = x ~> 2x' <= x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkLeq(lhs, arith::mkConst(0)));
                            } else {
                                // 2x' = x ~> 2x' >= x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::mkConst(0)));
                                res_lits.insert(arith::mkGeq(lhs, arith::mkConst(0)));
                            }
                        }
                    }
                }
            }
        }
    }
}

/**
 * handles constraints like x' = -x or x' = y /\ y' = x
 */
void TRP::recurrent_cycles(const Bools::Expr loop, const Model &model) {
    if (!config.recurrent_cycles) {
        return;
    }
    for (const auto &[pre,_] : pre_to_post.get<Arith>()) {
        if (const auto orig_eq{loop->getEquality(pre)}) {
            auto vars{(*orig_eq)->vars()};
            vars.erase(pre);
            if (vars.size() != 1) {
                continue;
            }
            const auto post{ArithVar::postVar(pre)};
            auto eq{*orig_eq};
            auto other{*vars.begin()};
            auto other_coeff{*eq->coeff(other)};
            if (other_coeff->is(1)) {
                continue;
            }
            auto other_sign{***other_coeff->isRational() > 0};
            linked_hash_set<std::pair<Arith::Var, bool>> seen;
            while (other->isPostVar() && !seen.contains({other, other_sign})) {
                if (other == post && other_coeff->is(1)) {
                    const auto constant{arith::mkConst(eq->getConstantAddend())};
                    arith_var_map post_to_pre;
                    post_to_pre.left.insert(arith_var_map::left_value_type(post, pre));
                    const auto rhs_cycle_plus_one_steps{(*orig_eq + constant * n)->renameVars(post_to_pre)};
                    res_lits.insert(arith::mkEq(post, rhs_cycle_plus_one_steps));
                    break;
                } else {
                    seen.emplace(other, other_sign);
                    const auto other_eq{loop->getEquality(ArithVar::progVar(other))};
                    if (!other_eq) {
                        break;
                    }
                    eq = ArithSubs({{other, *other_eq}})(eq);
                    vars = (*other_eq)->vars();
                    if (vars.size() != 1) {
                        break;
                    }
                    other = *vars.begin();
                    other_coeff = *eq->coeff(other);
                    other_sign = ***other_coeff->isRational() > 0;
                }
            }
        }
    }
}

void TRP::recurrent_bounds(const Bools::Expr loop, Model model) {
    if (!config.recurrent_bounds) {
        return;
    }
    assert(loop->isConjunction());
    BoolExprSet delta_eqs{loop};
    std::unordered_map<Var, Arith::Var> deltas;
    Arith::Subs subs;
    Arith::Subs zeros;
    for (const auto &[pre,_] : pre_to_post.get<Arith>()) {
        const auto post{ArithVar::postVar(pre)};
        const auto d{Arith::next()};
        const auto diff{Arith::varToExpr(post) - Arith::varToExpr(pre)};
        delta_eqs.insert(bools::mkLit(arith::mkEq(d, diff)));
        model.put<Arith>(d, model.eval<Arith>(post - pre));
        subs.put(d, diff);
        deltas.emplace(d, pre);
        zeros.put(d, arith::mkConst(0));
    }
    const auto with_deltas{bools::mkAnd(delta_eqs)};
    const auto recurrent{mbp(with_deltas, model, [&](const auto &x) {
        return !deltas.contains(x);
    })};
    {
        const auto lits{recurrent->lits().get<Arith::Lit>()};
        for (const auto &l : lits) {
            const auto lit{l->subs(subs)};
            if (const auto div{lit->isDivisibility()}) {
                const auto numerator{div->first};
                const auto denominator{div->second};
                const auto constant{arith::mkConst(numerator->getConstantAddend())};
                res_lits.insert(arith::mkEq(arith::mkMod(numerator - constant + n * constant, arith::mkConst(denominator)), arith::mkConst(0)));
            } else if (l->isLinear() && (l->isEq() || l->isGt())) {
                auto old_lhs{lit->lhs()};
                if (lit->isGt()) {
                    old_lhs = old_lhs - arith::mkConst(1);
                }
                const auto constant{arith::mkConst(old_lhs->getConstantAddend())};
                const auto new_lhs{old_lhs - constant + n * constant};
                const auto rhs{arith::mkConst(0)};
                if (lit->isGt()) {
                    res_lits.insert(arith::mkGeq(new_lhs, rhs));
                } else if (lit->isEq()) {
                    res_lits.insert(arith::mkEq(new_lhs, rhs));
                }
            }
        }
    }
    if (config.recurrent_pseudo_bounds) {
        const auto pseudo_pre{mbp(with_deltas, model, [&](const auto &x) {
            return !theory::isProgVar(x) && !deltas.contains(x);
        })};
        const auto pseudo_post{mbp(with_deltas, model, [&](const auto &x) {
            return !theory::isPostVar(x) && !deltas.contains(x);
        })};
        for (const auto &pseudo : std::vector{pseudo_pre, pseudo_post}) {
            const auto lits{pseudo->lits().get<Arith::Lit>()};
            for (const auto &l : lits) {
                if (l->isLinear() && (l->isEq() || l->isGt())) {
                    const auto vars{l->vars()};
                    if (std::any_of(vars.begin(), vars.end(), [&](const auto x) {
                            return !deltas.contains(x);
                        }) &&
                        std::any_of(vars.begin(), vars.end(), [&](const auto x) {
                            return deltas.contains(x);
                        }) &&
                        std::all_of(vars.begin(), vars.end(), [&](const auto x) {
                            const auto it{deltas.find(x)};
                            return it == deltas.end() || (!vars.contains(it->second) && !vars.contains(ArithVar::postVar(it->second)));
                        })) {
                        auto non_recurrent{zeros(l->lhs())};
                        auto recurrent{subs(l->lhs() - non_recurrent)};
                        auto val{model.eval<Arith>(non_recurrent)};
                        if (l->isGt()) {
                            non_recurrent = non_recurrent - arith::mkConst(1);
                            val = val - 1;
                        } else if (val > 0) {
                            recurrent = -recurrent;
                            non_recurrent = -non_recurrent;
                            val = -val;
                        }
                        const auto rhs{arith::mkConst(0)};
                        if (val == 0) {
                            if (l->isEq()) {
                                res_lits.insert(arith::mkEq(recurrent, rhs));
                                res_lits.insert(arith::mkEq(non_recurrent, rhs));
                            } else {
                                res_lits.insert(arith::mkGeq(recurrent, rhs));
                                res_lits.insert(arith::mkGeq(non_recurrent, rhs));
                            }
                        } else if (val < 0) {
                            res_lits.insert(arith::mkLt(non_recurrent, rhs));
                            res_lits.insert(arith::mkGeq(recurrent + non_recurrent, rhs));
                            res_lits.insert(arith::mkGeq(recurrent - n, rhs));
                        }
                    }
                }
            }
        }
    }
}

Bools::Expr TRP::compute(const Bools::Expr loop, const Model &model) {
    assert(loop->isConjunction());
    recurrent_pseudo_divisibility(loop, model);
    recurrent_exps(loop, model);
    recurrent_cycles(loop, model);
    recurrent_bounds(loop, model);
    const auto res {bools::mkAndFromLits(res_lits)};
    res_lits.clear();
    if (res->vars().contains(n)) {
        return res && bools::mkLit(arith::mkGt(n, arith::mkConst(0)));
    } else {
        return res;
    }
}

Arith::Var TRP::get_n() const {
    return n;
}

Bools::Expr TRP::mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) const {
    if (!model.eval<Bools>(trans)) {
        std::cout << "mbp: not a model" << std::endl;
        std::cout << "trans: " << trans << std::endl;
        std::cout << "model: " << model << std::endl;
        assert(false);
    }
    switch (config.mbpKind) {
    case Config::TRPConfig::RealMbp:
        return mbp::real_mbp(trans, model, eliminate);
    case Config::TRPConfig::LowerIntMbp:
        return mbp::int_mbp(trans, model, eliminate, false);
    case Config::TRPConfig::UpperIntMbp:
        return mbp::int_mbp(trans, model, eliminate, true);
    case Config::TRPConfig::RealQe:
        return qe::real_qe(trans, model, eliminate);
    default:
        throw std::invalid_argument("unknown mbp kind");
    }
}
