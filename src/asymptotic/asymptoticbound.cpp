#include "asymptoticbound.hpp"

#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <optional>

#include "numexpression.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "limitsmt.hpp"
#include "inftyexpression.hpp"
#include "config.hpp"
#include "set.hpp"

using namespace std;


AsymptoticBound::AsymptoticBound(Guard guard,
                                 Expr cost, bool finalCheck)
    : guard(guard), cost(cost), finalCheck(finalCheck),
      addition(DirectionSize), multiplication(DirectionSize), division(DirectionSize), currentLP() {
    assert(guard.isWellformed());
}


void AsymptoticBound::initLimitVectors() {

    for (int i = 0; i < DirectionSize; ++i) {
        Direction dir = static_cast<Direction>(i);

        for (const LimitVector &lv : LimitVector::Addition) {
            if (lv.isApplicable(dir)) {
                addition[dir].push_back(lv);
            }
        }

        for (const LimitVector &lv : LimitVector::Multiplication) {
            if (lv.isApplicable(dir)) {
                multiplication[dir].push_back(lv);
            }
        }

        for (const LimitVector &lv : LimitVector::Division) {
            if (lv.isApplicable(dir)) {
                division[dir].push_back(lv);
            }
        }
    }

}


void AsymptoticBound::normalizeGuard() {

    Conjunction<IntTheory> ineqs;
    for (const auto &lit : guard) {
        const Rel &rel = std::get<Rel>(lit);
        if (rel.isEq()) {
            // Split equation
            ineqs.push_back(Rel::buildGeq(rel.lhs() - rel.rhs(), 0));
            ineqs.push_back(Rel::buildGeq(rel.rhs() - rel.lhs(), 0));
        } else {
            ineqs.push_back(rel.toG().makeRhsZero());
        }
    }
    for (const auto &lit: ineqs) {
        const Rel &rel = std::get<Rel>(lit);
        if (rel.isPoly() && !rel.isStrict()) {
            normalizedGuard.push_back(rel.toGt());
        } else {
            normalizedGuard.push_back(rel);
        }
    }
}

void AsymptoticBound::createInitialLimitProblem() {
    currentLP = LimitProblem(normalizedGuard, cost);
}

void AsymptoticBound::propagateBounds() {
    assert(substitutions.size() == 0);

    if (currentLP.isUnsolvable()) {
        return;
    }

    // build substitutions from equations
    for (const auto &lit : guard) {
        const Rel &rel = std::get<Rel>(lit);
        Expr target = rel.rhs() - rel.lhs();
        if (rel.isEq() && rel.isPoly()) {

            std::vector<NumVar> vars;
            std::vector<NumVar> tempVars;
            for (const auto & var : target.vars()) {
                if (var.isTempVar()) {
                    tempVars.push_back(var);
                } else {
                    vars.push_back(var);
                }
            }

            vars.insert(vars.begin(), tempVars.begin(), tempVars.end());

            // check if equation can be solved for a single variable
            // check program variables first
            for (const auto &var : vars) {
                //solve target for var (result is in target)
                auto optSolved = target.solveTermFor(var, TrivialCoeffs);
                if (optSolved) {
                    substitutions.push_back({{var, *optSolved}});
                    break;
                }
            }
        }
    }

    // apply all substitutions resulting from equations
    for (unsigned int i = 0; i < substitutions.size(); ++i) {
        currentLP.substitute(substitutions[i], i);
    }

    if (currentLP.isUnsolvable()) {
        return;
    }
    limitProblems.push_back(currentLP);
}

ExprSubs AsymptoticBound::calcSolution(const LimitProblem &limitProblem) {
    assert(limitProblem.isSolved());

    ExprSubs solution;
    for (int index : limitProblem.getSubstitutions()) {
        const auto &sub = substitutions[index];

        solution = solution.compose(sub);
    }

    solution = solution.compose(limitProblem.getSolution());

    Guard guardCopy = guard;
    guardCopy.push_back(Rel::buildGt(cost, 0));
    for (const auto &lit : guardCopy) {
        const Rel &rel = std::get<Rel>(lit);
        for (const auto &var : rel.vars()) {
            if (!solution.contains(var)) {
                solution = solution.compose({{var, 0}});
            }
        }
    }

    return solution;
}


