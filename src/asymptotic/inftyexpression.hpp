#pragma once

#include <set>

#include "numexpression.hpp"

/**
 * This enum represents a direction. POS stands for POS_INF or POS_CONS.
 */
enum Direction { POS_INF = 0, NEG_INF, POS_CONS, NEG_CONS, POS };
extern const int DirectionSize;
extern const char* DirectionNames[];

/**
 * This class extends an Expression by a direction.
 */
class InftyExpression : public Expr {
public:
    /**
     * Creates a new InftyExpression from the given expression and direction.
     */
    InftyExpression(const Expr &other, Direction dir);

    /**
     * Sets the direction of this InftyExpression.
     */
    void setDirection(Direction dir);

    /**
     * Returns the direction of this InftyExpression.
     */
    Direction getDirection() const;

    /**
     * Returns true if this InftyExpression is trivially unsatisfiable, e.g,
     * if this is a variable and the direction is POS_INF or NEG_INF.
     */
    bool isTriviallyUnsatisfiable() const;

private:
    Direction direction {};

};

std::ostream& operator<<(std::ostream &os, const InftyExpression &ie);

/**
 * just compares the expressions, not their labels, such that the
 * set of labeled expressions cannot contain duplicate expressions
 */
bool operator<(const InftyExpression &x, const InftyExpression &y);

typedef std::set<InftyExpression> InftyExpressionSet;
