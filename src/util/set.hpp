#pragma once

#include <ostream>
#include <set>

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
