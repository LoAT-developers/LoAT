#pragma once

#include "proof.hpp"

#include <string>
#include <variant>

/**
 * encapsulates the result of some computation, together with a proof
 */
template<class T, class P>
class Result
{

    bool success;
    T res;

protected:

    P proof{};

public:

    Result(): success(false) {}

    explicit Result(const T &t, bool success = false): success(success), res(t) {}

    Result& operator=(const T &t) {
        set(t);
        return *this;
    }

    template <class... Args>
    void appendAll(const Args ...args) {
        std::stringstream ss;
        ([&]{
            ss << args;
        } (), ...);
        proof.append(ss);
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

    void result(const std::string &s) {
        proof.result(s);
    }

    void result(const std::ostream &s) {
        proof.result(s);
    }

    void print() const {
        proof.print();
    }

    void storeSubProof(Proof subProof) {
        proof.storeSubProof(subProof);
    }

    void concat(const Proof &that) {
        proof.concat(that);
    }

    void concat(const Result<T, P> &that) {
        if (that) {
            proof.concat(that.proof);
            res = that.res;
            success = true;
        }
    }

    bool empty() const {
        return proof.empty();
    }

    const P& getProof() const {
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
