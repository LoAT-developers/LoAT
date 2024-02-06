#pragma once

#include <ostream>
#include <set>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>

template<class T>
std::ostream& operator<<(std::ostream &s, const std::set<T> &v) {
    s << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) {
            s << ", ";
        }
        s << *it;
    }
    s << "}";
    return s;
}

template <class T>
using linked_hash_set = boost::multi_index_container<
    T,
    boost::multi_index::indexed_by<
        boost::multi_index::hashed_unique<boost::multi_index::identity<T>>,
        boost::multi_index::sequenced<>>>;
