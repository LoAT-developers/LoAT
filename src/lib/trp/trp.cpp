#include "trp.hpp"
#include "intmbp.hpp"
#include "realmbp.hpp"
#include "realqe.hpp"
#include "redundantinequations.hpp"
#include "smtfactory.hpp"

TRP::TRP(const Renaming& pre_to_post, const Config::TRPConfig& config) :
    pre_to_post(pre_to_post),
    post_to_pre(pre_to_post.invert()),
    config(config) {
    for (const auto& p : pre_to_post) {
        theory::apply(
            p,
            [&](const auto& p) {
                const auto& [pre, post]{p};
                using T = decltype(theory::theory(pre));
                const auto i{T::next(0)};
                pre_to_intermediate.insert(pre, i);
                post_to_intermediate.insert(post, i);
            });
    }
}

void TRP::recurrent_pseudo_divisibility(const Bools::Expr& loop, const ModelPtr &model) {
    if (!config.recurrent_pseudo_divs) {
        return;
    }
    assert(loop->isConjunction());
    for (const auto lits{loop->lits().get<Arith::Lit>()}; const auto &l : lits) {
        if (const auto div{l->isDivisibility()}) {
            const auto &[t, mod]{*div};
            if (const auto vars{t->vars()}; std::ranges::all_of(vars, theory::isProgVar)) {
                const auto post{t->renameVars(pre_to_post.get<Arrays<Arith>>())};
                if (auto diff{model->eval(t) - model->eval(post)}; diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(post, arith::mkConst(mod)), arith::zero()));
                }
            } else if (std::ranges::all_of(vars, theory::isPostVar)) {
                const auto pre{t->renameVars(post_to_pre.get<Arrays<Arith>>())};
                if (auto diff{model->eval(t) - model->eval(pre)}; diff % mod == 0) {
                    res_lits.insert(arith::mkEq(arith::mkMod(pre, arith::mkConst(mod)), arith::zero()));
                }
            }
        }
    }
}

/**
 * handles constraints like x' = 2x
 */
