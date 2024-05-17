#include "intmbp.hpp"
#include "mbputil.hpp"

Bools::Expr int_mbp(const Bools::Expr &t, const Model &model, const Arith::Var x) {
    assert(t->isConjunction());
    // std::cout << "eliminating " << x << " from " << t << std::endl;
    // std::cout << "model: " << x << model << std::endl;
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
    } else {
        std::optional<std::pair<Arith::Expr, Rational>> closest_lb;
        linked_hash_set<Divisibility> divs;
        Int flcm{1};
        Int mlcm{1};
        const auto lits {t->lits().get<Arith::Lit>()};
        for (const auto &l: lits) {
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
                        const auto dist{lhs->evalToRational(model.get<Arith>()) / coeff_val};
                        if (!closest_lb || dist < closest_lb->second) {
                            closest_lb = {{lhs, dist}};
                        }
                    }
                }
            }
        }
        if (closest_lb) {
            for (const auto &d : divs) {
                mlcm = mp::lcm(mlcm, d.modulo * flcm / d.factor);
            }
            const auto bound {closest_lb->first};
            // std::cout << "bound: " << bound << std::endl;
            const auto coeff {*bound->coeff(x)};
            // std::cout << "coeff: " << coeff << std::endl;
            const auto coeff_val {*coeff->isInt()};
            const auto scaled_bound {bound * arith::mkConst(mlcm / coeff_val)};
            // std::cout << "scaled bound: " << scaled_bound << std::endl;
            const auto scaled_x {arith::mkConst(mlcm) * x};
            // std::cout << "scaled x: " << scaled_x << std::endl;
            const auto rhs {-(scaled_bound - scaled_x)};
            // std::cout << "rhs: " << rhs << std::endl;
            const auto substitute {(rhs + arith::mkConst(model.eval<Arith>(arith::mkMod(scaled_x - (rhs + arith::mkConst(1)), arith::mkConst(mlcm))) + 1))->divide(mlcm)};
            // std::cout << "substitute: " << substitute << std::endl;
            const auto subs {ArithSubs({{x, substitute}})};
            return Subs::build<Arith>(subs)(t);
        } else {
            // easy case: no lower bound, so all constraints involving x can
            // be satisfied by choosing a sufficiently small value for x
            return t->map(
                [&](const auto &lit){
                    return std::visit(
                        Overload{
                            [&](const Arith::Lit &l) {
                                if (l->has((x))) {
                                    return top();
                                } else {
                                    return bools::mkLit(lit);
                                }
                            },
                            [&](const Bools::Lit&) {
                                return bools::mkLit(lit);
                            }
                        }, lit);
                    });
        }
    }
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