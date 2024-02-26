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

#include <cmath>
#include <purrs.hh>
#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>

using namespace std;

bool Expr::findAll(const Expr &pattern, linked_hash_set<Expr> &found) const {
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

bool Expr::isLinear(const std::optional<linked_hash_set<NumVar>> &vars) const {
    auto theVars = vars ? *vars : this->vars();
    // linear expressions are always polynomials
    if (!isPoly()) return false;

    // degree only works reliable on expanded expressions (despite the tutorial stating otherwise)
    Expr expanded = expand();

    // GiNaC does not provide an info flag for this, so we check the degree of every variable.
    // We also have to check if the coefficient contains variables,
    // e.g. y has degree 1 in x*y, but we don't consider x*y to be linear.
    for (const NumVar &var : theVars) {
        int deg = expanded.degree(var);
        if (deg > 1 || deg < 0) {
            return false;
        }

        if (deg == 1) {
            auto coefficientVars = expanded.coeff(var,deg).vars();
            for (const NumVar &e: coefficientVars) {
                if (theVars.contains(e)) {
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

Num Expr::totalDegree() const {
    if (isAdd()) {
        Num res(0);
        for (unsigned i = 0; i < arity(); ++i) {
            Num deg = op(i).totalDegree();
            if ((deg - res).is_positive()) {
                res = deg;
            }
        }
        return res;
    } else if (isMul()) {
        Num res(0);
        for (unsigned i = 0; i < arity(); ++i) {
            res = res + op(i).totalDegree();
        }
        return res;
    } else if (isVar()) {
        return 1;
    } else if (isPow()) {
        return op(1).toNum();
    }
    if (!isGround()) {
        std::cerr << "Expr::totalDegree: " << *this << " is not a polynomial" << std::endl;
        throw std::invalid_argument("not a polynomial");
    }
    assert(isGround());
    return 0;
}

bool Expr::isPoly(const NumVar &n) const {
    return ex.is_polynomial(*n);
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
    const auto vs = vars();
    if (vs.size() > 2) return false;
    for (const auto &v: vs) {
        if (degree(v) > 1) return false;
        const Expr c = coeff(v);
        if (!c.isInt()) return false;
        if ((c.toNum() - 1).is_positive() || (c.toNum() + 1).is_negative()) return false;
    }
    return true;
}

unsigned Expr::maxDegree() const {
    assert(isPoly());
    Expr expanded = expand();

    unsigned res = 0;
    for (const auto &var : vars()) {
        res = std::max(res, expanded.degree(var));
    }
    return res;
}

unsigned Expr::getIndex(const GiNaC::symbol &x) {
    const auto name {x.get_name()};
    if (name[1] == 't') {
        return -stoi(x.get_name().substr(2));
    } else {
        return stoi(x.get_name().substr(1));
    }
}

void Expr::collectVars(linked_hash_set<NumVar> &res) const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        SymbolVisitor(linked_hash_set<NumVar> &t) : target(t) {}
        void visit(const GiNaC::symbol &sym) {
            target.emplace(getIndex(sym));
        }
    private:
        linked_hash_set<NumVar> &target;
    };

    SymbolVisitor v(res);
    traverse(v);
}


linked_hash_set<NumVar> Expr::vars() const {
    linked_hash_set<NumVar> res;
    collectVars(res);
    return res;
}


bool Expr::isGround() const {
    return ex.info(GiNaC::info_flags::numeric);
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


NumVar Expr::someVar() const {
    struct SymbolVisitor : public GiNaC::visitor, public GiNaC::symbol::visitor {
        void visit(const GiNaC::symbol &var) {
            variable = NumVar(getIndex(var));
        }
        NumVar result() const {
            return *variable;
        }
    private:
        std::optional<NumVar> variable {};
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

unsigned Expr::degree(const NumVar &var) const {
    return ex.degree(*var);
}

unsigned Expr::ldegree(const NumVar &var) const {
    return ex.ldegree(*var);
}

Expr Expr::coeff(const NumVar &var, int degree) const {
    return Expr(ex.coeff(*var, degree));
}

Expr Expr::lcoeff(const NumVar &var) const {
    return Expr(ex.lcoeff(*var));
}

Expr Expr::expand() const {
    return Expr(ex.expand());
}

/*
 * Let q be the result of normalizing the given polynomial such that the least coefficient of the homogeneous part is 1.
 * This function returns a polynomial p where the least coefficient of the homogeneous part is normalized to 1,
 * the non-homogeneous part is an integer, and p = ceil(q). Useful for normalizing the lhs of relations of the form
 * poly <= 0.
 */
Expr Expr::normalizeCoefficients() const {
    if (!isPoly()) {
        return *this;
    }
    const auto expanded {this->expand()};
    auto getConstantArg = [](const auto addend, const auto default_value) {
        for (size_t i = 0; i < addend.arity(); ++i) {
            if (addend.op(i).isGround()) {
                return addend.op(i).toNum();
            }
        }
        return GiNaC::numeric(default_value);
    };
    if (isMul()) {
        return expanded / Expr(GiNaC::abs(getConstantArg(expanded, 1)));
    } else if (isAdd()) {
        // first make sure that all coefficients are integers
        GiNaC::numeric lcm {1};
        for (size_t i = 0; i < expanded.arity(); ++i) {
            const auto op {expanded.op(i)};
            if (!op.isGround()) {
                lcm = GiNaC::lcm(lcm, GiNaC::abs(getConstantArg(op, 1)).denom());
            }
        }
        auto integral = expanded * Expr(lcm);
        // compute the gcd of all coefficients
        std::optional<GiNaC::numeric> gcd;
        for (size_t i = 0; i < integral.arity(); ++i) {
            const auto op {integral.op(i)};
            if (!op.isGround()) {
                const auto factor {GiNaC::abs(getConstantArg(op, 1))};
                if (gcd) {
                    gcd = GiNaC::gcd(*gcd, factor);
                } else {
                    gcd = factor;
                }
            }
        }
        // normalize such that the least coefficient of the homogeneous part is 1
        auto normalized = integral / Expr(gcd.value_or(1));
        // normalize the non-homogeneous part to the next integer
        auto addend {getConstantArg(normalized, 0)};
        return normalized - Expr(addend + GiNaC::floor(addend));
    } else {
        return *this;
    }
}

bool Expr::has(const Expr &pattern) const {
    return ex.has(pattern.ex);
}

std::pair<Expr, std::vector<std::pair<NumVar, Expr>>> Expr::flattenExp() const {
    struct Mapper: GiNaC::map_function {
        GiNaC::ex operator()(const GiNaC::ex &ex) {
            if (GiNaC::is_a<GiNaC::power>(ex)) {
                const auto base {ex.op(0)};
                const auto exp {ex.op(1)};
                if (GiNaC::is_a<GiNaC::numeric>(exp)) {
                    return ex;
                }
                GiNaC::ex new_base, new_exp;
                if (GiNaC::is_a<GiNaC::symbol>(base) || GiNaC::is_a<GiNaC::numeric>(base)) {
                    new_base = base;
                } else {
                    new_base = base.map(*this);
                    repl.push_back({NumVar::next(), Expr(new_base)});
                }
                if (GiNaC::is_a<GiNaC::symbol>(exp)) {
                    new_exp = exp;
                } else {
                    new_exp = exp.map(*this);
                    repl.push_back({NumVar::next(), Expr(new_exp)});
                }
                return GiNaC::pow(new_base, new_exp);
            } else {
                return ex.map(*this);
            }
        }

        std::vector<std::pair<NumVar, Expr>> repl {};
    };
    Mapper f;
    const Expr res {f(ex)};
    return {res, f.repl};
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

NumVar Expr::toVar() const {
    return NumVar(getIndex(GiNaC::ex_to<GiNaC::symbol>(ex)));
}

GiNaC::numeric Expr::toNum() const {
    return GiNaC::ex_to<GiNaC::numeric>(ex);
}

Expr Expr::op(unsigned int i) const {
    return Expr(ex.op(i));
}

size_t Expr::arity() const {
    return ex.nops();
}

Expr::Mapper::Mapper(const ExprSubs &map): map(map) {}

GiNaC::ex Expr::Mapper::operator()(const GiNaC::ex &ex) {
    if (ex.info(GiNaC::info_flags::symbol)) {
        return map.get(NumVar(getIndex(GiNaC::ex_to<GiNaC::symbol>(ex)))).ex;
    } else {
        return ex.map(*this);
    }
}

Expr Expr::subs(const ExprSubs &map) const {
    return Expr(Expr::Mapper(map)(ex));
}

void Expr::traverse(GiNaC::visitor &v) const {
    ex.traverse(v);
}

std::strong_ordering operator<=>(const Expr &x, const Expr &y) {
    const auto res {x.ex.compare(y.ex)};
    if (res == 0) {
        return std::strong_ordering::equal;
    } else if (res < 0) {
        return std::strong_ordering::less;
    } else {
        return std::strong_ordering::greater;
    }
}

Expr Expr::numerator() const {
    return Expr(ex.numer());
}

Expr Expr::denominator() const {
    return Expr(ex.denom());
}

bool Expr::match(const Expr &pattern) const {
    return ex.match(pattern.ex);
}

Expr operator-(const Expr &x) {
    return Expr(-x.ex);
}

Expr operator-(const Expr &x, const Expr &y) {
    return Expr(x.ex - y.ex);
}

Expr operator+(const Expr &x, const Expr &y) {
    return Expr(x.ex + y.ex);
}

Expr operator*(const Expr &x, const Expr &y) {
    return Expr(x.ex * y.ex);
}

Expr operator/(const Expr &x, const Expr &y) {
    return Expr(x.ex / y.ex);
}

Expr operator^(const Expr &x, const Expr &y) {
    return Expr(GiNaC::pow(x.ex, y.ex));
}

Expr Expr::wildcard(unsigned int label) {
    return Expr(GiNaC::wild(label));
}

Num Expr::denomLcm() const {
    const Expr &denom = Expr::wildcard(0);
    const Expr &num = Expr::wildcard(1);
    const Expr &pattern = denom / num;
    linked_hash_set<Expr> matches;
    GiNaC::numeric lcm = 1;
    findAll(pattern, matches);
    for (const Expr &e: matches) {
        lcm = GiNaC::lcm(lcm, e.denominator().toNum());
    }
    return lcm;
}

Expr Expr::toIntPoly() const {
    GiNaC::numeric lcm = denomLcm();
    return lcm == 1 ? *this : *this * Expr(lcm);
}

bool Expr::isIntegral() const {
    assert(isPoly());

    // shortcut for the common case
    if (isIntPoly()) {
        return true;
    }

    // collect variables from e into a vector
    vector<NumVar> vars;
    for (const auto &sym : this->vars()) {
        vars.push_back(sym);
    }

    // degrees, subs share indices with vars
    vector<int> degrees;
    vector<int> subs;
    Expr expanded = expand();
    for (const auto &x: vars) {
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

std::optional<Expr> Expr::solveTermFor(const NumVar &var, SolvingLevel level) const {
    // expand is needed before using degree/coeff
    Expr term = this->expand();

    // we can only solve linear expressions...
    if (term.degree(var) != 1) return {};

    // ...with rational coefficients
    Expr c = term.coeff(var);
    if (!c.isRationalConstant()) return {};

    bool trivialCoeff = (c == 1 || c == -1);

    if (level == TrivialCoeffs && !trivialCoeff) {
        return {};
    }

    term = (term - c*var) / (-c);

    // If c is trivial, we don't have to check if the result maps to int,
    // since we assume that all constraints in the guard map to int.
    // So if c is trivial, we can also handle non-polynomial terms.
    if (level == ResultMapsToInt && !trivialCoeff) {
        if (!term.isPoly() || !term.isIntegral()) return {};
    }

    // we assume that terms in the guard map to int, make sure this is the case
    if (trivialCoeff) {
        assert(!term.isPoly() || term.isIntegral());
    }

    return {term};
}

std::size_t Expr::hash() const {
    return ex.gethash();
}

size_t hash_value(const Expr &e) {
    return e.hash();
}

bool operator==(const Expr &e1, const Expr &e2) {
    return e1.ex.is_equal(e2.ex);
}

std::ostream& operator<<(std::ostream &s, const Expr &e) {
    return s << e.ex;
}

ExprSubs::ExprSubs() {}

ExprSubs::ExprSubs(std::initializer_list<std::pair<const NumVar, Expr>> init): map(init) {}

Expr ExprSubs::get(const NumVar &key) const {
    const auto res {map.get(key)};
    return res ? *res : key;
}

void ExprSubs::put(const NumVar &key, const Expr &val) {
    map.put(key, val);
}

ExprSubs::const_iterator ExprSubs::begin() const {
    return map.begin();
}

ExprSubs::const_iterator ExprSubs::end() const {
    return map.end();
}

bool ExprSubs::contains(const NumVar &e) const {
    return map.contains(e);
}

bool ExprSubs::empty() const {
    return map.empty();
}

unsigned int ExprSubs::size() const {
    return map.size();
}

size_t ExprSubs::erase(const NumVar &key) {
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

void ExprSubs::concatInPlace(const ExprSubs &that) {
    std::vector<std::pair<NumVar, Expr>> changed;
    for (const auto &[key, val]: *this) {
        const auto new_val {val.subs(that)};
        if (val != new_val) {
            changed.emplace_back(key, new_val);
        }
    }
    for (const auto &[key, val]: changed) {
        put(key, val);
    }
}

ExprSubs ExprSubs::unite(const ExprSubs &that) const {
    ExprSubs res;
    for (const auto &p: *this) {
        res.put(p.first, p.second);
    }
    for (const auto &p: that) {
        if (res.contains(p.first)) {
            throw std::invalid_argument("union of substitutions is only defined if their domain is disjoint");
        }
        res.put(p.first, p.second);
    }
    return res;
}

ExprSubs ExprSubs::project(const linked_hash_set<NumVar> &vars) const {
    ExprSubs res;
    if (size() < vars.size()) {
        for (const auto &p: *this) {
            if (vars.contains(p.first)) {
                res.put(p.first, p.second);
            }
        }
    } else {
        for (const auto &x: vars) {
            const auto val {map.get(x)};
            if (val) {
                res.put(x, *val);
            }
        }
    }
    return res;
}

bool ExprSubs::changes(const NumVar &key) const {
    return contains(key) && get(key) != key;
}

bool ExprSubs::isLinear() const {
    return std::all_of(begin(), end(), [](const auto &p) {
       return p.second.isLinear();
    });
}

bool ExprSubs::isPoly() const {
    return std::all_of(begin(), end(), [](const auto &p) {
       return p.second.isPoly();
    });
}

bool ExprSubs::isOctagon() const {
    return std::all_of(begin(), end(), [](const auto &p) {
       return p.second.isOctagon();
    });
}

void ExprSubs::collectDomain(linked_hash_set<NumVar> &vars) const {
    for (const auto &p: *this) {
        vars.insert(p.first);
    }
}

void ExprSubs::collectCoDomainVars(linked_hash_set<NumVar> &vars) const {
    for (const auto &p: *this) {
        p.second.collectVars(vars);
    }
}

void ExprSubs::collectVars(linked_hash_set<NumVar> &vars) const {
    collectCoDomainVars(vars);
    collectDomain(vars);
}

linked_hash_set<NumVar> ExprSubs::domain() const {
    linked_hash_set<NumVar> res;
    collectDomain(res);
    return res;
}

linked_hash_set<NumVar> ExprSubs::coDomainVars() const {
    linked_hash_set<NumVar> res;
    collectCoDomainVars(res);
    return res;
}

linked_hash_set<NumVar> ExprSubs::allVars() const {
    linked_hash_set<NumVar> res;
    collectVars(res);
    return res;
}

size_t ExprSubs::hash() const {
    return boost::hash_unordered_range(map.begin(), map.end());
}

bool operator==(const ExprSubs &m1, const ExprSubs &m2) {
    return m1.map == m2.map;
}

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
            s << p.first << " <- " << p.second;
        }
        return s << "}";
    }
}
