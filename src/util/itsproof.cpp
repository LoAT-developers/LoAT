#include "itsproof.hpp"
#include "export.hpp"

#include <iostream>
#include <string>

void ITSProof::ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule) {
    if (Proof::disabled()) {
        return;
    }
    section(transformation);
    std::stringstream s;
    s << "Original rule:\n";
    ITSExport::printRule(oldRule, s);
    s << "\nNew rule:\n";
    ITSExport::printRule(newRule, s);
    append(s);
}

void ITSProof::majorProofStep(const std::string &step, const ITSProblem &its) {
    if (Proof::disabled()) {
        return;
    }
    headline(step);
    std::stringstream s;
    ITSExport::printForProof(its, s);
    append(s);
}

void ITSProof::minorProofStep(const std::string &step, const ITSProblem &its) {
    if (Proof::disabled()) {
        return;
    }
    section(step);
    std::stringstream s;
    ITSExport::printForProof(its, s);
    append(s);
}

void ITSProof::deletionProof(const std::set<TransIdx> &rules) {
    if (Proof::disabled()) {
        return;
    }
    if (!rules.empty()) {
        section("Applied Deletion");
        std::stringstream s;
        s << "Removed the following rules:";
        for (TransIdx i: rules) {
            s << " " << i;
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
    ITSExport::printRule(fst, s);
    s << "\nSecond rule:\n";
    ITSExport::printRule(snd, s);
    s << "\nNew rule:\n";
    ITSExport::printRule(newRule, s);
    append(s);
}

void ITSProof::dependencyGraphRefinementProof(const std::set<Edge> &removed) {
    if (Proof::disabled()) {
        return;
    }
    if (!removed.empty()) {
        section("Refined Dependency Graph");
        std::stringstream s;
        s << "Removed the following edges:";
        for (const auto &e: removed) {
            s << " " << e.first << "->" << e.second;
        }
        append(s);
    }
}
