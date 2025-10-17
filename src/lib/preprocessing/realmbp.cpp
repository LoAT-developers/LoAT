#include "realmbp.hpp"
#include "mbputil.hpp"
#include "smtfactory.hpp"

Bools::Expr real_mbp(const Bools::Expr &t, const ModelPtr &model, const Arith::Var& x) {
    auto bounds {t->getBounds(x)};
    const auto it {std::ranges::find_if(bounds, [](const auto &b) {
        return b.kind == BoundKind::Equality;
    })};
    if (it != bounds.end()) {
        return t->subs(ArithSubs{{x, it->bound}});
    }
    if (const auto closest {mbp::closest_lower_bound(bounds, model, x)}) {
        return t->subs(ArithSubs{{x, *closest}});
    }
    return t->toMinusInfinity(x);
}

Bools::Expr real_mbp(const Bools::Expr &t, const ModelPtr &model, const Var &x) {
    return std::visit(
        Overload{
            [&](const Bools::Var& x) {
                return mbp::bool_mbp(t, model, x);
            },
            [&](const Arith::Var& x) {
                const auto res {real_mbp(t, model, x)};
                assert(res != bot());
                return res;
            },
            [](const Arrays<Arith>::Var&) -> Bools::Expr {
                throw std::invalid_argument("real mbp does not support arrays");
            }
        }, x);
}

Bools::Expr mbp::real_mbp(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Var&)> &eliminate) {
    Bools::Expr res {trans};
    for (const auto &x: trans->vars()) {
        if (eliminate(x)) {
            res = ::real_mbp(res, model, x);
        }
    }
    return res;
}

Bools::Expr mbp::real_qe(const Bools::Expr &t, const std::function<bool(const Var &)> &eliminate) {
    const auto solver {SmtFactory::modelBuildingSolver(QF_LA)};
    solver->add(t);
    std::vector<Bools::Expr> disjuncts;
    SmtResult smt_res;
    while ((smt_res = solver->check()) == SmtResult::Sat) {
        const auto model {solver->model()};
        const auto next {real_mbp(model->syntacticImplicant(t), model, eliminate)};
        disjuncts.push_back(next);
        solver->add(!next);
    }
    assert(smt_res == SmtResult::Unsat);
    return bools::mkOr(disjuncts);
}