int AsymptoticBound::findUpperBoundforSolution(const LimitProblem &limitProblem,
                                               const ExprSubs &solution) {
    NumVar n = limitProblem.getN();
    int upperBound = 0;
    for (auto const &pair : solution) {
        if (!pair.first.isTempVar()) {
            Expr sub = pair.second;
            assert(sub.isPoly(n));
            assert(sub.isGround()
                   || (sub.isUnivariate() && sub.has(n)));

            Expr expanded = sub.expand();
            int d = expanded.degree(n);

            if (d > upperBound) {
                upperBound = d;
            }
        }
    }

    return upperBound;
}


int AsymptoticBound::findLowerBoundforSolvedCost(const LimitProblem &limitProblem,
                                                 const ExprSubs &solution) {

    Expr solvedCost = cost.subs(solution);

    int lowerBound;
    NumVar n = limitProblem.getN();
    if (solvedCost.isPoly()) {
        assert(solvedCost.isPoly(n));
        assert(solvedCost.isNotMultivariate());

        Expr expanded = solvedCost.expand();
        int d = expanded.degree(n);
        lowerBound = d;

    } else {
        std::vector<Expr> nonPolynomial;
        Expr expanded = solvedCost.expand();

        Expr powerPattern = Expr::wildcard(1) ^ Expr::wildcard(2);
        linked_hash_set<Expr> powers;
        assert(expanded.findAll(powerPattern, powers));

        lowerBound = 1;
        for (const Expr &ex : powers) {

            if (ex.op(1).has(n) && ex.op(1).isPoly(n)) {
                assert(ex.op(0).isInt());
                assert(ex.op(0).toNum().is_positive());
                Num numBase = ex.op(0).toNum();
                if ((numBase - std::numeric_limits<int>::min()).is_negative() ||
                        (numBase - std::numeric_limits<int>::max()).is_positive()) {
                    throw std::overflow_error("base too large");
                }
                int base = numBase.to_int();
                if (base > lowerBound) {
                    lowerBound = base;
                }
            }
        }
        assert(lowerBound > 1);

        // code the lowerBound as a negative number to mark it as exponential
        lowerBound = -lowerBound;
    }

    return lowerBound;
}

void AsymptoticBound::removeUnsatProblems() {
    for (int i = limitProblems.size() - 1; i >= 0; --i) {
        auto result = SmtFactory::check(BoolExpression<IntTheory>::buildAndFromLits(limitProblems[i].getQuery()));

        if (result == Unsat) {
            limitProblems.erase(limitProblems.begin() + i);
        } else if (result == Unknown
                   && !finalCheck
                   && limitProblems[i].getSize() >= Config::Limit::ProblemDiscardSize) {
            limitProblems.erase(limitProblems.begin() + i);
        }
    }
}


bool AsymptoticBound::solveViaSMT(Complexity currentRes) {
    if (!currentLP.isPoly() || !trySmtEncoding(currentRes)) {
        return false;
    }

    solvedLimitProblems.push_back(currentLP);

    proof.append("Solved the limit problem by the following transformations:");
    proof.append(currentLP.getProof());

    isAdequateSolution(currentLP);
    return true;
}


bool AsymptoticBound::solveLimitProblem() {
    if (limitProblems.empty()) {
        return false;
    }

    currentLP = std::move(limitProblems.back());
    limitProblems.pop_back();

    start:
    if (!currentLP.isUnsolvable() && !currentLP.isSolved()) {

        InftyExpressionSet::const_iterator it;

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (tryRemovingConstant(it)) {
                goto start;
            }
        }

        //if the problem is polynomial, try a (max)SMT encoding
        if (currentLP.isPoly()) {
            if (trySmtEncoding(Complexity::Const)) {
                goto start;
            }
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (tryTrimmingPolynomial(it)) {
                goto start;
            }
        }

        if (trySubstitutingVariable()) {
            goto start;
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (tryReducingExp(it)) {
                goto start;
            }
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (tryReducingGeneralExp(it)) {
                goto start;
            }
        }

        if (tryInstantiatingVariable()) {
            goto start;
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (it->isNotMultivariate() && tryApplyingLimitVector(it)) {
                goto start;
            }
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (it->isMultivariate() && tryApplyingLimitVectorSmartly(it)) {
                goto start;
            }
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (tryApplyingLimitVector(it)) {
                goto start;
            }
        }

    }

    if (!currentLP.isUnsolvable() && currentLP.isSolved()) {
        solvedLimitProblems.push_back(currentLP);

        proof.append("Solved the limit problem by the following transformations:");
        proof.append(currentLP.getProof());

        if (isAdequateSolution(currentLP)) {
            return true;
        }
    }

    if (limitProblems.empty()) {
        return !solvedLimitProblems.empty();

    } else {
        currentLP = std::move(limitProblems.back());
        limitProblems.pop_back();
        goto start;
    }
}


