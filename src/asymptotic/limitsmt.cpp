#include "limitsmt.hpp"

#include "smt.hpp"
#include "smtfactory.hpp"
#include "inftyexpression.hpp"

#include <map>

using namespace std;


/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a positive constant
 */
static BExpr<IntTheory> posConstraint(const map<Int, IntTheory::Expression>& coefficients) {
    std::vector<IntTheory::Lit> conjunction;
    for (auto &[degree, c] : coefficients) {
        if (degree > 0) {
            conjunction.push_back(Rel::buildGeq(c, ne::buildConstant(0)));
            conjunction.push_back(Rel::buildLeq(c, ne::buildConstant(0)));
        } else {
            conjunction.push_back(Rel::buildGt(c, ne::buildConstant(0)));
        }
    }
    return BoolExpression<IntTheory>::buildAndFromLits(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a negative constant
 */
static BExpr<IntTheory> negConstraint(const map<Int, IntTheory::Expression>& coefficients) {
    std::vector<IntTheory::Lit> conjunction;
    for (const auto &[degree, c] : coefficients) {
        if (degree > 0) {
            conjunction.push_back(Rel::buildGeq(c, ne::buildConstant(0)));
            conjunction.push_back(Rel::buildLeq(c, ne::buildConstant(0)));
        } else {
            conjunction.push_back(Rel::buildLt(c, 0));
        }
    }
    return BoolExpression<IntTheory>::buildAndFromLits(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = -\infty
 */
static BExpr<IntTheory> negInfConstraint(const map<Int, IntTheory::Expression>& coefficients) {
    Int maxDegree {0};
    for (const auto &[degree, _]: coefficients) {
        maxDegree = degree > maxDegree ? degree : maxDegree;
    }
    std::vector<BExpr<IntTheory>> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<IntTheory::Lit> conjunction;
        for (const auto &[degree, c]: coefficients) {
            if (degree > i) {
                conjunction.push_back(Rel::buildGeq(c, ne::buildConstant(0)));
                conjunction.push_back(Rel::buildLeq(c, ne::buildConstant(0)));
            } else if (degree == i) {
                conjunction.push_back(Rel::buildLt(c, ne::buildConstant(0)));
            }
        }
        disjunction.push_back(BoolExpression<IntTheory>::buildAndFromLits(conjunction));
    }
    return BoolExpression<IntTheory>::buildOr(disjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = \infty
 */
static BExpr<IntTheory> posInfConstraint(const map<Int, IntTheory::Expression>& coefficients) {
    Int maxDegree {0};
    for (const auto &[degree, _] : coefficients) {
        maxDegree = degree > maxDegree ? degree : maxDegree;
    }
    std::vector<BExpr<IntTheory>> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<IntTheory::Lit> conjunction;
        for (const auto &[degree, c] : coefficients) {
            if (degree > i) {
                conjunction.push_back(Rel::buildGeq(c, ne::buildConstant(0)));
                conjunction.push_back(Rel::buildLeq(c, ne::buildConstant(0)));
            } else if (degree == i) {
                conjunction.push_back(Rel::buildGt(c, ne::buildConstant(0)));
            }
        }
        disjunction.push_back(BoolExpression<IntTheory>::buildAndFromLits(conjunction));
    }
    return BoolExpression<IntTheory>::buildOr(disjunction);
}

/**
 * @return the (abstract) coefficients of 'n' in 'ex', where the key is the degree of the respective monomial
 */
static map<Int, IntTheory::Expression> getCoefficients(const IntTheory::Expression ex, const IntTheory::Var n) {
    const auto maxDegree {ex->degree(n)};
    map<Int, IntTheory::Expression> coefficients;
    for (int i = 0; i <= maxDegree; i++) {
        coefficients.emplace(i, *ex->coeff(n, i));
    }
    return coefficients;
}

std::optional<ExprSubs> LimitSmtEncoding::applyEncoding(const LimitProblem &currentLP, const IntTheory::Expression cost, Complexity currentRes) {
    // initialize z3
    const auto solver {SmtFactory::_modelBuildingSolver<IntTheory>(Smt<IntTheory>::chooseLogic<std::vector<Theory<IntTheory>::Lit>, ExprSubs>({currentLP.getQuery(), {Rel::buildGt(cost, 0)}}, {}))};
    // the parameter of the desired family of solutions
    const auto n {currentLP.getN()};
    // get all relevant variables
    const auto vars {currentLP.getVariables()};
    // create linear templates for all variables
    ExprSubs templateSubs;
    std::map<IntTheory::Var, IntTheory::Var> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        const auto c0 {NumVar::next()};
        const auto c {NumVar::next()};
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n->toExpr() * c));
    }
    // replace variables in the cost function with their linear templates
    const auto templateCost {templateSubs(cost)};
    // if the cost function is a constant, then we are bound to fail
    const auto maxPossibleFiniteRes = templateCost->isPoly() ? Complexity::Poly(*templateCost->degree(n)) : Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {};
    }
    // encode every entry of the limit problem
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        // replace variables with their linear templates
        const auto ex {templateSubs(it->first)};
        const auto direction {it->second};
        const auto coefficients {getCoefficients(ex, n)};
        // add the required constraints (depending on the direction-label from the limit problem)
        if (direction == POS) {
            solver->add(posConstraint(coefficients) | posInfConstraint(coefficients));
        } else if (direction == POS_CONS) {
            solver->add(posConstraint(coefficients));
        } else if (direction == POS_INF) {
            solver->add(posInfConstraint(coefficients));
        } else if (direction == NEG_CONS) {
            solver->add(negConstraint(coefficients));
        } else if (direction == NEG_INF) {
            solver->add(negInfConstraint(coefficients));
        }
    }
    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&]() -> bool {
        return solver->check() == Sat;
    };
    // remember the current state for backtracking before trying several variations
    solver->push();
    // first fix that all program variables have to be constants
    // a model witnesses unbounded complexity
    for (const auto &var : vars) {
        if (!var->isTempVar()) {
            solver->add(Rel::buildGeq(varCoeff.at(var), ne::buildConstant(0)));
            solver->add(Rel::buildLeq(varCoeff.at(var), ne::buildConstant(0)));
        }
    }
    if (!checkSolver()) {
        if (maxPossibleFiniteRes <= currentRes) {
            return {};
        }
        // we failed to find a model -- drop all non-mandatory constraints
        solver->pop();
        if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && mp::denominator(maxPossibleFiniteRes.getPolynomialDegree()) == 1) {
            const auto maxPossibleDegree {mp::denominator(maxPossibleFiniteRes.getPolynomialDegree())};
            // try to find a witness for polynomial complexity with degree maxDeg,...,1
            const auto coefficients {getCoefficients(templateCost, n)};
            for (auto i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; --i) {
                const auto c {coefficients.find(i)->second};
                // remember the current state for backtracking
                solver->push();
                solver->add(Rel::buildGt(c, ne::buildConstant(0)));
                if (checkSolver()) {
                    break;
                } else if (i == 1 || Complexity::Poly(i - 1) <= currentRes) {
                    // we even failed to prove the minimal requested bound -- give up
                    return {};
                } else {
                    // remove all non-mandatory constraints and retry with degree i-1
                    solver->pop();
                }
            }
        } else if (!checkSolver()) {
            return {};
        }
    }
    // we found a model -- create the corresponding solution of the limit problem
    ExprSubs smtSubs;
    const auto model {solver->model()};
    for (const auto &var : vars) {
        const auto c0 {varCoeff0.at(var)};
        const auto c {model.get<IntTheory>(varCoeff.at(var))};
        smtSubs.put(var, model.contains<IntTheory>(c0) ? ne::buildConstant(model.get<IntTheory>(c0) + c) * n : ne::buildConstant(c) * n);
    }
    return {smtSubs};
}

