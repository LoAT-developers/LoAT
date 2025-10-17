#include "mbputil.hpp"

std::optional<Arith::Expr> mbp::closest_lower_bound(const linked_hash_set<Bound> &bounds, const ModelPtr& model, const Arith::Var &x) {
    std::optional<Arith::Expr> closest;
    Rational dist;
    const auto val {model->eval(x)};
    for (const auto & [bound, kind]: bounds) {
        if (kind == BoundKind::Lower) {
            VarSet vars;
            vars.get<Arith::Var>() = bound->vars();
            const auto b_val{model->evalToRational(bound)};
            const auto d{mp::abs(val - b_val)};
            if (!closest || d < dist || (d == dist && (*closest)->isRational() && !bound->isRational()) || (d == dist && bound < *closest)) {
                dist = d;
                closest = bound;
            }
        }
    }
    return closest;
}

Bools::Expr mbp::bool_mbp(const Bools::Expr &t, const ModelPtr& model, const Bools::Var& x) {
    return t->subs(BoolSubs(x, Bools::constToExpr(model->get(x))));
}

Bools::Expr mbp::bool_qe(const Bools::Expr &t, const Bools::Var& x) {
    return t->subs(BoolSubs(x, top())) || t->subs(BoolSubs(x, bot()));
}
