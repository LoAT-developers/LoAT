#include "limitproblem.hpp"
#include "smtfactory.hpp"


#include <sstream>
#include <utility>

LimitProblem::LimitProblem()
    : variableN(ArithVar::next()), unsolvable(false), log(new std::ostringstream()) {
}


LimitProblem::LimitProblem(const Guard &normalizedGuard, const Arith::Expr cost)
    : LimitProblem() {
    for (const auto &lit : normalizedGuard) {
        addExpression(InftyExpression(std::get<ArithLit>(lit).lhs(), POS));
    }
    addExpression(InftyExpression(cost, POS_INF));
    (*log) << "Created initial limit problem:" << std::endl << *this << std::endl << std::endl;
}


LimitProblem::LimitProblem(const Guard &normalizedGuard)
    : variableN(ArithVar::next()), unsolvable(false), log(new std::ostringstream()) {
    for (const auto &lit : normalizedGuard) {
        addExpression(InftyExpression(std::get<ArithLit>(lit).lhs(), POS));
    }
    (*log) << "Created initial limit problem without cost:" << std::endl << *this << std::endl << std::endl;
}


LimitProblem::LimitProblem(const LimitProblem &other)
    : set(other.set),
    variableN(other.variableN),
    substitutions(other.substitutions),
    unsolvable(other.unsolvable),
    log(new std::ostringstream()) {
    (*log) << other.log->str();
}


LimitProblem& LimitProblem::operator=(const LimitProblem &other) {
    if (this != &other) {
        set = other.set;
        variableN = other.variableN;
        substitutions = other.substitutions;
        (*log) << other.log->str();
        unsolvable = other.unsolvable;
    }
    return *this;
}


LimitProblem::LimitProblem(LimitProblem &&other)
    : set(std::move(other.set)),
    variableN(other.variableN),
    substitutions(std::move(other.substitutions)),
    unsolvable(other.unsolvable),
    log(std::move(other.log)) {
}


LimitProblem& LimitProblem::operator=(LimitProblem &&other) {
    if (this != &other) {
        set = std::move(other.set);
        variableN = other.variableN;
        substitutions = std::move(other.substitutions);
        log = std::move(other.log);
        unsolvable = other.unsolvable;
    }
    return *this;
}


void LimitProblem::addExpression(const InftyExpression &p) {
    InftyExpressionSet::iterator it = set.find(p);
    if (it == set.end()) {
        // ex is not present
        set.insert(p);
    } else {
        const auto &[ex,d1] {p};
        const auto &[_,d2] {*it};
        // ex is already present
        if (d1 != d2) {
            if (d2 == POS && (d1 == POS_INF || d1 == POS_CONS)) {
                // fix direction
                set.erase(it);
                set.insert(p);
            } else if (!(d1 == POS && (d2 == POS_INF || d2 == POS_CONS))) {
                // the limit problem is contradictory
                unsolvable = true;
            }
        }
    }
    // check if the expression is unsatisfiable
    if (isTriviallyUnsatisfiable(p)) {
        unsolvable = true;
    }
}


InftyExpressionSet::iterator LimitProblem::cbegin() const {
    return set.cbegin();
}


InftyExpressionSet::iterator LimitProblem::cend() const {
    return set.cend();
}


