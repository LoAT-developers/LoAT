#pragma once

#include "theory.hpp"
#include "types.hpp"

template <class T>
class Redundance {
public:
    virtual T get_singleton_language(const TransIdx idx, const Guard &guard) = 0;
    virtual T get_language(const TransIdx idx) = 0;
    virtual void set_language(const TransIdx idx, const T &t) = 0;
    virtual bool is_redundant(const T &t) const = 0;
    virtual void mark_as_redundant(const T &t) = 0;
    virtual void concat(T &t1, const T &t2) const = 0;
    virtual void transitive_closure(T &t) const = 0;
};
