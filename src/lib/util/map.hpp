#pragma once

#include <iostream>
#include <ostream>
#include <map>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>

template<class S, class T>
std::ostream& operator<<(std::ostream &s, const std::map<S, T> &map) {
    s << "{";
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it != map.begin()) {
            s << ", ";
        }
        s << it->first << " -> " << it->second;
    }
    s << "}";
    return s;
}

template <class S, class T>
class linked_hash_map {

private:

    struct first {
        typedef S result_type;
        result_type operator()(const std::pair<S, T>& p) const {
            return p.first;
        }
    };

    struct hash {};
    struct list {};

    using container = boost::multi_index_container<
        std::pair<S, T>,
        boost::multi_index::indexed_by<
            boost::multi_index::hashed_unique<
                boost::multi_index::tag<hash>,
                first>,
            boost::multi_index::sequenced<
                boost::multi_index::tag<list>>>>;

    container c;

    template <class SS, class TT>
    friend bool operator==(const linked_hash_map<SS, TT> &x, const linked_hash_map<SS, TT> &y);

public:

    typedef typename container::const_iterator const_iterator;

    linked_hash_map() {}

    linked_hash_map(std::initializer_list<std::pair<const S, T>> init) {
        for (const auto &p: init) {
            c.insert(p);
        }
    }

    void put(const S &s, const T &t) {
        erase(s);
        boost::multi_index::get<hash>(c).emplace(s, t);
    }

    auto erase(const S &key) {
        return boost::multi_index::get<hash>(c).erase(key);
    }

    const T& operator[](const S &key) const {
        return find(key)->second;
    }

    const_iterator find(const S &key) const {
        return boost::multi_index::get<hash>(c).find(key);
    }

    const_iterator begin() const {
        return c.begin();
    }

    const_iterator end() const {
        return c.end();
    }

    bool empty() const {
        return c.empty();
    }

    size_t size() const {
        return c.size();
    }

};

template <class S, class T>
bool operator==(const linked_hash_map<S, T> &x, const linked_hash_map<S, T> &y) {
    return boost::multi_index::get<typename linked_hash_map<S, T>::hash>(x.c) == boost::multi_index::get<typename linked_hash_map<S, T>::hash>(y.c);
}

template<class S, class T>
std::ostream& operator<<(std::ostream &s, const linked_hash_map<S, T> &map) {
    s << "{";
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it != map.begin()) {
            s << ", ";
        }
        s << it->first << " -> " << it->second;
    }
    s << "}";
    return s;
}
