#pragma once

#include <vector>

#include "redundance.hpp"

class RedundanceViaSquareFreeWords: public Redundance<std::vector<long>> {

public:

    using T = std::vector<long>;

private:

    std::set<T> covered;
    long next_char;
    std::map<std::pair<TransIdx, Guard>, long> alphabet;
    std::map<TransIdx, T> regexes;

public:

    virtual T get_singleton_language(const TransIdx idx, const Guard &guard) override;
    virtual T get_language(const TransIdx idx) override;
    virtual void set_language(const TransIdx idx, const T &t) override;
    virtual bool is_redundant(const T &t) const override;
    virtual void mark_as_redundant(const T &t) override;
    virtual void concat(T &t1, const T &t2) const override;
    virtual void transitive_closure(T &t) const override;

};
