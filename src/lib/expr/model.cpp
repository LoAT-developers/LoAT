#include "model.hpp"

Model::Model() {}
Model::Model(const typename TheTheory::Model &m): m(m) {}

Subs Model::toSubs() const {
    Subs res;
    toSubsImpl(res);
    return res;
}

Model Model::composeBackwards(const Subs &subs) const {
    Model res;
    composeBackwardsImpl(subs, res);
    return res;
}

bool Model::eval(const Lit &lit) const {
    return evalImpl<0>(lit);
}

Const Model::eval(const Expr &e) const {
    return std::visit(
        Overload {
            [&](const auto &e) {
                using T = decltype(theory::theory(e));
                return Const{eval<T>(e)};
            }
        }, e);
}

Const Model::get(const Var &var) const {
    return theory::apply(
        var,
        [&](const auto& x) {
            using T = decltype(theory::theory(x));
            return Const{std::get<typename T::Model>(m)[x]};
        });
}
bool Model::contains(const Var &var) const {
    return theory::apply(
        var,
        [&](const auto& x) {
            using T = decltype(theory::theory(x));
            return contains<T>(std::get<typename T::Var>(var));
        });
}

void syntacticImplicant(const Bools::Expr e, const Model &m, BoolExprSet &res) {
    if (e->isAnd() || e->isOr()) {
        for (const auto &c: e->getChildren()) {
            syntacticImplicant(c, m, res);
        }
    } else {
        if (const auto lit = e->getTheoryLit()) {
            std::visit(
                Overload{
                    [&](const Arith::Lit &l) {
                        if (l->isNeq()) {
                            const auto lt{arith::mkLt(l->lhs(), arith::mkConst(0))};
                            if (m.eval(lt)) {
                                res.insert(bools::mkLit(lt));
                            } else {
                                const auto gt{arith::mkGt(l->lhs(), arith::mkConst(0))};
                                if (m.eval(gt)) {
                                    res.insert(bools::mkLit(gt));
                                }
                            }
                        } else if (m.eval(l)) {
                            res.insert(e);
                        }
                    },
                    [&](const auto &l) {
                        if (m.eval(l)) {
                            res.insert(e);
                        }
                    }},
                *lit);
        } else {
            throw std::invalid_argument("unknown kind of BoolExpr");
        }
    }
}

Bools::Expr Model::syntacticImplicant(const Bools::Expr e) const {
    assert(eval<Bools>(e));
    BoolExprSet res;
    ::syntacticImplicant(e, *this, res);
    return bools::mkAnd(res);
}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    return s << e.toSubs();
}
