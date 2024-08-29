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
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "propagated equivalences: " << subs << std::endl;
        }
        return rule.subs(Subs::build<Bools>(subs));
    }
}

std::optional<Rule> propagateEqualitiesImpl(const Rule &rule, const Preprocess::SymbolAcceptor &allow) {
    const auto subs{rule.getGuard()->propagateEqualities(allow)};
    if (subs.empty()) {
        return {};
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "extracted implied equalities: " << subs << std::endl;
        }
        return rule.subs(Subs::build<Arith>(subs));
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
        return rule.withGuard(new_guard);
    }
}

std::optional<Rule> eliminateArithVars(const Rule &rule) {
    // this makes only sense for acceleraion-based techniques
    if (Config::Analysis::engine == Config::Analysis::ABMC || Config::Analysis::engine == Config::Analysis::ADCL) {
        if (const auto res{propagateEqualitiesPickily(rule)}) {
            return res;
        }
    }
    if (const auto res{propagateEqualities(rule)}) {
        return res;
    }
    return integerFourierMotzkin(rule);
}

std::optional<Rule> Preprocess::preprocessRule(const Rule &rule) {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing " << rule << std::endl;
    }
    auto current {rule};
    auto success {false};
    auto changed{false};
    do {
        changed = false;
        if (const auto res{propagateEquivalences(current)}) {
            success = true;
            current = *res;
            changed = true;
        }
        if (const auto res{eliminateArithVars(current)}) {
            success = true;
            current = *res;
            changed = true;
        }
    } while (changed);
    if (success && Config::Analysis::doLogPreproc()) {
        std::cout << "got " << current << std::endl;
    }
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
