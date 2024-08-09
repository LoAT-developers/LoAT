#pragma once

#include "result.hpp"
#include "itsproof.hpp"

template <class T>
class ITSResult: public Result<T, ITSProof> {

public:

    ITSResult(): Result<T, ITSProof>(false) {}

    ITSResult(const T &t, bool success = false): Result<T, ITSProof>(t, success) {}

    void majorProofStep(const std::string &step, const ITSProof &subproof, const ITSProblem &its) {
        this->proof.majorProofStep(step, subproof, its);
    }

    void dependencyGraphRefinementProof(const linked_hash_set<ITSProblem::DG::Edge> &removed) {
        this->proof.dependencyGraphRefinementProof(removed);
    }

    void deletionProof(const linked_hash_set<TransIdx> &rules) {
        this->proof.deletionProof(rules);
    }

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule) {
        this->proof.chainingProof(fst, snd, newRule);
    }

};

class ResultViaSideEffects: public ITSResult<std::monostate> {

public:

    ResultViaSideEffects(): ITSResult<std::monostate>(std::monostate()) {}

};
