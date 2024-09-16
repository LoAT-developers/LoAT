#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"

Bools::Expr propagateEquivalences(const Bools::Expr e) {
    const auto subs {impliedEquivalences(e)};
    return subs.empty() ? e : Subs::build<Bools>(subs)(e);
}

Bools::Expr propagateEqualities(const Bools::Expr e, const Preprocess::SymbolAcceptor &allow) {
    const auto subs {e->propagateEqualities(allow)};
    return subs.empty() ? e : Subs::build<Arith>(subs)(e);

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

Bools::Expr Preprocess::preprocessFormula(const Bools::Expr e, const SymbolAcceptor &allow) {
    Bools::Expr res {e};
    auto changed {false};
    do {
        changed = false;
        const auto tmp {::propagateEquivalences(res)};
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
    } while (changed);
    res = simplifyAnd(res);
    do {
        changed = false;
        auto tmp {::propagateEqualities(res, allow)};
        if (tmp != res) {
            changed = true;
            res = simplifyAnd(tmp);
        }
        tmp = integerFourierMotzkin(res, allow);
        if (tmp != res) {
            changed = true;
            res = simplifyAnd(tmp);
        }
    } while (changed);
    return res;
}

std::tuple<Bools::Expr, Renaming, Renaming> Preprocess::chain(const Bools::Expr &fst, const Bools::Expr &snd) {
    Renaming sigma1, inverted1;
    Renaming sigma2, inverted2;
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
        const auto x {Renaming::renameVar(post, sigma1, inverted1)};
        sigma2.insert(pre, x);
        inverted2.insert(x, pre);
    }
    for (const auto &x: second_vars) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            Renaming::renameVar(x, sigma2, inverted2);
        }
    }
    return {sigma1(fst) && sigma2(snd), inverted1, inverted2};
}
