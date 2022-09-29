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

#include "expression.hpp"
#include "exceptions.hpp"

#include <sstream>

using namespace std;

bool Expr_is_less::operator()(const Expr &lh, const Expr &rh) const {
     return lh.compare(rh) < 0;
}

bool Var_is_less::operator()(const Var &lh, const Var &rh) const {
     return lh.get_name().compare(rh.get_name()) < 0;
}

const Var Expr::NontermSymbol = GiNaC::symbol("NONTERM");

void Expr::applySubs(const ExprSubs &subs) {
    this->ex = this->ex.subs(subs.ginacMap);
}

bool Expr::findAll(const Expr &pattern, ExprSet &found) const {
    bool anyFound = false;

    if (match(pattern)) {
        found.insert(*this);
        anyFound = true;
    }

    for (size_t i = 0; i < arity(); i++) {
        if (op(i).findAll(pattern, found)) {
            anyFound = true;
        }
    }

    return anyFound;
}


bool Expr::equals(const Var &var) const {
    return this->compare(var) == 0;
}


bool Expr::isNontermSymbol() const {
    return equals(NontermSymbol);
}


bool Expr::isLinear(const option<VarSet> &vars) const {
    VarSet theVars = vars ? vars.get() : this->vars();
    // linear expressions are always polynomials
    if (!isPoly()) return false;

    // degree only works reliable on expanded expressions (despite the tutorial stating otherwise)
    Expr expanded = expand();

    // GiNaC does not provide an info flag for this, so we check the degree of every variable.
    // We also have to check if the coefficient contains variables,
    // e.g. y has degree 1 in x*y, but we don't consider x*y to be linear.
    for (const Var &var : theVars) {
        int deg = expanded.degree(var);
        if (deg > 1 || deg < 0) {
            return false;
        }

        if (deg == 1) {
            VarSet coefficientVars = expanded.coeff(var,deg).vars();
            for (const Var &e: coefficientVars) {
                if (theVars.find(e) != theVars.end()) {
                    return false;
                }
            }
        }
    }
    return true;
}


bool Expr::isPoly() const {
    return ex.info(GiNaC::info_flags::polynomial);
}

bool Expr::isPoly(const Var &n) const {
    return ex.is_polynomial(n);
}


bool Expr::isIntPoly() const {
    return ex.info(GiNaC::info_flags::integer_polynomial);
}


bool Expr::isInt() const {
    return ex.info(GiNaC::info_flags::integer);
}


bool Expr::isRationalConstant() const {
    return ex.info(GiNaC::info_flags::rational);
}


bool Expr::isNonIntConstant() const {
    return ex.info(GiNaC::info_flags::rational)
           && !ex.info(GiNaC::info_flags::integer);
}


bool Expr::isNaturalPow() const {
    if (!this->isPow()) {
        return false;
    }

    Expr power = this->op(1);
    if (!power.isInt()) {
        return false;
    }

    return power.toNum() > 1;
}

bool Expr::isOctagon() const {
    if (!isPoly()) return false;
    const VarSet vs = vars();
    if (vs.size() > 2) return false;
    for (const auto &v: vs) {
        if (degree(v) > 1) return false;
        const Expr c = coeff(v);
        if (!c.isInt()) return false;
        if (std::abs(c.toNum().to_int()) > 1) return false;
    }
    return true;
}

int Expr::maxDegree() const {
    assert(isPoly());
    Expr expanded = expand();

    int res = 0;
    for (const auto &var : vars()) {
        res = std::max(res, expanded.degree(var));
    }
    return res;
}


void Expr::collectVars(VarSet &res) const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        SymbolVisitor(VarSet &t) : target(t) {}
        void visit(const GiNaC::symbol &sym) {
            if (sym != NontermSymbol) target.insert(sym);
        }
    private:
        VarSet &target;
    };

    SymbolVisitor v(res);
    traverse(v);
}


VarSet Expr::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}


bool Expr::isGround() const {
    return !hasVarWith([](const Var &) { return true; });
}


bool Expr::isUnivariate() const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        void visit(const GiNaC::symbol &var) {
            if (foundVar == nullptr) {
                foundVar = &var;
                exactlyOneVar = true;

            } else if (exactlyOneVar && var != *foundVar) {
                exactlyOneVar = false;
            }
        }
        bool result() const {
            return exactlyOneVar;
        }
    private:
        bool exactlyOneVar = false;
        const GiNaC::symbol *foundVar = nullptr;
    };

    SymbolVisitor visitor;
    traverse(visitor);
    return visitor.result();
}


Var Expr::someVar() const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        void visit(const GiNaC::symbol &var) {
            variable = var;
        }
        Var result() const {
            return variable;
        }
    private:
        Var variable;
    };

    SymbolVisitor visitor;
    traverse(visitor);
    return visitor.result();
}


