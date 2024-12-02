#include "realmbp.hpp"
#include "mbputil.hpp"

Bools::Expr real_mbp(const Bools::Expr &t, const Model &model, const Arith::Var x) {
    auto bounds {t->getBounds(x)};
    const auto it {std::find_if(bounds.begin(), bounds.end(), [](const auto &b) {
        return b.kind == BoundKind::Equality;
    })};
    if (it != bounds.end()) {
        return Subs::build<Arith>(x, it->bound)(t);
    } else {
        const auto closest {mbp::closest_lower_bound(bounds, model.get<Arith>(), x)};
        if (closest) {
            return Subs::build<Arith>(x, *closest)(t);
        } else {
            return t->toMinusInfinity(x);
        }
    }
}

Bools::Expr real_mbp(const Bools::Expr &t, const Model &model, const Var &x) {
    return std::visit(
        Overload{
            [&](const Bools::Var x) {
                return mbp::bool_mbp(t, model, x);
            },
            [&](const Arith::Var x) {
                const auto res {real_mbp(t, model, x)};
                assert(res != bot());
                return res;
            }
        }, x);
}

Bools::Expr mbp::real_mbp(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var&)> &eliminate) {
    Bools::Expr res {trans};
    for (const auto &x: trans->vars()) {
        if (eliminate(x)) {
            res = ::real_mbp(res, model, x);
        }
    }
    return res;
}