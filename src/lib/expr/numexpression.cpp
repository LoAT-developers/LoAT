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

Polynomial::Polynomial(const std::map<Monomial, rational> &monomials): monomials(monomials) {}

bool Polynomial::isLinear() const {
    for (const auto &p: monomials) {
        if (p.first.size() > 1) {
            return false;
        }
        if (!p.first.empty() && p.first.begin()->second > 1) {
            return false;
        }
    }
    return true;
}

integer Polynomial::maxDegree() const;
integer Polynomial::totalDegree() const;
void Polynomial::collectVars(std::set<NumVar> &res) const;
std::set<NumVar> Polynomial::vars() const;
bool Polynomial::isConstant() const;
bool Polynomial::isInt() const;
bool Polynomial::isRational() const;
bool Polynomial::isUnivariate() const;
NumVar Polynomial::someVar() const;
bool Polynomial::isNotMultivariate() const;
bool Polynomial::isMultivariate() const;
unsigned Polynomial::degree(const NumVar &var) const;
Polynomial Polynomial::coeff(const NumVar &var, int degree = 1) const;
Polynomial Polynomial::lcoeff(const NumVar &var) const;
bool Polynomial::isVar() const;
NumVar Polynomial::toVar() const;
rational Polynomial::toRational() const;
//    Expr subs(const ExprSubs &map) const;
std::optional<std::string> Polynomial::toQepcad() const;
std::optional<Polynomial> Polynomial::solveFor(const NumVar &var, SolvingLevel level) const;

friend bool operator==(const Monomial&, const Monomial&);
friend std::strong_ordering operator<=>(const Monomial&, const Monomial&);
friend bool operator==(const Polynomial&, const Polynomial&);
friend std::strong_ordering operator<=>(const Polynomial&, const Polynomial&);

//std::string toQepcadRec(const Expr& e) {
//    if (e.isInt() || e.isVar()) {
//        return e.toString();
//    } else if (e.isAdd()) {
//        unsigned arity = e.arity();
//        if (arity == 0) {
//            return "0";
//        }
//        std::string res = toQepcadRec(e.op(0));
//        for (unsigned i = 1; i < arity; ++i) {
//            std::string subRes = toQepcadRec(e.op(i));
//            if (subRes[0] != '-') {
//                res += "+";
//            }
//            res += subRes;
//        }
//        return res;
//    } else if (e.isMul()) {
//        unsigned arity = e.arity();
//        if (arity == 0) {
//            return "1";
//        }
//        bool sign = true;
//        Expr constant = 1;
//        for (unsigned i = 0; i < arity; ++i) {
//            const auto op = e.op(i);
//            if (op.isRationalConstant()) {
//                constant = constant * op;
//                if (op.toNum().is_negative()) {
//                    sign = !sign;
//                    constant = -constant;
//                }
//            }
//        }
//        constant = constant.expand();
//        if (constant.toNum().is_zero()) {
//            return "0";
//        }
//        std::string res = sign ? "" : "-";
//        bool skip;
//        if (constant.toNum().is_equal(1)) {
//            skip = true;
//        } else {
//            res += constant.toString();
//            skip = false;
//        }
//        for (unsigned i = 0; i < arity; ++i) {
//            if (!e.op(i).isRationalConstant()) {
//                if (skip) {
//                    skip = false;
//                } else {
//                    res += " ";
//                }
//                res = res + toQepcadRec(e.op(i));
//            }
//        }
//        return res;
//    } else if (e.isNaturalPow()) {
//        return toQepcadRec(e.op(0)) + "^" + toQepcadRec(e.op(1));
//    } else if (e.isRationalConstant()) {
//        return e.numerator().toString() + "/" + e.denominator().toString();
//    } else {
//        throw std::invalid_argument("conversion to Qepcad failed for polynomial " + e.toString());
//    }
//}

//std::optional<Expr> Expr::solveTermFor(const IntVar &var, SolvingLevel level) const {
//    // expand is needed before using degree/coeff
//    Expr term = this->expand();

//    // we can only solve linear expressions...
//    if (term.degree(var) != 1) return {};

//    // ...with rational coefficients
//    Expr c = term.coeff(var);
//    if (!c.isRationalConstant()) return {};

//    bool trivialCoeff = (c == 1 || c == -1);

//    if (level == TrivialCoeffs && !trivialCoeff) {
//        return {};
//    }

//    term = (term - c*var) / (-c);

//    // If c is trivial, we don't have to check if the result maps to int,
//    // since we assume that all constraints in the guard map to int.
//    // So if c is trivial, we can also handle non-polynomial terms.
//    if (level == ResultMapsToInt && !trivialCoeff) {
//        if (!term.isPoly() || !term.isIntegral()) return {};
//    }

//    // we assume that terms in the guard map to int, make sure this is the case
//    if (trivialCoeff) {
//        assert(!term.isPoly() || term.isIntegral());
//    }

//    return {term};
//}

bool operator==(const Expr &e1, const Expr &e2) {
    return e1.ex.is_equal(e2.ex);
}

std::ostream& operator<<(std::ostream &s, const Expr &e) {
    return s << e.ex;
}

