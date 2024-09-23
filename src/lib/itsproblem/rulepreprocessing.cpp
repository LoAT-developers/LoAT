#include "rulepreprocessing.hpp"
#include "theory.hpp"
#include "formulapreprocessing.hpp"
#include "theory.hpp"
#include "intfm.hpp"
#include "config.hpp"
#include "impliedequivalences.hpp"

#include <unordered_set>
#include <numeric>

std::optional<RulePtr> propagateEquivalences(const RulePtr &rule) {
    const auto subs{impliedEquivalences(rule->getGuard())};
    if (subs.empty()) {
        return {};
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "propagated equivalences: " << subs << std::endl;
        }
        return rule->subs(Subs::build<Bools>(subs));
    }
}

std::optional<RulePtr> eliminateIdentities(const RulePtr &rule) {
    VarSet remove;
    for (const auto &[x, v] : rule->getUpdate()) {
        if (TheTheory::varToExpr(x) == v) {
            remove.insert(x);
        }
    }
    if (remove.empty()) {
        return {};
    } else {
        auto new_update{rule->getUpdate()};
        new_update.erase(remove);
        const auto res{rule->withUpdate(new_update)};
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "removed identity updates: " << res << std::endl;
        }
        return res;
    }
}

std::optional<RulePtr> propagateEqualitiesImpl(const RulePtr &rule, const Preprocess::SymbolAcceptor &allow) {
    const auto subs{rule->getGuard()->propagateEqualities(allow)};
    if (subs.empty()) {
        return {};
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "extracted implied equalities: " << subs << std::endl;
        }
        return rule->subs(Subs::build<Arith>(subs));
    }
}

std::optional<RulePtr> propagateEqualities(const RulePtr &rule) {
    return propagateEqualitiesImpl(rule, theory::isTempVar);
}

std::optional<RulePtr> propagateEqualitiesPickily(const RulePtr &rule) {
    auto varsInUpdate{rule->getUpdate().coDomainVars()};
    Preprocess::SymbolAcceptor isTempInUpdate{[&](const Var &sym) {
        return theory::isTempVar(sym) && varsInUpdate.contains(sym);
    }};
    return propagateEqualitiesImpl(rule, isTempInUpdate);
}

std::optional<RulePtr> integerFourierMotzkin(const RulePtr &rule) {
    auto varsInUpdate{rule->getUpdate().coDomainVars()};
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    const auto new_guard{integerFourierMotzkin(rule->getGuard(), isTempOnlyInGuard)};
    if (new_guard == rule->getGuard()) {
        return {};
    } else {
        return rule->withGuard(new_guard);
    }
}

std::optional<RulePtr> eliminateArithVars(const RulePtr &rule) {
    if (const auto res{propagateEqualities(rule)}) {
        return res;
    }
    return integerFourierMotzkin(rule);
}

std::optional<RulePtr> Preprocess::preprocessRule(const RulePtr &rule) {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing " << rule << std::endl;
    }
    auto current {rule};
    auto success {false};
    if (const auto g{Preprocess::simplifyAnd(current->getGuard())}; g != current->getGuard()) {
        success = true;
        current = current->withGuard(g);
    }
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
            current = (*res)->withGuard(Preprocess::simplifyAnd((*res)->getGuard()));
            changed = true;
        }
    } while (changed);
    if (const auto res {eliminateIdentities(current)}) {
        current = *res;
        success = true;
    }
    if (success && Config::Analysis::doLogPreproc()) {
        std::cout << "got " << current << std::endl;
    }
    return success ? current: std::optional<RulePtr>{};
}

RulePtr Preprocess::chain(const std::vector<RulePtr> &rules) {
    std::vector<Bools::Expr> guards;
    Subs up;
    for (const auto &r: rules) {
        guards.push_back(up(r->getGuard()));
        up = r->getUpdate().compose(up);
    }
    return Rule::mk(bools::mkAnd(guards), up);
}
