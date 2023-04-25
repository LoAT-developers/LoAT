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

#include <variant>
#include <initializer_list>
#include <optional>
#include <boost/multiprecision/cpp_int.hpp>

#include "numvar.hpp"

namespace mp = boost::multiprecision;
using integer = mp::cpp_int;
using rational = mp::cpp_rational;

// Specifies for which coefficients c we can solve "c*x == t" for x.
enum SolvingLevel {
    TrivialCoeffs = 0, // only c=1 and c=-1 is allowed
    ResultMapsToInt = 1, // c can be any rational constant, as long as x = t/c maps to int
    ConstantCoeffs = 2, // c can be any rational constant (the result may not map to int, use with caution!)
};

template <class T>
class Substitution {

    friend auto operator<=>(const Substitution<T> &m1, const Substitution<T> &m2) = default;

public:

    using const_iterator = typename std::map<NumVar, T>::const_iterator;

    Substitution() {}

    Substitution(std::initializer_list<std::pair<const NumVar, T>> init): map(init) {}

    T get(const NumVar &key) const {
        const auto it {map.find(key)};
        return it == map.end() ? key : it->second;
    }

    void put(const NumVar &key, const T &val) {
        map[key] = val;
    }

    const_iterator begin() const {
        return map.begin();
    }

    const_iterator end() const {
        return map.end();
    }

    const_iterator find(const NumVar &e) const {
        return map.find(e);
    }

    bool contains(const NumVar &e) const {
        return map.find(e) != map.end();
    }

    bool empty() const {
        return map.empty();
    }

    unsigned int size() const {
        return map.size();
    }

    size_t erase(const NumVar &key) {
        return map.erase(key);
    }

    Substitution<T> compose(const Substitution<T> &that) const {
        Substitution<T> res;
        for (const auto &[var, val]: *this) {
            res.put(var, val.subs(that));
        }
        for (const auto &[var, val]: that) {
            if (!res.contains(var)) {
                res.put(var, val);
            }
        }
        return res;
    }

    Substitution<T> concat(const Substitution<T> &that) const {
        Substitution<T> res;
        for (const auto &[var, val]: *this) {
            res.put(var, val.subs(that));
        }
        return res;
    }

    Substitution<T> unite(const Substitution<T> &that) const {
        Substitution<T> res;
        for (const auto &[var, val]: *this) {
            res.put(var, val);
        }
        for (const auto &[var, val]: that) {
            if (res.find(var) != res.end()) {
                throw std::invalid_argument("union of substitutions is only defined if their domain is disjoint");
            }
            res.put(var, val);
        }
        return res;
    }

    Substitution<T> project(const std::set<NumVar> &vars) const {
        Substitution<T> res;
        if (size() < vars.size()) {
            for (const auto &[var, val]: *this) {
                if (vars.find(var) != vars.end()) {
                    res.put(var, val);
                }
            }
        } else {
            for (const auto &x: vars) {
                const auto it {find(x)};
                if (it != end()) {
                    res.put(it->first, it->second);
                }
            }
        }
        return res;
    }

    Substitution<T> setminus(const std::set<NumVar> &vars) const {
        if (size() < vars.size()) {
            Substitution<T> res;
            for (const auto &[var, val]: *this) {
                if (vars.find(var) == vars.end()) {
                    res.put(var, val);
                }
            }
            return res;
        } else {
            Substitution<T> res(*this);
            for (const auto &x: vars) {
                res.erase(x);
            }
            return res;
        }
    }

    bool changes(const NumVar &key) const {
        return contains(key) && get(key) != key;
    }

    bool isLinear() const {
        return std::all_of(begin(), end(), [](const auto &p) {
            return p.second.isLinear();
        });
    }

    bool isPoly() const {
        return std::all_of(begin(), end(), [](const auto &p) {
            return p.second.isPoly();
        });
    }

    std::set<NumVar> domain() const {
        std::set<NumVar> res;
        collectDomain(res);
        return res;
    }

    std::set<NumVar> coDomainVars() const {
        std::set<NumVar> res;
        collectCoDomainVars(res);
        return res;
    }

    std::set<NumVar> allVars() const {
        std::set<NumVar> res;
        collectVars(res);
        return res;
    }

    void collectDomain(std::set<NumVar> &vars) const {
        for (const auto &[var, _]: *this) {
            vars.insert(var);
        }
    }

    void collectCoDomainVars(std::set<NumVar> &vars) const {
        for (const auto &[_, val]: *this) {
            val.collectVars(vars);
        }
    }

    void collectVars(std::set<NumVar> &vars) const {
        for (const auto &[var, val]: *this) {
            vars.insert(var);
            val.collectVars(vars);
        }
    }

private:

    std::map<NumVar, T> map;

};

template <class T>
std::ostream& operator<<(std::ostream &s, const Substitution<T> &map) {
    if (map.empty()) {
        return s << "{}";
    } else {
        s << "{";
        bool fst = true;
        for (const auto &p: map) {
            if (!fst) {
                s << ", ";
            } else {
                fst = false;
            }
            s << p.first << ": " << p.second;
        }
        return s << "}";
    }
}

class Polynomial {

    using Monomial = std::map<NumVar, integer>;
    using Subs = Substitution<Polynomial>;

public:

    Polynomial(const std::map<Monomial, rational> &addends);

    bool isLinear() const;
    integer maxDegree() const;
    integer totalDegree() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isConstant() const;
    bool isInt() const;
    bool isRational() const;
    bool isUnivariate() const;
    NumVar someVar() const;
    bool isNotMultivariate() const;
    bool isMultivariate() const;
    integer degree(const NumVar &var) const;
    Polynomial coeff(const NumVar &var, integer degree = 1) const;
    bool isVar() const;
    NumVar toVar() const;
    rational toRational() const;
    bool isIntegral() const;
    bool isIntPoly() const;
    Polynomial subs(const Subs &map) const;
    std::optional<Polynomial> solveFor(const NumVar &var, SolvingLevel level) const;

    friend bool operator==(const Polynomial&, const Polynomial&) = default;
    friend std::strong_ordering operator<=>(const Polynomial&, const Polynomial&) = default;
    friend std::ostream& operator<<(std::ostream &s, const Polynomial &p);

private:

    std::map<Monomial, mp::cpp_rational> addends;

};

class Expr {

    using Subs = Substitution<Expr>;

public:

    class Exp {
        mp::cpp_int base;
        Polynomial exponent;
    };

    Expr(const std::map<Exp, Polynomial> &addends);

    bool isLinear() const;
    bool isPoly() const;
    bool isNaturalPow() const;
    void collectVars(std::set<NumVar> &res) const;
    std::set<NumVar> vars() const;
    bool isConstant() const;
    bool isInt() const;
    bool isRational() const;
    bool isUnivariate() const;
    NumVar someVar() const;
    bool isNotMultivariate() const;
    bool isMultivariate() const;
    bool isVar() const;
    bool isPow() const;
    NumVar toVar() const;
    rational toRational() const;
    Expr subs(const Subs &map) const;
    bool isPoly(const NumVar &n) const;
    std::optional<Expr> solveFor(const NumVar &var, SolvingLevel level) const;

    friend bool operator==(const Expr&, const Expr&);
    friend std::strong_ordering operator<=>(const Expr&, const Expr&);

private:

    std::map<Exp, Polynomial> addends;

};
