#include "chain.hpp"
#include "theory.hpp"

Var renameVar(const Var &x, Subs &sigma, Subs &inverted) {
    return theory::apply(x, [&sigma, &inverted](const auto &x) {
        const auto th {theory::theory(x)};
        const auto next {th.next()};
        sigma.put<decltype(th)>(x, th.varToExpr(next));
        inverted.put<decltype(th)>(next, th.varToExpr(x));
        return Var(next);
    });
}

std::pair<Subs, Subs> computeVarRenaming(const Rule &first, const Rule &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            renameVar(x, sigma, inverted);
        }
    }
    return {sigma, inverted};
}

std::pair<Rule, Subs> Chaining::chain(const Rule &fst, const Rule &snd) {
    const auto [sigma, inverted] {computeVarRenaming(fst, snd)};
    const auto guard {fst.getGuard() && theory::subs(snd.getGuard(), theory::compose(sigma, fst.getUpdate()))};
    const auto up {theory::compose(theory::concat(snd.getUpdate(), sigma), fst.getUpdate())};
    return {Rule(guard, up), inverted};
}

std::tuple<Transition, Subs, Subs> Chaining::chain(const Transition &fst, const Transition &snd) {
    Subs sigma1, inverted1;
    Subs sigma2, inverted2;
    auto first_vars {fst.vars()};
    auto var_map {fst.var_map()};
    VarSet post_vars;
    for (const auto &[pre,post]: *var_map) {
        const auto x {renameVar(post, sigma1, inverted1)};
        sigma2.put(pre, theory::toExpr(x));
        inverted2.put(x, theory::toExpr(pre));
        post_vars.insert(post);
    }
    for (const auto &x: snd.vars()) {
        if (theory::isTempVar(x) && first_vars.contains(x) && !post_vars.contains(x)) {
            renameVar(x, sigma2, inverted2);
        }
    }
    return {Transition::build(fst.toBoolExpr()->subs(sigma1) && snd.toBoolExpr()->subs(sigma2), fst.var_map()), inverted1, inverted2};
}