bool Expr::isNotMultivariate() const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        void visit(const GiNaC::symbol &var) {
            if (foundVar == nullptr) {
                foundVar = &var;

            } else if (var != *foundVar) {
                atMostOneVar = false;
            }
        }
        bool result() const {
            return atMostOneVar;
        }
    private:
        bool atMostOneVar = true;
        const GiNaC::symbol *foundVar = nullptr;
    };

    SymbolVisitor visitor;
    traverse(visitor);
    return visitor.result();
}


bool Expr::isMultivariate() const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        void visit(const GiNaC::symbol &var) {
            if (foundVar == nullptr) {
                foundVar = &var;

            } else if (var != *foundVar) {
                atLeastTwoVars = true;
            }
        }
        bool result() const {
            return atLeastTwoVars;
        }
    private:
        bool atLeastTwoVars = false;
        const GiNaC::symbol *foundVar = nullptr;
    };

    SymbolVisitor visitor;
    traverse(visitor);
    return visitor.result();
}

string Expr::toString() const {
    stringstream ss;
    ss << *this;
    return ss.str();
}

bool Expr::equals(const Expr &that) const {
    return ex.is_equal(that.ex);
}

int Expr::degree(const Var &var) const {
    return ex.degree(var);
}

int Expr::ldegree(const Var &var) const {
    return ex.ldegree(var);
}

Expr Expr::coeff(const Var &var, int degree) const {
    return ex.coeff(var, degree);
}

Expr Expr::lcoeff(const Var &var) const {
    return ex.lcoeff(var);
}

Expr Expr::expand() const {
    return ex.expand();
}

bool Expr::has(const Expr &pattern) const {
    return ex.has(pattern.ex);
}

bool Expr::isZero() const {
    return ex.is_zero();
}

bool Expr::isVar() const {
    return ex.info(GiNaC::info_flags::symbol);
}

bool Expr::isPow() const {
    return GiNaC::is_a<GiNaC::power>(ex);
}

bool Expr::isMul() const {
    return GiNaC::is_a<GiNaC::mul>(ex);
}

bool Expr::isAdd() const {
    return GiNaC::is_a<GiNaC::add>(ex);
}

Var Expr::toVar() const {
    return GiNaC::ex_to<GiNaC::symbol>(ex);
}

GiNaC::numeric Expr::toNum() const {
    return GiNaC::ex_to<GiNaC::numeric>(ex);
}

Expr Expr::op(unsigned int i) const {
    return ex.op(i);
}

size_t Expr::arity() const {
    return ex.nops();
}

Expr Expr::subs(const ExprSubs &map) const {
    return ex.subs(map.ginacMap);
}

void Expr::traverse(GiNaC::visitor &v) const {
    ex.traverse(v);
}

int Expr::compare(const Expr &that) const {
    return ex.compare(that.ex);
}

unsigned Expr::hash() const {
    return ex.gethash();
}

Expr Expr::numerator() const {
    return ex.numer();
}

Expr Expr::denominator() const {
    return ex.denom();
}

bool Expr::match(const Expr &pattern) const {
    return ex.match(pattern.ex);
}

Expr operator-(const Expr &x) {
    return -x.ex;
}

Expr operator-(const Expr &x, const Expr &y) {
    return x.ex - y.ex;
}

Expr operator+(const Expr &x, const Expr &y) {
    return x.ex + y.ex;
}

Expr operator*(const Expr &x, const Expr &y) {
    return x.ex * y.ex;
}

Expr operator/(const Expr &x, const Expr &y) {
    return x.ex / y.ex;
}

Expr operator^(const Expr &x, const Expr &y) {
    return GiNaC::pow(x.ex, y.ex);
}

Expr Expr::wildcard(unsigned int label) {
    return GiNaC::wild(label);
}

Num Expr::denomLcm() const {
    const Expr &denom = Expr::wildcard(0);
    const Expr &num = Expr::wildcard(1);
    const Expr &pattern = denom / num;
    ExprSet matches;
    GiNaC::numeric lcm = 1;
    findAll(pattern, matches);
    for (const Expr &e: matches) {
        lcm = GiNaC::lcm(lcm, e.denominator().toNum());
    }
    return lcm;
}

Expr Expr::toIntPoly() const {
    GiNaC::numeric lcm = denomLcm();
    return lcm == 1 ? *this : *this * lcm;
}

