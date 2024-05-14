#include "intmbp.hpp"
#include "mbputil.hpp"

Bools::Expr int_mbp(const Bools::Expr &t, const Model &model, const Arith::Var x) {
    auto bounds{t->getBounds(x)};
    const auto it{std::find_if(bounds.begin(), bounds.end(), [](const auto &b) {
        return b.kind == BoundKind::Equality;
    })};
    if (it != bounds.end()) {
        auto res{Subs::build<Arith>(x, it->bound)(t)};
        const auto factor{it->bound->getConstantFactor()};
        const auto denom{mp::denominator(factor)};
        if (denom != 1) {
            res = res && bools::mkLit(arith::mkEq(arith::mkMod(it->bound * arith::mkConst(denom), arith::mkConst(denom)), arith::mkConst(0)));
        }
        return res;
    } else {
        auto div{t->getDivisibility(x)};
        Int flcm{1};
        Int mlcm{1};
        for (const auto &b : bounds) {
            flcm = mp::lcm(flcm, mp::denominator(b.bound->getConstantFactor()));
        }
        for (const auto &d : div) {
            flcm = mp::lcm(flcm, d.factor);
            mlcm = mp::lcm(mlcm, d.modulo);
        }
        mlcm = mp::lcm(mlcm, flcm);
        const auto closest{mbp::closest_lower_bound(bounds, model.get<Arith>(), x)};
        if (closest) {
            // (x - closest) % mlcm
            const auto mod{arith::mkMod(arith::mkConst(mlcm) * (x - *closest), arith::mkConst(mlcm))};
            const auto addend{arith::mkConst(model.eval<Arith>(mod))};
            auto res{Subs::build<Arith>(x, *closest + addend)(t)};
            if (mlcm > 1) {
                res = res && bools::mkLit(arith::mkEq(arith::mkMod(*closest * arith::mkConst(mlcm), arith::mkConst(mlcm)), arith::mkConst(0)));
            }
            return res;
        } else {
            const auto mod{arith::mkMod(arith::mkConst(mlcm) * x, arith::mkConst(mlcm))};
            const auto val{arith::mkConst(model.eval<Arith>(mod))};
            return Subs::build<Arith>(x, val)(t->toMinusInfinity(x));
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