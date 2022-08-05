#include "recurrentsetfinder.hpp"
#include "../smt/yices/yices.hpp"
#include "../util/proof.hpp"
#include "../accelerate/accelerationCalculus/accelerationproblem.hpp"
#include "../analysis/preprocess.hpp"

void RecurrentSetFinder::run(ITSProblem &its) {
    Yices::init();
//    bool foundRecurrentSet = false;
    for (auto loc: its.getLocations()) {
        for (auto idx: its.getSimpleLoopsAt(loc)) {
            Proof preProof;
            Rule rule = its.getRule(idx);
            const Result<Rule> newRule = Preprocess::preprocessRule(its, rule);
            if (newRule) {
                preProof.ruleTransformationProof(rule, "preprocessing", newRule.get(), its);
                preProof.storeSubProof(newRule.getProof());
                rule = *newRule;
            }
            AccelerationProblem ap = AccelerationProblem::initForRecurrentSet(rule.toLinear(), its);
            auto accelRes = ap.computeRes();
            if (!accelRes.empty()) {
                Proof proof;
                std::stringstream headline;
                headline << "Searching Recurrent Set for Transition #" << idx;
                proof.majorProofStep(headline.str(), its);
                proof.concat(preProof);
                proof.section("Found recurrent set");
                proof.concat(accelRes.front().proof);
                std::cout << "NO" << std::endl;
                proof.print();
//                foundRecurrentSet = true;
                break;
           }
        }
    }
//    if (!foundRecurrentSet) {
//        for (auto loc: its.getLocations()) {
//            for (auto idx: its.getSimpleLoopsAt(loc)) {
//                const auto &rule = its.getRule(idx).toLinear();
//                const Subs &up = rule.getUpdate();
//                if (Smt::isImplication(rule.getGuard(), rule.getGuard()->subs(up), its)) {
//                    Proof proof;
//                    std::stringstream headline;
//                    headline << "Searching Recurrent Set for Transition #" << idx;
//                    proof.majorProofStep(headline.str(), its);
//                    proof.append("guard is monotonically increasing");
//                    proof.newline();
//                    proof.result("Found Recurrent Set!");
//                    std::cout << "NO" << std::endl;
//                    proof.print();
//                    break;
//                }
//            }
//        }
//    }
    Yices::exit();
}
