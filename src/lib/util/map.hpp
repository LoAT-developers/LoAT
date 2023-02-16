#pragma once

#include <ostream>
#include <map>

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
