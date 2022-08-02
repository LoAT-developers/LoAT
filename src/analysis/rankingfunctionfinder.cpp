#include "rankingfunctionfinder.hpp"
#include "../smt/yices/yices.hpp"
#include "../util/proof.hpp"
#include "../accelerate/accelerationCalculus/rankingfunctionproblem.hpp"
#include "../analysis/preprocess.hpp"

void RankingFunctionFinder::run(ITSProblem &its) {
    Yices::init();
    for (auto loc: its.getLocations()) {
        for (auto idx: its.getSimpleLoopsAt(loc)) {
            Proof preProof;
            auto rule = its.getRule(idx);
            const Result<Rule> newRule = Preprocess::preprocessRule(its, rule);
            if (newRule) {
                preProof.ruleTransformationProof(rule, "preprocessing", newRule.get(), its);
                rule = newRule.get();
            }
            RankingFunctionProblem ap = RankingFunctionProblem::init(rule.toLinear(), its);
            auto accelRes = ap.computeRes();
            if (!accelRes.empty()) {
                Proof proof;
                std::stringstream headline;
                headline << "Searching Ranking Function for Transition #" << idx;
                proof.majorProofStep(headline.str(), its);
                proof.concat(preProof);
                proof.section("Found ranking function");
                proof.concat(ap.getProof());
                std::cout << "YES" << std::endl;
                proof.print();
                break;
           }
        }
    }
    Yices::exit();
}
