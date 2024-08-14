#pragma once

#include <boost/container_hash/hash.hpp>

template <class It>
size_t hash_unordered_range(It begin, It end) {
    size_t res {0};
    for (; begin != end; ++begin) {
        boost::hash_combine(res, *begin);
    }
    return res;
}