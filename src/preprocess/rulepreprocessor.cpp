#include "rulepreprocessor.hpp"

#include "rulepreprocessing.hpp"

#include <utility>

RulePreprocessor::RulePreprocessor(ITSPtr its): its(std::move(its)) {}

std::optional<SmtResult> RulePreprocessor::run() {
    std::vector<RulePtr> remove;
    replacements.emplace_back();
    for (const auto &r : its->getAllTransitions()) {
        if (const auto res {Preprocess::preprocessRule(r)}; r != res) {
            if (res->getGuard() == bot()) {
                remove.push_back(r);
            } else {
                replacements.back().emplace(res, r);
            }
        }
    }
    for (const auto &[replacement, orig] : replacements.back()) {
        its->replaceRule(orig, replacement);
    }
    for (const auto &idx: remove) {
        its->removeRule(idx);
    }
    if (!replacements.back().empty() || !remove.empty()) {
        return its->isEmpty() ? std::optional{SmtResult::Sat} : std::optional{SmtResult::Unknown};
    }
    return {};
}
