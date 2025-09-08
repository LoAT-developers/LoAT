#include "mbputil.hpp"

std::optional<Arith::Expr> mbp::closest_lower_bound(const linked_hash_set<Bound> &bounds, const ModelPtr& model, const Arith::Var &x) {
    std::optional<Arith::Expr> closest;
    Rational dist;
    const auto val {model->eval(x)};
    for (const auto &b: bounds) {
        if (b.kind == BoundKind::Lower) {
            const auto b_val{model->evalToRational(b.bound)};
            if (const auto d{mp::abs(val - b_val)}; !closest || d < dist || (d == dist && (*closest)->isRational() && !b.bound->isRational()) || (d == dist && b.bound < *closest)) {
                dist = d;
                closest = b.bound;
            }
        }
    }
    return closest;
}

Bools::Expr mbp::bool_mbp(const Bools::Expr &t, const ModelPtr& model, const Bools::Var& x) {
    return Subs::build<Bools>(x, Bools::constToExpr(model->get(x)))(t);
}

Bools::Expr mbp::bool_qe(const Bools::Expr &t, const Bools::Var& x) {
    return Subs::build<Bools>(x, top())(t) || Subs::build<Bools>(x, bot())(t);
}