AsymptoticBound::ComplexityResult AsymptoticBound::getComplexity(const LimitProblem &limitProblem) {
    ComplexityResult res;

    res.solution = calcSolution(limitProblem);
    res.upperBound = findUpperBoundforSolution(limitProblem, res.solution);

    for (auto const &pair : res.solution) {
        if (!pair.second.isRationalConstant()) {
            ++res.inftyVars;
        }
    }

    if (res.inftyVars == 0) {
        res.complexity = Complexity::Unknown;
    } else if (res.upperBound == 0) {
        res.complexity = Complexity::Unbounded;
    } else {
        res.lowerBound = findLowerBoundforSolvedCost(limitProblem, res.solution);

        if (res.lowerBound < 0) { // lower bound is exponential
            res.lowerBound = -res.lowerBound;
            res.complexity = Complexity::Exp;

            // Note: 2^sqrt(n) is not exponential, we just give up such cases (where the exponent might be sublinear)
            // Example: cost 2^y with guard x > y^2
            if (res.upperBound > 1) {
                res.complexity = Complexity::Unknown;
            }

        } else {
            res.complexity = Complexity::Poly(res.lowerBound, res.upperBound);
        }
    }

    if (res.complexity > bestComplexity.complexity) {
        bestComplexity = res;
    }

    return res;
}


bool AsymptoticBound::isAdequateSolution(const LimitProblem &limitProblem) {
    assert(limitProblem.isSolved());

    ComplexityResult result = getComplexity(limitProblem);

    if (result.complexity == Complexity::Unbounded) {
        return true;
    }

    if (toComplexity(cost)  > result.complexity) {
        return false;
    }

    Expr solvedCost = cost.subs(result.solution).expand();
    NumVar n = limitProblem.getN();

    if (solvedCost.isPoly(n)) {
        if (!cost.isPoly()) {
            return false;
        }

        if (cost.maxDegree() > solvedCost.degree(n)) {
            return false;
        }

    }

    for (const auto &var : cost.vars()) {
        if (var.isTempVar()) {
            // we try to achieve ComplexInfty
            return false;
        }
    }

    return true;
}


void AsymptoticBound::createBacktrackingPoint(const InftyExpressionSet::const_iterator &it,
                                              Direction dir) {
    assert(dir == POS_INF || dir == POS_CONS);

    if (finalCheck && it->getDirection() == POS) {
        limitProblems.push_back(currentLP);
        limitProblems.back().addExpression(InftyExpression(*it, dir));
    }
}


bool AsymptoticBound::tryRemovingConstant(const InftyExpressionSet::const_iterator &it) {
    if (currentLP.removeConstantIsApplicable(it)) {

        currentLP.removeConstant(it);
        return true;

    } else {
        return false;
    }
}


bool AsymptoticBound::tryTrimmingPolynomial(const InftyExpressionSet::const_iterator &it) {
    if (currentLP.trimPolynomialIsApplicable(it)) {
        createBacktrackingPoint(it, POS_CONS);

        currentLP.trimPolynomial(it);

        return true;
    } else {
        return false;
    }
}


bool AsymptoticBound::tryReducingExp(const InftyExpressionSet::const_iterator &it) {
    if (currentLP.reduceExpIsApplicable(it)) {
        createBacktrackingPoint(it, POS_CONS);

        currentLP.reduceExp(it);

        return true;
    } else {
        return false;
    }
}


bool AsymptoticBound::tryReducingGeneralExp(const InftyExpressionSet::const_iterator &it) {
    if (currentLP.reduceGeneralExpIsApplicable(it)) {
        createBacktrackingPoint(it, POS_CONS);

        currentLP.reduceGeneralExp(it);

        return true;
    } else {
        return false;
    }
}


