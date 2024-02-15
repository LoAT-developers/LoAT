#pragma once

#include <ostream>
#include <optional>

template<class S>
std::ostream& operator<<(std::ostream &s, const std::optional<S> &o) {
    if (o) {
        return s << *o;
    } else {
        return s << "{}";
    }
}
