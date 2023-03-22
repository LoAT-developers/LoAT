#include "chain.hpp"
#include "substitution.hpp"

Subs computeVarRenaming(const Rule &first, const Rule &second, VariableManager &its) {
    Subs sigma;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (its.isTempVar(x) && first_vars.find(x) != first_vars.end()) {
            if (std::holds_alternative<NumVar>(x)) {
                const auto &var = std::get<NumVar>(x);
                sigma.put<IntTheory>(var, its.addFreshTemporaryVariable<IntTheory>(var.getName()));
            } else if (std::holds_alternative<BoolVar>(x)) {
                const auto &var = std::get<BoolVar>(x);
                sigma.put<BoolTheory>(var, BExpression::buildTheoryLit(its.addFreshTemporaryVariable<BoolTheory>(var.getName())));
            }
        }
    }
    return sigma;
}

Rule Chaining::chain(const Rule &fst, const Rule &snd, VariableManager &its) {
    const auto sigma {computeVarRenaming(fst, snd, its)};
    const auto guard {fst.getGuard() & snd.getGuard()->subs(substitution::compose(sigma, fst.getUpdate()))};
    const auto up {substitution::compose(substitution::concat(snd.getUpdate(), sigma), fst.getUpdate())};
    return Rule(guard, up);
}
