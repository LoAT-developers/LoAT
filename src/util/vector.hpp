#pragma once

#include <ostream>
#include <vector>

template<class T>
std::ostream& operator<<(std::ostream &s, const std::vector<T> &v) {
    s << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it != v.begin()) {
            s << ", ";
        }
        s << *it;
    }
    s << "]";
    return s;
}
