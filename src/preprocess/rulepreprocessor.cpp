#include "rulepreprocessor.hpp"
#include "rulepreprocessing.hpp"

RulePreprocessor::RulePreprocessor(const ITSPtr& its): its(its) {}

std::optional<SmtResult> RulePreprocessor::run() {
    std::vector<RulePtr> remove;
    for (const auto &r : its->getAllTransitions()) {
        if (const auto res {Preprocess::preprocessRule(r)}; r != res) {
            if (res->getGuard() == bot()) {
                remove.push_back(r);
            } else {
                replacements.emplace(res, r);
            }
        }
    }
    for (const auto &[replacement, orig] : replacements) {
        its->replaceRule(orig, replacement);
    }
    for (const auto &idx: remove) {
        its->removeRule(idx);
    }
    if (!replacements.empty() || !remove.empty()) {
        return its->isEmpty() ? std::optional{SmtResult::Sat} : std::optional{SmtResult::Unknown};
    }
    return {};
}
