#pragma once

#include <ostream>

class Range {
    unsigned s;
    unsigned e;

    Range(unsigned s, unsigned e);

public:
    unsigned start() const;
    unsigned end() const;
    unsigned length() const;
    bool empty() const;

    static Range from_length(unsigned start, unsigned length);
    static Range from_interval(unsigned start, unsigned end);

};

std::ostream& operator<<(std::ostream &s, const Range&);