bool AsymptoticBound::tryApplyingLimitVector(const InftyExpressionSet::const_iterator &it) {
    std::vector<LimitVector> *limitVectors;

    Expr l, r;
    if (it->isNonIntConstant()) {
        l = it->numerator();
        r = it->denominator();

        limitVectors = &division[it->getDirection()];

    } else if (it->isAdd()) {
        l = 0;
        r = 0;
        int pos = 0;

        for (int i = 0; i <= pos; ++i) {
            l = l + it->op(i);
        }
        for (unsigned int i = pos + 1; i < it->arity(); ++i) {
            r = r + it->op(i);
        }

        limitVectors = &addition[it->getDirection()];

    } else if (it->isMul()) {
        l = 1;
        r = 1;
        int pos = 0;

        for (int i = 0; i <= pos; ++i) {
            l = l * it->op(i);
        }
        for (unsigned int i = pos + 1; i < it->arity(); ++i) {
            r = r * it->op(i);
        }

        limitVectors = &multiplication[it->getDirection()];

    } else if (it->isNaturalPow()) {
        Expr base = it->op(0);
        Num power = it->op(1).toNum();

        if (power.is_even()) {
            l = base ^ Expr(power / 2);
            r = l;
        } else {
            l = base;
            r = base ^ Expr(power - 1);
        }

        limitVectors = &multiplication[it->getDirection()];

    } else {
        return false;
    }

    return applyLimitVectorsThatMakeSense(it, l, r, *limitVectors);
}


bool AsymptoticBound::tryApplyingLimitVectorSmartly(const InftyExpressionSet::const_iterator &it) {
    Expr l, r;
    std::vector<LimitVector> *limitVectors;
    if (it->isAdd()) {
        l = 0;
        r = 0;

        bool foundOneVar = false;
        std::optional<NumVar> oneVar;
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr ex(it->op(i));

            if (ex.isGround()) {
                l = ex;
                r = *it - ex;
                break;

            } else if (ex.isUnivariate()) {
                if (!foundOneVar) {
                    foundOneVar = true;
                    oneVar = ex.someVar();
                    l = ex;

                } else if (oneVar && *oneVar == ex.someVar()) {
                    l = l + ex;

                } else {
                    r = r + ex;
                }
            } else {
                r = r + ex;
            }
        }

        if (l.isZero() || r.isZero()) {
            return false;
        }

        limitVectors = &addition[it->getDirection()];
    } else if (it->isMul()) {
        l = 1;
        r = 1;

        bool foundOneVar = false;
        std::optional<NumVar> oneVar;
        for (unsigned int i = 0; i < it->arity(); ++i) {
            Expr ex(it->op(i));

            if (ex.isGround()) {
                l = ex;
                r = *it / ex;
                break;

            } else if (ex.isUnivariate()) {
                if (!foundOneVar) {
                    foundOneVar = true;
                    oneVar = ex.someVar();
                    l = ex;

                } else if (oneVar && *oneVar == ex.someVar()) {
                    l = l * ex;

                } else {
                    r = r * ex;
                }
            } else {
                r = r * ex;
            }
        }

        if (l == 1 || r == 1) {
            return false;
        }

        limitVectors = &multiplication[it->getDirection()];
    } else {
        return false;
    }

    return applyLimitVectorsThatMakeSense(it, l, r, *limitVectors);
}


bool AsymptoticBound::applyLimitVectorsThatMakeSense(const InftyExpressionSet::const_iterator &it,
                                                     const Expr &l, const Expr &r,
                                                     const std::vector<LimitVector> &limitVectors) {
    bool posInfVector = false;
    bool posConsVector = false;
    toApply.clear();
    for (const LimitVector &lv: limitVectors) {
        if (lv.makesSense(l, r)) {
            toApply.push_back(lv);

            if (lv.getType() == POS_INF) {
                posInfVector = true;
            } else if (lv.getType() == POS_CONS) {
                posConsVector = true;
            }
        }
    }

    if (posInfVector && !posConsVector) {
        createBacktrackingPoint(it, POS_CONS);
    }
    if (posConsVector && !posInfVector) {
        createBacktrackingPoint(it, POS_INF);
    }

    if (!toApply.empty()) {
        for (unsigned int i = 0; i < toApply.size() - 1; ++i) {
            limitProblems.push_back(currentLP);
            LimitProblem &copy = limitProblems.back();
            auto copyIt = copy.find(*it);

            copy.applyLimitVector(copyIt, l, r, toApply[i]);

            if (copy.isUnsolvable()) {
                limitProblems.pop_back();
            }
        }

        currentLP.applyLimitVector(it, l, r, toApply.back());

        return true;
    } else {
        return false;
    }
}


