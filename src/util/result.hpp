#ifndef RESULT_HPP
#define RESULT_HPP

#include "proof.hpp"

template<class T>
class Result
{

bool success;
Proof proof;
T res;

public:
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

    void ruleTransformationProof(const Rule &oldRule, const std::string &transformation, const Rule &newRule, const ITSProblem &its) {
        proof.ruleTransformationProof(oldRule, transformation, newRule, its);
    }

    void majorProofStep(const std::string &step, const ITSProblem &its) {
        proof.majorProofStep(step, its);
    }

    void minorProofStep(const std::string &step, const ITSProblem &its) {
        proof.minorProofStep(step, its);
    }

    void deletionProof(const std::set<TransIdx> &rules) {
        proof.deletionProof(rules);
    }

    void storeSubProof(Proof subProof, const std::string &technique) {
        proof.storeSubProof(subProof, technique);
    }

    void chainingProof(const Rule &fst, const Rule &snd, const Rule &newRule, const ITSProblem &its) {
        proof.chainingProof(fst, snd, newRule, its);
    }

    void concat(const Proof &that) {
        proof.concat(that);
    }

    void concat(const Result<T> &that) {
        if (that) {
            proof.concat(that.proof);
            res = that.res;
            success = that.success;
        }
    }

    bool empty() const {
        return proof.empty();
    }

    Proof getProof() const {
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

    const T& operator*() const {
        return res;
    }

    const T* operator->() const {
        return &res;
    }

};

#endif // RESULT_HPP
