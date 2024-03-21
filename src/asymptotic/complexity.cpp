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
#include "optional.hpp"

#include <limits>

const Complexity Complexity::Unknown = Complexity(CpxUnknown);
const Complexity Complexity::Const = Complexity::Poly(0);
const Complexity Complexity::Exp = Complexity(CpxExponential);
const Complexity Complexity::Unbounded = Complexity(CpxUnbounded);

Complexity Complexity::Poly(Int degree) {
    return Complexity(degree);
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

Complexity Complexity::operator+(const Complexity &other) const {
    if (type == CpxUnknown || other.type == CpxUnknown) {
        return Unknown;
    }
    return std::max(*this, other);
}

Complexity Complexity::operator*(const Complexity &other) const {
    if (type == CpxUnknown || other.type == CpxUnknown) {
        return Unknown;
    }
    if (type == CpxPolynomial && other.type == CpxPolynomial) {
        return Complexity(polyDegree + other.polyDegree);
    }
    return std::max(*this, other);
}

Complexity Complexity::operator^(const Int &exponent) const {
    assert(exponent >= 0);

    if (type == CpxPolynomial) {
        return Complexity(polyDegree * exponent);
    }
    // power does not affect any other complexities
    return *this;
}

std::string Complexity::toString() const {
    switch (type) {
    case CpxUnknown: return "Unknown";
    case CpxPolynomial:
        if (polyDegree == 0) {
            return "Constant";
        } else {
            return "Poly(n^" + polyDegree.str() + ")";
        }
    case CpxExponential: return "Exp";
    case CpxUnbounded: return "Unbounded";
    }
    throw std::invalid_argument("unreachable");
}

std::string Complexity::toWstString() const {
    std::string res = "WORST_CASE(";
    switch (type) {
    case CpxExponential: res += "EXP"; break;
    case CpxUnbounded: res += "INF"; break;
    case CpxUnknown: res += "Omega(0)"; break;
    case CpxPolynomial:
        if (polyDegree == 0) {
            res += "Omega(1)";
        } else {
            res += "Omega(n^" + polyDegree.str() + ")";
        }
        break;
    default: assert(false && "unreachable");;
    }
    res += ",?)";
    return res;
}

std::ostream& operator<<(std::ostream &s, const Complexity &cpx) {
    return s << cpx.toString();
}

Complexity toComplexityRec(const Arith::Expr term) {
    return term->apply<Complexity>(
        [](const ArithConstPtr) {
            return Complexity::Const;
        },
        [](const ArithVarPtr) {
            return Complexity::Poly(1);
        },
        [](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Complexity::Const, [](const auto &x, const auto y) {
                return x + toComplexityRec(y);
            });
        },
        [](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Complexity::Const, [](const auto &x, const auto y) {
                return x * toComplexityRec(y);
            });
        },
        [](const ArithExpPtr e) {
            // If the exponent is at least polynomial (non-constant), complexity might be exponential
            if (toComplexityRec(e->getExponent()) > Complexity::Const) {
                return map<ArithConstPtr, Complexity>(
                           e->getBase()->isRational(),
                           [](const auto c) {
                               return **c <= 1 ? Complexity::Const : Complexity::Exp;
                           }).value_or(Complexity::Exp);
            }
            // Otherwise the complexity is polynomial, if the exponent is nonnegative
            return map<Int, Complexity>(
                       e->getExponent()->isInt(),
                       [&](const auto &exp) {
                           return exp < 0 ? Complexity::Unknown : toComplexityRec(e->getBase()) ^ exp;
                       }).value_or(Complexity::Unknown);
        });
}

Complexity toComplexity(const Arith::Expr e) {
    return toComplexityRec(e);
}
