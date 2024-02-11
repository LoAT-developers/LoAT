#pragma once

#include "proof.hpp"
#include "rule.hpp"

class RuleProof: public Proof {
public:

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule);

};
