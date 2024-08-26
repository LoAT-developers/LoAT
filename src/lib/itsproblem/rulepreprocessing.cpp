#include "rulepreprocessing.hpp"
#include "theory.hpp"
#include "formulapreprocessing.hpp"
#include "theory.hpp"
#include "intfm.hpp"
#include "config.hpp"
#include "impliedequivalences.hpp"

#include <unordered_set>
#include <numeric>

std::optional<Rule> propagateEquivalences(const Rule &rule) {
    const auto subs{impliedEquivalences(rule.getGuard())};
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

std::optional<Rule> eliminateIdentities(const Rule &rule) {
    VarSet remove;
    for (const auto &[x, v] : rule.getUpdate()) {
        if (TheTheory::varToExpr(x) == v) {
            remove.insert(x);
        }
    }
    if (remove.empty()) {
        return {};
    } else {
        auto new_update {rule.getUpdate()};
        new_update.erase(remove);
        const auto res {rule.withUpdate(new_update)};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed identity updates: " << res << std::endl;
        }
        return res;
    }
}

std::optional<Rule> propagateEqualitiesImpl(const Rule &rule, const Preprocess::SymbolAcceptor &allow) {
    const auto subs{rule.getGuard()->propagateEqualities(allow)};
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

std::optional<Rule> propagateEqualities(const Rule &rule) {
    return propagateEqualitiesImpl(rule, theory::isTempVar);
}

std::optional<Rule> propagateEqualitiesPickily(const Rule &rule) {
    auto varsInUpdate{rule.getUpdate().coDomainVars()};
    Preprocess::SymbolAcceptor isTempInUpdate{[&](const Var &sym) {
        return theory::isTempVar(sym) && varsInUpdate.contains(sym);
    }};
    return propagateEqualitiesImpl(rule, isTempInUpdate);
}

std::optional<Rule> integerFourierMotzkin(const Rule &rule) {
    auto varsInUpdate{rule.getUpdate().coDomainVars()};
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    const auto new_guard{integerFourierMotzkin(rule.getGuard(), isTempOnlyInGuard)};
    if (new_guard == rule.getGuard()) {
        return {};
    } else {
        const auto res {rule.withGuard(new_guard)};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "eliminated temporary variables: " << res << std::endl;
        }
        return res;
    }
}

std::optional<Rule> eliminateArithVars(const Rule &rule) {
    if (const auto res{propagateEqualitiesPickily(rule)}) {
        return res;
    }
    if (const auto res{propagateEqualities(rule)}) {
        return res;
    }
    return integerFourierMotzkin(rule);
}

std::optional<Rule> Preprocess::preprocessRule(const Rule &rule) {
    auto current {rule};
    auto success {false};
    if (const auto res{propagateEquivalences(current)}) {
        current = *res;
        success = true;
    }
    if (const auto res {eliminateIdentities(current)}) {
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
    return success ? current: std::optional<Rule>{};
}

std::pair<Subs, Subs> computeVarRenaming(const Rule &first, const Rule &second) {
    Subs sigma, inverted;
    auto first_vars {first.vars()};
    for (const auto &x: second.vars()) {
        if (theory::isTempVar(x) && first_vars.contains(x)) {
            Subs::renameVar(x, sigma, inverted);
        }
    }
    return {sigma, inverted};
}

std::pair<Rule, Subs> Preprocess::chain(const Rule &fst, const Rule &snd) {
    const auto [sigma, inverted] {computeVarRenaming(fst, snd)};
    const auto guard {fst.getGuard() && sigma.compose(fst.getUpdate())(snd.getGuard())};
    const auto up {snd.getUpdate().concat(sigma).compose(fst.getUpdate())};
    return {Rule(guard, up), inverted};
}
