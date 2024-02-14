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
class linked_hash_set {

private:

    struct hash {};
    struct list {};

    using container = boost::multi_index_container<
        T,
        boost::multi_index::indexed_by<
            boost::multi_index::hashed_unique<
                boost::multi_index::tag<hash>,
                boost::multi_index::identity<T>>,
            boost::multi_index::sequenced<
                boost::multi_index::tag<list>>>>;

    container c{};

    template <class TT>
    friend bool operator==(const linked_hash_set<TT> &x, const linked_hash_set<TT> &y);

public:

    typedef typename container::template index<list>::type::const_iterator const_iterator;

    linked_hash_set() {}

    linked_hash_set(std::initializer_list<T> init) {
        boost::multi_index::get<hash>(c).insert(init.begin(), init.end());
    }

    template <class Iterator>
    linked_hash_set(Iterator begin, Iterator end) {
        boost::multi_index::get<hash>(c).insert(begin, end);
    }

    template <class... Args>
    auto emplace(const Args &...args) {
        return boost::multi_index::get<hash>(c).emplace(args...);
    }

    template <class Iterator>
    auto insert(Iterator begin, Iterator end) {
        return boost::multi_index::get<hash>(c).insert(begin, end);
    }

    auto insert(const T &t) {
        return boost::multi_index::get<hash>(c).insert(t);
    }

    const_iterator erase(const_iterator it) {
        return boost::multi_index::get<list>(c).erase(it);
    }

    void clear() {
        c.clear();
    }

    auto erase(const T &t) {
        return boost::multi_index::get<hash>(c).erase(t);
    }

    bool contains(const T &t) const {
        return boost::multi_index::get<hash>(c).contains(t);
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

};

template <class T>
bool operator==(const linked_hash_set<T> &x, const linked_hash_set<T> &y) {
    return boost::multi_index::get<typename linked_hash_set<T>::hash>(x.c) == boost::multi_index::get<typename linked_hash_set<T>::hash>(y.c);
}

template<class T>
std::ostream& operator<<(std::ostream &s, const linked_hash_set<T> &v) {
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
