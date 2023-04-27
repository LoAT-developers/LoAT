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

Expr::Expr(const std::map<std::optional<Exp>, Polynomial> &addends): addends(addends) {}

Expr Expr::zero {{{{}, Polynomial::mk(0)}}};

Expr Expr::mk(const std::map<std::optional<Exp>, Polynomial> &addends) {
    if (addends.empty()) {
        return zero;
    }
    Expr res(addends);
    for (auto it = res.addends.begin(); it != res.addends.end();) {
        auto &[exp, coeff] {*it};
        if (exp && coeff.isZero()) {
            it = res.addends.erase(it);
        } else {
            assert(!exp || exp->base > 0);
            ++it;
        }
    }
    return res;
}

Expr Expr::mk(const rational &x) {
    if (x == 0) {
        return zero;
    }
    return Expr({{{}, Polynomial::mk(x)}});
}

void Expr::collectVars(std::set<NumVar> &res) const {
    for (const auto &[exp, coeff]: addends) {
        coeff.collectVars(res);
        if (exp) {
            res.insert(exp->exponent);
        }
    }
}

std::set<NumVar> Expr::vars() const {
    std::set<NumVar> res;
    collectVars(res);
    return res;
}

bool Expr::isInt() const {
    if (addends.size() > 1) {
        return false;
    }
    const auto &[exp, coeff] {*addends.begin()};
    return !exp && coeff.isInt();
}

bool Expr::isRational() const {
    if (addends.size() > 1) {
        return false;
    }
    const auto &[exp, coeff] {*addends.begin()};
    return !exp && coeff.isRational();
}

std::optional<NumVar> Expr::isUnivariate() const {
    std::optional<NumVar> var;
    for (const auto &[exp, coeff]: addends) {
        if (!coeff.isRational()) {
            if (!var) {
                var = coeff.isUnivariate();
                if (!var) {
                    return {};
                }
            } else {
                const auto coeffVar {coeff.isUnivariate()};
                if (coeffVar != var) {
                    return {};
                }
            }
        }
        if (exp) {
            if (!var) {
                var = exp->exponent;
            } else if (*var != exp->exponent) {
                return {};
            }
        }
    }
    return var;
}

NumVar Expr::someVar() const {
    for (const auto &[exp, coeff]: addends) {
        if (exp) {
            return exp->exponent;
        } else if (!coeff.isRational()) {
            return coeff.someVar();
        }
    }
    throw std::invalid_argument("someVar on ground expression");
}

bool Expr::isMultivariate() const {
    std::optional<NumVar> var;
    for (const auto &[exp, coeff]: addends) {
        if (!coeff.isRational()) {
            auto coeffVar {coeff.isUnivariate()};
            auto ground {coeff.isRational()};
            if (!ground && !coeffVar) {
                return true;
            }
            if (!var) {
                var = coeffVar;
            } else if (!ground && var != coeffVar) {
                return true;
            }
        }
        if (exp) {
            if (!var) {
                var = exp->exponent;
            } else if (*var != exp->exponent) {
                return true;
            }
        }
    }
    return false;
}

bool Expr::isVar() const {
    if (addends.size() > 1) {
        return false;
    }
    auto it {addends.begin()};
    const auto &[exp, coeff] {*it};
    return !exp->base && coeff.isVar();
}

NumVar Expr::toVar() const {
    assert(isVar());
    return addends.begin()->second.toVar();
}

rational Expr::toRational() const {
    assert(isRational());
    return addends.begin()->second.toRational();
}

Expr Expr::add(const std::vector<Expr> &exprs) {
    if (exprs.empty()) {
        return zero;
    }
    auto expr_it {exprs.begin()};
    std::map<std::optional<Exp>, Polynomial> addends {expr_it->addends};
    for (++expr_it; expr_it != exprs.end(); ++expr_it) {
        for (const auto &[exp, coeff]: expr_it->addends) {
            auto it {addends.find(exp)};
            if (it == addends.end()) {
                addends.emplace(exp, coeff);
            } else {
                it->second = Polynomial::add({coeff, it->second});
            }
        }
    }
    return Expr(addends);
}

Expr Expr::mult(const std::vector<Expr> &exprs) {
    if (exprs.empty()) {
        return mk(1);
    }
    std::map<std::optional<Exp>, std::vector<Polynomial>> addends;
    std::map<std::optional<Exp>, std::vector<Polynomial>> res;
    for (auto expr_it = exprs.begin(); expr_it != exprs.end(); ++expr_it) {
        addends = res;
        res.clear();
        for (const auto &[exp_1, coeffs_1]: addends) {
            for (const auto &[exp_2, coeff_2]: expr_it->addends) {
                std::vector<Polynomial> coeffs {coeffs_1};
                coeffs.emplace_back(coeff_2);
                if (exp_1 && exp_2 && exp_1->exponent != exp_2->exponent) {
                    throw std::invalid_argument("Expr::mult called with exponentials with different exponents");
                }
                std::optional<Exp> exp;
                if (exp_1 && !exp_2) {
                    exp = exp_1;
                } else if (!exp_1 && exp_2) {
                    exp = exp_2;
                } else {
                    exp = {.base = exp_1->base * exp_2->base, .exponent = exp_1->exponent};
                }
                auto it {res.find(exp)};
                if (it == res.end()) {
                    res.emplace(exp, coeffs);
                } else {
                    it->second.insert(it->second.end(), coeffs.begin(), coeffs.end());
                }
            }
        }
    }
    std::map<std::optional<Exp>, Polynomial> multiplied;
    for (const auto &[exp, coeffs]: addends) {
        multiplied.emplace(exp, Polynomial::mult(coeffs));
    }
    return Expr(multiplied);
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
        factors.emplace_back(coeff);
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
            currSubs.put(vars[i], Polynomial(subs[i]));
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
