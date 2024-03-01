#pragma once

#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <memory>

#include "theory.hpp"
#include "conjunction.hpp"
#include "inftyexpression.hpp"
#include "limitvector.hpp"

/**
 * This class represents a limit problem, i.e., a set of InftyExpressions.
 */
class LimitProblem {
public:
    /**
     * Creates a new, empty LimitProblem.
     */
    LimitProblem();

    /**
     * Creates the initial LimitProblem for the given guard and cost.
     * @param normalizedGuard the guard in normalized form, i.e., a list of relations
     *                        of the form t > 0
     * @param cost a term
     */
    LimitProblem(const Conjunction &normalizedGuard, const Arith::Expr cost);

    /**
     * Creates the initial LimitProblem without any cost term.
     */
    LimitProblem(const Conjunction &normalizedGuard);

    // copy constructor and assignment operator
    LimitProblem(const LimitProblem &other);
    LimitProblem& operator=(const LimitProblem &other);

    // move constructor and move assignment operator
    LimitProblem(LimitProblem &&other);
    LimitProblem& operator=(LimitProblem &&other);

    /**
     * Adds a new InftyExpression to this LimitProblem.
     * Might mark this LimitProblem as unsolvable.
     */
    void addExpression(const InftyExpression &ex);

    /**
     * Returns a const_iterator to the beginning of the underlying set.
     * The underlying set ignores the direction of a InftyExpression.
     */
    InftyExpressionSet::const_iterator cbegin() const;

    /**
     * Returns a const_iterator to the end of the underlying set.
     * The underlying set ignores the direction of a InftyExpression.
     */
    InftyExpressionSet::const_iterator cend() const;

    /**
     * Applies the given LimitVector to the InftyExpression specified by
     * the given const_iterator where the resulting expression are given by l and r.
     * transformation rule (A)
     * @param it must be a valid const_iterator of the underlying set
     * @param lv must be applicable to *it
     */
    void applyLimitVector(const InftyExpressionSet::const_iterator &it,
                          const Arith::Expr l, const Arith::Expr r,
                          const LimitVector &lv);

    /**
     * Removes an integer from this LimitProblem.
     * transformation rule (B)
     * @param it must be a valid const_iterator of the underlying set and
     *           must point to an integer whose sign matches its direction
     */
    void removeConstant(const InftyExpressionSet::const_iterator &it);

    /**
     * Applies the given substitution to this LimitProblem and stores the given number
     * as an identifier for the substitution.
     * transformation rule (C)
     * @param sub must be a valid substitution
     */
    void substitute(const ArithSubs &sub, int substitutionIndex);

    /**
     * Discards all but the leading term of the given univariate polynomial.
     * transformation rule (D)
     * @param it must be a valid const_iterator of the underlying set and
     *           must point to a non-constant, univariate polynomial whose
     *           direction is POS, POS_INF, or NEG_INF
     */
    void trimPolynomial(const InftyExpressionSet::const_iterator &it);

    /**
     * Replaces a power by its exponent and base (minus one).
     * @param it must be a valid const_iterator of the underlying set and
     *           must point to a univariate addition that consists of exactly
     *           one power where the exponent is a non-constant polynomial
     *           and arbitrary many monoms. The direction of *it must be POS_INF
     *           or POS.
     */
    void reduceExp(const InftyExpressionSet::const_iterator &it);

    /**
     * "Unstacks" a power.
     * @param it must be a valid const_iterator of the underlying set and
     *           must point to an addition where a summand is a power that has
     *           at least two different variables or whose exponent is not a
     *           polynomial.
     */
    void reduceGeneralExp(const InftyExpressionSet::const_iterator &it);

    /**
     * Clears the set of InftyExpressions, useful if the problem was completely
     * solved by a SMT query.
     */
    void removeAllConstraints();

    /**
     * Returns true iff this problem is marked as unsolvable.
     */
    bool isUnsolvable() const;

    /**
     * Marks this problem as unsolvable.
     */
    void setUnsolvable();

    /**
     * Returns true iff this problem is solved and not marked as unsolvable.
     */
    bool isSolved() const;

    /**
     * Returns a solution for this LimitProblem.
     * This LimitProblem must be solved and must not be marked as unsolvable.
     */
    ArithSubs getSolution() const;

    /**
     * Returns the variable that is used in the solution returned by getSolution().
     */
    Arith::Var getN() const;

    /**
     * Returns a reference to the vector storing the substitution identifiers.
     */
    const std::vector<int>& getSubstitutions() const;

    /**
     * Returns a const_iterator of the underlying set to the given InftyExpression.
     * Ignores the direction of the given InftyExpression.
     */
    InftyExpressionSet::const_iterator find(const InftyExpression &ex) const;

    /**
     * Returns a set of all variables appearing in this limit problem
     */
    std::set<Arith::Var> getVariables() const;

    /**
     * Returns this LimitProblem as a set of relational Expressions:
     * t (+), t (+!), t(+/+!) -> t > 0
     * t (-), t (-!) -> t < 0
     */
    std::vector<Arith::Lit> getQuery() const;

    /**
     * Returns true if the result of getQuery() is unsatisfiable according to z3.
     * Returns false if it is satisfiable or if satisfiability is unknown.
     */
    bool isUnsat() const;


    /**
     * Returns true if all expressions of this limit problem are linear.
     */
    bool isLinear() const;

    /**
     * Returns true if all expressions of this limit problem are polynomial.
     */
    bool isPoly() const;


    /**
     * Returns true iff the conditions for calling removeConstant(it) are met.
     */
    bool removeConstantIsApplicable(const InftyExpressionSet::const_iterator &it);


    /**
     * Returns true iff the conditions for calling trimPolynomial(it) are met.
     */
    bool trimPolynomialIsApplicable(const InftyExpressionSet::const_iterator &it);

    /**
     * Returns true iff the conditions for calling reduceExp(it) are met.
     */
    bool reduceExpIsApplicable(const InftyExpressionSet::const_iterator &it);

    /**
     * Returns true iff the conditions for calling reduceGeneralExp(it) are met.
     */
    bool reduceGeneralExpIsApplicable(const InftyExpressionSet::const_iterator &it);

    /**
     * Returns the number of InftyExpressions in this LimitProblem.
     */
    InftyExpressionSet::size_type getSize() const;

    const InftyExpressionSet getSet() const;

    /**
     * Returns the internal log.
     */
    std::string getProof() const;

private:
    InftyExpressionSet set {};
    Arith::Var variableN;
    std::vector<int> substitutions {};
    bool unsolvable;

    // use unique_ptr, as gcc < 5 is lacking std::move on ostringstream
    std::unique_ptr<std::ostringstream> log;
};

std::ostream& operator<<(std::ostream &os, const LimitProblem &lp);
