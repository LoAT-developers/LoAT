#include "formulapreprocessing.hpp"
#include "subs.hpp"
#include "impliedequivalences.hpp"
#include "intfm.hpp"
#include "config.hpp"

bool FormulaPreprocessor::propagateEquivalences() {
    if (const auto subs {impliedEquivalences(e)}; subs.empty()) {
        return false;
    } else {
        e = subs(e);
        return true;
    }
}

bool FormulaPreprocessor::propagateEqualities() {
    if (const auto subs {e->propagateEqualities(allow)}; subs.empty()) {
        return false;
    } else {
        e = Subs::build<Arith>(subs)(e);
        return true;
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

FormulaPreprocessor::FormulaPreprocessor(const std::function<bool(const Var &)> &allow): allow(allow) {}

Bools::Expr FormulaPreprocessor::run(const Bools::Expr in) {
    e = in;
    auto changed {false};
    while (propagateEquivalences());
    e = Preprocess::simplifyAnd(e);
    do {
        if ((changed = propagateEqualities())) {
            e = Preprocess::simplifyAnd(e);
        }
        IntegerFourierMotzkin intfm(allow);
        if (const auto fm_res {intfm.run(e)}; fm_res != e) {
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
    return {sigma1(fst) && sigma2(snd), sigma1.invert(), sigma2.invert()};
}
