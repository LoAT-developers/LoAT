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

typename TheTheory::Const Model::eval(const ThExpr &e) const {
    return std::visit(
        Overload {
            [&](const auto &e) {
                using T = decltype(theory::theory(e));
                return TheTheory::Const{eval<T>(e)};
            }
        }, e);
}

TheTheory::Const Model::get(const Var &var) const {
    return theory::apply(
        var,
        [&](const auto& x) {
            using T = decltype(theory::theory(x));
            return TheTheory::Const{std::get<typename T::Model>(m)[x]};
        });
}

void syntacticImplicant(const BoolExpr e, const Model &m, linked_hash_set<BoolExpr> &res) {
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

BoolExpr Model::syntacticImplicant(const BoolExpr e) const {
    linked_hash_set<BoolExpr> res;
    ::syntacticImplicant(e, *this, res);
    return bools::mkAnd(res);
}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    return s << e.toSubs();
}
