#include "mbputil.hpp"

std::optional<Arith::Expr> mbp::closest_lower_bound(const linked_hash_set<Bound> &bounds, const Arith::Model &model, const Arith::Var &x) {
    std::optional<Arith::Expr> closest;
    Rational dist;
    const auto val {x->eval(model)};
    for (const auto &b: bounds) {
        if (b.kind == BoundKind::Lower) {
            const auto b_val{b.bound->evalToRational(model)};
            const auto d{mp::abs(val - b_val)};
            if (!closest || d < dist || (d == dist && break_tie(*closest, b.bound))) {
                dist = d;
                closest = b.bound;
            }
        }
    }
    return closest;
}

Bools::Expr mbp::bool_mbp(const Bools::Expr &t, const Model &model, const Bools::Var x) {
    return Subs::build<Bools>(x, Bools::constToExpr(model.get<Bools>(x)))(t);
}

bool mbp::break_tie(const Arith::Expr fst, const Arith::Expr snd) {
    if (fst->isRational() && !snd->isRational()) {
        return true;
    }
    if (!fst->isRational() && snd->isRational()) {
        return false;
    }
    const auto f_max{fst->max_coeff()};
    const auto s_max{snd->max_coeff()};
    if (f_max != s_max) {
        return f_max > s_max;
    }
    const auto f_sum{fst->coeff_sum()};
    const auto s_sum{snd->coeff_sum()};
    if (f_sum != s_sum) {
        return f_sum > s_sum;
    }
    return fst > snd;
}