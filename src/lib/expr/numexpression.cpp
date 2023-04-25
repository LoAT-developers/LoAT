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

#include "numexpression.hpp"

#include <sstream>
#include <assert.h>

Polynomial::Polynomial(const std::map<Monomial, rational> &addends): addends(addends) {
    for (auto it = this->addends.begin(); it != this->addends.end();) {
        const auto &[monomial, coeff] {*it};
        if (coeff == 0 && monomial.empty()) {
            it = this->addends.erase(it);
        } else {
            ++it;
        }
    }
}

bool Polynomial::isLinear() const {
    for (const auto &[monomial, _]: addends) {
        if (monomial.size() > 1) {
            return false;
        }
        if (!monomial.empty() && monomial.begin()->second > 1) {
            return false;
        }
    }
    return true;
}

integer Polynomial::maxDegree() const {
    integer res {0};
    for (const auto &[monomial, _]: addends) {
        for (const auto &[_, exponent]: monomial) {
            res = max(res, exponent);
        }
    }
    return res;
}

integer Polynomial::totalDegree() const {
    integer res {0};
    for (const auto &[monomial, _]: addends) {
        integer deg {0};
        for (const auto &[_, exponent]: monomial) {
            deg += exponent;
        }
        res = max(res, deg);
    }
    return res;
}

void Polynomial::collectVars(std::set<NumVar> &res) const {
    for (const auto &[monomial, _]: addends) {
        integer deg {0};
        for (const auto &[var, _]: monomial) {
            res.insert(var);
        }
    }
}

std::set<NumVar> Polynomial::vars() const {
    std::set<NumVar> res;
    collectVars(res);
    return res;
}

bool Polynomial::isConstant() const {
    return addends.empty();
}

bool is_int(const rational &x) {
    return mp::abs(mp::denominator(x)) == 1;
}

bool Polynomial::isInt() const {
    if (addends.size() == 0) {
        return true;
    }
    if (addends.size() == 1) {
        const auto &[monomial, coeff] {*addends.begin()};
        return monomial.empty() && is_int(coeff);
    }
    return false;
}

bool Polynomial::isRational() const {
    return addends.size() == 0 || (addends.size() == 1 && addends.begin()->first.empty());
}

bool Polynomial::isUnivariate() const {
    std::optional<NumVar> var;
    for (const auto &[monomial, _]: addends) {
        if (monomial.size() > 1) {
            return false;
        }
        const auto &x {monomial.begin()->first};
        if (!var) {
            var = x;
        } else if (*var != x) {
            return false;
        }
    }
    return var ? true : false;
}

NumVar Polynomial::someVar() const {
    return addends.begin()->first.begin()->first;
}

bool Polynomial::isNotMultivariate() const {
    std::optional<NumVar> var;
    for (const auto &[monomial, _]: addends) {
        if (monomial.size() > 1) {
            return false;
        }
        const auto &x {monomial.begin()->first};
        if (!var) {
            var = x;
        } else if (*var != x) {
            return false;
        }
    }
    return true;
}

bool Polynomial::isMultivariate() const {
    std::optional<NumVar> var;
    for (const auto &[monomial, _]: addends) {
        if (monomial.size() > 1) {
            return true;
        }
        const auto &x {monomial.begin()->first};
        if (!var) {
            var = x;
        } else if (*var != x) {
            return true;
        }
    }
    return false;
}

integer Polynomial::degree(const NumVar &var) const {
    integer res {0};
    for (const auto &[monomial, _]: addends) {
        auto it {monomial.find(var)};
        if (it != monomial.end()) {
            res = max(res, it->second);
        }
    }
    return res;
}

Polynomial Polynomial::coeff(const NumVar &var, integer degree) const {
    std::map<Monomial, rational> res;
    for (const auto &[monomial, coeff]: addends) {
        auto it {monomial.find(var)};
        if (it != monomial.end() && it->second == degree) {
            auto mon {monomial};
            mon.erase(var);
            res.emplace(mon, coeff);
        }
    }
    return Polynomial(res);
}

bool Polynomial::isVar() const {
    if (addends.size() == 1) {
        const auto &[monomial, coeff] {*addends.begin()};
        return coeff == 1 && monomial.size() == 1 && monomial.begin()->second == 1;
    }
    return false;
}

NumVar Polynomial::toVar() const {
    assert(isVar());
    return addends.begin()->first.begin()->first;
}

rational Polynomial::toRational() const {
    assert(isConstant());
    return addends.begin()->second;
}

//    Expr subs(const Subs &map) const;

bool Polynomial::isIntPoly() const {
    for (const auto &[_, coeff]: addends) {
        if (!is_int(coeff)) {
            return false;
        }
    }
    return true;
}

bool Polynomial::isIntegral() const {
    if (isIntPoly()) {
        return true;
    }
    const auto varSet {this->vars()};
    std::vector<NumVar> vars{varSet.begin(), varSet.end()};
    std::vector<integer> degrees;
    std::vector<integer> subs;
    for (const auto &x: vars) {
        degrees.push_back(degree(x));
        subs.push_back(0);
    }

    while (true) {
        // substitute every variable x_i by the integer subs[i] and check if the result is an integer
        Subs currSubs;
        for (unsigned int i = 0; i < degrees.size(); i++) {
            currSubs.put(vars[i], subs[i]);
        }
        const auto res {this->subs(currSubs)};
        if (!res.isInt()) {
            return false;
        }
        // increase subs (lexicographically) if possible
        // (the idea is that subs takes all possible combinations of 0,...,degree[i]+1 for every entry i)
        bool foundNext {false};
        for (unsigned int i = 0; i < degrees.size(); i++) {
            if (subs[i] >= degrees[i]+1) {
                subs[i] = 0;
            } else {
                subs[i] += 1;
                foundNext = true;
                break;
            }
        }
        if (!foundNext) {
            return true;
        }
    }
}

std::optional<Polynomial> Polynomial::solveFor(const NumVar &var, SolvingLevel level) const {
    std::map<Monomial, rational> res;
    rational c;
    for (const auto &[monomial, coeff]: addends) {
        auto it {monomial.find(var)};
        if (it == monomial.end()) {
            res.emplace(monomial, coeff);
        } else if (monomial.size() > 1 || it->second > 1) {
            return {};
        } else {
            c = it->second;
        }
    }
    if (level == TrivialCoeffs && (!is_int(c) || mp::abs(mp::numerator(c)) != 1)) {
        return {};
    }
    c = -c;
    for (auto &[_, coeff]: res) {
        coeff = coeff / (-c);
    }
    const Polynomial ret{res};
    if (level == ResultMapsToInt && !ret.isIntegral()) {
        return {};
    }
    return ret;
}

std::ostream& operator<<(std::ostream &s, const Polynomial &p) {
    bool first {true};
    for (const auto &[monomial, coeff]: p.addends) {
        if (first) {
            first = false;
        } else {
            s << " + ";
        }
        s << coeff;
        for (const auto &[var, degree]: monomial) {
            s << " * " << var << "^" << degree;
        }
    }
    return s;
}
