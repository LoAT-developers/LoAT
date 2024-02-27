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
#include "set.hpp"
#include "guardtoolbox.hpp"
#include "theories.hpp"
#include "optional.hpp"
#include "string.hpp"


AsymptoticBound::AsymptoticBound(Guard guard,
                                 Arith::Expr cost, bool finalCheck)
    : guard(guard), cost(cost), finalCheck(finalCheck),
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

    auto g {BExpression::mkAndFromLits(guard)};
    auto changed {false};
    do {
        changed = false;
        auto subs {GuardToolbox::propagateEqualities(g, [](const auto &x){return !theories::isTempVar(x);})};
        if (subs) {
            substitutions.push_back(*subs);
            g = g->subs(Subs::build<Arith>(*subs));
            changed = true;
        } else {
            subs = GuardToolbox::propagateEqualities(g, [](const auto &x){return theories::isTempVar(x);});
            if (subs) {
                substitutions.push_back(*subs);
                g = g->subs(Subs::build<Arith>(*subs));
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

    Guard guardCopy = guard;
    guardCopy.push_back(ArithLit::mkGt(cost, 0));
    for (const auto &lit : guardCopy) {
        const ArithLit &rel = std::get<ArithLit>(lit);
        for (const auto &var : rel.vars()) {
            if (!solution.contains(var)) {
                solution = solution.compose({{var, 0}});
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
            assert(sub->isPoly(n));
            assert(sub->isRational() || (sub->isUnivariate() && sub->has(n)));
            const auto d {*sub->degree(n)};
            if (d > upperBound) {
                upperBound = d;
            }
        }
    }
    return upperBound;
}


Int AsymptoticBound::findLowerBoundforSolvedCost(const LimitProblem &limitProblem, const ArithSubs &solution) {
    const auto solvedCost {solution(cost)};
    Int lowerBound;
    const auto n {limitProblem.getN()};
    if (solvedCost->isPoly()) {
        assert(!solvedCost->isMultivariate());
        lowerBound = *solvedCost->degree(n);
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

void AsymptoticBound::removeUnsatProblems() {
    for (int i = limitProblems.size() - 1; i >= 0; --i) {
        auto result = SmtFactory::_check(BoolExpression<Arith>::mkAndFromLits(limitProblems[i].getQuery()));

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
            if (!it->first->isMultivariate() && tryApplyingLimitVector(it)) {
                goto start;
            }
        }

        for (it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
            if (it->first->isMultivariate() && tryApplyingLimitVectorSmartly(it)) {
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
        if (!cost->isPoly()) {
            return false;
        }

        if (cost->maxDegree() > solvedCost->degree(n)) {
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

    if (finalCheck && it->second == POS) {
        limitProblems.push_back(currentLP);
        limitProblems.back().addExpression(InftyExpression(it->first, dir));
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
    Arith::Expr l, r;
    const auto e {it->first};
    const auto d {it->second};
    const auto has_limit_vectors
        {e->map<bool>(
              [&](const NumConstantPtr c) {
                  if (c->denominator()->is(1)) {
                      l = c->numerator();
                      r = c->denominator();
                      limitVectors = &division[d];
                      return true;
                  }
                  return false;
              },
              [&](const NumVarPtr) {
                  return false;
              },
              [&](const AddPtr a) {
                  const auto &args {a->getArgs()};
                  auto arg_it {args.begin()};
                  l = *arg_it;
                  ++arg_it;
                  std::vector<Arith::Expr> rhs_args;
                  for (; arg_it != args.end(); ++arg_it) {
                      rhs_args.emplace_back(*arg_it);
                  }
                  r = arith::mkPlus(rhs_args);
                  limitVectors = &addition[d];
                  return true;
              },
              [&](const MultPtr m) {
                  const auto &args {m->getArgs()};
                  auto arg_it {args.begin()};
                  l = *arg_it;
                  ++arg_it;
                  std::vector<Arith::Expr> rhs_args;
                  for (; arg_it != args.end(); ++arg_it) {
                      rhs_args.emplace_back(*arg_it);
                  }
                  r = arith::mkTimes(rhs_args);
                  limitVectors = &multiplication[d];
                  return true;
              },
              [&](const ExpPtr e) {
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


bool AsymptoticBound::tryApplyingLimitVectorSmartly(const InftyExpressionSet::const_iterator &it) {
    Arith::Expr l, r;
    std::vector<LimitVector> *limitVectors;
    const auto e {it->first};
    const auto d {it->second};
    const auto has_limit_vectors
        {e->map<bool>(
            [&](const NumConstantPtr) {
                return false;
            },
            [&](const NumVarPtr) {
                return false;
            },
            [&](const AddPtr a) {
                std::vector<Arith::Expr> l_args;
                std::vector<Arith::Expr> r_args;
                std::optional<NumVarPtr> oneVar;
                for (const auto &ex: a->getArgs()) {
                    if (ex->isRational()) {
                        l_args.clear();
                        r_args.clear();
                        l_args.emplace_back(ex);
                        r_args.emplace_back(e - ex);
                        break;
                    } else if (ex->isUnivariate()) {
                        if (!oneVar) {
                            oneVar = ex->someVar();
                        }
                        if (oneVar == ex->someVar()) {
                            l_args.push_back(ex);
                        } else {
                            r_args.push_back(ex);
                        }
                    } else {
                        r_args.push_back(ex);
                    }
                }
                l = arith::mkPlus(l_args);
                r = arith::mkPlus(r_args);
                if (l->is(0) || r->is(0)) {
                    return false;
                }
                limitVectors = &addition[d];
                return true;
            },
            [&](const MultPtr m) {
                std::vector<Arith::Expr> l_args;
                std::vector<Arith::Expr> r_args;
                l_args.emplace_back(arith::mkConst(1));
                r_args.emplace_back(arith::mkConst(1));
                std::optional<NumVarPtr> oneVar;
                for (const auto &ex: m->getArgs()) {
                    const auto c {ex->isRational()};
                    if (c) {
                        l_args.clear();
                        r_args.clear();
                        l_args.push_back(ex);
                        r_args.push_back(e->divide(***c));
                        break;
                    } else if (ex->isUnivariate()) {
                        if (!oneVar) {
                            oneVar = ex->someVar();
                        }
                        if (oneVar == ex->someVar()) {
                            l_args.emplace_back(ex);
                        } else {
                            r_args.emplace_back(ex);
                        }
                    } else {
                        r_args.emplace_back(ex);
                    }
                }
                l = arith::mkPlus(l_args);
                r = arith::mkPlus(r_args);
                if (l->is(1) || r->is(1)) {
                    return false;
                }
                limitVectors = &multiplication[d];
                return true;
            },
            [](const auto ExpPtr) {
                return false;
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


bool AsymptoticBound::tryInstantiatingVariable() {
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        const auto [e,dir] {*it};

        if (e->isUnivariate() && (dir == POS || dir == POS_CONS || dir == NEG_CONS)) {
            const auto &query = currentLP.getQuery();
            auto solver = SmtFactory::_modelBuildingSolver<Arith>(Smt<Arith>::chooseLogic<std::vector<Theory<Arith>::Lit>, ArithSubs>({query}, {}));
            solver->add(BoolExpression<Arith>::mkAndFromLits(query));
            SmtResult result = solver->check();

            if (result == Unsat) {
                currentLP.setUnsolvable();

            } else if (result == Sat) {
                const auto model {solver->model()};
                const auto var {*e->someVar()};

                const auto rational {model.get<Arith>(var)};
                substitutions.push_back({{var, arith::mkConst(rational)}});

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
        const auto [e,dir] {*it};
        const auto e_var {e->isVar()};
        if (e_var) {
            for (it2 = std::next(it); it2 != currentLP.cend(); ++it2) {
                const auto [e2,dir2] {*it2};
                if (e2->isVar()) {
                    if (((dir == POS || dir == POS_INF) && (dir2 == POS || dir2 == POS_INF))
                        || (dir == NEG_INF && dir2 == NEG_INF)) {
                        assert(*it != *it2);

                        ArithSubs sub{{*e_var, e2}};
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
                                                             const Arith::Expr &cost,
                                                             bool finalCheck,
                                                             const Complexity &currentRes) {

    AsymptoticBound asymptoticBound(guard, cost, finalCheck);
    asymptoticBound.initLimitVectors();

    asymptoticBound.createInitialLimitProblem();
    // first try the SMT encoding
    bool polynomial = cost->isPoly() && asymptoticBound.currentLP.isPoly();
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
