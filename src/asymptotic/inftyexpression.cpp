#include "inftyexpression.hpp"

#include <iostream>

const int DirectionSize = 5;
const char* DirectionNames[] = { "+", "-", "+!", "-!", "+/+!"};


bool isTriviallyUnsatisfiable(const InftyExpression &p) {
    const auto &[e,d] {p};
    const auto r {e->isRational()};
    if (r) {
        if (d == POS_INF || d == NEG_INF) {
            return true;
        } else if ((d == POS_CONS || d == POS) && *r <= 0) {
            return true;
        } else if (d == NEG_CONS && *r >= 0) {
            return true;
        }
    }
    return false;
}

bool operator<(const InftyExpression &x, const InftyExpression &y) {
    return x.first < y.first;
}

std::ostream& operator<<(std::ostream &os, const InftyExpression &p) {
    const auto &[e,d] {p};
    return os << e << " (" << DirectionNames[d] << ")";
}
