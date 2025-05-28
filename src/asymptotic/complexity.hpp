#pragma once

#include "theory.hpp"

#include <assert.h>


/**
 * This class represents a runtime complexity.
 * As we can now output sublinear runtimes (e.g. n^0.5), this is now a Real value.
 * [If C++ only had sum types ...]
 */
class Complexity {
public:
    enum ComplexityType {
        CpxUnknown = 0,
        CpxPolynomial = 1, // e.g. n^(1/2), n^3, the degree is stored. This includes constant complexity with n^0
        CpxExponential = 2, // any exponential like 2^x
        CpxUnbounded = 4, // infinite runtime, but not nontermination (if runtime depends on a free variable)
    };

    static const Complexity Unknown;
    static const Complexity Const; // equivalent to Poly(0)
    static Complexity Poly(Int degree);
    static const Complexity Exp;
    static const Complexity Unbounded;

    // defaults to unknown
    Complexity() : type(CpxUnknown), polyDegree(1) {}

    bool operator==(const Complexity &other) const;
    bool operator<(const Complexity &other) const;
    bool operator>(const Complexity &other) const;
    bool operator!=(const Complexity &other) const { return !(*this == other); }
    bool operator<=(const Complexity &other) const { return *this < other || *this == other; }
    bool operator>=(const Complexity &other) const { return *this > other || *this == other; }

    Complexity operator+(const Complexity &other) const;
    Complexity operator*(const Complexity &other) const;
    Complexity operator^(const Int &exponent) const;

    std::string toString() const; // readable format
    std::string toWstString() const; // WORST_CASE(cpx,?) format

private:
    explicit Complexity(ComplexityType type) : type(type), polyDegree(1) {}
    explicit Complexity(const Int &degree) : type(CpxPolynomial), polyDegree(degree) {}

private:
    ComplexityType type;

    // The degree for polynomial complexity, not meaningful for other types
    Int polyDegree;
};

std::ostream& operator<<(std::ostream &, const Complexity &);

Complexity toComplexity(const Arith::Expr e);
