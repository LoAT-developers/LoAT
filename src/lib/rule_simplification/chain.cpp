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
    const auto guard {fst.getGuard() && sigma.compose(fst.getUpdate())(snd.getGuard())};
    const auto up {snd.getUpdate().concat(sigma).compose(fst.getUpdate())};
    return {Rule(guard, up), inverted};
}

std::tuple<Bools::Expr, Subs, Subs> Chaining::chain(const Bools::Expr &fst, const Bools::Expr &snd) {
    Subs sigma1, inverted1;
    Subs sigma2, inverted2;
    auto first_vars {fst->vars()};
    auto second_vars {snd->vars()};
    VarSet post_vars;
    for (const auto &vars : {first_vars, second_vars}) {
        for (const auto &x : vars) {
            if (theory::isProgVar(x)) {
                post_vars.insert(theory::postVar(x));
            } else if (theory::isPostVar(x)) {
                post_vars.insert(x);
            }
        }
    }
    for (const auto &post: post_vars) {
        const auto pre {theory::progVar(post)};
        const auto x {renameVar(post, sigma1, inverted1)};
        sigma2.put(pre, theory::toExpr(x));
        inverted2.put(x, theory::toExpr(pre));
    }
    for (const auto &x: second_vars) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            renameVar(x, sigma2, inverted2);
        }
    }
    return {sigma1(fst) && sigma2(snd), inverted1, inverted2};
}
