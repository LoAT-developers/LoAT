#pragma once

#include "rule.hpp"

struct LoopComplexity {
    unsigned negated {0};
    unsigned non_recursive {0};
    unsigned foreign_vars {0};
    unsigned tmp_vars {0};

    static LoopComplexity compute(const Rule &rule);

    static std::strong_ordering compare(const Rule &r1, const Rule &r2);

};

std::strong_ordering operator <=>(const LoopComplexity &c1, const LoopComplexity &c2);

std::ostream &operator<<(std::ostream &s, const LoopComplexity &c);
