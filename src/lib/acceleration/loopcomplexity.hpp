#pragma once

#include "rule.hpp"

struct LoopComplexity {
    unsigned negated_int {0};
    unsigned negated_bool {0};
    unsigned non_recursive {0};
    unsigned foreign_vars {0};
    unsigned tmp_vars {0};

    static LoopComplexity compute(const RulePtr rule);

    static std::strong_ordering compare(const RulePtr r1, const RulePtr r2);

};

std::strong_ordering operator <=>(const LoopComplexity &c1, const LoopComplexity &c2);

std::ostream &operator<<(std::ostream &s, const LoopComplexity &c);