bool Expr::isIntegral() const {
    assert(isPoly());

    // shortcut for the common case
    if (isIntPoly()) {
        return true;
    }

    // collect variables from e into a vector
    vector<Var> vars;
    for (Var sym : this->vars()) {
        vars.push_back(sym);
    }

    // degrees, subs share indices with vars
    vector<int> degrees;
    vector<int> subs;
    Expr expanded = expand();
    for (const Var &x: vars) {
        degrees.push_back(expanded.degree(x));
        subs.push_back(0);
    }

    while (true) {
        // substitute every variable x_i by the integer subs[i] and check if the result is an integer
        ExprSubs currSubs;
        for (unsigned int i = 0; i < degrees.size(); i++) {
            currSubs.put(vars[i], subs[i]);
        }
        Expr res = this->subs(currSubs).expand();
        if (!res.isInt()) {
            return false;
        }

        // increase subs (lexicographically) if possible
        // (the idea is that subs takes all possible combinations of 0,...,degree[i]+1 for every entry i)
        bool foundNext = false;
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

std::string toQepcadRec(const Expr& e) {
    if (e.isInt() || e.isVar()) {
        return e.toString();
    } else if (e.isAdd()) {
        unsigned arity = e.arity();
        if (arity == 0) {
            return "0";
        }
        std::string res = toQepcadRec(e.op(0));
        for (unsigned i = 1; i < arity; ++i) {
            std::string subRes = toQepcadRec(e.op(i));
            if (subRes[0] != '-') {
                res += "+";
            }
            res += subRes;
        }
        return res;
    } else if (e.isMul()) {
        unsigned arity = e.arity();
        if (arity == 0) {
            return "1";
        }
        bool sign = true;
        Expr constant = 1;
        for (unsigned i = 0; i < arity; ++i) {
            const auto op = e.op(i);
            if (op.isRationalConstant()) {
                constant = constant * op;
                if (op.toNum().is_negative()) {
                    sign = !sign;
                    constant = -constant;
                }
            }
        }
        constant = constant.expand();
        if (constant.toNum().is_zero()) {
            return "0";
        }
        std::string res = sign ? "" : "-";
        bool skip;
        if (constant.toNum().is_equal(1)) {
            skip = true;
        } else {
            res += constant.toString();
            skip = false;
        }
        for (unsigned i = 0; i < arity; ++i) {
            if (!e.op(i).isRationalConstant()) {
                if (skip) {
                    skip = false;
                } else {
                    res += " ";
                }
                res = res + toQepcadRec(e.op(i));
            }
        }
        return res;
    } else if (e.isNaturalPow()) {
        return toQepcadRec(e.op(0)) + "^" + toQepcadRec(e.op(1));
    } else if (e.isRationalConstant()) {
        return e.numerator().toString() + "/" + e.denominator().toString();
    } else {
        throw QepcadError("conversion to Qepcad failed for polynomial " + e.toString());
    }
}

option<std::string> Expr::toQepcad() const {
    if (!this->isPoly()) return {};
    return toQepcadRec(this->expand());
}

Sign::T Expr::sign() const {
    using namespace Sign;
    if (isRationalConstant()) {
        const auto num = toNum();
        if (num.is_zero()) return Zero;
        if (num.is_positive()) return Positive;
        return Negative;
    } else if (isAdd()) {
        T res = Zero;
        for (size_t i = 0; i < arity(); ++i) {
            T subres = op(i).sign();
            if (subres == Unknown) return Unknown;
            if (res != subres) {
                if (res == Zero) res = subres;
                else return Unknown;
            }
        }
        return res;
    } else if (isMul()) {
        T res = Positive;
        for (size_t i = 0; i < arity(); ++i) {
            T subres = op(i).sign();
            if (subres == Unknown || subres == Zero) return subres;
            if (res == subres) {
                if (subres == Negative) res = Positive;
            } else {
                res = Negative;
            }
        }
        return res;
    } else if (isNaturalPow()) {
        T res = op(0).sign();
        if (res != Negative) return res;
        int pow = op(1).toNum().to_int();
        if (pow % 2 == 0) return Positive;
        return Negative;
    }
    return Unknown;
}

Monotonicity::T Expr::monotonicity(const Var &x) const {
    using namespace Monotonicity;
    const Expr diff = this->subs({x, Expr(x)+1}) - *this;
    switch (diff.sign()) {
    case Sign::Zero: return Constant;
    case Sign::Positive: return Increasing;
    case Sign::Negative: return Decreasing;
    default: return Unknown;
    }
}

namespace Monotonicity {

std::ostream& operator<<(std::ostream &s, const T e) {
    switch (e) {
    case Increasing: s << "increasing";
        break;
    case Decreasing: s << "decreasing";
        break;
    case Constant: s << "constant";
        break;
    case Unknown: s << "unknown";
        break;
    }
    return s;
}

}

ExprSubs::ExprSubs() {}

ExprSubs::ExprSubs(const Var &key, const Expr &val) {
    put(key, val);
}

Expr ExprSubs::get(const Var &key) const {
    const auto it = map.find(key);
    return it == map.end() ? key : it->second;
}

void ExprSubs::put(const Var &key, const Expr &val) {
    map[key] = val;
    putGinac(key, val);
}

ExprSubs::const_iterator ExprSubs::begin() const {
    return map.begin();
}

ExprSubs::const_iterator ExprSubs::end() const {
    return map.end();
}

ExprSubs::const_iterator ExprSubs::find(const Var &e) const {
    return map.find(e);
}

bool ExprSubs::contains(const Var &e) const {
    return map.find(e) != map.end();
}

bool ExprSubs::empty() const {
    return map.empty();
}

unsigned int ExprSubs::size() const {
    return map.size();
}

size_t ExprSubs::erase(const Var &key) {
    eraseGinac(key);
    return map.erase(key);
}

ExprSubs ExprSubs::compose(const ExprSubs &that) const {
    ExprSubs res;
    for (const auto &p: *this) {
        res.put(p.first, p.second.subs(that));
    }
    for (const auto &p: that) {
        if (!res.contains(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

ExprSubs ExprSubs::concat(const ExprSubs &that) const {
    ExprSubs res;
    for (const auto &p: *this) {
        res.put(p.first, p.second.subs(that));
    }
    return res;
}

ExprSubs ExprSubs::project(const VarSet &vars) const {
    ExprSubs res;
    for (const auto &p: *this) {
        if (vars.find(p.first) != vars.end()) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

void ExprSubs::putGinac(const Var &key, const Expr &val) {
    ginacMap[key] = val.ex;
}

void ExprSubs::eraseGinac(const Var &key) {
    ginacMap.erase(key);
}

bool ExprSubs::changes(const Var &key) const {
    return contains(key) && !get(key).equals(key);
}

bool ExprSubs::isLinear() const {
    return std::all_of(begin(), end(), [](const std::pair<Var, Expr> &p) {
       return p.second.isLinear();
    });
}

bool ExprSubs::isPoly() const {
    return std::all_of(begin(), end(), [](const std::pair<Var, Expr> &p) {
       return p.second.isPoly();
    });
}

bool ExprSubs::isOctagon() const {
    return std::all_of(begin(), end(), [](const std::pair<Var, Expr> &p) {
       return p.second.isOctagon();
    });
}

void ExprSubs::collectDomain(VarSet &vars) const {
    for (const auto &p: *this) {
        vars.insert(p.first);
    }
}

void ExprSubs::collectCoDomainVars(VarSet &vars) const {
    for (const auto &p: *this) {
        p.second.collectVars(vars);
    }
}

void ExprSubs::collectVars(VarSet &vars) const {
    collectCoDomainVars(vars);
    collectDomain(vars);
}

VarSet ExprSubs::domain() const {
    VarSet res;
    collectDomain(res);
    return res;
}

VarSet ExprSubs::coDomainVars() const {
    VarSet res;
    collectCoDomainVars(res);
    return res;
}

VarSet ExprSubs::allVars() const {
    VarSet res;
    collectVars(res);
    return res;
}

unsigned ExprSubs::hash() const {
    unsigned hash = 7;
    for (const auto& p: *this) {
        hash = hash * 31 + p.first.gethash();
        hash = hash * 31 + p.second.hash();
    }
    return hash;
}

int ExprSubs::compare(const ExprSubs &that) const {
    if (*this == that) return 0;
    else if (*this < that) return -1;
    else return 1;
}

bool operator==(const ExprSubs &m1, const ExprSubs &m2) {
    if (m1.size() != m2.size()) {
        return false;
    }
    auto it1 = m1.begin();
    auto it2 = m2.begin();
    while (it1 != m1.end() && it2 != m2.end()) {
        if (!Expr(it1->first).equals(it2->first)) return false;
        if (!it1->second.equals(it2->second)) return false;
        ++it1;
        ++it2;
    }
    return it1 == m1.end() && it2 == m2.end();
}

std::ostream& operator<<(std::ostream &s, const ExprSubs &map) {
    if (map.empty()) {
        s << "{}";
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
    }
    return s << "}";
}

bool operator<(const ExprSubs &x, const ExprSubs &y) {
    auto it1 = x.begin();
    auto it2 = y.begin();
    while (it1 != x.end() && it2 != y.end()) {
        int fst = it1->first.compare(it2->first);
        if (fst != 0) {
            return fst < 0;
        }
        int snd = it1->second.compare(it2->second);
        if (snd != 0) {
            return snd < 0;
        }
        ++it1;
        ++it2;
    }
    return it1 == x.end() && it2 != y.end();
}
