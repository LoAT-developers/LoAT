#include "limitproblem.hpp"
#include "smtfactory.hpp"


#include <sstream>
#include <utility>

LimitProblem::LimitProblem()
    : variableN(NumVar::next()), unsolvable(false), log(new std::ostringstream()) {
}


LimitProblem::LimitProblem(const Guard &normalizedGuard, const Expr &cost)
    : LimitProblem() {
    for (const auto &lit : normalizedGuard) {
        const Rel &rel = std::get<Rel>(lit);
        assert(rel.isGZeroConstraint());
        addExpression(InftyExpression(rel.lhs(), POS));
    }

    addExpression(InftyExpression(cost, POS_INF));

    (*log) << "Created initial limit problem:" << std::endl
        << *this << std::endl << std::endl;
}


LimitProblem::LimitProblem(const Guard &normalizedGuard)
    : variableN(NumVar::next()), unsolvable(false), log(new std::ostringstream()) {
    for (const auto &lit : normalizedGuard) {
        const Rel &rel = std::get<Rel>(lit);
        assert(rel.isGZeroConstraint());
        addExpression(InftyExpression(rel.lhs(), POS));
    }

    (*log) << "Created initial limit problem without cost:" << std::endl
        << *this << std::endl << std::endl;
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


void LimitProblem::addExpression(const InftyExpression &ex) {
    InftyExpressionSet::iterator it = set.find(ex);

    if (it == set.end()) {
        // ex is not present
        set.insert(ex);

    } else {
        // ex is already present
        if (it->getDirection() != ex.getDirection()) {
            if (it->getDirection() == POS &&
                (ex.getDirection() == POS_INF || ex.getDirection() == POS_CONS)) {
                // fix direction
                set.erase(it);
                set.insert(ex);

            } else if (!(ex.getDirection() == POS &&
                         (it->getDirection() == POS_INF || it->getDirection() == POS_CONS))) {
                // the limit problem is contradictory
                unsolvable = true;
            }
        }
    }

    // check if the expression is unsatisfiable
    if (ex.isTriviallyUnsatisfiable()) {
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
                                    const Expr &l, const Expr &r,
                                    const LimitVector &lv) {
    assert(lv.isApplicable(it->getDirection()));

    InftyExpression firstIE(l, lv.getFirst());
    InftyExpression secondIE(r, lv.getSecond());

    (*log) << "applying transformation rule (A), replacing " << *it
        << " by " << firstIE << " and " << secondIE << " using " << lv << std::endl;

    set.erase(it);
    addExpression(firstIE);
    addExpression(secondIE);

    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::removeConstant(const InftyExpressionSet::const_iterator &it) {
    assert(it->isInt());

    Num num = it->toNum();
#ifndef NDEBUG
    Direction dir = it->getDirection();
    assert((num.is_positive() && (dir == POS_CONS || dir == POS))
           || (num.is_negative() && dir == NEG_CONS));
#endif

    (*log) << "applying transformation rule (B), deleting " << *it << std::endl;

    set.erase(it);

    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::substitute(const ExprSubs &sub, int substitutionIndex) {
#ifndef NDEBUG
    for (auto const &s : sub) {
        assert(!s.second.has(s.first));
    }
#endif

    (*log) << "applying transformation rule (C) using substitution " << sub << std::endl;

    InftyExpressionSet oldSet;
    oldSet.swap(set);
    for (const InftyExpression &ex : oldSet) {
        addExpression(InftyExpression(ex.subs(sub), ex.getDirection()));
    }

    substitutions.push_back(substitutionIndex);

    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::trimPolynomial(const InftyExpressionSet::const_iterator &it) {
    // the expression has to be a univariate polynomial
    assert(it->isPoly());
    assert(it->isUnivariate());

    Direction dir = it->getDirection();
    assert((dir == POS) || (dir == POS_INF) || (dir == NEG_INF));

    NumVar var = it->someVar();

    Expr expanded = it->expand();

    if (expanded.isAdd()) {
        Expr leadingTerm = expanded.lcoeff(var) * Expr(pow(*var, expanded.degree(var)));

        if (dir == POS) {
            // Fix the direction
            dir = POS_INF;
        }

        InftyExpression inftyExp(leadingTerm, dir);

        (*log) << "applying transformation rule (D), replacing " << *it
            << " by " << inftyExp << std::endl;

        set.erase(it);
        addExpression(inftyExp);
    }

    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::reduceExp(const InftyExpressionSet::const_iterator &it) {
    assert(it->getDirection() == POS_INF || it->getDirection() == POS);

    assert(it->isUnivariate());
    NumVar x = it->someVar();

    Expr powerInExp;
    if (it->isAdd()) {
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr summand = it->op(i);
            if (summand.isPow() && summand.op(1).has(x)) {
                powerInExp = summand;
                break;
            }
        }

    } else {
        powerInExp = *it;
    }
    assert(powerInExp.isPow());

    Expr b = *it - powerInExp;
    assert(b.isPoly(x));

    Expr a = powerInExp.op(0);
    Expr e = powerInExp.op(1);

    assert(a.isPoly(x));
    assert(e.isPoly(x));
    assert(e.has(x));

    InftyExpression firstIE(a - 1, POS);
    InftyExpression secondIE(e, POS_INF);

    (*log) << "applying transformation rule (E), replacing " << *it << " by "
        << firstIE << " and " << secondIE << std::endl;

    set.erase(it);
    addExpression(firstIE);
    addExpression(secondIE);

    (*log) << "resulting limit problem:" << std::endl << *this << std::endl << std::endl;
}


void LimitProblem::reduceGeneralExp(const InftyExpressionSet::const_iterator &it) {
    assert(it->getDirection() == POS_INF || it->getDirection() == POS);

    Expr powerInExp;
    if (it->isAdd()) {
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr summand = it->op(i);
            if (summand.isPow() && (!summand.op(1).isPoly()
                                         || summand.isMultivariate())) {
                powerInExp = summand;
                break;
            }
        }

    } else {
        powerInExp = *it;
    }
    assert(powerInExp.isPow());
    assert(!powerInExp.op(1).isPoly()
           || powerInExp.isMultivariate());

    Expr b = *it - powerInExp;

    Expr a = powerInExp.op(0);
    Expr e = powerInExp.op(1);

    InftyExpression firstIE(a - 1, POS);
    InftyExpression secondIE(e + b, POS_INF);

    (*log) << "reducing general power, replacing " << *it
        << " by " << firstIE << " and " << secondIE << std::endl;

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
    for (const InftyExpression &ex : set) {
        if (!ex.isVar()) {
            return false;
        }
    }

    // Since the infinity expressions are compared using GiNaC::ex_is_less,
    // the directions do not affect the comparison.
    // Therefore, there cannot be a variable with different directions.
    return true;
}


ExprSubs LimitProblem::getSolution() const {
    assert(isSolved());

    ExprSubs solution;
    for (const InftyExpression &ex : set) {
        assert(ex.isVar());
        switch (ex.getDirection()) {
            case POS:
            case POS_INF:
                solution.put(ex.toVar(), variableN);
                break;
            case NEG_INF:
                solution.put(ex.toVar(), -Expr(variableN));
                break;
            case POS_CONS:
                solution.put(ex.toVar(), 1);
                break;
            case NEG_CONS:
                solution.put(ex.toVar(), -1);
                break;
        }
    }

    return solution;
}


NumVar LimitProblem::getN() const {
    return variableN;
}


const std::vector<int>& LimitProblem::getSubstitutions() const {
    return substitutions;
}


InftyExpressionSet::const_iterator LimitProblem::find(const InftyExpression &ex) const {
    return set.find(ex);
}


std::set<NumVar> LimitProblem::getVariables() const {
    std::set<NumVar> res;
    for (const InftyExpression &ex : set) {
        const auto exVars = ex.vars();
        res.insert(exVars.begin(), exVars.end());
    }
    return res;
}


std::vector<Theory<IntTheory>::Lit> LimitProblem::getQuery() const {
    std::vector<Theory<IntTheory>::Lit> query;

    for (const InftyExpression &ex : set) {
        if (ex.getDirection() == NEG_INF || ex.getDirection() == NEG_CONS) {
            query.push_back(Rel(ex.expand(), Rel::lt, 0));
        } else {
            query.push_back(Rel(ex.expand(), Rel::gt, 0));
        }
    }

    return query;
}


bool LimitProblem::isUnsat() const {
    return SmtFactory::check(BoolExpression<IntTheory>::buildAndFromLits(getQuery())) == Unsat;
}


bool LimitProblem::isLinear() const {
    for (const InftyExpression &ex : set) {
        if (!ex.isLinear()) {
            return false;
        }
    }
    return true;
}

bool LimitProblem::isPoly() const {
    for (const InftyExpression &ex : set) {
        if (!ex.isPoly()) {
            return false;
        }
    }
    return true;
}

bool LimitProblem::removeConstantIsApplicable(const InftyExpressionSet::const_iterator &it) {
    if (!it->isInt()) {
        return false;
    }

    Num num = it->toNum();
    Direction dir = it->getDirection();

    return (num.is_positive() && (dir == POS_CONS || dir == POS))
           || (num.is_negative() && dir == NEG_CONS);
}


bool LimitProblem::trimPolynomialIsApplicable(const InftyExpressionSet::const_iterator &it) {
    Direction dir = it->getDirection();
    if (!((dir == POS) || (dir == POS_INF) || (dir == NEG_INF))) {
        return false;
    }

    if (!it->isPoly()) {
        return false;
    }

    // Check if it is a monom
    if (!it->expand().isAdd()) {
        return false;
    }

    return it->isUnivariate();
}


bool LimitProblem::reduceExpIsApplicable(const InftyExpressionSet::const_iterator &it) {
    Direction dir = it->getDirection();
    if (!(dir == POS_INF || dir == POS)) {
        return false;
    }

    if (!it->isUnivariate()) {
        return false;
    }

    NumVar x = it->someVar();

    Expr powerInExp;
    if (it->isAdd()) {
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr summand = it->op(i);
            if (summand.isPow() && summand.op(1).has(x)) {
                powerInExp = summand;
                break;
            }
        }

    } else {
        powerInExp = *it;
    }

    if (!powerInExp.isPow()) {
        return false;
    }

    Expr b = *it - powerInExp;

    if (!b.isPoly(x)) {
        return false;
    }

    Expr a = powerInExp.op(0);
    Expr e = powerInExp.op(1);

    if (!(a.isPoly(x) && e.isPoly(x))) {
        return false;
    }

    return e.has(x);
}


bool LimitProblem::reduceGeneralExpIsApplicable(const InftyExpressionSet::const_iterator &it) {
    Direction dir = it->getDirection();
    if (!(dir == POS_INF || dir == POS)) {
        return false;
    }

    if (it->isAdd()) {
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr summand = it->op(i);
            if (summand.isPow() && (!summand.op(1).isPoly()
                                         || summand.isMultivariate())) {
                return true;
            }
        }

        return false;
    }

    return it->isPow() && (!it->op(1).isPoly()
                                || it->isMultivariate());
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

    os << "[" << (lp.isUnsolvable() ? "unsolvable"
                  : (lp.isSolved() ? "solved" : "not solved")) << "]";

    return os;
}