BExpr<IntTheory> encodeBoolExpr(const BExpr<IntTheory> expr, const ExprSubs &templateSubs, const IntTheory::Var n) {
    BoolExpressionSet<IntTheory> newChildren;
    for (const auto &c: expr->getChildren()) {
        newChildren.insert(encodeBoolExpr(c, templateSubs, n));
    }
    if (expr->isAnd()) {
        return BoolExpression<IntTheory>::buildAnd(newChildren);
    } else if (expr->isOr()) {
        return BoolExpression<IntTheory>::buildOr(newChildren);
    } else {
        auto lit = expr->getTheoryLit();
        assert(lit);
        const auto lhs {std::get<Rel>(*lit).lhs()};
        const auto ex {templateSubs(lhs)};
        const auto coefficients {getCoefficients(ex, n)};
        return posConstraint(coefficients) | posInfConstraint(coefficients);
    }
}

std::pair<ExprSubs, Complexity> LimitSmtEncoding::applyEncoding(const BExpr<IntTheory> expr, const IntTheory::Expression cost, Complexity currentRes) {
    // initialize z3
    auto solver {SmtFactory::_modelBuildingSolver<IntTheory>(Smt<IntTheory>::chooseLogic(BoolExpressionSet<IntTheory>{expr, BoolExpression<IntTheory>::buildTheoryLit(Rel::buildGt(cost, 0))}))};
    // the parameter of the desired family of solutions
    const auto n {NumVar::next()};
    // get all relevant variables
    auto vars {expr->vars().get<IntTheory::Var>()};
    cost->collectVars(vars);
    auto hasTmpVars {false};
    // create linear templates for all variables
    ExprSubs templateSubs;
    std::map<IntTheory::Var, IntTheory::Var> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        hasTmpVars |= var->isTempVar();
        const auto c0 {NumVar::next()};
        const auto c {NumVar::next()};
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n->toExpr() * c));
    }
    // replace variables in the cost function with their linear templates
    const auto templateCost {templateSubs(cost)};
    // if the cost function is a constant, then we are bound to fail
    const auto maxPossibleFiniteRes = templateCost->isPoly() ? Complexity::Poly(*templateCost->degree(n)) : Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {{}, Complexity::Unknown};
    }
    const auto encoding {encodeBoolExpr(expr, templateSubs, n)};
    solver->add(encoding);
    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&solver] {
        return solver->check() == Sat;
    };
    auto model = [&solver, &vars, &varCoeff0, &varCoeff, &n] {
        ExprSubs smtSubs;
        const auto model {solver->model()};
        for (const auto &var : vars) {
            const auto c0 {varCoeff0.at(var)};
            const auto c {model.get<IntTheory>(varCoeff.at(var))};
            smtSubs.put(var, model.contains<IntTheory>(c0) ? ne::buildConstant(model.get<IntTheory>(c0) + c) * n : ne::buildConstant(c) * n);
        }
        return smtSubs;
    };
    if (hasTmpVars) {
        solver->push();
        solver->add(posInfConstraint(getCoefficients(templateCost, n)));
        // first fix that all program variables have to be constants
        // a model witnesses unbounded complexity
        for (const auto &var : vars) {
            if (!var->isTempVar()) {
                solver->add(Rel::buildGeq(varCoeff.at(var), ne::buildConstant(0)));
                solver->add(Rel::buildLeq(varCoeff.at(var), ne::buildConstant(0)));
            }
        }
        if (checkSolver()) {
            return {model(), Complexity::Unbounded};
        }
        solver->pop();
    }
    if (maxPossibleFiniteRes <= currentRes) {
        return {{}, Complexity::Unknown};
    }
    // we failed to find a model -- drop all non-mandatory constraints
    if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && mp::denominator(maxPossibleFiniteRes.getPolynomialDegree()) == 1) {
        const auto maxPossibleDegree {mp::denominator(maxPossibleFiniteRes.getPolynomialDegree())};
        // try to find a witness for polynomial complexity with degree maxDeg,...,1
        const auto coefficients {getCoefficients(templateCost, n)};
        for (auto i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; --i) {
            const auto c {coefficients.find(i)->second};
            // remember the current state for backtracking
            solver->push();
            solver->add(Rel::buildGt(c, ne::buildConstant(0)));
            if (checkSolver()) {
                return {model(), Complexity::Poly(i)};
            } else {
                // remove all non-mandatory constraints and retry with degree i-1
                solver->pop();
            }
        }
    }
    return {{}, Complexity::Unknown};
}
