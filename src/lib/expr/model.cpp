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

void syntacticImplicant(const BoolExprPtr e, const Model &m, BoolExprSet &res) {
    if (e->isAnd() || e->isOr()) {
        for (const auto &c: e->getChildren()) {
            syntacticImplicant(c, m, res);
        }
    } else {
        const auto lit = e->getTheoryLit();
        if (lit) {
            if (m.eval(*lit)) {
                res.insert(e);
            }
        } else {
            throw std::invalid_argument("unknown kind of BoolExpr");
        }
    }
}

BoolExprPtr Model::syntacticImplicant(const BoolExprPtr e) const {
    BoolExprSet res;
    ::syntacticImplicant(e, *this, res);
    return bools::mkAnd(res);
}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    return s << e.toSubs();
}
