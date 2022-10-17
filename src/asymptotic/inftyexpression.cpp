#include "inftyexpression.hpp"

#include <iostream>

const int DirectionSize = 5;
const char* DirectionNames[] = { "+", "-", "+!", "-!", "+/+!"};


InftyExpression::InftyExpression(const Expr &other, Direction dir)
    : Expr(other) {
    setDirection(dir);
}


void InftyExpression::setDirection(Direction dir) {
    direction = dir;
}


Direction InftyExpression::getDirection() const {
    return direction;
}


bool InftyExpression::isTriviallyUnsatisfiable() const {
    if (this->isRationalConstant()) {
        if (direction == POS_INF || direction == NEG_INF) {
            return true;

        } else if ((direction == POS_CONS || direction == POS)
                   && isRationalConstant() && !toNum().is_positive()) {
            return true;

        } else if (direction == NEG_CONS && isRationalConstant() && toNum().is_nonneg_integer()) {
            return true;
        }
    }

    return false;
}

bool operator<(const InftyExpression &x, const InftyExpression &y) {
    signed diff = x.getDirection() - y.getDirection();
    if (diff != 0) {
        return diff < 0;
    } else {
        return static_cast<Expr>(x) < static_cast<Expr>(y);
    }
}

std::ostream& operator<<(std::ostream &os, const InftyExpression &ie) {
    os << static_cast<const Expr &>(ie) << " ("
       << DirectionNames[ie.getDirection()] << ")";

    return os;
}
