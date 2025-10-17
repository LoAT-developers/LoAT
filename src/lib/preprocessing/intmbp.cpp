#include "intmbp.hpp"
#include "mbputil.hpp"
#include "smtfactory.hpp"

Bools::Expr int_mbp(const Bools::Expr &t, const ModelPtr &model, const Arith::Var x, const Config::TRPConfig::MbpKind mode) {
    assert(t->isConjunction());
    // divisibility constraints for x
    linked_hash_set<Divisibility> divs;
    // lower bounds for x
    linked_hash_set<Arith::Expr> lb;
    // upper bounds for x
    linked_hash_set<Arith::Expr> ub;
    // least common multiple of all coefficients (or factors) of x in the given expression
    Int flcm{1};
    // least common multiple of all divisors (or modulus) in divisibility constraints for x
    Int mlcm{1};
    auto lits{t->lits()};
    auto &arith_lits{lits.get<Arith::Lit>()};
    // Iterate over all arithmetic literals to populate the sets above.
    // Erases literals that contain x as side effect.
    for (auto it = arith_lits.begin(); it != arith_lits.end();) {
        if (const auto &l{*it}; l->has(x)) {
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
                    // split equalities into two inequations
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
                            if (l->has(x)) {
                                return top();
                            }
                            return bools::mkLit(lit);
                        },
                        [&](const Bools::Lit &) {
                            return bools::mkLit(lit);
                        },
                        [](const Arrays<Arith>::Lit &) -> Bools::Expr {
                            throw std::invalid_argument("real mbp does not support arrays");
                        }
                    },
                    lit);
            });
    }
    // In Cooper's QE procedure, we'd now sacale all literals so that the coefficient of x is flcm.
    // We can't do that explicitly, as our expressions are normalized automatically.
    // So instead, we collect all divisibility constraints / bounds for flcm * x in the sets below.
    // Equivalently, assume that we substituted flcm * x with a fresh variable x', and the sets below contain the divisibility constraints / bounds for x'.
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
    for (const auto & [fac, mod, res] : divs) {
        const auto factor{flcm / fac};
        scaled_divs.insert(Divisibility{.factor = 1, .modulo = mod * factor, .res = res * arith::mkConst(factor)});
    }
    // in addition to the constraints above, we have flcm|x'
    scaled_divs.insert(Divisibility{.factor = 1, .modulo = flcm, .res = arith::mkConst(0)});
    // compute the least common multiple of all divisors
    for (const auto &d : scaled_divs) {
        mlcm = mp::lcm(mlcm, d.modulo);
    }
    // Compute the value that we substitute for x'.
    // Here, we can either start from the closest upper bound, or from the closest lower bound.
    // The decision depends on the given mode.
    // If the mode is IntMbp, then we prefer upper to lower bounds iff there are fewer upper than lower bounds.
    Arith::Expr substitute {arith::mkConst(0)};
    if (mode == Config::TRPConfig::UpperIntMbp || (mode == Config::TRPConfig::IntMbp && scaled_ub.size() < scaled_lb.size())) {
        // start from the closest upper bound
        auto closest_upper{*scaled_ub.begin()};
        auto min_val{model->eval(closest_upper)};
        for (const auto &u : scaled_ub) {
            const auto val{model->eval(u)};
            if (scaled_lb.contains(u - arith::mkConst(2))) {
                closest_upper = u;
                break;
            }
            // If two bounds have the same distance, we prefer non-constant over constant bounds, as they often lead to formulas that cover more cases.
            // If both are (non-)constant, we simply compare the pointers to break the tie.
            if (val < min_val || (val == min_val && closest_upper->isRational() && !u->isRational()) || (val == min_val && u < closest_upper)) {
                closest_upper = u;
                min_val = val;
            }
        }
        // compute i_l as in [Spacer], but negated (as we decided to pick an upper instead of a lower bound)
        const auto i_l{arith::mkMod(closest_upper - arith::mkConst(1) - arith::mkConst(flcm) * x, arith::mkConst(mlcm))};
        // evaluate i_l in the current model
        const auto i_l_val{model->eval(i_l)};
        substitute = closest_upper - arith::mkConst(1 + i_l_val);
    } else {
        // start from the closest lower bound -- symmetric to the case above
        auto closest_lower{*scaled_lb.begin()};
        auto max_val{model->eval(closest_lower)};
        for (const auto &l : scaled_lb) {
            const auto val{model->eval(l)};
            if (scaled_ub.contains(l + arith::mkConst(2))) {
                closest_lower = l;
                break;
            }
            if (val > max_val || (val == max_val && closest_lower->isRational() && !l->isRational()) || (val == max_val && l < closest_lower)) {
                closest_lower = l;
                max_val = val;
            }
        }
        const auto i_l{arith::mkMod(arith::mkConst(flcm) * x - (closest_lower + arith::mkConst(1)), arith::mkConst(mlcm))};
        const auto i_l_val{model->eval(i_l)};
        substitute = closest_lower + arith::mkConst(1 + i_l_val);
    }
    // re-add the literals for x', but replace x' with the substitute computed above
    for (const auto &l : scaled_lb) {
        arith_lits.insert(arith::mkGt(substitute, l));
    }
    for (const auto &u : scaled_ub) {
        arith_lits.insert(arith::mkLt(substitute, u));
    }
    for (const auto &d : scaled_divs) {
        arith_lits.insert(arith::mkEq(arith::mkMod(substitute + d.res, arith::mkConst(d.modulo)), arith::mkConst(0)));
    }
    return bools::mkAnd(lits);
}

Bools::Expr do_mbp(const Bools::Expr &t, const ModelPtr& model, const Var &x, const Config::TRPConfig::MbpKind mode) {
    return std::visit(
        Overload{
            [&](const Bools::Var &y) {
                return mbp::bool_mbp(t, model, y);
            },
            [&](const Arith::Var &y) {
                const auto res{int_mbp(t, model, y, mode)};
                assert(res != bot());
                return res;
            },
        [](const Arrays<Arith>::Var &) -> Bools::Expr {
            throw std::invalid_argument("mbp does not support arrays");
        }},
        x);
}

Bools::Expr mbp::int_mbp(const Bools::Expr &trans, const ModelPtr& model, const Config::TRPConfig::MbpKind mode, const std::function<bool(const Var &)> &eliminate) {
    Bools::Expr res{trans};
    for (const auto &x : trans->vars()) {
        if (eliminate(x)) {
            res = do_mbp(res, model, x, mode);
        }
    }
    return res;
}

Bools::Expr mbp::int_qe(const Bools::Expr &trans, const std::function<bool(const Var &)> &eliminate) {
    const auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    solver->add(trans);
    std::vector<Bools::Expr> disjuncts;
    SmtResult smt_res;
    while ((smt_res = solver->check()) == SmtResult::Sat) {
        const auto model {solver->model()};
        const auto next {int_mbp(solver->model()->syntacticImplicant(trans), model, Config::TRPConfig::IntMbp, eliminate)};
        disjuncts.push_back(next);
        solver->add(!next);
    }
    assert(smt_res == SmtResult::Unsat);
    return bools::mkOr(disjuncts);
}
