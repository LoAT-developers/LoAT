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
    do {
        changed = false;
        auto tmp {::propagateEqualities(res, allow)};
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
        tmp = integerFourierMotzkin(res, allow);
        if (tmp != res) {
            changed = true;
            res = tmp;
        }
    } while (changed);
    return res;
}

std::tuple<Bools::Expr, Subs, Subs> Preprocess::chain(const Bools::Expr &fst, const Bools::Expr &snd) {
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
        const auto x {Subs::renameVar(post, sigma1, inverted1)};
        sigma2.put(pre, theory::toExpr(x));
        inverted2.put(x, theory::toExpr(pre));
    }
    for (const auto &x: second_vars) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            Subs::renameVar(x, sigma2, inverted2);
        }
    }
    return {sigma1(fst) && sigma2(snd), inverted1, inverted2};
}
