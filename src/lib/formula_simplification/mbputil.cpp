#include "mbputil.hpp"

std::optional<Arith::Expr> mbp::closest_lower_bound(const linked_hash_set<Bound> &bounds, const Arith::Model &model, const Arith::Var &x) {
    std::optional<Arith::Expr> closest;
    Rational dist;
    const auto val {x->eval(model)};
    for (const auto &b: bounds) {
        if (b.kind == BoundKind::Lower) {
            const auto b_val{b.bound->evalToRational(model)};
            const auto d{mp::abs(val - b_val)};
            if (!closest || d < dist || (d == dist && b.bound < *closest)) {
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