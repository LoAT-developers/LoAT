#include "intmbp.hpp"
#include "mbputil.hpp"
#include "smtfactory.hpp"

Bools::Expr int_mbp(const Bools::Expr &t, const Model &model, const Arith::Var x, const Config::TRPConfig::MbpKind mode) {
    assert(t->isConjunction());
    linked_hash_set<Divisibility> divs;
    linked_hash_set<Arith::Expr> lb;
    linked_hash_set<Arith::Expr> ub;
    Int flcm{1};
    Int mlcm{1};
    auto lits{t->lits()};
    auto &arith_lits{lits.get<Arith::Lit>()};
    for (auto it = arith_lits.begin(); it != arith_lits.end();) {
        const auto &l{*it};
        if (l->has(x)) {
            if (const auto div{l->isDivisibility(x)}) {
                flcm = mp::lcm(flcm, div->factor);
                divs.insert(*div);
            } else {
                if (!l->isLinear()) {
                    std::cerr << l << " is neither linear nor a divisibility constraint for " << x << std::endl;
                    assert(false);
                }
                const auto handle_gt = [&](const auto lhs) {
                    const auto coeff{*lhs->coeff(x)};
                    if (const auto coeff_val{coeff->isInt()}) {
                        flcm = mp::lcm(flcm, mp::abs(*coeff_val));
                        if (coeff_val > 0) {
                            lb.insert(lhs);
                        } else {
                            ub.insert(lhs);
                        }
                    } else {
                        throw std::invalid_argument("not a LIA expression");
                    }
                };
                if (l->isGt()) {
                    handle_gt(l->lhs());
                } else if (l->isEq()) {
                    handle_gt(l->lhs() + arith::mkConst(1));
                    handle_gt(-l->lhs() + arith::mkConst(1));
                }
            }
            it = arith_lits.erase(it);
        } else {
            ++it;
        }
    }
    if (lb.empty() || ub.empty()) {
        // easy case: no lower (or upper) bound, so all constraints involving x can
        // be satisfied by choosing a sufficiently small (large) value for x
        return t->map(
            [&](const auto &lit) {
                return std::visit(
                    Overload{
                        [&](const Arith::Lit &l) {
                            if (l->has((x))) {
                                return top();
                            } else {
                                return bools::mkLit(lit);
                            }
                        },
                        [&](const Bools::Lit &) {
                            return bools::mkLit(lit);
                        }},
                    lit);
            });
    }
    linked_hash_set<Divisibility> scaled_divs;
    linked_hash_set<Arith::Expr> scaled_lb;
    linked_hash_set<Arith::Expr> scaled_ub;
    for (const auto &l : lb) {
        const auto coeff{*l->coeff(x)};
        const auto coeff_val{*coeff->isInt()};
        const auto scaled_l {-(l - coeff * x) * arith::mkConst(flcm / mp::abs(coeff_val))};
        scaled_lb.insert(scaled_l);
    }
    for (const auto &u : ub) {
        const auto coeff{*u->coeff(x)};
        const auto coeff_val{*coeff->isInt()};
        const auto scaled_u {(u - coeff * x) * arith::mkConst(flcm / mp::abs(coeff_val))};
        scaled_ub.insert(scaled_u);
    }
    for (const auto &d : divs) {
        const auto factor{flcm / d.factor};
        scaled_divs.insert(Divisibility{.factor = 1, .modulo = d.modulo * factor, .res = d.res * arith::mkConst(factor)});
    }
    scaled_divs.insert(Divisibility{.factor = 1, .modulo = flcm, .res = arith::mkConst(0)});
    for (const auto &d : scaled_divs) {
        mlcm = mp::lcm(mlcm, d.modulo);
    }
    Arith::Expr substitute {arith::mkConst(0)};
    if (mode == Config::TRPConfig::UpperIntMbp || (mode == Config::TRPConfig::IntMbp && scaled_ub.size() < scaled_lb.size())) {
        auto closest_upper{*scaled_ub.begin()};
        auto min_val{closest_upper->eval(model.get<Arith>())};
        for (const auto &u : scaled_ub) {
            const auto val{u->eval(model.get<Arith>())};
            if (scaled_lb.contains(u - arith::mkConst(2))) {
                closest_upper = u;
                min_val = val;
                break;
            }
            if (val < min_val || (val == min_val && closest_upper->isRational() && !u->isRational()) || (val == min_val && u < closest_upper)) {
                closest_upper = u;
                min_val = val;
            }
        }
        const auto i_l{arith::mkMod(closest_upper - arith::mkConst(1) - arith::mkConst(flcm) * x, arith::mkConst(mlcm))};
        const auto i_l_val{i_l->eval(model.get<Arith>())};
        substitute = closest_upper - arith::mkConst(1 + i_l_val);
    } else {
        auto closest_lower{*scaled_lb.begin()};
        auto max_val{closest_lower->eval(model.get<Arith>())};
        for (const auto &l : scaled_lb) {
            const auto val{l->eval(model.get<Arith>())};
            if (scaled_ub.contains(l + arith::mkConst(2))) {
                closest_lower = l;
                max_val = val;
                break;
            }
            if (val > max_val || (val == max_val && closest_lower->isRational() && !l->isRational()) || (val == max_val && l < closest_lower)) {
                closest_lower = l;
                max_val = val;
            }
        }
        const auto i_l{arith::mkMod(arith::mkConst(flcm) * x - (closest_lower + arith::mkConst(1)), arith::mkConst(mlcm))};
        const auto i_l_val{i_l->eval(model.get<Arith>())};
        substitute = closest_lower + arith::mkConst(1 + i_l_val);
    }
    for (const auto &l : scaled_lb) {
        arith_lits.insert(arith::mkGt(substitute, l));
    }
    for (const auto &u : scaled_ub) {
        arith_lits.insert(arith::mkLt(substitute, u));
    }
    for (const auto &d : scaled_divs) {
        arith_lits.insert(arith::mkEq(arith::mkMod(substitute + d.res, arith::mkConst(d.modulo)), arith::mkConst(0)));
    }
    return bools::mkAndFromLits(lits);
}

Bools::Expr do_mbp(const Bools::Expr &t, const Model &model, const Var &x, const Config::TRPConfig::MbpKind mode) {
    return std::visit(
        Overload{
            [&](const Bools::Var x) {
                return mbp::bool_mbp(t, model, x);
            },
            [&](const Arith::Var x) {
                const auto res{int_mbp(t, model, x, mode)};
                assert(res != bot());
                return res;
            }},
        x);
}

Bools::Expr mbp::int_mbp(const Bools::Expr &trans, const Model &model, const Config::TRPConfig::MbpKind mode, const std::function<bool(const Var &)> &eliminate) {
    Bools::Expr res{trans};
    for (const auto &x : trans->vars()) {
        if (eliminate(x)) {
            res = do_mbp(res, model, x, mode);
        }
    }
    return res;
}

Bools::Expr mbp::int_qe(const Bools::Expr &t, const std::function<bool(const Var &)> &eliminate) {
    auto solver {SmtFactory::modelBuildingSolver(Logic::QF_LA)};
    solver->add(t);
    std::vector<Bools::Expr> disjuncts;
    SmtResult smt_res;
    while ((smt_res = solver->check()) == SmtResult::Sat) {
        const auto model {solver->model()};
        const auto next {int_mbp(solver->model().syntacticImplicant(t), model, Config::TRPConfig::IntMbp, eliminate)};
        disjuncts.push_back(next);
        solver->add(!next);
    }
    assert(smt_res == SmtResult::Unsat);
    return bools::mkOr(disjuncts);
}