void LimitProblem::applyLimitVector(const InftyExpressionSet::const_iterator &it,
                                    const Arith::Expr l, const Arith::Expr r,
                                    const LimitVector &lv) {
    const auto &[_,d] {*it};
    assert(lv.isApplicable(d));
    InftyExpression firstIE(l, lv.getFirst());
    InftyExpression secondIE(r, lv.getSecond());
    (*log) << "applying transformation rule (A), replacing " << *it << " by " << firstIE << " and " << secondIE << " using " << lv << std::endl;
    set.erase(it);
    addExpression(firstIE);
    addExpression(secondIE);
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::removeConstant(const InftyExpressionSet::const_iterator &it) {
    const auto &[e,d] {*it};
    const auto i {e->isInt()};
#ifndef NDEBUG
    assert((*i > 0 && (d == POS_CONS || d == POS))
           || (*i < 0 && d == NEG_CONS));
#endif
    (*log) << "applying transformation rule (B), deleting " << *it << std::endl;
    set.erase(it);
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::substitute(const ArithSubs &sub, int substitutionIndex) {
#ifndef NDEBUG
    for (auto const &s : sub) {
        assert(!s.second->has(s.first));
    }
#endif
    (*log) << "applying transformation rule (C) using substitution " << sub << std::endl;
    InftyExpressionSet oldSet;
    oldSet.swap(set);
    for (const auto &[ex,d] : oldSet) {
        addExpression(InftyExpression(sub(ex), d));
    }
    substitutions.push_back(substitutionIndex);
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::trimPolynomial(const InftyExpressionSet::const_iterator &it) {
    auto [e,dir] {*it};
    // the expression has to be a univariate polynomial
    assert(e->isPoly());
    assert(e->isUnivariate());
    assert((dir == POS) || (dir == POS_INF) || (dir == NEG_INF));
    const auto var {e->someVar()};
    if (e->isAdd()) {
        const auto leadingTerm {*e->lcoeff(*var) * arith::mkExp(*var, arith::mkConst(*e->degree(*var)))};
        if (dir == POS) {
            // Fix the direction
            dir = POS_INF;
        }
        InftyExpression inftyExp(leadingTerm, dir);
        (*log) << "applying transformation rule (D), replacing " << *it << " by " << inftyExp << std::endl;
        set.erase(it);
        addExpression(inftyExp);
    }
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::reduceExp(const InftyExpressionSet::const_iterator &it) {
    const auto &[exp,dir] {*it};
    assert(dir == POS_INF || dir == POS);
    assert(exp->isUnivariate());
    const auto x {*exp->someVar()};
    ArithExpPtr powerInExp;
    const auto add {exp->isAdd()};
    if (add) {
        for (const auto &arg: (*add)->getArgs()) {
            const auto p {arg->isPow()};
            if (p) {
                if ((*p)->getExponent()->has(x)) {
                    powerInExp = *p;
                    break;
                }
            }
        }
    } else {
        powerInExp = *exp->isPow();
    }
    const auto b {exp - powerInExp};
    assert(b->isPoly(x));
    assert(powerInExp->getBase()->isPoly(x));
    assert(powerInExp->getExponent()->isPoly(x));
    assert(powerInExp->getExponent()->has(x));
    InftyExpression firstIE(powerInExp->getBase() - arith::mkConst(1), POS);
    InftyExpression secondIE(powerInExp->getExponent(), POS_INF);
    (*log) << "applying transformation rule (E), replacing " << *it << " by " << firstIE << " and " << secondIE << std::endl;
    set.erase(it);
    addExpression(firstIE);
    addExpression(secondIE);
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::reduceGeneralExp(const InftyExpressionSet::const_iterator &it) {
    const auto &[exp,dir] {*it};
    assert(dir == POS_INF || dir == POS);
    ArithExpPtr powerInExp;
    const auto add {exp->isAdd()};
    if (add) {
        for (const auto &arg: (*add)->getArgs()) {
            const auto p {arg->isPow()};
            if (p) {
                if (!(*p)->getExponent()->isPoly() || arg->isMultivariate()) {
                    powerInExp = *p;
                    break;
                }
            }
        }
    } else {
        powerInExp = *exp->isPow();
    }
    assert(!powerInExp->getExponent()->isPoly() || powerInExp->isMultivariate());
    const auto b {exp - powerInExp};
    InftyExpression firstIE(powerInExp->getBase() - arith::mkConst(1), POS);
    InftyExpression secondIE(powerInExp->getExponent() + b, POS_INF);
    (*log) << "reducing general power, replacing " << *it << " by " << firstIE << " and " << secondIE << std::endl;
    set.erase(it);
    addExpression(firstIE);
    addExpression(secondIE);
    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::removeAllConstraints() {
    (*log) << "removing all constraints (solved by SMT)" << std::endl;
    set.clear();
    (*log) << "resulting limit problem: " << *this << std::endl << std::endl;
}


bool LimitProblem::isUnsolvable() const {
    return unsolvable;
}


void LimitProblem::setUnsolvable() {
    unsolvable = true;
}

bool LimitProblem::isSolved() const {
    if (isUnsolvable()) {
        return false;
    }
    // Check if an expression is not a variable
    for (const auto &[ex,_] : set) {
        if (!ex->isVar()) {
            return false;
        }
    }
    // Since the infinity expressions are compared using GiNaC::ex_is_less,
    // the directions do not affect the comparison.
    // Therefore, there cannot be a variable with different directions.
    return true;
}


ArithSubs LimitProblem::getSolution() const {
    assert(isSolved());
    ArithSubs solution;
    for (const auto &[ex,d] : set) {
        const auto x {*ex->isVar()};
        switch (d) {
        case POS:
        case POS_INF:
            solution.put(x, variableN);
            break;
        case NEG_INF:
            solution.put(x, -variableN);
            break;
        case POS_CONS:
            solution.put(x, arith::mkConst(1));
            break;
        case NEG_CONS:
            solution.put(x, arith::mkConst(-1));
            break;
        }
    }
    return solution;
}


Arith::Var LimitProblem::getN() const {
    return variableN;
}


const std::vector<int>& LimitProblem::getSubstitutions() const {
    return substitutions;
}


InftyExpressionSet::const_iterator LimitProblem::find(const InftyExpression &ex) const {
    return set.find(ex);
}


std::set<Arith::Var> LimitProblem::getVariables() const {
    std::set<Arith::Var> res;
    for (const auto &[ex,_] : set) {
        const auto exVars = ex->vars();
        res.insert(exVars.begin(), exVars.end());
    }
    return res;
}


std::vector<Theory<Arith>::Lit> LimitProblem::getQuery() const {
    std::vector<Theory<Arith>::Lit> query;
    for (const auto &[ex,d] : set) {
        if (d == NEG_INF || d == NEG_CONS) {
            query.push_back(arith::mkLt(ex, arith::mkConst(0)));
        } else {
            query.push_back(arith::mkGt(ex, arith::mkConst(0)));
        }
    }
    return query;
}


bool LimitProblem::isUnsat() const {
    return SmtFactory::_check(BoolExpression<Arith>::mkAndFromLits(getQuery())) == Unsat;
}


bool LimitProblem::isLinear() const {
    for (const auto &[ex,_] : set) {
        if (!ex->isLinear()) {
            return false;
        }
    }
    return true;
}

bool LimitProblem::isPoly() const {
    for (const auto &[ex,_] : set) {
        if (!ex->isPoly()) {
            return false;
        }
    }
    return true;
}

bool LimitProblem::removeConstantIsApplicable(const InftyExpressionSet::const_iterator &it) {
    const auto &[e,dir] {*it};
    const auto i {e->isInt()};
    if (!i) {
        return false;
    }
    return (*i > 0 && (dir == POS_CONS || dir == POS)) || (*i < 0 && dir == NEG_CONS);
}


bool LimitProblem::trimPolynomialIsApplicable(const InftyExpressionSet::const_iterator &it) {
    const auto &[e,dir] {*it};
    if (!((dir == POS) || (dir == POS_INF) || (dir == NEG_INF))) {
        return false;
    }
    if (!e->isPoly()) {
        return false;
    }
    // Check if it is a monom
    if (!e->isAdd()) {
        return false;
    }
    return e->isUnivariate();
}


bool LimitProblem::reduceExpIsApplicable(const InftyExpressionSet::const_iterator &it) {
    const auto &[ex,dir] {*it};
    if (!(dir == POS_INF || dir == POS)) {
        return false;
    }
    if (!ex->isUnivariate()) {
        return false;
    }
    const auto x {*ex->someVar()};
    ArithExpPtr powerInExp;
    const auto add {ex->isAdd()};
    if (add) {
        for (const auto &arg: (*add)->getArgs()) {
            const auto p {arg->isPow()};
            if (p) {
                if ((*p)->getExponent()->has(x)) {
                    powerInExp = *p;
                    break;
                }
            }
        }
    } else {
        const auto p {ex->isPow()};
        if (!p) {
            return false;
        }
        powerInExp = *p;
    }
    const auto b = ex - powerInExp;
    if (!b->isPoly(x)) {
        return false;
    }
    if (!(powerInExp->getBase()->isPoly(x) && powerInExp->getExponent()->isPoly(x))) {
        return false;
    }
    return powerInExp->getExponent()->has(x);
}


bool LimitProblem::reduceGeneralExpIsApplicable(const InftyExpressionSet::const_iterator &it) {
    const auto &[ex,dir] {*it};
    if (!(dir == POS_INF || dir == POS)) {
        return false;
    }
    const auto add {ex->isAdd()};
    if (add) {
        for (const auto &arg: (*add)->getArgs()) {
            const auto p {arg->isPow()};
            if (p) {
                if ((*p)->getExponent()->isPoly() || arg->isMultivariate()) {
                    return true;
                }
            }
        }
        return false;
    }
    const auto p {ex->isPow()};
    if (p) {
        return (*p)->getExponent()->isPoly() || ex->isMultivariate();
    }
    return false;
}

InftyExpressionSet::size_type LimitProblem::getSize() const {
    return set.size();
}

const InftyExpressionSet LimitProblem::getSet() const {
    return set;
}

std::string LimitProblem::getProof() const {
    return log->str();
}


std::ostream& operator<<(std::ostream &os, const LimitProblem &lp) {
    if (lp.cbegin() != lp.cend()) {
        std::copy(lp.cbegin(), --lp.cend(), std::ostream_iterator<InftyExpression>(os, ", "));
        os << *(--lp.cend()) << " ";
    }
    return os << "[" << (lp.isUnsolvable() ? "unsolvable" : (lp.isSolved() ? "solved" : "not solved")) << "]";
}
