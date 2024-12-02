#include "rulepreprocessing.hpp"
#include "theory.hpp"
#include "formulapreprocessing.hpp"
#include "theory.hpp"
#include "intfm.hpp"
#include "config.hpp"
#include "impliedequivalences.hpp"

#include <unordered_set>
#include <numeric>

RulePtr propagateEquivalences(const RulePtr &rule) {
    const auto subs{impliedEquivalences(rule->getGuard())};
    if (subs.empty()) {
        return rule;
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

RulePtr propagateEqualities(const RulePtr &rule) {
    const auto subs{rule->getGuard()->propagateEqualities(theory::isTempVar)};
    if (subs.empty()) {
        return rule;
    } else {
        if (Config::Analysis::doLogPreproc()) {
            std::cout << "extracted implied equalities: " << subs << std::endl;
        }
        return rule->subs(Subs::build<Arith>(subs));
    }
}

RulePtr integerFourierMotzkin(const RulePtr &rule) {
    auto varsInUpdate{rule->getUpdate().coDomainVars()};
    auto isTempOnlyInGuard = [&](const Var &sym) {
        return theory::isTempVar(sym) && !varsInUpdate.contains(sym);
    };
    if (const auto new_guard {integerFourierMotzkin(rule->getGuard(), isTempOnlyInGuard)}; new_guard == rule->getGuard()) {
        return rule;
    } else {
        return rule->withGuard(new_guard);
    }
}

RulePtr eliminateArithVars(const RulePtr &rule) {
    if (const auto res{propagateEqualities(rule)}; res != rule) {
        return res;
    }
    return integerFourierMotzkin(rule);
}

RulePtr Preprocess::preprocessRule(const RulePtr &rule) {
    if (Config::Analysis::doLogPreproc()) {
        std::cout << "preprocessing " << rule << std::endl;
    }
    auto current {rule};
    if (const auto g{Preprocess::simplifyAnd(current->getGuard())}; g != current->getGuard()) {
        current = current->withGuard(g);
    }
    auto changed{false};
    do {
        const auto prop {propagateEquivalences(current)};
        changed = prop != current;
        current = eliminateArithVars(prop);
        if (current != prop) {
            changed = true;
            current = current->withGuard(Preprocess::simplifyAnd(current->getGuard()));
        }
    } while (changed);
    if (const auto res {eliminateIdentities(current)}) {
        current = *res;
    }
    if (current != rule && Config::Analysis::doLogPreproc()) {
        std::cout << "got " << current << std::endl;
    }
    return current;
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
