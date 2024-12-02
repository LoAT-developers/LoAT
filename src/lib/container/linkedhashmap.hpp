#pragma once

#include <iostream>
#include <ostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>

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
            boost::multi_index::sequenced<
                boost::multi_index::tag<list>>,
            boost::multi_index::hashed_unique<
                boost::multi_index::tag<hash>,
                first>>>;

    container c{};

    template <class SS, class TT>
    friend bool operator==(const linked_hash_map<SS, TT> &x, const linked_hash_map<SS, TT> &y);

public:

    typedef typename container::template index<list>::type::const_iterator const_iterator;

    linked_hash_map() {}

    linked_hash_map(std::initializer_list<std::pair<const S, T>> init) {
        auto &h {boost::multi_index::get<hash>(c)};
        for (const auto &p: init) {
            h.insert(p);
        }
    }

    void put(const S &s, const T &t) {
        auto &h {boost::multi_index::get<hash>(c)};
        h.erase(s);
        h.emplace(s, t);
    }

    template <class... Args>
    auto emplace(const Args &...args) {
        return boost::multi_index::get<hash>(c).emplace(args...);
    }

    std::optional<T> get(const S &key) const {
        auto &h {boost::multi_index::get<hash>(c)};
        const auto it {h.find(key)};
        if (it == h.end()) {
            return {};
        } else {
            return it->second;
        }
    }

    auto erase(const S &key) {
        return boost::multi_index::get<hash>(c).erase(key);
    }

    auto erase(const const_iterator &it) {
        return boost::multi_index::get<list>(c).erase(it);
    }

    const T& operator[](const S &key) const {
        return boost::multi_index::get<hash>(c).find(key)->second;
    }

    const T& at(const S &key) const {
        return (*this)[key];
    }

    bool contains(const S &key) const {
        auto &h {boost::multi_index::get<hash>(c)};
        return h.find(key) != h.end();
    }

    const_iterator begin() const {
        return boost::multi_index::get<list>(c).begin();
    }

    const_iterator end() const {
        return boost::multi_index::get<list>(c).end();
    }

    bool empty() const {
        return c.empty();
    }

    size_t size() const {
        return c.size();
    }

    void project(const linked_hash_set<S> &vars) {
        for (auto it = begin(); it != end();) {
            if (vars.contains(it->first)) {
                ++it;
            } else {
                it = erase(it);
            }
        }
    }

    void project(const std::function<bool(const S)> &p) {
        for (auto it = begin(); it != end();) {
            if (p(it->first)) {
                ++it;
            } else {
                it = erase(it);
            }
        }
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
