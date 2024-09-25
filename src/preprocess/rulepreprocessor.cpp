#include "rulepreprocessor.hpp"
#include "rulepreprocessing.hpp"

RulePreprocessor::RulePreprocessor(const ITSPtr its): its(its) {}

std::optional<SmtResult> RulePreprocessor::run() {
    std::vector<RulePtr> remove;
    for (const auto &r : its->getAllTransitions()) {
        SingleRulePreprocessor srp;
        const auto res {srp.run(r)};
        if (r != res) {
            if (res->getGuard() == bot()) {
                remove.push_back(r);
            } else {
                replacements.emplace(res, std::pair(r, srp.get_subs()));
            }
        }
    }
    for (const auto &[replacement, p] : replacements) {
        its->replaceRule(p.first, replacement);
    }
    for (const auto &idx: remove) {
        its->removeRule(idx);
    }
    if (!replacements.empty() || !remove.empty()) {
        return its->isEmpty() ? std::optional{SmtResult::Sat} : std::optional{SmtResult::Unknown};
    } else {
        return {};
    }
}

ITSCex RulePreprocessor::transform_cex(const ITSCex &cex) const {
    return cex.replace_rules(replacements);
}
