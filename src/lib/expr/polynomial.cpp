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

Polynomial::Polynomial(const std::map<Monomial, rational> &addends): addends(addends) {}

Polynomial Polynomial::mk(const std::map<Monomial, rational> &addends) {
    if (addends.empty()) {
        return zero;
    }
    Polynomial res(addends);
    for (auto it = res.addends.begin(); it != res.addends.end();) {
        const auto &[monomial, coeff] {*it};
        if (coeff == 0 && !monomial.empty()) {
            it = res.addends.erase(it);
        } else {
            ++it;
        }
    }
    return res;
}

Polynomial Polynomial::mk(const rational &x) {
    if (x == 0) {
        return zero;
    } else {
        return Polynomial({{{}, x}});
    }
}

Polynomial Polynomial::zero {{{{}, 0}}};

bool Polynomial::isZero() const {
    return *this == zero;
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

bool is_int(const rational &x) {
    return mp::abs(mp::denominator(x)) == 1;
}

bool Polynomial::isInt() const {
    if (addends.size() == 1) {
        const auto &[monomial, coeff] {*addends.begin()};
        return monomial.empty() && is_int(coeff);
    }
    return false;
}

bool Polynomial::isRational() const {
    return addends.size() == 1 && addends.begin()->first.empty();
}

std::optional<NumVar> Polynomial::isUnivariate() const {
    std::optional<NumVar> var;
    for (const auto &[monomial, _]: addends) {
        if (monomial.size() > 1) {
            return {};
        }
        const auto &x {monomial.begin()->first};
        if (!var) {
            var = x;
        } else if (*var != x) {
            return {};
        }
    }
    return var;
}

NumVar Polynomial::someVar() const {
    return addends.begin()->first.begin()->first;
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

bool is_linear(const Polynomial::Monomial &monomial) {
    return monomial.empty() || (monomial.size() == 1 && monomial.begin()->second == 1);
}

bool Polynomial::isVar() const {
    auto it {addends.begin()};
    const auto &[monomial, coeff] {*it};
    if (!is_linear(monomial)) {
        return false;
    }
    if (addends.size() == 1) {
        return coeff == 1;
    } else if (addends.size() == 2) {
        ++it;
        const auto &[monomial_2, coeff_2] {*it};
        if (!is_linear(monomial_2)) {
            return false;
        }
        return (monomial.empty() && coeff_2 == 1) || (monomial_2.empty() && coeff == 1);
    }
    return false;
}

NumVar Polynomial::toVar() const {
    assert(isVar());
    for (const auto &[monomial, _]: addends) {
        if (!monomial.empty()) {
            return monomial.begin()->first;
        }
    }
    throw std::invalid_argument("toVar on constant polynomial");
}

rational Polynomial::toRational() const {
    assert(isRational());
    return addends.begin()->second;
}

Polynomial Polynomial::add(const std::vector<Polynomial> &polys) {
    if (polys.empty()) {
        return zero;
    }
    auto poly_it {polys.begin()};
    std::map<Monomial, rational> addends {poly_it->addends};
    for (++poly_it; poly_it != polys.end(); ++poly_it) {
        for (const auto &[monomial, coeff]: poly_it->addends) {
            auto it {addends.find(monomial)};
            if (it == addends.end()) {
                addends.emplace(monomial, coeff);
            } else {
                it->second += coeff;
            }
        }
    }
    return Polynomial(addends);
}

Polynomial Polynomial::mult(const std::vector<Polynomial> &polys) {
    if (polys.empty()) {
        return mk(1);
    }
    auto poly_it {polys.begin()};
    std::map<Monomial, rational> addends;
    std::map<Monomial, rational> res{poly_it->addends};
    for (++poly_it; poly_it != polys.end(); ++poly_it) {
        addends = res;
        res.clear();
        for (const auto &[monomial_1, coeff_1]: addends) {
            for (const auto &[monomial_2, coeff_2]: poly_it->addends) {
                const auto coeff {coeff_1 * coeff_2};
                Monomial monomial {monomial_1};
                for (const auto &[var, degree]: monomial_2) {
                    auto it {monomial.find(var)};
                    if (it == monomial.end()) {
                        res.emplace(var, degree);
                    } else {
                        it->second += degree;
                    }
                }
                auto it {res.find(monomial)};
                if (it == res.end()) {
                    res.emplace(monomial, coeff);
                } else {
                    it->second += coeff;
                }
            }
        }
    }
    return Polynomial(res);
}

rational power(const rational &x, const integer &exp) {
    auto power {x};
    for (integer i = 1; i < exp;) {
        if (2 * i <= exp) {
            power *= power;
            i *= 2;
        } else {
            power *= x;
            ++i;
        }
    }
    return power;
}

Polynomial Polynomial::pow(const integer &exp) const {
    std::map<Monomial, rational> addends;
    for (const auto &[monomial, coeff]: this->addends) {
        auto new_monomial(monomial);
        for (auto &[_, degree]: new_monomial) {
            degree *= exp;
        }
        addends.emplace(new_monomial, power(coeff, exp));
    }
    return Polynomial(addends);
}

Polynomial Polynomial::subs(const Subs &subs) const {
    std::vector<Polynomial> addends;
    for (const auto &[monomial, coeff]: this->addends) {
        std::vector<Polynomial> factors;
        for (const auto &[var, degree]: monomial) {
            factors.emplace_back(subs.get(var).pow(degree));
        }
        factors.emplace_back(mk(coeff));
        addends.emplace_back(mult(factors));
    }
    return add(addends);
}

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
            currSubs.put(vars[i], mk(subs[i]));
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
