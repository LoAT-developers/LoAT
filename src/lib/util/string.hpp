#pragma once

#include <sstream>

template <class T>
std::string toString(const T &t) {
    std::stringstream s;
    s << t;
    return s.str();
}
