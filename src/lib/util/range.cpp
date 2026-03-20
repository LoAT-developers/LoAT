#include "range.hpp"

Range::Range(const unsigned s, const unsigned e) : s(s), e(e) {}

unsigned Range::start() const {
    return s;
}

unsigned Range::end() const {
    return e;
}

unsigned Range::length() const {
    return e - s + 1;
}

bool Range::empty() const {
    return length() == 0;
}

Range Range::from_length(const unsigned start, const unsigned length) {
    return {start, start + length - 1};
}

Range Range::from_interval(const unsigned start, const unsigned end) {
    return {start, end};
}

std::ostream& operator<<(std::ostream& s, const Range& r) {
    return s << "[" << r.start() << ", " << r.end() << "]";
}
