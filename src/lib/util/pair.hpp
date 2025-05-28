#pragma once

#include <ostream>

template<class S, class T>
std::ostream& operator<<(std::ostream &s, const std::pair<S, T> &p) {
    return s << "(" << p.first << ", " << p.second << ")";
}
