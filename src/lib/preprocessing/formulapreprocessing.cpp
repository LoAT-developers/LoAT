#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"
#include "config.hpp"

Bools::Expr propagateEquivalences(const Bools::Expr e) {
    if (const auto subs {impliedEquivalences(e)}; subs.empty()) {
        return e;
    } else {
        return subs(e);
    }
}

Bools::Expr propagateEqualities(const Bools::Expr e, const std::function<bool(const Var &)> &allow) {
    if (const auto subs {e->propagateEqualities(allow)}; subs.empty()) {
        return e;
    } else {
        return Subs::build<Arith>(subs)(e);
    }
}

Bools::Expr Preprocess::simplifyAnd(const Bools::Expr e) {
    if (e->isConjunction()) {
        auto lits{e->lits()};
        if (ArithLit::simplifyAnd(lits.get<Arith::Lit>())) {
            return bools::mkAndFromLits(lits);
        }
    }
    return e;
}

Bools::Expr Preprocess::preprocessFormula(Bools::Expr e, const std::function<bool(const Var &)> &allow) {
    for (const auto prop = propagateEquivalences(e); prop != e;) {
        e = prop;
    }
    e = Preprocess::simplifyAnd(e);
    bool changed;
    do {
        changed = false;
        if (const auto prop {propagateEqualities(e, allow)}; prop != e) {
            changed = true;
            e = Preprocess::simplifyAnd(prop);
        }
        if (const auto fm_res {integerFourierMotzkin(e, allow)}; fm_res != e) {
            changed = true;
            e = Preprocess::simplifyAnd(fm_res);
        }
    } while (changed);
    return e;
}

std::tuple<Bools::Expr, Renaming, Renaming> Preprocess::chain(const Bools::Expr &fst, const Bools::Expr &snd) {
    Renaming sigma1;
    Renaming sigma2;
    auto first_vars {fst->vars()};
    auto second_vars {snd->vars()};
    VarSet post_vars;
    for (const auto &vars : {first_vars, second_vars}) {
        for (const auto &x : vars) {
            theory::apply(x, [&](const auto &x) {
                if (x->isProgVar()) {
                    post_vars.insert(x->postVar());
                } else if (x->isPostVar()) {
                    post_vars.insert(x);
                }
            });
        }
    }
    for (const auto &post: post_vars) {
        theory::apply(post, [&](const auto &post) {
            using T = decltype(theory::theory(post));
            const auto pre {post->progVar()};
            const auto x {Renaming::renameVar<T>(post, sigma1)};
            sigma2.insert<T>(pre, x);
        });
    }
    for (const auto &x: second_vars) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            Renaming::renameVar(x, sigma2);
        }
    }
    return {sigma1(fst) && sigma2(snd), sigma1.invert(), sigma2.invert()};
}
