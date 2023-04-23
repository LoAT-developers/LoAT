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

RationalNumber::RationalNumber(const mp::cpp_rational &val): val(val) {}

Integer RationalNumber::numerator() const {
    return Integer(mp::numerator(val));
}

Integer RationalNumber::denominator() const {
    return Integer(mp::numerator(val));
}
bool RationalNumber::isLinear() const {
    return true;
}

bool RationalNumber::isPoly() const {
    return true;
}

bool RationalNumber::isNaturalPow() const {
    return false;
}

unsigned RationalNumber::maxDegree() const {
    return 0;
}

Integer RationalNumber::totalDegree() const {
    return 0;
}

void RationalNumber::collectVars(std::set<NumVar> &res) const {
    return;
}

std::set<NumVar> RationalNumber::vars() const {
    return {};
}

bool RationalNumber::isConstant() const {
    return true;
}

bool RationalNumber::isInt() const {
    return denominator() == 0;
}

bool RationalNumber::isRational() const {
    return true;
}

bool RationalNumber::isUnivariate() const {
    return false;
}

virtual NumVar someVar() const;
virtual bool isNotMultivariate() const;
virtual bool isMultivariate() const;
virtual unsigned degree(const NumVar &var) const;
virtual Expr coeff(const NumVar &var, int degree = 1) const;
virtual Expr lcoeff(const NumVar &var) const;
virtual bool isVar() const;
virtual bool isPow() const;
virtual bool isMul() const;
virtual bool isAdd() const;
virtual NumVar toVar() const;
virtual ::Rational toRational() const;
virtual Expr op(unsigned int i) const;
virtual size_t arity() const;
virtual Expr subs(const ExprSubs &map) const;
virtual bool isPoly(const NumVar &n) const;
virtual Integer denomLcm() const;
virtual std::optional<std::string> toQepcad() const;
virtual std::optional<Expr> solveTermFor(const NumVar &var, SolvingLevel level) const;

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

std::optional<std::string> Expr::toQepcad() const {
    if (!this->isPoly()) return {};
    return toQepcadRec(this->expand());
}

//std::optional<Expr> Expr::solveTermFor(const NumVar &var, SolvingLevel level) const {
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

//ExprSubs::ExprSubs(std::initializer_list<std::pair<const NumVar, Expr>> init): map(init) {
//    for (const auto &p: init) {
//        putGinac(p.first, p.second);
//    }
//}

//Expr ExprSubs::get(const NumVar &key) const {
//    const auto it = map.find(key);
//    return it == map.end() ? key : it->second;
//}

//void ExprSubs::put(const NumVar &key, const Expr &val) {
//    map[key] = val;
//    putGinac(key, val);
//}

//ExprSubs::const_iterator ExprSubs::begin() const {
//    return map.begin();
//}

//ExprSubs::const_iterator ExprSubs::end() const {
//    return map.end();
//}

//ExprSubs::const_iterator ExprSubs::find(const NumVar &e) const {
//    return map.find(e);
//}

//bool ExprSubs::contains(const NumVar &e) const {
//    return map.find(e) != map.end();
//}

//bool ExprSubs::empty() const {
//    return map.empty();
//}

//unsigned int ExprSubs::size() const {
//    return map.size();
//}

//size_t ExprSubs::erase(const NumVar &key) {
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

//ExprSubs ExprSubs::project(const std::set<NumVar> &vars) const {
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

//ExprSubs ExprSubs::setminus(const std::set<NumVar> &vars) const {
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

//void ExprSubs::putGinac(const NumVar &key, const Expr &val) {
//    ginacMap[*key] = val.ex;
//}

//void ExprSubs::eraseGinac(const NumVar &key) {
//    ginacMap.erase(*key);
//}

//bool ExprSubs::changes(const NumVar &key) const {
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

//void ExprSubs::collectDomain(std::set<NumVar> &vars) const {
//    for (const auto &p: *this) {
//        vars.insert(p.first);
//    }
//}

//void ExprSubs::collectCoDomainVars(std::set<NumVar> &vars) const {
//    for (const auto &p: *this) {
//        p.second.collectVars(vars);
//    }
//}

//void ExprSubs::collectVars(std::set<NumVar> &vars) const {
//    collectCoDomainVars(vars);
//    collectDomain(vars);
//}

//std::set<NumVar> ExprSubs::domain() const {
//    std::set<NumVar> res;
//    collectDomain(res);
//    return res;
//}

//std::set<NumVar> ExprSubs::coDomainVars() const {
//    std::set<NumVar> res;
//    collectCoDomainVars(res);
//    return res;
//}

//std::set<NumVar> ExprSubs::allVars() const {
//    std::set<NumVar> res;
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
