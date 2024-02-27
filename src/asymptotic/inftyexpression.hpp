#pragma once

#include <set>

#include "arithexpr.hpp"

/**
 * This enum represents a direction. POS stands for POS_INF or POS_CONS.
 */
enum Direction { POS_INF = 0, NEG_INF, POS_CONS, NEG_CONS, POS };
extern const int DirectionSize;
extern const char* DirectionNames[];

using InftyExpression = std::pair<ExprPtr, Direction>;

/**
 * Returns true if this InftyExpression is trivially unsatisfiable, e.g,
 * if this is a variable and the direction is POS_INF or NEG_INF.
 */
bool isTriviallyUnsatisfiable(const InftyExpression&);

std::ostream& operator<<(std::ostream &os, const InftyExpression &ie);

/**
 * just compares the expressions, not their labels, such that the
 * set of labeled expressions cannot contain duplicate expressions
 */
bool operator<(const InftyExpression &x, const InftyExpression &y);

typedef std::set<InftyExpression> InftyExpressionSet;
