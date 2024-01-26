#pragma once

#include "result.hpp"
#include "itsproof.hpp"

template <class T>
class Result: public ResultBase<T, ITSProof> {

public:

    Result(): ResultBase<T, ITSProof>(false) {}

    Result(const T &t, bool success = false): ResultBase<T, ITSProof>(t, success) {}

    void majorProofStep(const std::string &step, const ITSProof &subproof, const ITSProblem &its) {
        this->proof.majorProofStep(step, subproof, its);
    }

    void dependencyGraphRefinementProof(const std::set<ITSProblem::DG::Edge> &removed) {
        this->proof.dependencyGraphRefinementProof(removed);
    }

    void deletionProof(const std::set<TransIdx> &rules) {
        this->proof.deletionProof(rules);
    }

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule) {
        this->proof.chainingProof(fst, snd, newRule);
    }

};

class ResultViaSideEffects: public Result<std::monostate> {

public:

    ResultViaSideEffects(): Result<std::monostate>(std::monostate()) {}

};
