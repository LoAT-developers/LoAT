#include "limitsmt.hpp"

#include "smt.hpp"
#include "smtfactory.hpp"
#include "inftyexpression.hpp"

using namespace std;


/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a positive constant
 */
static BExpr<IntTheory> posConstraint(const map<int, Expr>& coefficients) {
    std::vector<Rel> conjunction;
    for (pair<int, Expr> p : coefficients) {
        int degree = p.first;
        Expr c = p.second;
        if (degree > 0) {
            conjunction.push_back(Rel::buildEq(c, 0));
        } else {
            conjunction.push_back(Rel::buildGt(c, 0));
        }
    }
    return BoolExpression<IntTheory>::buildAndFromLits(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a negative constant
 */
static BExpr<IntTheory> negConstraint(const map<int, Expr>& coefficients) {
    std::vector<Rel> conjunction;
    for (pair<int, Expr> p : coefficients) {
        int degree = p.first;
        Expr c = p.second;
        if (degree > 0) {
            conjunction.push_back(Rel::buildEq(c, 0));
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
static BExpr<IntTheory> negInfConstraint(const map<int, Expr>& coefficients) {
    int maxDegree = 0;
    for (pair<int, Expr> p: coefficients) {
        maxDegree = p.first > maxDegree ? p.first : maxDegree;
    }
    std::vector<BExpr<IntTheory>> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Rel> conjunction;
        for (pair<int, Expr> p: coefficients) {
            int degree = p.first;
            Expr c = p.second;
            if (degree > i) {
                conjunction.push_back(Rel::buildEq(c, 0));
            } else if (degree == i) {
                conjunction.push_back(Rel::buildLt(c, 0));
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
static BExpr<IntTheory> posInfConstraint(const map<int, Expr>& coefficients) {
    int maxDegree = 0;
    for (pair<int, Expr> p: coefficients) {
        maxDegree = p.first > maxDegree ? p.first : maxDegree;
    }
    std::vector<BExpr<IntTheory>> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Rel> conjunction;
        for (pair<int, Expr> p: coefficients) {
            int degree = p.first;
            Expr c = p.second;
            if (degree > i) {
                conjunction.push_back(Rel::buildEq(c, 0));
            } else if (degree == i) {
                conjunction.push_back(Rel::buildGt(c, 0));
            }
        }
        disjunction.push_back(BoolExpression<IntTheory>::buildAndFromLits(conjunction));
    }
    return BoolExpression<IntTheory>::buildOr(disjunction);
}

/**
 * @return the (abstract) coefficients of 'n' in 'ex', where the key is the degree of the respective monomial
 */
static map<int, Expr> getCoefficients(const Expr &ex, const NumVar &n) {
    int maxDegree = ex.degree(n);
    map<int, Expr> coefficients;
    for (int i = 0; i <= maxDegree; i++) {
        coefficients.emplace(i, ex.coeff(n, i));
    }
    return coefficients;
}

std::optional<ExprSubs> LimitSmtEncoding::applyEncoding(const LimitProblem &currentLP, const Expr &cost,
                                                        Complexity currentRes)
{
    // initialize z3
    auto solver = SmtFactory::modelBuildingSolver<IntTheory>(Smt<IntTheory>::chooseLogic<std::vector<Theory<IntTheory>::Lit>, ExprSubs>({currentLP.getQuery(), {Rel::buildGt(cost, 0)}}, {}));

    // the parameter of the desired family of solutions
    auto n = currentLP.getN();

    // get all relevant variables
    std::set<NumVar> vars = currentLP.getVariables();

    // create linear templates for all variables
    ExprSubs templateSubs;
    std::map<NumVar, NumVar> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        auto c0 = NumVar::next();
        auto c = NumVar::next();
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (Expr(n) * c));
    }

    // replace variables in the cost function with their linear templates
    Expr templateCost = cost.subs(templateSubs).expand();

    // if the cost function is a constant, then we are bound to fail
    Complexity maxPossibleFiniteRes = templateCost.isPoly() ?
            Complexity::Poly(templateCost.degree(n)) :
            Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {};
    }

    // encode every entry of the limit problem
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        // replace variables with their linear templates
        Expr ex = it->subs(templateSubs).expand();
        map<int, Expr> coefficients = getCoefficients(ex, n);
        Direction direction = it->getDirection();
        // add the required constraints (depending on the direction-label from the limit problem)
        if (direction == POS) {
            BExpr<IntTheory> disjunction = posConstraint(coefficients) | posInfConstraint(coefficients);
            solver->add(disjunction);
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
        SmtResult res = solver->check();
        return res == Sat;
    };

    // remember the current state for backtracking before trying several variations
    solver->push();

    // first fix that all program variables have to be constants
    // a model witnesses unbounded complexity
    for (const auto &var : vars) {
        if (!var.isTempVar()) {
            solver->add(Rel::buildEq(varCoeff.at(var), 0));
        }
    }

    if (!checkSolver()) {
        if (maxPossibleFiniteRes <= currentRes) {
            return {};
        }
        // we failed to find a model -- drop all non-mandatory constraints
        solver->pop();
        if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && maxPossibleFiniteRes.getPolynomialDegree().isInteger()) {
            int maxPossibleDegree = maxPossibleFiniteRes.getPolynomialDegree().asInteger();
            // try to find a witness for polynomial complexity with degree maxDeg,...,1
            map<int, Expr> coefficients = getCoefficients(templateCost, n);
            for (int i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; i--) {
                Expr c = coefficients.find(i)->second;
                // remember the current state for backtracking
                solver->push();
                solver->add(Rel::buildGt(c, 0));
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
    auto model = solver->model();
    for (const auto &var : vars) {
        auto c0 = varCoeff0.at(var);
        auto c = model.get<IntTheory>(varCoeff.at(var));
        smtSubs.put(var, model.contains<IntTheory>(c0) ? (Expr(model.get<IntTheory>(c0)) + Expr(c) * n) : (Expr(c) * n));
    }

    return {smtSubs};
}

BExpr<IntTheory> encodeBoolExpr(const BExpr<IntTheory> expr, const ExprSubs &templateSubs, const NumVar &n) {
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
        auto &rel = std::get<Rel>(*lit);
        assert(rel.isGZeroConstraint());
        const auto &lhs = rel.isStrict() ? rel.lhs() : rel.lhs() + 1;
        Expr ex = lhs.subs(templateSubs).expand();
        map<int, Expr> coefficients = getCoefficients(ex, n);
        return posConstraint(coefficients) | posInfConstraint(coefficients);
    }
}

std::pair<ExprSubs, Complexity> LimitSmtEncoding::applyEncoding(const BExpr<IntTheory> expr, const Expr &cost,
                                                                Complexity currentRes)
{
    // initialize z3
    auto solver = SmtFactory::modelBuildingSolver<IntTheory>(Smt<IntTheory>::chooseLogic(BoolExpressionSet<IntTheory>{expr, BoolExpression<IntTheory>::buildTheoryLit(Rel::buildGt(cost, 0))}));

    // the parameter of the desired family of solutions
    NumVar n = NumVar::next();

    // get all relevant variables
    std::set<NumVar> vars = expr->vars().get<NumVar>();
    cost.collectVars(vars);
    bool hasTmpVars = false;

    // create linear templates for all variables
    ExprSubs templateSubs;
    std::map<NumVar, NumVar> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        hasTmpVars |= var.isTempVar();
        auto c0 = NumVar::next();
        auto c = NumVar::next();
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (Expr(n) * c));
    }

    // replace variables in the cost function with their linear templates
    Expr templateCost = cost.subs(templateSubs).expand();

    // if the cost function is a constant, then we are bound to fail
    Complexity maxPossibleFiniteRes = templateCost.isPoly() ?
            Complexity::Poly(templateCost.degree(n)) :
            Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {{}, Complexity::Unknown};
    }

    auto normalized = expr->toG();
    auto encoding = encodeBoolExpr(normalized, templateSubs, n);
    solver->add(encoding);

    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&solver] {
        SmtResult res = solver->check();
        return res == Sat;
    };

    auto model = [&solver, &vars, &varCoeff0, &varCoeff, &n] {
        ExprSubs smtSubs;
        Model model = solver->model();
        for (const auto &var : vars) {
            auto c0 = varCoeff0.at(var);
            auto c = model.get<IntTheory>(varCoeff.at(var));
            smtSubs.put(var, model.contains<IntTheory>(c0) ? (Expr(model.get<IntTheory>(c0)) + Expr(c) * n) : (Expr(c) * n));
        }
        return smtSubs;
    };

    if (hasTmpVars) {
        solver->push();
        solver->add(posInfConstraint(getCoefficients(templateCost, n)));
        // first fix that all program variables have to be constants
        // a model witnesses unbounded complexity
        for (const auto &var : vars) {
            if (!var.isTempVar()) {
                solver->add(Rel::buildEq(varCoeff.at(var), 0));
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
    if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && maxPossibleFiniteRes.getPolynomialDegree().isInteger()) {
        int maxPossibleDegree = maxPossibleFiniteRes.getPolynomialDegree().asInteger();
        // try to find a witness for polynomial complexity with degree maxDeg,...,1
        map<int, Expr> coefficients = getCoefficients(templateCost, n);
        for (int i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; i--) {
            Expr c = coefficients.find(i)->second;
            // remember the current state for backtracking
            solver->push();
            solver->add(Rel::buildGt(c, 0));
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