void TRP::recurrent_exps(const Bools::Expr& loop, const ModelPtr &model) {
    if (!config.recurrent_exps) {
        return;
    }
    assert(loop->isConjunction());
    for (const auto lits{loop->lits().get<Arith::Lit>()}; const auto &l : lits) {
        if (l->lhs()->isLinear()) {
            auto lhs{l->lhs()};
            if (const auto cells{lhs->cells()}; l->isEq() && cells.size() == 2) {
                auto pre{*cells.begin()};
                auto post{*std::next(cells.begin())};
                if (!pre->isProgVar()) {
                    const auto tmp{pre};
                    pre = post;
                    post = tmp;
                }
                if (pre->isProgVar() && post == pre->withVar(pre->var()->postVar())) {
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
                        const auto val{model->get(pre)};
                        if (post_coeff < -pre_coeff) {
                            if (val >= 0) {
                                // x' = 2x ~> x' >= 2x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::zero()));
                                res_lits.insert(arith::mkGeq(lhs, arith::zero()));
                            } else {
                                // x' = 2x ~> x' <= 2x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::zero()));
                                res_lits.insert(arith::mkLeq(lhs, arith::zero()));
                            }
                        } else {
                            if (val >= 0) {
                                // 2x' = x ~> 2x' <= x for non-negative x
                                res_lits.insert(arith::mkGeq(pre, arith::zero()));
                                res_lits.insert(arith::mkLeq(lhs, arith::zero()));
                            } else {
                                // 2x' = x ~> 2x' >= x for negative x
                                res_lits.insert(arith::mkLt(pre, arith::zero()));
                                res_lits.insert(arith::mkGeq(lhs, arith::zero()));
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
void TRP::recurrent_cycles(const Bools::Expr& loop, const linked_hash_set<ArithVarPtr> &pre_cells) {
    if (!config.recurrent_cycles) {
        return;
    }
    for (const auto &pre : pre_cells) {
        if (const auto orig_eq{loop->getEquality(pre)}) {
            auto cells{(*orig_eq)->cells()};
            cells.erase(pre);
            if (cells.size() != 1) {
                continue;
            }
            const auto post{pre->renameVars(pre_to_post)};
            auto eq{*orig_eq};
            auto other{*cells.begin()};
            auto other_coeff{*eq->coeff(other)};
            if (other_coeff->is(1)) {
                continue;
            }
            auto other_sign{***other_coeff->isRational() > 0};
            linked_hash_set<std::pair<ArithVarPtr, bool>> seen;
            while (other->isPostCell() && !seen.contains({other, other_sign})) {
                if (other == post && other_coeff->is(1)) {
                    const auto constant{arith::mkConst(eq->getConstantAddend())};
                    const auto rhs_cycle_plus_one_steps{(*orig_eq + constant * n)->renameVars(post_to_pre)};
                    res_lits.insert(arith::mkEq(post, rhs_cycle_plus_one_steps));
                    break;
                }
                seen.emplace(other, other_sign);
                const auto other_eq{loop->getEquality(other->renameVars(post_to_pre))};
                if (!other_eq) {
                    break;
                }
                eq = eq->subs(ArraySubs<Arith>({{other->var(), arrays::update(other, *other_eq)}}));
                cells = (*other_eq)->cells();
                if (cells.size() != 1) {
                    break;
                }
                other = *cells.begin();
                other_coeff = *eq->coeff(other);
                other_sign = ***other_coeff->isRational() > 0;
            }
        }
    }
}

void TRP::recurrent_bounds(const Bools::Expr& loop, const linked_hash_set<ArithVarPtr>& pre_cells, const ModelPtr& model) {
    if (!config.recurrent_bounds) {
        return;
    }
    assert(loop->isConjunction());
    BoolExprSet delta_eqs{loop};
    std::unordered_map<Cell, ArithVarPtr> deltas;
    Arrays<Arith>::Subs subs;
    Arrays<Arith>::Subs zeros;
    const auto cells {loop->cells().get<ArithVarPtr>()};
    for (const auto &pre : pre_cells) {
        const auto post{pre->renameVars(pre_to_post.get<Arrays<Arith>>())};
        const auto d{arrays::nextConst<Arith>()};
        const auto diff{post - pre};
        delta_eqs.insert(bools::mkLit(arith::mkEq(d, diff)));
        model->put(d, model->eval(post - pre));
        subs.put(d->var(), arrays::update(d, diff));
        deltas.emplace(d, pre);
        zeros.put(d->var(), arrays::update(d, arith::zero()));
    }
    const auto with_deltas{bools::mkAnd(delta_eqs)};
    {
        const auto recurrent{mbp(with_deltas, model, [&](const auto &x) {
            return !deltas.contains(x);
        })};
        for (const auto lits{recurrent->lits().get<Arith::Lit>()}; const auto &l : lits) {
            const auto lit{l->subs(subs)};
            if (const auto div{lit->isDivisibility()}) {
                const auto numerator{div->first};
                const auto denominator{div->second};
                const auto constant{arith::mkConst(numerator->getConstantAddend())};
                res_lits.insert(arith::mkEq(arith::mkMod(numerator - constant + n * constant, arith::mkConst(denominator)), arith::zero()));
            } else if (l->isLinear() && (l->isEq() || l->isGt())) {
                auto old_lhs{lit->lhs()};
                if (lit->isGt()) {
                    old_lhs = old_lhs - arith::one();
                }
                const auto constant{arith::mkConst(old_lhs->getConstantAddend())};
                const auto new_lhs{old_lhs - constant + n * constant};
                const auto rhs{arith::zero()};
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
            return !theory::isProgCell(x) && !deltas.contains(x);
        })};
        const auto pseudo_post{mbp(with_deltas, model, [&](const auto &x) {
            return !theory::isPostCell(x) && !deltas.contains(x);
        })};
        for (const auto &pseudo : std::vector{pseudo_pre, pseudo_post}) {
            for (const auto lits{pseudo->lits().get<Arith::Lit>()}; const auto &l : lits) {
                if (l->isLinear() && (l->isEq() || l->isGt())) {
                    if (const auto cells{l->cells()}; std::ranges::any_of(cells, [&](const auto& x) {
                            return !deltas.contains(x);
                        }) &&
                        std::ranges::any_of(cells, [&](const auto& x) {
                            return deltas.contains(x);
                        }) &&
                        std::ranges::all_of(cells, [&](const auto& x) {
                            const auto it{deltas.find(x)};
                            return it == deltas.end()
                                || (!cells.contains(it->second)
                                    && !cells.contains(it->second->renameVars(pre_to_post.get<Arrays<Arith>>())));
                        })) {
                        auto non_recurrent{l->lhs()->subs(zeros)};
                        auto recurrent{(l->lhs() - non_recurrent)->subs(subs)};
                        auto val{model->eval(non_recurrent)};
                        if (l->isGt()) {
                            non_recurrent = non_recurrent - arith::one();
                            val = val - 1;
                        } else if (val > 0) {
                            recurrent = -recurrent;
                            non_recurrent = -non_recurrent;
                            val = -val;
                        }
                        const auto rhs{arith::zero()};
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

Bools::Expr TRP::recurrent(const Bools::Expr& loop, const ModelPtr &model) {
    assert(loop->isConjunction());
    linked_hash_set<ArithVarPtr> pre_cells;
    const auto cells {loop->cells().get<ArithVarPtr>()};
    for (const auto& c: cells) {
        if (c->isProgCell()) {
            pre_cells.insert(c);
        } else if (c->isPostCell()) {
            pre_cells.insert(c->renameVars(pre_to_post));
        }
    }
    recurrent_pseudo_divisibility(loop, model);
    recurrent_exps(loop, model);
    recurrent_cycles(loop, pre_cells);
    recurrent_bounds(loop, pre_cells, model);
    auto res {bools::mkAnd(res_lits)};
    res_lits.clear();
    if (res->vars().contains(n->var())) {
        return res && bools::mkLit(arith::mkGt(n, arith::zero()));
    }
    return res;
}

Bools::Expr TRP::compute(const Bools::Expr& loop, const ModelPtr &model) {
    if (SmtFactory::check(loop->renameVars(post_to_intermediate) && loop->renameVars(pre_to_intermediate) && !loop) == SmtResult::Unsat) {
        return loop;
    }
    const auto pre{mbp(loop, model, [](const auto &x) {
        return !theory::isProgCell(x);
    })};
    if (Config::Analysis::log) {
        std::cout << "pre: " << pre << std::endl;
    }
    const auto step{recurrent(loop, model)};
    if (Config::Analysis::log) {
        std::cout << "recurrence analysis: " << step << std::endl;
    }
    const auto post{mbp(loop, model, [](const auto &x) {
        return !theory::isPostCell(x);
    })};
    if (Config::Analysis::log) {
        std::cout << "post: " << post << std::endl;
    }
    return removeRedundantInequations(pre && step && post);
}

ArithVarPtr TRP::get_n() const {
    return n;
}

Bools::Expr TRP::mbp(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Cell &)> &eliminate) const {
    if (!model->eval(trans)) {
        std::cout << "mbp: not a model" << std::endl;
        std::cout << "trans: " << trans << std::endl;
        std::cout << "model: " << model->toString(trans->vars()) << std::endl;
        assert(false);
    }
    Bools::Expr res {top()};
    switch (config.mbpKind) {
    case Config::TRPConfig::RealMbp:
        res = mbp::real_mbp(trans, model, eliminate);
        break;
    case Config::TRPConfig::IntMbp:
    case Config::TRPConfig::LowerIntMbp:
    case Config::TRPConfig::UpperIntMbp:
        res = mbp::int_mbp(trans, model, config.mbpKind, eliminate);
        break;
    case Config::TRPConfig::RealQe:
        res = qe::real_qe(trans, model, eliminate);
        break;
    default:
        throw std::invalid_argument("unknown mbp kind");
    }
    return res;
}
