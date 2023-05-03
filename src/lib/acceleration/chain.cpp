#include "chain.hpp"
#include "substitution.hpp"
#include "variable.hpp"

std::pair<Subs, Subs> computeVarRenaming(const Rule &first, const Rule &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    int next_int_var {std::min(first.nextTmpVarIdx<IntTheory>(), second.nextTmpVarIdx<IntTheory>())};
    int next_bool_var {std::min(first.nextTmpVarIdx<BoolTheory>(), second.nextTmpVarIdx<BoolTheory>())};
    for (const auto &x: second.vars()) {
        if (variable::isTempVar(x) && first_vars.find(x) != first_vars.end()) {
            if (std::holds_alternative<NumVar>(x)) {
                const auto &var = std::get<NumVar>(x);
                const NumVar next {next_int_var};
                sigma.put<IntTheory>(var, next);
                inverted.put(next, var);
                --next_int_var;
            } else if (std::holds_alternative<BoolVar>(x)) {
                const auto &var = std::get<BoolVar>(x);
                const BoolVar next {next_bool_var};
                sigma.put<BoolTheory>(var, BExpression::buildTheoryLit(next));
                inverted.put<BoolTheory>(next, BExpression::buildTheoryLit(var));
                --next_bool_var;
            }
        }
    }
    return {sigma, inverted};
}

std::pair<Rule, Subs> Chaining::chain(const Rule &fst, const Rule &snd) {
    const auto [sigma, inverted] {computeVarRenaming(fst, snd)};
    const auto guard {fst.getGuard() & snd.getGuard()->subs(substitution::compose(sigma, fst.getUpdate()))};
    const auto up {substitution::compose(substitution::concat(snd.getUpdate(), sigma), fst.getUpdate())};
    return {Rule(guard, up), inverted};
}
