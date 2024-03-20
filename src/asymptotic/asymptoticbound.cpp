#include "asymptoticbound.hpp"

#include <iterator>
#include <vector>
#include <algorithm>
#include <sstream>
#include <optional>

#include "arithexpr.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"
#include "limitsmt.hpp"
#include "inftyexpression.hpp"
#include "config.hpp"
#include "linkedhashset.hpp"
#include "guardtoolbox.hpp"
#include "theory.hpp"
#include "optional.hpp"
#include "string.hpp"


AsymptoticBound::AsymptoticBound(Conjunction guard,
                                 Arith::Expr cost)
    : guard(guard), cost(cost),
      addition(DirectionSize), multiplication(DirectionSize), division(DirectionSize), currentLP() {}


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

void AsymptoticBound::createInitialLimitProblem() {
    currentLP = LimitProblem(guard, cost);
}

void AsymptoticBound::propagateBounds() {
    assert(substitutions.size() == 0);

    if (currentLP.isUnsolvable()) {
        return;
    }

    auto g {bools::mkAndFromLits(guard)};
    auto changed {false};
    do {
        changed = false;
        auto subs {GuardToolbox::propagateEqualities(g, [](const auto &x){return !theory::isTempVar(x);})};
        if (subs) {
            substitutions.push_back(*subs);
            g = Subs::build<Arith>(*subs)(g);
            changed = true;
        } else {
            subs = GuardToolbox::propagateEqualities(g, [](const auto &x){return theory::isTempVar(x);});
            if (subs) {
                substitutions.push_back(*subs);
                g = Subs::build<Arith>(*subs)(g);
                changed = true;
            }
        }
    } while (changed);

    // apply all substitutions resulting from equations
    for (unsigned int i = 0; i < substitutions.size(); ++i) {
        currentLP.substitute(substitutions[i], i);
    }

    if (currentLP.isUnsolvable()) {
        return;
    }
    limitProblems.push_back(currentLP);
}

ArithSubs AsymptoticBound::calcSolution(const LimitProblem &limitProblem) {
    assert(limitProblem.isSolved());

    ArithSubs solution;
    for (int index : limitProblem.getSubstitutions()) {
        const auto &sub = substitutions[index];

        solution = solution.compose(sub);
    }

    solution = solution.compose(limitProblem.getSolution());

    auto guardCopy = guard;
    guardCopy.push_back(arith::mkGt(cost, arith::mkConst(0)));
    for (const auto &lit : guardCopy) {
        const ArithLit &rel = std::get<ArithLit>(lit);
        for (const auto &var : rel.vars()) {
            if (!solution.contains(var)) {
                solution = solution.compose({{var, arith::mkConst(0)}});
            }
        }
    }

    return solution;
}


Int AsymptoticBound::findUpperBoundforSolution(const LimitProblem &limitProblem, const ArithSubs &solution) {
    const auto n {limitProblem.getN()};
    Int upperBound {0};
    for (auto const &[x,sub] : solution) {
        if (!x->isTempVar()) {
            assert(sub->isRational() || (sub->isUnivariate() && sub->has(n)));
            const auto d {sub->isPoly(n)};
            if (*d > upperBound) {
                upperBound = *d;
            }
        }
    }
    return upperBound;
}


Int AsymptoticBound::findLowerBoundforSolvedCost(const LimitProblem &limitProblem, const ArithSubs &solution) {
    const auto solvedCost {solution(cost)};
    Int lowerBound;
    const auto n {limitProblem.getN()};
    const auto d {solvedCost->isPoly()};
    if (d) {
        assert(!solvedCost->isMultivariate());
        lowerBound = *d;
    } else {
        std::vector<Arith::Expr> nonPolynomial;
        const auto powers {solvedCost->exps()};
        lowerBound = 1;
        for (const auto &p : powers) {
            if (p->getExponent()->has(n) && p->getExponent()->isPoly(n)) {
                const auto numBase {*p->getBase()->isInt()};
                assert(numBase > 0);
                if (numBase > lowerBound) {
                    lowerBound = numBase;
                }
            }
        }
        assert(lowerBound > 1);

        // code the lowerBound as a negative number to mark it as exponential
        lowerBound = -lowerBound;
    }

    return lowerBound;
}