//ExprSubs::ExprSubs() {}

//ExprSubs::ExprSubs(std::initializer_list<std::pair<const IntVar, Expr>> init): map(init) {
//    for (const auto &p: init) {
//        putGinac(p.first, p.second);
//    }
//}

//Expr ExprSubs::get(const IntVar &key) const {
//    const auto it = map.find(key);
//    return it == map.end() ? key : it->second;
//}

//void ExprSubs::put(const IntVar &key, const Expr &val) {
//    map[key] = val;
//    putGinac(key, val);
//}

//ExprSubs::const_iterator ExprSubs::begin() const {
//    return map.begin();
//}

//ExprSubs::const_iterator ExprSubs::end() const {
//    return map.end();
//}

//ExprSubs::const_iterator ExprSubs::find(const IntVar &e) const {
//    return map.find(e);
//}

//bool ExprSubs::contains(const IntVar &e) const {
//    return map.find(e) != map.end();
//}

//bool ExprSubs::empty() const {
//    return map.empty();
//}

//unsigned int ExprSubs::size() const {
//    return map.size();
//}

//size_t ExprSubs::erase(const IntVar &key) {
//    eraseGinac(key);
//    return map.erase(key);
//}

//ExprSubs ExprSubs::compose(const ExprSubs &that) const {
//    ExprSubs res;
//    for (const auto &p: *this) {
//        res.put(p.first, p.second.subs(that));
//    }
//    for (const auto &p: that) {
//        if (!res.contains(p.first)) {
//            res.put(p.first, p.second);
//        }
//    }
//    return res;
//}

//ExprSubs ExprSubs::concat(const ExprSubs &that) const {
//    ExprSubs res;
//    for (const auto &p: *this) {
//        res.put(p.first, p.second.subs(that));
//    }
//    return res;
//}

//ExprSubs ExprSubs::unite(const ExprSubs &that) const {
//    ExprSubs res;
//    for (const auto &p: *this) {
//        res.put(p.first, p.second);
//    }
//    for (const auto &p: that) {
//        if (res.find(p.first) != res.end()) {
//            throw std::invalid_argument("union of substitutions is only defined if their domain is disjoint");
//        }
//        res.put(p.first, p.second);
//    }
//    return res;
//}

//ExprSubs ExprSubs::project(const std::set<IntVar> &vars) const {
//    ExprSubs res;
//    if (size() < vars.size()) {
//        for (const auto &p: *this) {
//            if (vars.find(p.first) != vars.end()) {
//                res.put(p.first, p.second);
//            }
//        }
//    } else {
//        for (const auto &x: vars) {
//            const auto it {find(x)};
//            if (it != end()) {
//                res.put(it->first, it->second);
//            }
//        }
//    }
//    return res;
//}

//ExprSubs ExprSubs::setminus(const std::set<IntVar> &vars) const {
//    if (size() < vars.size()) {
//        ExprSubs res;
//        for (const auto &p: *this) {
//            if (vars.find(p.first) == vars.end()) {
//                res.put(p.first, p.second);
//            }
//        }
//        return res;
//    } else {
//        ExprSubs res(*this);
//        for (const auto &x: vars) {
//            res.erase(x);
//        }
//        return res;
//    }
//}

//void ExprSubs::putGinac(const IntVar &key, const Expr &val) {
//    ginacMap[*key] = val.ex;
//}

//void ExprSubs::eraseGinac(const IntVar &key) {
//    ginacMap.erase(*key);
//}

//bool ExprSubs::changes(const IntVar &key) const {
//    return contains(key) && get(key) != key;
//}

//bool ExprSubs::isLinear() const {
//    return std::all_of(begin(), end(), [](const auto &p) {
//       return p.second.isLinear();
//    });
//}

//bool ExprSubs::isPoly() const {
//    return std::all_of(begin(), end(), [](const auto &p) {
//       return p.second.isPoly();
//    });
//}

//bool ExprSubs::isOctagon() const {
//    return std::all_of(begin(), end(), [](const auto &p) {
//       return p.second.isOctagon();
//    });
//}

//void ExprSubs::collectDomain(std::set<IntVar> &vars) const {
//    for (const auto &p: *this) {
//        vars.insert(p.first);
//    }
//}

//void ExprSubs::collectCoDomainVars(std::set<IntVar> &vars) const {
//    for (const auto &p: *this) {
//        p.second.collectVars(vars);
//    }
//}

//void ExprSubs::collectVars(std::set<IntVar> &vars) const {
//    collectCoDomainVars(vars);
//    collectDomain(vars);
//}

//std::set<IntVar> ExprSubs::domain() const {
//    std::set<IntVar> res;
//    collectDomain(res);
//    return res;
//}

//std::set<IntVar> ExprSubs::coDomainVars() const {
//    std::set<IntVar> res;
//    collectCoDomainVars(res);
//    return res;
//}

//std::set<IntVar> ExprSubs::allVars() const {
//    std::set<IntVar> res;
//    collectVars(res);
//    return res;
//}

std::ostream& operator<<(std::ostream &s, const ExprSubs &map) {
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
