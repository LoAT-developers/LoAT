#include "chcpreprocessing.hpp"
#include "theory.hpp"
#include "formulapreprocessing.hpp"
#include "theory.hpp"
#include "intfm.hpp"
#include "config.hpp"
#include "impliedequivalences.hpp"

#include <unordered_set>
#include <numeric>

std::optional<Clause> propagateEquivalences(const Clause &rule) {
    const auto subs{impliedEquivalences(rule.get_constraint())};
    if (subs.empty()) {
        return {};
    } else {
        const auto res {rule.subs(Subs::build<Bools>(subs))};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "propagated equivalences: " << res << std::endl;
        }
        return res;
    }
}

std::optional<Clause> propagateEqualitiesImpl(const Clause &rule, const Preprocess::SymbolAcceptor &allow) {
    const auto subs{rule.get_constraint()->propagateEqualities(allow)};
    if (subs.empty()) {
        return {};
    } else {
        const auto res {rule.subs(Subs::build<Arith>(subs))};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "extracted implied equalities: " << res << std::endl;
        }
        return res;
    }
}

std::optional<Clause> propagateEqualities(const Clause &rule) {
    return propagateEqualitiesImpl(rule, theory::isTempVar);
}

VarSet collectVarsInUpdateRhs(const Clause &rule) {
    VarSet varsInUpdate;
    if (const auto &conc {rule.get_conclusion()}) {
        for (const auto &e: conc->get_args()) {
            theory::collectVars(e, varsInUpdate);
        }
    }
    return varsInUpdate;
}

std::optional<Clause> propagateEqualitiesPickily(const Clause &rule) {
    VarSet varsInUpdate {collectVarsInUpdateRhs(rule)};
    Preprocess::SymbolAcceptor isTempInUpdate{[&](const Var &sym) {
        return theory::isTempVar(sym) && varsInUpdate.contains(sym);
    }};
    return propagateEqualitiesImpl(rule, isTempInUpdate);
}

std::optional<Clause> integerFourierMotzkin(const Clause &rule) {
    VarSet varsInUpdate {collectVarsInUpdateRhs(rule)};
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    const auto new_guard{integerFourierMotzkin(rule.get_constraint(), isTempOnlyInGuard)};
    if (new_guard == rule.get_constraint()) {
        return {};
    } else {
        Clause res {rule};
        res.set_constraint(new_guard);
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "eliminated temporary variables: " << res << std::endl;
        }
        return res;
    }
}

std::optional<Clause> eliminateArithVars(const Clause &rule) {
    if (const auto res{propagateEqualitiesPickily(rule)}) {
        return res;
    }
    if (const auto res{propagateEqualities(rule)}) {
        return res;
    }
    return integerFourierMotzkin(rule);
}

std::optional<Clause> Preprocess::preprocess(const Clause &rule) {
    auto current {rule};
    auto success {false};
    if (const auto res{propagateEquivalences(current)}) {
        current = *res;
        success = true;
    }
    auto changed {false};
    do {
        changed = false;
        if (const auto res {eliminateArithVars(current)}) {
            changed = true;
            success = true;
            current = *res;
        }
    } while (changed);
    return success ? current: std::optional<Clause>{};
}


Clause Preprocess::chain(const Clause &c1, const Clause &c2) {
    assert(c1.get_conclusion() && c1.get_conclusion()->get_pred() == c2.get_premise()->get_pred());
    Subs subs1;
    for (const auto &x : c2.vars()) {
        subs1.put(x, theory::toExpr(theory::next(x)));
    }
    const Clause c3{c2.subs(subs1)};
    Subs subs2;
    const auto &c1_args{c1.get_conclusion()->get_args()};
    const auto &c3_args{c3.get_premise()->get_args()};
    for (unsigned i = 0; i < c3_args.size(); ++i) {
        subs2.put(c3_args[i], c1_args[i]);
    }
    Clause res;
    if (const auto p{c1.get_premise()}) {
        res.set_premise(p->subs(subs2));
    }
    if (const auto c{c3.get_conclusion()}) {
        res.set_conclusion(c->subs(subs2));
    }
    res.set_constraint(subs2(c1.get_constraint()) && subs2(c3.get_constraint()));
    return res;
}
