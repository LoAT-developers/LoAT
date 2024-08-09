#include "ruleresult.hpp"

RuleResult::RuleResult(const Rule &t, bool success): Result<Rule, RuleProof>(t, success) {}

void RuleResult::operator=(const Rule &t) {
    set(t);
}

void RuleResult::ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule) {
    this->proof.ruleTransformationProof(oldRule, transformation, newRule);
}
