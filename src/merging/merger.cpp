#include "merger.hpp"
#include "../config.hpp"
#include "../analysis/preprocess.hpp"
#include "../its/export.hpp"

#include <sstream>

Merger::Merger(ITSProblem &its): its(its) {}

void Merger::merge() {
    const std::set<LocationIdx> &locs = its.getLocations();
    for (auto it1 = locs.begin(), end = locs.end(); it1 != end; ++it1) {
        for (auto it2 = it1; it2 != end; ++it2) {
            if (it1 == it2) continue;
            merge(*it1, *it2);
        }
    }
}

void Merger::merge(LocationIdx from, LocationIdx to) {
    bool changed;
    do {
        changed = false;
        const std::vector<TransIdx> &transitions = its.getTransitionsFromTo(from, to);
        for (auto it1 = transitions.begin(), end = transitions.end(); !changed && it1 != end; ++it1) {
            for (auto it2 = it1; !changed && it2 != end; ++it2) {
                if (it1 == it2) continue;
                const Rule ruleA = its.getRule(*it1);
                const Rule ruleB = its.getRule(*it2);
                if (ruleA.getRhss().size() != ruleB.getRhss().size()) continue;
                bool costMatch;
                if (Config::Analysis::nonTermination()) {
                    costMatch = ruleA.getCost().isNontermSymbol() == ruleB.getCost().isNontermSymbol();
                } else {
                    costMatch = ruleA.getCost().expand().equals(ruleB.getCost().expand());
                }
                if (!costMatch) continue;
                std::vector<RuleRhs> ruleARhss = ruleA.getRhss();
                std::vector<RuleRhs> ruleBRhss = ruleB.getRhss();
                bool failed;
                do {
                    const RuleRhs &current = ruleARhss.back();
                    failed = true;
                    for (auto it = ruleBRhss.begin(), end = ruleBRhss.end(); it != end; ++it) {
                        if (current.getLoc() == it->getLoc() && current.getUpdate() == it->getUpdate()) {
                            ruleARhss.pop_back();
                            ruleBRhss.erase(it);
                            failed = false;
                            break;
                        }
                    }
                } while (!ruleARhss.empty() && !failed);
                if (!failed) {
                    Rule newRule = ruleA.withGuard(ruleA.getGuard() | ruleB.getGuard());
                    changed = true;
                    proof.section("Applied merging");
                    std::stringstream ss;
                    ss << "first rule:\n";
                    ITSExport::printRule(ruleA, its, ss);
                    ss << "\nsecond rule:\n";
                    ITSExport::printRule(ruleB, its, ss);
                    ss << "\nnew rule:\n";
                    ITSExport::printRule(newRule, its, ss);
                    proof.append(ss);
                    its.replaceRules({*it1, *it2}, {newRule});
                }
            }
        }
    } while (changed);
}

Proof Merger::mergeRules(ITSProblem &its) {
    Merger merger(its);
    merger.merge();
    return merger.proof;
}
