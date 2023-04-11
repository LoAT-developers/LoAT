#include "limitvector.hpp"

#include <cassert>

const std::vector<LimitVector> LimitVector::Addition = {
    // increasing limit vectors
    LimitVector(POS_INF, POS_INF, POS_INF),
    LimitVector(POS_INF, POS_INF, POS_CONS),
    LimitVector(POS_INF, POS_CONS, POS_INF),
    LimitVector(POS_INF, POS_INF, NEG_CONS),
    LimitVector(POS_INF, NEG_CONS, POS_INF),

    // decreasing limit vectors
    LimitVector(NEG_INF, NEG_INF, NEG_INF),
    LimitVector(NEG_INF, NEG_INF, NEG_CONS),
    LimitVector(NEG_INF, NEG_CONS, NEG_INF),
    LimitVector(NEG_INF, NEG_INF, POS_CONS),
    LimitVector(NEG_INF, POS_CONS, NEG_INF),

    // positive limit vectors
    LimitVector(POS_CONS, POS_CONS, POS_CONS),

    // negative limit vectors
    LimitVector(NEG_CONS, NEG_CONS, NEG_CONS)
};


const std::vector<LimitVector> LimitVector::Multiplication = {
    // increasing limit vectors
    LimitVector(POS_INF, POS_INF, POS_INF),
    LimitVector(POS_INF, POS_INF, POS_CONS),
    LimitVector(POS_INF, POS_CONS, POS_INF),
    LimitVector(POS_INF, NEG_INF, NEG_INF),
    LimitVector(POS_INF, NEG_INF, NEG_CONS),
    LimitVector(POS_INF, NEG_CONS, NEG_INF),

    // decreasing limit vectors
    LimitVector(NEG_INF, NEG_INF, POS_INF),
    LimitVector(NEG_INF, POS_INF, NEG_INF),
    LimitVector(NEG_INF, NEG_INF, POS_CONS),
    LimitVector(NEG_INF, POS_CONS, NEG_INF),
    LimitVector(NEG_INF, POS_INF, NEG_CONS),
    LimitVector(NEG_INF, NEG_CONS, POS_INF),

    // positive limit vectors
    LimitVector(POS_CONS, POS_CONS, POS_CONS),
    LimitVector(POS_CONS, NEG_CONS, NEG_CONS),

    // negative limit vectors
    LimitVector(NEG_CONS, POS_CONS, NEG_CONS),
    LimitVector(NEG_CONS, NEG_CONS, POS_CONS)
};


const std::vector<LimitVector> LimitVector::Division = {
    // increasing limit vectors
    LimitVector(POS_INF, POS_INF, POS_CONS),
    LimitVector(POS_INF, NEG_INF, NEG_CONS),

    // decreasing limit vectors
    LimitVector(NEG_INF, NEG_INF, POS_CONS),
    LimitVector(NEG_INF, POS_INF, NEG_CONS),

    // positive limit vectors
    LimitVector(POS_CONS, POS_CONS, POS_CONS),
    LimitVector(POS_CONS, NEG_CONS, NEG_CONS),

    // negative limit vectors
    LimitVector(NEG_CONS, NEG_CONS, POS_CONS),
    LimitVector(NEG_CONS, POS_CONS, NEG_CONS)
};


LimitVector::LimitVector(Direction type, Direction first, Direction second)
    : type(type), first(first), second(second) {
    assert(type != POS);
    assert(first != POS);
    assert(second != POS);
}


Direction LimitVector::getType() const {
    return type;
}


Direction LimitVector::getFirst() const {
    return first;
}


Direction LimitVector::getSecond() const {
    return second;
}


bool LimitVector::isApplicable(Direction dir) const {
    return  dir == type || (dir == POS && (type == POS_INF || type == POS_CONS));
}


bool LimitVector::makesSense(Expr l, Expr r) const {
    InftyExpression inftyL(l, first);
    if (inftyL.isTriviallyUnsatisfiable()) {
        return false;
    }

    InftyExpression inftyR(r, second);
    if (inftyR.isTriviallyUnsatisfiable()) {
        return false;
    }

    if (l == r && first != second) {
        return false;
    }

    if ((first == NEG_CONS || first == NEG_INF)
        && l.isPow()
        && l.op(1).isRationalConstant()
        && l.op(1).toNum().is_even()) {
        return false;
    }

    if ((second == NEG_CONS || second == NEG_INF)
        && r.isPow()
        && r.op(1).isRationalConstant()
        && r.op(1).toNum().is_even()) {
        return false;
    }

    return true;
}


std::ostream& operator<<(std::ostream &os, const LimitVector &lv) {
    os << DirectionNames[lv.getType()] << " limit vector "
       << "(" << DirectionNames[lv.getFirst()] << ","
       << DirectionNames[lv.getSecond()] << ")";

    return os;
}
