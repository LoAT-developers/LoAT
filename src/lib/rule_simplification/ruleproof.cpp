#include "ruleproof.hpp"
#include "ruleexport.hpp"

#include <iostream>
#include <string>

void RuleProof::ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule) {
    if (Proof::disabled()) {
        return;
    }
    headline(transformation);
    std::stringstream s;
    s << "Original rule:\n";
    RuleExport::printRule(oldRule, s);
    s << "\nNew rule:\n";
    RuleExport::printRule(newRule, s);
    append(s);
}
