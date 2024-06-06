#include "intmbp.hpp"
#include "mbputil.hpp"

Bools::Expr int_mbp(const Bools::Expr &t, const Model &model, const Arith::Var x) {
    assert(t->isConjunction());
    std::cout << "eliminating " << x << " from " << t << std::endl;
    std::cout << "model: " << model << std::endl;
    if (auto eq{t->getEquality(x)}) {
        // easy case: we found an equality involving n
        const auto factor{(*eq)->getConstantFactor()};
        // we have n = eq = factor * p where factor = num/denom, i.e., denom * n = num * p
        const auto num{mp::numerator(factor)};
        const auto denom{mp::denominator(factor)};
        // replace n by num/denom * p ...
        auto res{Subs::build<Arith>(x, *eq)(t)};
        if (denom != 1) {
            // and enforce that num * p = eq * denom is divisble by denom, if necessary
            res = res && bools::mkLit(arith::mkEq(arith::mkMod(*eq * arith::mkConst(denom), arith::mkConst(denom)), arith::mkConst(0)));
        }
        return res;
    }
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
                assert(l->isLinear());
                assert(l->isGt());
                const auto lhs{l->lhs()};
                const auto coeff{*lhs->coeff(x)};
                const auto coeff_val{*coeff->isInt()};
                flcm = mp::lcm(flcm, mp::abs(coeff_val));
                if (coeff_val > 0) {
                    lb.insert(lhs);
                } else {
                    ub.insert(lhs);
                }
            }
            it = arith_lits.erase(it);
        } else {
            ++it;
        }
    }
    if (lb.empty()) {
        // easy case: no lower bound, so all constraints involving x can
        // be satisfied by choosing a sufficiently small value for x
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
        std::cout << "lower bound: " << l << std::endl;
        std::cout << "scaled lower bound: " << scaled_l << std::endl;
        scaled_lb.insert(scaled_l);
    }
    for (const auto &u : ub) {
        const auto coeff{*u->coeff(x)};
        const auto coeff_val{*coeff->isInt()};
        const auto scaled_u {(u - coeff * x) * arith::mkConst(flcm / mp::abs(coeff_val))};
        std::cout << "upper bound: " << u << std::endl;
        std::cout << "scaled upper bound: " << scaled_u << std::endl;
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
    auto closest_bound{*scaled_lb.begin()};
    auto max_val{closest_bound->eval(model.get<Arith>())};
    for (const auto &l : scaled_lb) {
        const auto val{l->eval(model.get<Arith>())};
        if (val > max_val) {
            closest_bound = l;
            max_val = val;
        }
    }
    const auto i_l{arith::mkMod(arith::mkConst(flcm) * x - (closest_bound + arith::mkConst(1)), arith::mkConst(mlcm))};
    const auto i_l_val {i_l->eval(model.get<Arith>())};
    const auto substitute{closest_bound + arith::mkConst(1 + i_l_val)};
    std::cout << "flcm: " << flcm << std::endl;
    std::cout << "mlcm: " << mlcm << std::endl;
    std::cout << "closest bound: " << closest_bound << std::endl;
    std::cout << "i_l: " << i_l << std::endl;
    std::cout << "i_l_val: " << i_l_val << std::endl;
    std::cout << "substitue: " << substitute << std::endl;
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

Bools::Expr int_mbp(const Bools::Expr &t, const Model &model, const Var &x) {
    return std::visit(
        Overload{
            [&](const Bools::Var x) {
                return mbp::bool_mbp(t, model, x);
            },
            [&](const Arith::Var x) {
                const auto res{int_mbp(t, model, x)};
                assert(res != bot());
                return res;
            }},
        x);
}

Bools::Expr mbp::int_mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    Bools::Expr res{trans};
    for (const auto &x : trans->vars()) {
        if (eliminate(x)) {
            res = ::int_mbp(res, model, x);
        }
    }
    return res;
}