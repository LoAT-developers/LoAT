#ifndef LIMITVECTOR_H
#define LIMITVECTOR_H

#include <ostream>
#include <vector>

#include "inftyexpression.hpp"

/**
 * This class represents a limit vector, i.e., a 2-tuple of directions.
 */
class LimitVector {
public:
    /**
     * Collections of limit vectors for addition, multiplication, and division.
     */
    static const std::vector<LimitVector> Addition;
    static const std::vector<LimitVector> Multiplication;
    static const std::vector<LimitVector> Division;

public:
    /**
     * Creates a new LimitVector from the given directions.
     * @param type specifies whether this LimitVector is increasing,
     *             decreasing, positive or negative. Must not be POS.
     * @param first first component. Must not be POS.
     * @param second second component. Must not be POS.
     */
    LimitVector(Direction type, Direction first, Direction second);

    /**
     * Returns the type of this LimitVector.
     * @return a direction that is not POS
     */
    Direction getType() const;

    /**
     * Returns the first component of this LimitVector.
     * @return a direction that is not POS
     */
    Direction getFirst() const;

    /**
     * Returns the second component of this LimitVector.
     * @return a direction that is not POS
     */
    Direction getSecond() const;

    /**
     * Returns true iff this LimitVector is applicable to an InftyExpression with
     * the given direction, i.e., dir matches the type of this LimitVector or
     * dir is POS and this LimitVector is increasing or positive.
     */
    bool isApplicable(Direction dir) const;

    /**
     * Returns false if applying this limit vector's directions to the expressions
     * would result in a trivially unsolvable limit problem.
     */
    bool makesSense(Arith::Expr l, Arith::Expr r) const;

private:
    const Direction type;
    const Direction first;
    const Direction second;
};

std::ostream& operator<<(std::ostream &os, const LimitVector &lv);

#endif // LIMITVECTOR_H
