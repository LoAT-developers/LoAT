#pragma once

#include "itsproof.hpp"

#include <variant>

/**
 * encapsulates the result of some computation, together with a proof
 */
template<class T>
class Result
{

bool success;
ITSProof proof;
T res;

public:

    Result(): success(false) {}

    Result(const T &t, bool success = false): success(success), res(t) {}

    void operator=(const T &t) {
        set(t);
    }

    void append(const std::string &s) {
        proof.append(s);
    }

    void append(const std::ostream &s) {
        proof.append(s);
    }

    void append(const Proof::Style &style, std::string s) {
        proof.newline();
    }

    void newline() {
        proof.newline();
    }

    void headline(const std::string &s) {
        proof.headline(s);
    }

    void headline(const std::ostream &s) {
        proof.headline(s);
    }

    void section(const std::string &s) {
        proof.section(s);
    }

    void section(const std::ostream &s) {
        proof.section(s);
    }

    void result(const std::string &s) {
        proof.result(s);
    }

    void result(const std::ostream &s) {
        proof.result(s);
    }

    void print() const {
        proof.print();
    }

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule) {
        proof.ruleTransformationProof(oldRule, transformation, newRule);
    }

    void dependencyGraphRefinementProof(const std::set<ITSProblem::DG::Edge> &removed) {
        proof.dependencyGraphRefinementProof(removed);
    }

    void majorProofStep(const std::string &step, const ITSProof &subproof, const ITSProblem &its) {
        proof.majorProofStep(step, subproof, its);
    }

    void deletionProof(const std::set<TransIdx> &rules) {
        proof.deletionProof(rules);
    }

    void storeSubProof(Proof subProof) {
        proof.storeSubProof(subProof);
    }

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule) {
        proof.chainingProof(fst, snd, newRule);
    }

    void concat(const Proof &that) {
        proof.concat(that);
    }

    void concat(const Result<T> &that) {
        if (that) {
            proof.concat(that.proof);
            res = that.res;
            success = true;
        }
    }

    bool empty() const {
        return proof.empty();
    }

    const ITSProof& getProof() const {
        return proof;
    }

    T get() const {
        return res;
    }

    void set(const T &t, bool success = true) {
        this->success |= success;
        res = t;
    }

    explicit operator bool() const {
        return success;
    }

    void fail() {
        success = false;
    }

    void succeed() {
        success = true;
    }

    template<class S>
    Result<S> map(const std::function<S(const T&)> &mapper) const {
        Result<S> res;
        res.concat(proof);
        res = mapper(this->res);
        if (!success) {
            res.fail();
        }
        return res;
    }

    const T& operator*() const {
        return res;
    }

    const T* operator->() const {
        return &res;
    }

    T& operator*() {
        return res;
    }

    T* operator->() {
        return &res;
    }

};

class ResultViaSideEffects: public Result<std::monostate> {

public:
    ResultViaSideEffects(): Result<std::monostate>(std::monostate()) {}

};