bool AsymptoticBound::solveViaSMT(Complexity currentRes) {
    if (!currentLP.isPoly() || !trySmtEncoding(currentRes)) {
        return false;
    }

    solvedLimitProblems.push_back(currentLP);

    proof.append("Solved the limit problem by the following transformations:");
    proof.append(currentLP.getProof());

    getComplexity(currentLP);
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
        if (!pair.second->isRational()) {
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

    const auto solvedCost {result.solution(cost)};
    const auto n {limitProblem.getN()};

    if (solvedCost->isPoly(n)) {
        const auto total_degree {cost->isPoly()};
        if (!total_degree) {
            return false;
        }
        const auto n_degree {solvedCost->isPoly(n)};
        if (*total_degree > n_degree) {
            return false;
        }

    }

    for (const auto &var : cost->vars()) {
        if (var->isTempVar()) {
            // we try to achieve ComplexInfty
            return false;
        }
    }

    return true;
}


void AsymptoticBound::createBacktrackingPoint(const InftyExpressionSet::const_iterator &it,
                                              Direction dir) {
    assert(dir == POS_INF || dir == POS_CONS);

    if (it->second == POS) {
        limitProblems.push_back(currentLP);
        limitProblems.back().addExpression(InftyExpression(it->first, dir));
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
    Arith::Expr l {arith::mkConst(0)};
    Arith::Expr r {arith::mkConst(0)};
    const auto e {it->first};
    const auto d {it->second};
    const auto has_limit_vectors
        {e->apply<bool>(
              [&](const ArithConstPtr c) {
                  if (!c->denominator()->is(1)) {
                      l = c->numerator();
                      r = c->denominator();
                      limitVectors = &division[d];
                      return true;
                  }
                  return false;
              },
              [&](const Arith::Var) {
                  return false;
              },
              [&](const ArithAddPtr a) {
                  const auto &args {a->getArgs()};
                  auto arg_it {args.begin()};
                  l = *arg_it;
                  ++arg_it;
                  std::vector<Arith::Expr> rhs_args;
                  for (; arg_it != args.end(); ++arg_it) {
                      rhs_args.emplace_back(*arg_it);
                  }
                  r = arith::mkPlus(std::move(rhs_args));
                  limitVectors = &addition[d];
                  return true;
              },
              [&](const ArithMultPtr m) {
                  const auto &args {m->getArgs()};
                  auto arg_it {args.begin()};
                  l = *arg_it;
                  ++arg_it;
                  std::vector<Arith::Expr> rhs_args;
                  for (; arg_it != args.end(); ++arg_it) {
                      rhs_args.emplace_back(*arg_it);
                  }
                  r = arith::mkTimes(std::move(rhs_args));
                  limitVectors = &multiplication[d];
                  return true;
              },
              [&](const ArithExpPtr e) {
                  return apply<Int>(
                             e->getExponent()->isInt(),
                             [&](const auto &power) {
                                 if (power % 2 == 0) {
                                     l = e->getBase() ^ e->getExponent()->divide(2);
                                     r = l;
                                 } else {
                                     l = e->getBase();
                                     r = e->getBase() ^ arith::mkConst(power - 1);
                                 }
                                 limitVectors = &multiplication[d];
                             }).has_value();
              })};
    return has_limit_vectors ? applyLimitVectorsThatMakeSense(it, l, r, *limitVectors) : false;
}

bool AsymptoticBound::applyLimitVectorsThatMakeSense(const InftyExpressionSet::const_iterator &it,
                                                     const Arith::Expr l, const Arith::Expr r,
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


AsymptoticBound::Result AsymptoticBound::determineComplexity(const Conjunction &guard,
                                                             const Arith::Expr &cost,
                                                             const Complexity &currentRes) {

    AsymptoticBound asymptoticBound(guard, cost);
    asymptoticBound.initLimitVectors();

    asymptoticBound.createInitialLimitProblem();
    // first try the SMT encoding
    bool polynomial = cost->isPoly() && asymptoticBound.currentLP.isPoly();
    bool result = polynomial && asymptoticBound.solveViaSMT(currentRes);
    if (!result) {
        // Otherwise perform limit calculus
        asymptoticBound.propagateBounds();
        result = asymptoticBound.solveLimitProblem();
    }

    if (result) {

        // Print solution
        asymptoticBound.proof.append("Solution:");
        for (const auto &pair : asymptoticBound.bestComplexity.solution) {
            asymptoticBound.proof.append(toString(pair.first) + " / " + toString(pair.second));
        }

        const auto solvedCost {asymptoticBound.bestComplexity.solution(asymptoticBound.cost)};
        return Result(asymptoticBound.bestComplexity.complexity,
                      solvedCost,
                      asymptoticBound.bestComplexity.inftyVars,
                      asymptoticBound.proof);
    } else {

        asymptoticBound.proof.append("Could not solve the limit problem.");

        return Result(Complexity::Unknown);
    }

}
