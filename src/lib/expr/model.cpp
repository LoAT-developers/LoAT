#include "model.hpp"

Model::Model() {}
Model::Model(const typename TheTheory::Model &m): m(m) {}

Model Model::unite(const Model &m) const {
    auto res {*this};
    uniteImpl(res, m);
    return res;
}

Subs Model::toSubs() const {
    Subs res;
    toSubsImpl(res);
    return res;
}

Model Model::composeBackwards(const Renaming &subs) const {
    Model res;
    composeBackwardsImpl(subs, res);
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

TVL Model::partialEval(const Lit &lit) const {
    return partialEvalImpl<0>(lit);
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
            return Const{std::get<typename T::Model>(m).at(x)};
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

bool syntacticImplicant(const Bools::Expr e, const Model &m, BoolExprSet &res) {
    if (e->isAnd()) {
        BoolExprSet sub;
        for (const auto &c : e->getChildren()) {
            if (!syntacticImplicant(c, m, sub)) {
                return false;
            }
        }
        res.insert(sub.begin(), sub.end());
        return true;
    } else if (e->isOr()) {
        for (const auto &c : e->getChildren()) {
            if (syntacticImplicant(c, m, res)) {
                return true;
            }
        }
        return false;
    } else {
        if (const auto lit = e->getTheoryLit()) {
            return std::visit(
                Overload{
                    [&](const Arith::Lit &l) {
                        if (l->isNeq()) {
                            const auto lt{arith::mkLt(l->lhs(), arith::mkConst(0))};
                            if (m.eval(lt)) {
                                res.insert(bools::mkLit(lt));
                                return true;
                            } else {
                                const auto gt{arith::mkGt(l->lhs(), arith::mkConst(0))};
                                if (m.eval(gt)) {
                                    res.insert(bools::mkLit(gt));
                                    return true;
                                }
                            }
                        } else if (m.eval(l)) {
                            res.insert(e);
                            return true;
                        }
                        return false;
                    },
                    [&](const auto &l) {
                        if (m.eval(l)) {
                            res.insert(e);
                            return true;
                        }
                        return false;
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

Bools::Expr Model::specialize(const Bools::Expr e) const {
    return e->map([&](const auto &lit) {
        if (partialEval(lit) == TVL::FALSE) {
            return bot();
        } else {
            return bools::mkLit(lit);
        }
    });
}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    return s << e.toSubs();
}