bool AsymptoticBound::tryInstantiatingVariable() {
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        Direction dir = it->getDirection();

        if (it->isUnivariate() && (dir == POS || dir == POS_CONS || dir == NEG_CONS)) {
            const auto &query = currentLP.getQuery();
            auto solver = SmtFactory::modelBuildingSolver<IntTheory>(Smt<IntTheory>::chooseLogic<std::vector<Theory<IntTheory>::Lit>, ExprSubs>({query}, {}));
            solver->add(BoolExpression<IntTheory>::buildAndFromLits(query));
            SmtResult result = solver->check();

            if (result == Unsat) {
                currentLP.setUnsolvable();

            } else if (result == Sat) {
                const auto &model = solver->model();
                auto var = it->someVar();

                Expr rational {model.get<IntTheory>(var)};
                substitutions.push_back({{var, rational}});

                createBacktrackingPoint(it, POS_INF);
                currentLP.substitute(substitutions.back(), substitutions.size() - 1);

            } else {

                if (!finalCheck && currentLP.getSize() >= Config::Limit::ProblemDiscardSize) {
                    currentLP.setUnsolvable();
                }

                return false;
            }

            return true;
        }
    }

    return false;
}


bool AsymptoticBound::trySubstitutingVariable() {
    InftyExpressionSet::const_iterator it, it2;
    for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        if (it->isVar()) {
            for (it2 = std::next(it); it2 != currentLP.cend(); ++it2) {
                if (it2->isVar()) {
                    Direction dir = it->getDirection();
                    Direction dir2 = it2->getDirection();

                    if (((dir == POS || dir == POS_INF) && (dir2 == POS || dir2 == POS_INF))
                        || (dir == NEG_INF && dir2 == NEG_INF)) {
                        assert(*it != *it2);

                        ExprSubs sub{{it->toVar(), *it2}};
                        substitutions.push_back(sub);

                        createBacktrackingPoint(it, POS_CONS);
                        createBacktrackingPoint(it2, POS_CONS);
                        currentLP.substitute(sub, substitutions.size() - 1);

                        return true;
                    }
                }
            }
        }
    }

    return false;
}


bool AsymptoticBound::trySmtEncoding(Complexity currentRes) {
    auto optSubs = LimitSmtEncoding::applyEncoding(currentLP, cost, currentRes);
    if (!optSubs) return false;
    auto subs = *optSubs;
    auto idx = substitutions.size();
    substitutions.push_back(subs);
    currentLP.removeAllConstraints();
    currentLP.substitute(subs, idx);
    return true;
}


AsymptoticBound::Result AsymptoticBound::determineComplexity(const Guard &guard,
                                                             const Expr &cost,
                                                             bool finalCheck,
                                                             const Complexity &currentRes) {

    // Expand the cost to make it easier to analyze
    Expr expandedCost = cost.expand();

    AsymptoticBound asymptoticBound(guard, expandedCost, finalCheck);
    asymptoticBound.initLimitVectors();
    asymptoticBound.normalizeGuard();

    asymptoticBound.createInitialLimitProblem();
    // first try the SMT encoding
    bool polynomial = cost.isPoly() && asymptoticBound.currentLP.isPoly();
    bool result = polynomial && asymptoticBound.solveViaSMT(currentRes);
    if (!result) {
        // Otherwise perform limit calculus
        asymptoticBound.propagateBounds();
        asymptoticBound.removeUnsatProblems();
        result = asymptoticBound.solveLimitProblem();
    }

    if (result) {

        // Print solution
        asymptoticBound.proof.append("Solution:");
        for (const auto &pair : asymptoticBound.bestComplexity.solution) {
            asymptoticBound.proof.append(stringstream() << pair.first << " / " << pair.second);
        }

        Expr solvedCost = asymptoticBound.cost.subs(asymptoticBound.bestComplexity.solution);
        return Result(asymptoticBound.bestComplexity.complexity,
                      solvedCost.expand(),
                      asymptoticBound.bestComplexity.inftyVars,
                      asymptoticBound.proof);
    } else {

        asymptoticBound.proof.append("Could not solve the limit problem.");

        return Result(Complexity::Unknown);
    }

}
