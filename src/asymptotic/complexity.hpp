/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#pragma once

#include "numexpression.hpp"

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
        CpxNestedExponential = 3, // doubly exponential like 2^(2^x)
        CpxUnbounded = 4, // infinite runtime, but not nontermination (if runtime depends on a free variable)
        CpxNonterm = 5 // infinite runtime due to nontermination
    };

    static const Complexity Unknown;
    static const Complexity Const; // equivalent to Poly(0)
    static Complexity Poly(Int degree);
    static Complexity Poly(Int numer, Int denom);
    static const Complexity Exp;
    static const Complexity NestedExp;
    static const Complexity Unbounded;
    static const Complexity Nonterm;

    // defaults to unknown
    Complexity() : type(CpxUnknown), polyDegree(1) {}

    ComplexityType getType() const { return type; }
    Rational getPolynomialDegree() const { assert(type == CpxPolynomial); return polyDegree; }

    bool operator==(const Complexity &other) const;
    bool operator<(const Complexity &other) const;
    bool operator>(const Complexity &other) const;
    bool operator!=(const Complexity &other) const { return !(*this == other); }
    bool operator<=(const Complexity &other) const { return *this < other || *this == other; }
    bool operator>=(const Complexity &other) const { return *this > other || *this == other; }

    Complexity operator+(const Complexity &other);
    Complexity operator*(const Complexity &other);
    Complexity operator^(const Rational &exponent);

    std::string toString() const; // readable format
    std::string toWstString() const; // WORST_CASE(cpx,?) format

private:
    explicit Complexity(ComplexityType type) : type(type), polyDegree(1) {}
    explicit Complexity(const Rational &degree) : type(CpxPolynomial), polyDegree(degree) {}

private:
    ComplexityType type;

    // The degree for polynomial complexity, not meaningful for other types
    Rational polyDegree;
};

std::ostream& operator<<(std::ostream &, const Complexity &);

Complexity toComplexity(const ExprPtr e);
