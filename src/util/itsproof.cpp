#include "itsproof.hpp"
#include "ruleexport.hpp"
#include "export.hpp"

#include <iostream>
#include <string>

void ITSProof::majorProofStep(const std::string &step, const Proof &subproof, const ITSProblem &its) {
    if (Proof::disabled()) {
        return;
    }
    headline(step);
    storeSubProof(subproof);
    std::stringstream s;
    ITSExport::printForProof(its, s);
    append(s);
}

void ITSProof::deletionProof(const linked_hash_set<TransIdx> &rules) {
    if (Proof::disabled()) {
        return;
    }
    if (!rules.empty()) {
        section("Applied Deletion");
        std::stringstream s;
        s << "Removed the following rules: ";
        bool first {true};
        for (TransIdx i: rules) {
            if (first) {
                first = false;
            } else {
                s << ", ";
            }
            s << i;
        }
        append(s);
    }
}

void ITSProof::chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule) {
    if (Proof::disabled()) {
        return;
    }
    section("Applied Chaining");
    std::stringstream s;
    s << "First rule:\n";
    RuleExport::printRule(fst, s);
    s << "\nSecond rule:\n";
    RuleExport::printRule(snd, s);
    s << "\nNew rule:\n";
    RuleExport::printRule(newRule, s);
    append(s);
}
