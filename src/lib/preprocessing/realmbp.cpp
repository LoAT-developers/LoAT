#include "realmbp.hpp"
#include "mbputil.hpp"
#include "smtfactory.hpp"

void real_mbp(Conjunction &t, const Model &model, const Arith::Var x) {
    auto &lits {t.get<Arith::Lit>()};
    linked_hash_set<Bound> bounds;
    ArithSubs subs;
    for (auto it = lits.begin(); it != lits.end();) {
        const auto &lit {*it};
        assert(lit->isLinear({{x}}));
        if (const auto eq{lit->getEquality(x)}) {
            it = lits.erase(it);
            subs.put(x, *eq);
            break;
        } else {
            lit->getBounds(x, bounds);
            ++it;
        }
    }
    if (subs.empty()) {
        if (const auto closest {mbp::closest_lower_bound(bounds, model.get<Arith>(), x)}) {
            subs.put(x, *closest);
        }
    }
    std::vector<Arith::Lit> to_add;
    for (auto it = lits.begin(); it != lits.end();) {
        const auto &lit {*it};
        if (lit->has(x)) {
            if (!subs.empty()) {
                to_add.emplace_back(lit->subs(subs));
            }
            it = lits.erase(it);
        } else {
            ++it;
        }
    }
    for (const auto &lit: to_add) {
        lits.insert(lit);
    }
}

Conjunction mbp::real_mbp(const Conjunction &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    Conjunction res{trans};
    for (const auto &x : trans.vars()) {
        if (eliminate(x)) {
            std::visit(
                Overload{
                    [&](const Bools::Var x) {
                        mbp::bool_mbp(res, model, x);
                    },
                    [&](const Arith::Var x) {
                        real_mbp(res, model, x);
                    }},
                x);
        }
    }
    return res;
}
