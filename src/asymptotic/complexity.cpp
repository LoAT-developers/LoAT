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

#include "complexity.hpp"

#include <limits>

const Complexity Complexity::Unknown = Complexity(CpxUnknown);
const Complexity Complexity::Const = Complexity::Poly(0);
const Complexity Complexity::Exp = Complexity(CpxExponential);
const Complexity Complexity::NestedExp = Complexity(CpxNestedExponential);
const Complexity Complexity::Unbounded = Complexity(CpxUnbounded);
const Complexity Complexity::Nonterm = Complexity(CpxNonterm);

Complexity Complexity::Poly(int degree) {
    return Complexity(SimpleFraction(degree));
}

Complexity Complexity::Poly(int numer, int denom) {
    return Complexity(SimpleFraction(numer, denom));
}

bool Complexity::operator==(const Complexity &other) const {
    // Only compare polyDegree if type is Polynomial
    return type == other.type && (type != CpxPolynomial || polyDegree == other.polyDegree);
}

bool Complexity::operator<(const Complexity &other) const {
    // Compare type and polynomial degree for two polynomials
    return type < other.type || (type == CpxPolynomial && type == other.type && polyDegree < other.polyDegree);
}

bool Complexity::operator>(const Complexity &other) const {
    // Compare type and polynomial degree for two polynomials
    return type > other.type || (type == CpxPolynomial && type == other.type && polyDegree > other.polyDegree);
}

Complexity Complexity::operator+(const Complexity &other) {
    if (type == CpxUnknown || other.type == CpxUnknown) {
        return Unknown;
    }
    return std::max(*this, other);
}

Complexity Complexity::operator*(const Complexity &other) {
    if (type == CpxUnknown || other.type == CpxUnknown) {
        return Unknown;
    }
    if (type == CpxPolynomial && other.type == CpxPolynomial) {
        return Complexity(polyDegree + other.polyDegree);
    }
    return std::max(*this, other);
}

Complexity Complexity::operator^(const SimpleFraction &exponent) {
    assert(exponent.toFloat() >= 0);

    if (type == CpxPolynomial) {
        return Complexity(polyDegree * exponent);
    }
    // power does not affect any other complexities
    return *this;
}

Complexity Complexity::operator^(int exponent) {
    return (*this) ^ SimpleFraction(exponent);
}

std::string Complexity::toString() const {
    switch (type) {
        case CpxUnknown: return "Unknown";
        case CpxPolynomial:
            if (polyDegree.isZero()) {
                return "Constant";
            } else {
                return "Poly(n^" + polyDegree.toString() + ")";
            }
        case CpxExponential: return "Exp";
        case CpxNestedExponential: return "ExpNested";
        case CpxUnbounded: return "Unbounded";
        case CpxNonterm: return "Nonterm";
    }
    throw std::invalid_argument("unreachable");
}

std::string Complexity::toWstString() const {
    if (type == CpxNonterm) {
        return "NO";
    }

    std::string res = "WORST_CASE(";
    switch (type) {
        case CpxExponential: res += "EXP"; break;
        case CpxNestedExponential: res += "EXP"; break;
        case CpxUnbounded: res += "INF"; break;
        case CpxUnknown: res += "Omega(0)"; break;
        case CpxPolynomial:
            if (polyDegree.isZero()) {
                res += "Omega(1)";
            } else {
                res += "Omega(n^" + polyDegree.toString() + ")";
            }
            break;
        default: assert(false && "unreachable");;
    }
    res += ",?)";
    return res;
}

std::ostream& operator<<(std::ostream &s, const Complexity &cpx) {
    s << cpx.toString();
    return s;
}

Complexity toComplexityRec(const Expr &term) {

    //traverse the expression
    if (term.isRationalConstant()) {
        Num num = term.toNum();
        assert(num.is_integer() || num.is_real());
        //both for positive and negative constants, as we want to over-approximate the complexity! (e.g. A-B is O(n))
        return Complexity::Const;

    } else if (term.isPow()) {
        assert(term.arity() == 2);

        // If the exponent is at least polynomial (non-constant), complexity might be exponential
        if (toComplexityRec(term.op(1)) > Complexity::Const) {
            const Expr &base = term.op(0);
            if (base.isZero() || base.compare(1) == 0 || base.compare(-1) == 0) {
                return Complexity::Const;
            }
            return Complexity::Exp;

        // Otherwise the complexity is polynomial, if the exponent is nonnegative
        } else {
            if (!term.op(1).isRationalConstant()) {
                return Complexity::Unknown;
            }
            Num numexp = term.op(1).toNum();
            if (!numexp.is_nonneg_integer()) {
                return Complexity::Unknown;
            }
            if ((numexp - std::numeric_limits<int>::min()).is_negative() ||
                    (numexp - std::numeric_limits<int>::max()).is_positive()) {
                return Complexity::Unknown;
            }

            Complexity base = toComplexityRec(term.op(0));
            int exp = numexp.to_int();
            return base ^ exp;
        }

    } else if (term.isMul()) {
        assert(term.arity() > 0);
        Complexity cpx = toComplexityRec(term.op(0));
        for (unsigned int i=1; i < term.arity(); ++i) {
            cpx = cpx * toComplexityRec(term.op(i));
        }
        return cpx;

    } else if (term.isAdd()) {
        assert(term.arity() > 0);
        Complexity cpx = toComplexityRec(term.op(0));
        for (unsigned int i=1; i < term.arity(); ++i) {
            cpx = cpx + toComplexityRec(term.op(i));
        }
        return cpx;

    } else if (term.isVar()) {
        return Complexity::Poly(1);
    }

    //unknown expression type (e.g. relational)
    return Complexity::Unknown;
}


Complexity toComplexity(const Expr &e) {
    Expr simple = e.expand(); // multiply out
    return toComplexityRec(simple);
}
