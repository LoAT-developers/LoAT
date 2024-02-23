#pragma once

#include <string>
#include <vector>

#include "numexpression.hpp"
#include "inftyexpression.hpp"
#include "limitproblem.hpp"
#include "proof.hpp"
#include "complexity.hpp"
#include "theory.hpp"

class AsymptoticBound {
private:
    // internal struct for the return value of getComplexity()
    struct ComplexityResult {
        ComplexityResult()
            : upperBound(0), lowerBound(0), inftyVars(0) {
        }

        ExprSubs solution{};
        Complexity complexity;
        Int upperBound;
        Int lowerBound;
        int inftyVars;
    };

    AsymptoticBound(Guard guard, IntTheory::Expression cost, bool finalCheck);

    void initLimitVectors();
    void createInitialLimitProblem();
    void propagateBounds();
    ExprSubs calcSolution(const LimitProblem &limitProblem);
    Int findUpperBoundforSolution(const LimitProblem &limitProblem, const ExprSubs &solution);
    Int findLowerBoundforSolvedCost(const LimitProblem &limitProblem, const ExprSubs &solution);
    void removeUnsatProblems();
    bool solveViaSMT(Complexity currentRes);
    bool solveLimitProblem();
    ComplexityResult getComplexity(const LimitProblem &limitProblem);
    bool isAdequateSolution(const LimitProblem &limitProblem);

    void createBacktrackingPoint(const InftyExpressionSet::const_iterator &it, Direction dir);
    bool tryRemovingConstant(const InftyExpressionSet::const_iterator &it);
    bool tryTrimmingPolynomial(const InftyExpressionSet::const_iterator &it);
    bool tryReducingExp(const InftyExpressionSet::const_iterator &it);
    bool tryReducingGeneralExp(const InftyExpressionSet::const_iterator &it);
    bool tryApplyingLimitVector(const InftyExpressionSet::const_iterator &it);
    bool tryApplyingLimitVectorSmartly(const InftyExpressionSet::const_iterator &it);
    bool applyLimitVectorsThatMakeSense(const InftyExpressionSet::const_iterator &it,
                                        const Expr &l, const Expr &r,
                                        const std::vector<LimitVector> &limitVectors);
    bool tryInstantiatingVariable();
    bool trySubstitutingVariable();
    bool trySmtEncoding(Complexity currentRes);

    const Guard guard;
    const IntTheory::Expression cost;
    bool finalCheck;
    ComplexityResult bestComplexity {};
    Proof proof {};

    std::vector<std::vector<LimitVector>> addition;
    std::vector<std::vector<LimitVector>> multiplication;
    std::vector<std::vector<LimitVector>> division;

    std::vector<LimitProblem> limitProblems {};
    std::vector<LimitProblem> solvedLimitProblems {};
    LimitProblem currentLP;

    std::vector<ExprSubs> substitutions {};

    std::vector<LimitVector> toApply {};

public:
    /**
     * Result of the asymptotic complexity computation
     */
    struct Result {
        // The resulting complexity of the given rule.
        Complexity cpx;

        // The resulting cost, after expressing variables in terms of n.
        IntTheory::Expression solvedCost;

        // The number of non-constant variables (i.e., which grow with n).
        int inftyVars;

        Proof proof{};

        explicit Result(Complexity c) : cpx(c), solvedCost(0), inftyVars(0) {}
        Result(Complexity c, const IntTheory::Expression x, int v, Proof &proof) : cpx(c), solvedCost(x), inftyVars(v), proof(proof) {}
    };

    /**
     * Analyzes the given guard and cost.
     * @param varMan the VariableManager instance is needed to get information about free variables
     * @param finalCheck enables more sophisticated backtracking and uses Timeout::hard
     */
    static Result determineComplexity(const Guard &guard,
                                      const Expr &cost,
                                      bool finalCheck = false,
                                      const Complexity &currentRes = Complexity::Const);

};
