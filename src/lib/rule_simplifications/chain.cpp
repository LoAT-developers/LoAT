#include "chain.hpp"
#include "expr.hpp"

std::pair<Subs, Subs> computeVarRenaming(const Rule &first, const Rule &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (expr::isTempVar(x) && first_vars.contains(x)) {
            if (std::holds_alternative<NumVar>(x)) {
                const auto &var = std::get<NumVar>(x);
                const NumVar next {NumVar::next()};
                sigma.put<IntTheory>(var, next);
                inverted.put(next, var);
            } else if (std::holds_alternative<BoolVar>(x)) {
                const auto &var = std::get<BoolVar>(x);
                const BoolVar next {BoolVar::next()};
                sigma.put<BoolTheory>(var, BExpression::buildTheoryLit(BoolLit(next)));
                inverted.put<BoolTheory>(next, BExpression::buildTheoryLit(BoolLit(var)));
            }
        }
    }
    return {sigma, inverted};
}

std::pair<Rule, Subs> Chaining::chain(const Rule &fst, const Rule &snd) {
    const auto [sigma, inverted] {computeVarRenaming(fst, snd)};
    const auto guard {fst.getGuard() & snd.getGuard()->subs(expr::compose(sigma, fst.getUpdate()))};
    const auto up {expr::compose(expr::concat(snd.getUpdate(), sigma), fst.getUpdate())};
    return {Rule(guard, up), inverted};
}
