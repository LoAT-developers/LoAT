#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"

Bools::Expr propagateEquivalences(const Bools::Expr& e) {
    if (const auto subs {impliedEquivalences(e)}; subs.empty()) {
        return e;
    } else {
        return subs(e);
    }
}

Bools::Expr propagateEqualities(const Bools::Expr& e, const std::function<bool(const Var &)> &allow) {
    if (const auto subs {e->propagateEqualities(allow)}; subs.empty()) {
        return e;
    } else {
        return e->subs(subs);
    }
}

Bools::Expr Preprocess::simplifyAnd(const Bools::Expr& e) {
    if (e->isConjunction()) {
        if (auto lits{e->lits()}; ArithLit::simplifyAnd(lits.get<Arith::Lit>())) {
            return bools::mkAnd(lits);
        }
    }
    return e;
}

Bools::Expr Preprocess::preprocessFormula(Bools::Expr e, const std::function<bool(const Var &)> &allow) {
    for (const auto prop = propagateEquivalences(e); prop != e;) {
        e = prop;
    }
    e = simplifyAnd(e);
    bool changed;
    do {
        changed = false;
        if (const auto prop {propagateEqualities(e, allow)}; prop != e) {
            changed = true;
            e = simplifyAnd(prop);
        }
        if (const auto fm_res {integerFourierMotzkin(e, allow)}; fm_res != e) {
            changed = true;
            e = simplifyAnd(fm_res);
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
            if (theory::isProgVar(x)) {
                post_vars.insert(theory::postVar(x));
            } else if (theory::isPostVar(x)) {
                post_vars.insert(x);
            }
        }
    }
    for (const auto &post: post_vars) {
        const auto pre {theory::progVar(post)};
        const auto x {Renaming::renameVar(post, sigma1)};
        sigma2.insert(pre, x);
    }
    for (const auto &x: second_vars) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            Renaming::renameVar(x, sigma2);
        }
    }
    return {fst->renameVars(sigma1) && snd->renameVars(sigma2), sigma1.invert(), sigma2.invert()};
}
