#pragma once

#include "result.hpp"
#include "rule.hpp"
#include "ruleproof.hpp"

class RuleResult: public ResultBase<Rule, RuleProof> {

public:

    explicit RuleResult(const Rule &t, bool success = false);

    void operator=(const Rule &t);

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule);

};
