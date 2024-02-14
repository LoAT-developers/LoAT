#include "chain.hpp"
#include "expr.hpp"

void renameVar(const Var &x, Subs &sigma, Subs &inverted) {
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

std::pair<Subs, Subs> computeVarRenaming(const Rule &first, const Rule &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (expr::isTempVar(x) && first_vars.contains(x)) {
            renameVar(x, sigma, inverted);
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

std::pair<Subs, Subs> computeFirstRenaming(const Transition &first, const Transition &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    auto vm {first.var_map()};
    for (const auto &[_,x]: *vm) {
        if (first_vars.contains(x)) {
            renameVar(x, sigma, inverted);
        }
    }
    return {sigma, inverted};
}

std::pair<Subs, Subs> computeSecondRenaming(const Transition &first, const Transition &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    auto vm {first.var_map()};
    for (const auto &x: second.vars()) {
        if ((expr::isTempVar(x) && first_vars.contains(x)) || vm->contains(x)) {
            renameVar(x, sigma, inverted);
        }
    }
    return {sigma, inverted};
}

std::tuple<Transition, Subs, Subs> Chaining::chain(const Transition &fst, const Transition &snd) {
    const auto [sigma1, inverted1] {computeFirstRenaming(fst, snd)};
    const auto [sigma2, inverted2] {computeSecondRenaming(fst, snd)};
    return {Transition(fst.toBoolExpr()->subs(sigma1) & snd.toBoolExpr()->subs(sigma2), fst.var_map()), inverted1, inverted2};
}
